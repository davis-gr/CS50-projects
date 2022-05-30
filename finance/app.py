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
    portfolio = db.execute("SELECT ticker, sum(share_count) as shareCount FROM transactions WHERE user_id = ? GROUP BY ticker", session["user_id"])
    print(portfolio)
    currentPrices = []
    for stock in portfolio:
        currentPrices.append(lookup(stock["ticker"]))
    print(currentPrices)

    for stock in portfolio:
        if stock["ticker"] = 

    return render_template("index.html", portfolio = portfolio)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        quotes = lookup(request.form.get("symbol"))
        shareCount = int(request.form.get("shares"))
        userCash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        if not quotes:
            return apology("invalid ticker!")
        elif not shareCount or int(shareCount) < 1:
            return apology("invalid share count!")
        elif quotes["price"] * shareCount > userCash[0]['cash']:
            return apology("not enough $$$")
        else:
            remainingCash = userCash[0]['cash'] - quotes["price"] * shareCount
            db.execute("INSERT INTO transactions (user_id, type, ticker, share_count, share_price, datetime) VALUES(?, 'BUY', ?, ?, ?, datetime('now'))", session["user_id"], quotes["symbol"], shareCount, quotes["price"])
            db.execute("UPDATE users SET cash = ?", remainingCash)
            return redirect("/", flash('Bought!'))
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


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
        return redirect("/", flash('Welcome!'))

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
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Ensure 2nd password was submitted
        elif not request.form.get("password2"):
            return apology("must provide password twice", 403)

        # Ensure passwords are the same
        elif request.form.get("password") != request.form.get("password2"):
            return apology("passwords shall match", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username not exists
        if len(rows) == 1:
            return apology("usarname already exists", 403)

        #TODO register user
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", request.form.get("username"), generate_password_hash(request.form.get("password")))

        # Redirect user to home page
        return redirect("/", flash('Registered!'))

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
