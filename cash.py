from cs50 import get_float
dollar = get_float("Change owed: ")
# Check if input number is positive integer
while dollar < 0:
    print("Invalid, please enter again.")
    dollar = get_float("Change owed: ")
# covert dollar to cent
dollar *= 100
coin = 0
# Getting Coin number base in input number value range
while dollar >= 25:
    dollar -= 25
    coin += 1
while dollar >= 10:
    dollar -= 10
    coin += 1
while dollar >= 5:
    dollar -= 5
    coin += 1
while dollar >= 1:
    dollar -= 1
    coin += 1
print(coin)
