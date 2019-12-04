def haveSameNeighbour(number):
    strNumber = str(number)

    for idx in range(0, 5):
        if strNumber[idx] == strNumber[idx +1]:
            if idx >= 4:
                if strNumber[idx] != strNumber[idx -1]:
                    return True
            elif strNumber[idx +1] != strNumber[idx +2] and strNumber[idx] != strNumber[idx -1]:
                    return True

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

    print(haveSameNeighbour(123456))
    print(haveSameNeighbour(123356))
    print(haveSameNeighbour(133356))
    print(haveSameNeighbour(123566))
    print(haveSameNeighbour(113456))
    print(haveSameNeighbour(112666))
    print(haveSameNeighbour(111346))
    print(haveSameNeighbour(111366))
    print(haveSameNeighbour(699999))

    numbers_matching = 0

    for number in range(start_number, stop_number):
        if haveSameNeighbour(number) and isAlwaysInc(number):
            #print(number)
            numbers_matching += 1

    print(numbers_matching)
