from cs50 import get_int

n = get_int("Height: ")

while n < 1 or n > 8:
    n = get_int("Height: ")

for i in range(n):
    for j in range(n-1):
        print(".", end='')
        j -= 1
    print()