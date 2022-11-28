from cs50 import get_int

while (True):
    getHeight = get_int("Height: ")
    if not (getHeight >= 1 and getHeight <=8):
        continue
    else:
        break

for i in range(getHeight):
    print(("#" * i) + "  " + "*")