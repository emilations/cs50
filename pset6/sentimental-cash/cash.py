from cs50 import get_float

# Ask the user for input
while True:
    change_input = get_float("Change owed: ")
    if change_input > 0:
        break

# Define available coins
var1 = 1
var2 = 5
var3 = 10
var4 = 25

# Input transformation
change_trans = int(round(change_input * 100))

# Itterate on how many coins are needed
num_coins = 0

while change_trans >= var4:
    change_trans -= var4
    num_coins += 1

while change_trans >= var3:
    change_trans -= var3
    num_coins += 1

while change_trans >= var2:
    change_trans -= var2
    num_coins += 1

while change_trans >= var1:
    change_trans -= var1
    num_coins += 1

print(num_coins)