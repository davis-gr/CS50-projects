from cs50 import get_int

cardNum = get_int("Number: ")

cardNumStr = str(cardNum)
cardNumRev = cardNumStr[::-1]
cardNumLen = len(cardNumStr)

for i in cardNumRev[1::2]:
    