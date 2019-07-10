def read_file(filename):
    data = []
    f = open(filename)
    for line in f:
        data.append(line)
    f.close()
    return data

def two_in_a_row_with_jump(d):
    for i in range(len(d)-2):
        if d[i] == d[i+2]:
            print("Two in a row with jump ({}{}{}): {}".format(d[i], d[i+1], d[i+2], d), end='')
            return True
    print("Not two in a row with jump: {}".format(d), end='')
    return False

def pair_repeat(d):
    d_string = ''.join(d)
    for i in range(len(d)-2):
        pattern = d[i] + d[i+1]
        if pattern in d_string[i+2:]:
            print("pattern: {} found in string: {}".format(pattern, d_string), end='')
            return True
    print("Pattern not found in string: {}".format(d), end='')
    return False

def main():
    nice_strings = 0
    filename = "input"
    # filename = "test_input_b"

    data = read_file(filename)

    for d in data:
        if two_in_a_row_with_jump(d) and pair_repeat(d):
            nice_strings += 1
            print("Nice string: {}".format(d), end='')

    print("\nThere are {} nice strings".format(nice_strings))


if __name__ == "__main__":
    main()
