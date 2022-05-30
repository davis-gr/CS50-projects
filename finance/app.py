import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    portfolio = db.execute(
        "SELECT ticker, sum(share_count) as shareCount FROM transactions WHERE user_id = ? GROUP BY ticker HAVING sum(share_count) > 0", session["user_id"])
    currentPrices = []
    totalValue = 0
    for stock in portfolio:
        currentPrices.append(lookup(stock["ticker"]))
        for price in currentPrices:
            if stock["ticker"] == price["symbol"]:
                stock["name"] = price["name"]
                stock["price"] = price["price"]
                stock["value"] = stock["price"] * stock["shareCount"]
                totalValue += stock["value"]
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
    totalValue += cash[0]["cash"]
    return render_template("index.html", portfolio=portfolio, cash=cash, totalValue=totalValue)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        quotes = lookup(request.form.get("symbol"))
        try:
            shareCount = float(request.form.get("shares"))
        except ValueError:
            return apology("invalid share count!")
        userCash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        if not quotes:
            return apology("invalid ticker!")
        elif shareCount % 1 != 0:
            return apology("invalid share count!")
        elif shareCount < 1:
            return apology("invalid share count!")
        elif quotes["price"] * shareCount > userCash[0]['cash']:
            return apology("not enough $$$")
        else:
            remainingCash = userCash[0]['cash'] - quotes["price"] * shareCount
            db.execute("INSERT INTO transactions (user_id, type, ticker, share_count, share_price, datetime) VALUES(?, 'BUY', ?, ?, ?, datetime('now'))",
                       session["user_id"], quotes["symbol"], shareCount, quotes["price"])
            db.execute("UPDATE users SET cash = ? WHERE id = ?", remainingCash, session["user_id"])
            return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    transactions = db.execute(
        "SELECT ticker, share_count, share_price, datetime FROM transactions WHERE user_id = ?", session["user_id"])
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        quotes = lookup(request.form.get("symbol"))
        if not quotes:
            return apology("invalid ticker!")
        else:
            return render_template("quoted.html", symbol=quotes["symbol"], price=quotes["price"], name=quotes["name"])
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # Ensure 2nd password was submitted
        elif not request.form.get("confirmation"):
            return apology("must provide password twice")

        # Ensure passwords are the same
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords shall match")

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username not exists
        if len(rows) == 1:
            return apology("username already exists")

        # register user
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", request.form.get(
            "username"), generate_password_hash(request.form.get("password")))

        # Redirect user to home page
        return redirect("/", flash('Registered!'))

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    portfolio = db.execute(
        "SELECT ticker, sum(share_count) as shareCount FROM transactions WHERE user_id = ? GROUP BY ticker HAVING sum(share_count) > 0", session["user_id"])
    if request.method == "POST":
        ticker = request.form.get("symbol")
        if not ticker:
            return apology("missing ticker!")
        try:
            sellShares = int(request.form.get("shares"))
        except ValueError:
            return apology("missing share count!")
        if int(sellShares) < 1:
            return apology("invalid share count!")
        for stock in portfolio:
            if ticker in stock["ticker"]:
                if sellShares > stock["shareCount"]:
                    return apology("too many shares!")
                break
            return apology("invalid ticker!")
        quotes = lookup(request.form.get("symbol"))
        userCash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        remainingCash = userCash[0]['cash'] + quotes["price"] * sellShares
        db.execute("INSERT INTO transactions (user_id, type, ticker, share_count, share_price, datetime) VALUES(?, 'SELL', ?, ?, ?, datetime('now'))",
                   session["user_id"], quotes["symbol"], sellShares*-1, quotes["price"])
        db.execute("UPDATE users SET cash = ? WHERE id = ?", remainingCash, session["user_id"])
        return redirect("/")
    else:
        return render_template("sell.html", portfolio=portfolio)


@app.route("/password", methods=["GET", "POST"])
@login_required
def change_password():
    if request.method == "POST":
        if request.form.get("new_pass") != request.form.get("new_pass_confirm"):
            return apology("passwords shall match")
        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])

        # Ensure username exists and password is correct
        if not check_password_hash(rows[0]["hash"], request.form.get("old_pass")):
            return apology("invalid old password entered", 403)
        elif check_password_hash(rows[0]["hash"], request.form.get("old_pass")):
            db.execute("UPDATE users SET hash = ? WHERE id = ?", generate_password_hash(
                request.form.get("new_pass")), session["user_id"])
        return redirect("/", flash('Password changed!'))
    else:
        return render_template("password.html")

@app.route("/add", methods=["GET", "POST"])
@login_required
def add_cash():
    if request.method == "POST":
        if request.form.get("new_pass") != request.form.get("new_pass_confirm"):
            return apology("passwords shall match")
        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])

        # Ensure username exists and password is correct
        if not check_password_hash(rows[0]["hash"], request.form.get("old_pass")):
            return apology("invalid old password entered", 403)
        elif check_password_hash(rows[0]["hash"], request.form.get("old_pass")):
            db.execute("UPDATE users SET cash = ? WHERE id = ?", generate_password_hash(
                request.form.get("new_pass")), session["user_id"])
        return redirect("/", flash('Password changed!'))
    else:
        return render_template("add.html")