from cs50 import get_int

n = get_int("Height: ")

while n < 1 or n > 8:
    n = get_int("Height: ")

i = 1
for i in range(n):
    j = n-1
    print ("." * j)
    j = j-1