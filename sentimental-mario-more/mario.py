from cs50 import get_int

while (True):
    getHeight = get_int("Height: ")
    if not (getHeight >= 1 and getHeight <=8):
        continue
    else:
        break

whitespace = 0
for i in range(1,getHeight+1):
    whitespace = getHeight - i
    print((" " * whitespace)+("#" * i), end = '')
    print("  ", end = '')
    print((("#" * i) + " " * whitespace))
print("\n")