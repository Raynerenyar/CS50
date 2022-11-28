from cs50 import get_int

digits = get_int("Number: ")

# checksum
digitArr = [int(digit) for digit in str(digits)]
len = len(digitArr)
for i in range(len,0,1):
    print(i)