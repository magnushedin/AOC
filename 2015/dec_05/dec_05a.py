def read_file(filename):
    data = []
    f = open(filename)
    for line in f:
        data.append(line)
    f.close()
    return data

def three_vowels(vowels, d):
    count = 0
    for v in vowels:
        count += d.count(v)
    if count >= 3:
        return True
    else:
        print("Not enough with vowels: {}".format(d), end='')
        return False

def two_in_a_row(d):
    for i in range(len(d)-1):
        if d[i] == d[i+1]:
            return True
    print("Not two in a row: {}".format(d), end='')
    return False

def contain_evil_combo(evil_combos, d):
    for ec in evil_combos:
        if ec in d:
            print("Evil combo: {} -- {}".format(d, ec))
            return True
    return False

def main():
    vowels = "aeiou"
    evil_combos = ["ab", "cd", "pq", "xy"]
    nice_strings = 0
    filename = "input"

    data = read_file(filename)

    for d in data:
        if three_vowels(vowels, d) and two_in_a_row(d) and not contain_evil_combo(evil_combos, d):
            nice_strings += 1
            print("Nice string: {}".format(d), end='')

    print("\nThere are {} nice strings".format(nice_strings))


if __name__ == "__main__":
    main()
