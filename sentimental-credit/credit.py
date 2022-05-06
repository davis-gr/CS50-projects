from cs50 import get_int

cardNum = get_int("Number: ")

cardNumStr = str(cardNum)
cardNumReverse = cardNumStr[::-1]
cardNumLen = len(cardNumStr)

sumEven = 0
sumOdd = 0
sum = 0
prodEven = 0

for i in cardNumReverse[1::2]:
    intI = int(i)*2
    strI = str(intI)
    for j in strI:
        sumEven += int(strI[j])
print(sumEven)