from cs50 import get_int

cardNum = get_int("Number: ")

cardNumStr = str(cardNum)
cardNumReverse = cardNumStr[::-1]
cardNumLen = len(cardNumStr)

sumEven = 0
sumOdd = 0

for i in cardNumReverse[1::2]:
    intI = int(i)*2
    strI = str(intI)
    for j in range(len(strI)):
        sumEven += int(strI[j])

for k in cardNumReverse[0::2]:
    intK = int(k)
    sumOdd += intK

sum = sumEven+sumOdd

if sum % 10 == 0:
    if cardNumStr[0] == '4' and (cardNumLen == 13 or cardNumLen == 16):
        print("VISA")
    elif cardNumStr[0] == '4' and (cardNumStr[1] == '4' or cardNumStr[1] == '7') and cardNumLen == 15:
        print("AMEX")
    elif cardNumStr[0] == '5' and (cardNumStr[1] == '1' or cardNumStr[1] == '2' or cardNumStr[1] == '3' or cardNumStr[1] == '4' or cardNumStr[1] == '5') and cardNumLen == 16:
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")