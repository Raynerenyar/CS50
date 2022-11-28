from cs50 import get_int

digits = get_int("Number: ")

# checksum

def checksum():
    digitArr = [int(digit) for digit in str(digits)]
    length = len(digitArr)
    print("length of card num is " + str(length))
    sumOfProducts = 0
    for i in range(len-1,0,-2):
        digit = digitArr[i - 1] * 2
        # print(i)
        if (digit >= 10): # max digit = 9. max product is 19. Therefore first digit is always 1 if product >= 10
            sumOfProducts += (1 + digit % 10)
        else:
            sumOfProducts += digit
    # print(sumOfProducts)
    sumOfNonProducts = 0
    for i in range(len,0,-2):
        sumOfNonProducts += digitArr[i - 1]
    sumOfSums = sumOfNonProducts + sumOfProducts
    return (sumOfSums % 10) == 0

print(checksum())