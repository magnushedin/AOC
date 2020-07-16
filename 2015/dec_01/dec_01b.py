def read_file(filename):
    f = open(filename)
    input = f.read()
    f.close()
    return input

if __name__ == "__main__":
    filename = 'input'
    input = read_file(filename)

    pt = 0
    for (iter, i) in enumerate(input):
        #print("this char: {}".format(i))
        if i == ')':
            pt -= 1
        elif i == '(':
            pt += 1
        
        if (pt < 0):
            print("Entering basement at: {}".format(iter+1))
            break
