from cs50 import get_int


def main():
    digits = get_int("Number: ")
    digitArr = [int(digit) for digit in str(digits)]
    if (checksum(digitArr) == False):
        print("INVALID")
    else:
        cardIssuer(digitArr)


# checksum


def checksum(digitArr):

    length = len(digitArr)
    sumOfProducts = 0
    for i in range(length-1, 0, -2):
        digit = digitArr[i - 1] * 2
        # max digit = 9. max product is 19. Therefore first digit is always 1 if product >= 10
        if (digit >= 10):
            sumOfProducts += (1 + digit % 10)
        else:
            sumOfProducts += digit
    sumOfNonProducts = 0
    for i in range(length, 0, -2):
        sumOfNonProducts += digitArr[i - 1]
    sumOfSums = sumOfNonProducts + sumOfProducts
    return (sumOfSums % 10) == 0


# check issuer of card


def cardIssuer(digitArr):
    length = len(digitArr)

    # is mastercard? len = 16, 1st digit = 5
    # 2nd digit 1,2,3,4, or 5
    if (length == 16 and digitArr[0] == 5):
        MastercardApproved2ndDigits = [1, 2, 3, 4, 5]
        if (digitArr[1] in MastercardApproved2ndDigits):
            print("MASTERCARD")
        else:
            print("INVALID")

    # is AMEX? len = 15, 1st digit = 3
    # 2nd digit = 7 or 4
    elif (length == 15 and digitArr[0] == 3):
        AmexApproved2ndDigits = [7, 4]
        if (digitArr[1] in AmexApproved2ndDigits):
            print("AMEX")
        else:
            print("INVALID")

    # is VISA? len = 16, 1st digit = 4
    elif (length == 16 and digitArr[0] == 4):
        print("VISA")

    # is VISA? len = 13, 1st digit = 4
    elif (length == 13 and digitArr[0] == 4):
        print("VISA")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()
