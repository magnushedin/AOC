def read_file(filename):
    f = open(filename)
    input = f.read()
    f.close()
    return input

if __name__ == "__main__":
    filename = 'input'
    input = read_file(filename)

    pt = 0
    for i in input:
        #print("this char: {}".format(i))
        if i == ')':
            pt -= 1
        elif i == '(':
            pt += 1

    print("Final floor: {}".format(pt))
