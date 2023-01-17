from cs50 import get_int
card = get_int("Number: ")

# Getting size of input integer
size = str(card)

# calculate to get the sum of each card's digit
sum = 0
for i in range(0, len(size), 2):
    num = i * 2
    if num > 9:
        sum += (num / 10) + (num % 10)
    else:
        sum += num
for j in range(1, len(size), 2):
    num = j * 2
    if num > 9:
        sum += (num / 10) + (num % 10)
    else:
        sum += num
# the last digit need to be zero to be valid card
if not sum % 10 == 0:
    print("INVALID")

# calculate to get the first and the first 2 digit of credit card
digit1 = int(card / (10**(len(size)-1)))
digit2 = int(card / (10**(len(size)-2)))

# matching condition of each card's initial
if digit1 == 4:
    print("VISA")
elif digit2 == 34 or digit2 == 37:
    print("AMEX")
elif digit2 > 50 and digit2 < 56:
    print("MASTERCARD")
else:
    print("INVALID")
