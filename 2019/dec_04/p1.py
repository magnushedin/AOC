def haveSameNeighbour(number):
    strNumber = str(number)

    strLast = strNumber[0]

    for char in strNumber[1:]:
        if char == strLast:
            return True
        strLast = char

    return False


def isAlwaysInc(number):
    strNumber = str(number)

    prevDigit = strNumber[0]

    for digit in strNumber[1:]:
        if int(prevDigit) > int(digit):
            return False
        prevDigit = digit

    return True


if __name__ == '__main__':
    start_number = 246515
    stop_number = 739105

    numbers_matching = 0

    for number in range(start_number, stop_number):
        if haveSameNeighbour(number) and isAlwaysInc(number):
            numbers_matching += 1

    print(numbers_matching)
