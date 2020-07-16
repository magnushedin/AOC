import re

def read_file(filename):
    data = []
    f = open(filename)
    for line in f:
        data.append(line)
    f.close()
    return data


def count_hex(line):
    p = re.compile(r'\\x[0-9,a-f,A-F][0-9,a-f,A-F]')
    a = p.findall(line)

    return(len(a))


def count_chars(line):
    c = line.count("\"") + line.count("\\\\") + count_hex(line) * 3

    return c


def main(filename):
    data = read_file(filename)

    total_count = 0
    for d in data:
        nbr_chars = count_chars(d)
        print(d, end='')
        print(nbr_chars)
        total_count += nbr_chars

    print("Total count: {total_count}".format(total_count=total_count))

if __name__ == "__main__":
    main("input")
