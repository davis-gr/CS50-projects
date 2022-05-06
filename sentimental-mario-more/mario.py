from cs50 import get_int

n = get_int("Height: ")

while n < 1 or n > 8:
    n = get_int("Height: ")

for i in range(n):
    j = n-1
    while j > 0:
        print(".", end='')
        j = j-1
        k = 1
        for k in range(i):
            print("#")
    l = 1
    #for l in range()