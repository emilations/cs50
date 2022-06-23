from cs50 import get_int

# Ask the user for input
while True:
    number = get_int("Height: ")
    if (number >= 1 and number <= 8):
        break

# Start the
for i in range(1, number + 1):
    for j in range(number - i):
        print(" ", end="")
    for s in range(i):
        print("#", end="")
    print("")