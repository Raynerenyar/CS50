from cs50 import get_int

while (true):
    getHeight = get_int("Height: ")
    if (!(getHeight >= 1) and !(getHeight <=8)):
        continue
    else:
        break

for i in range(getHeight):
    print("#")