from cs50 import get_int

n = get_int("Height: ")

while n < 1 or n > 8:
    n = get_int("Height: ")

j = n-1
k = 1
for i in range(n):
    print(" " * j, end='')
    print("#" * k, end='')
    print("  ", end='')
    print("#" * k)
    j -= 1
    k += 1cd