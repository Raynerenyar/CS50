from cs50 import get_int

digits = get_int("Number: ")

# checksum
digitArr = [int(digit) for digit in str(digits)]
len = len(digitArr)
print("length of card num is " + str(len))
for i in range(len-1,0,-2):
    
    print(i)