from cs50 import get_int

digits = get_int("Number: ")

# checksum
digitArr = [int(digit) for digit in str(digits)]
len = len(digitArr)
print("length of card num is " + str(len))
sumOfProducts = 0
sumofNonProducts = 0
for i in range(len-1,0,-2):
    if (digitArr[i - 1] >= 10): # max digit = 9. max product is 19. Therefore first digit is always 1 if product >= 10
        sumOfProducts += (1 + digitArr[i - 1] % 10)
    else:
        sumOfProducts += digitArr[i - 1] * 2
print(sumOfProducts)
# for i in range(len,0,-2):
