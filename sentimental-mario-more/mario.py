from cs50 import get_int

# while (True):
#     getHeight = get_int("Height: ")
#     if (not getHeight >= 1 and not getHeight <=8):
#         continue
#     else:
#         break

getHeight = get_int("Height: ")
print(not getHeight >= 1)
print(not getHeight <= 8)

for i in range(getHeight):
    print("#")