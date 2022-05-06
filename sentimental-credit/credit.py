from cs50 import get_int

cardNum = get_int("Number: ")

cardNumStr = str(cardNum)
cardNumRev = cardNumStr[::-1]
cardNumLen = len(cardNumStr)

evenDigits = []
sumOdd = 0
sum = 0
prodEven = 0

for i in cardNumRev[1::2]:
    sumEven += int(i)*2
    sumEvenStr = str(sumEven)
    for j in sumEvenStr:
        prodEven += int(j)

print(sumEvenStr)
#for i in cardNumRev[0::2]:
    #sumOdd += i