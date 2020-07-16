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
    length_line = len(line.rstrip("\r\n"))

    # Create the new line according to instructions
    tmp_line = line.rstrip("\r\n")
    tmp_line = tmp_line.replace("\\","\\\\")
    tmp_line = tmp_line.replace("\"", "\\\"")
    tmp_line = "\"" + tmp_line + "\""

    # Calculate the answer for each string
    total_nbr_char = len(tmp_line)  # Every line starts and ends with a "    
    c = total_nbr_char - length_line

    # Debug print
    print("total_char: {tot_char}, line_length: {line_length}".format(tot_char=total_nbr_char, line_length=length_line))
    print(tmp_line)
    print(line.rstrip("\r\n"))
    
    return c


def main(filename):
    data = read_file(filename)
    total_count = 0

    # Sum the answer for each line
    for d in data:
        total_count += count_chars(d)

    # Print the answer
    print("Total count: {total_count}".format(total_count=total_count))

if __name__ == "__main__":
    main("test_input")
