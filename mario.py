from cs50 import get_int

row = get_int("Height: ")
# Check if row is between 1 to 8
while row < 1 or row > 8:
    print("Invalid, please enter again.")
    row = get_int("Height: ")
space = row - 1
for i in range(row):
    # print number of space base of row-1
    for j in range(space):
        print(" ", end="")
    # print number of hashtag base of the current row number
    for k in range(i+1):
        print("#", end="")
    print("  ", end="")
    # re-print number of hashtag agian
    for p in range(i+1):
        print("#", end="")
    print("")
    space -= 1
