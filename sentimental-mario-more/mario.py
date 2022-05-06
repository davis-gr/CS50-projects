from cs50 import get_int

n = get_int("Height: ")

while n < 1 or n > 8:
    n = get_int("Height: ")

