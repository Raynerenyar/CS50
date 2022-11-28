from cs50 import get_int

digits = get_int("Number: ")

# checksum
digitArr = [int(digit) for digit in str(digits)]
len = len(digitArr)
print("length of card num is " + str(len))
sumOfProducts = 0
sumofNonProducts = 0
for i in range(len-1,0,-2):
    if (digitArr[i - 1] >= 10):
    sumOfProducts += digitArr[i - 1]) * 2
for i in range(len,0,-2):
