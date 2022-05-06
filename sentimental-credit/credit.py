from cs50 import get_int

cardNum = get_int("Number: ")

cardNumStr = str(cardNum)
cardNumLen = len(cardNum)

if cardNumLen % 2 == 0:
    for i in cardNumStr: