def read_file(filename):
    f = open(filename)
    raw_data  = []
    for line in f:
        raw_data.append(line)
    f.close()
    return raw_data

def parse_data(raw_data):
    instructions = raw_data
    return instructions

def main():
    filename = "test_input"
    network = dict() # store every new signal in the network in this dict.
    raw_data = read_file(filename)
    instructions = parse_data(raw_data)

    for instruction in instructions:
        
        # Debug print content of the network dictionary
        for key in network.keys():
            print("{}: {}".format(key.rstrip("\n\r"), network[key]))

        # Debug print the instruction
        print("Instruction: {}".format(instruction), end = '')
        
        tmp = instruction.split(" -> ")
        # If line start with NOT
        if "NOT" in tmp[0]:  
            print("NOT")
            tmp[0] = tmp[0].split(" ")
            network[tmp[1]] = network[tmp[0][1]]
        # if line start with a number
        elif tmp[0].isnumeric():
            print("Numeric")
            network[tmp[1].rstrip("\n\r")] = int(tmp[0])
        # if line starts with a signal name
        elif not tmp[0].isnumeric():
            print("Signal")

    print("")

    for key in network.keys():
        print("{}: {}".format(key.rstrip("\n\r"), network[key]))

if __name__ == "__main__":
    main()
