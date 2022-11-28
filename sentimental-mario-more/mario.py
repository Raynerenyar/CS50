from cs50 import get_int

while (True):
    getHeight = get_int("Height: ")
    if not (getHeight >= 1 and getHeight <=8):
        continue
    else:
        break

Spacing = 0
for i in range(1,getHeight+1):
    Spacing = getHeight - i
    print((" " * Spacing)+("#" * i), end = '')
    print("  ", end = '')
    print((("#" * i) + " " * Spacing))
print("\n")