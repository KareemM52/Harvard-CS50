from cs50 import get_int

while True:
    h = get_int("Height: ")

    if not (h > 8 or h < 1):
        break

for i in range(h):
    print(" " * ((h - 1) - i), end="")
    print("#" * (i + 1))