from cs50 import get_float
from math import floor


def main():
    while True:
        changedoll = get_float("Change owed: ")
        changecent = floor(changedoll * 100)

        if changecent > 0:
            break

    pennies = ((changecent % 25) % 10) % 5 
    nickels = ((changecent % 25) % 10) // 5
    dimes = (changecent % 25) // 10
    quarters = changecent // 25
    
    
    print(f"Coin(s): {quarters + dimes + nickels + pennies}")


if __name__ == "__main__":
    main()