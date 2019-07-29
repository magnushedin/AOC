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
    filename = "input"
    network = dict() # store every new signal in the network in this dict.
    raw_data = read_file(filename)
    instructions = parse_data(raw_data)

    for instruction in instructions:
        
        # Debug print the instruction
        print("Instruction: {}".format(instruction), end = '')
        
        tmp = instruction.split(" -> ")
        # If line start with NOT
        if "NOT" in tmp[0]:  
            print("NOT")
            tmp[0] = tmp[0].split(" ")
            network[tmp[1]] = ~ network[tmp[0][1]]
        # if line start with a number
        elif tmp[0].isnumeric():
            print("Numeric")
            network[tmp[1].rstrip("\n\r")] = int(tmp[0])
        # if line starts with a signal name
        elif not tmp[0].isnumeric():
            print("Signal")
            tmp[0] = tmp[0].split(" ")
            if tmp[0][1] == "AND":
                network[tmp[1].rstrip("\r\n")] = network[tmp[0][0]] & network[tmp[0][2]]
                print("{} AND {} -> {} ({})".format(tmp[0][0], tmp[0][2], tmp[1], network[tmp[1].rstrip("\r\n")]))
            elif tmp[0][1] == "OR":
                network[tmp[1].rstrip("\r\n")] = network[tmp[0][0]] | network[tmp[0][2]]
                print("{} OR {} -> {} ({})".format(tmp[0][0], tmp[0][2], tmp[1], network[tmp[1].rstrip("\r\n")]))
            elif tmp[0][1] == "RSHIFT":
                network[tmp[1].rstrip("\r\n")] = network[tmp[0][0]] >> int(tmp[0][2])
                print("{} RSHIFT {} -> {} ({})".format(tmp[0][0], tmp[0][2], tmp[1], network[tmp[1].rstrip("\r\n")]))
            elif tmp[0][1] == "LSHIFT":
                network[tmp[1].rstrip("\r\n")] = network[tmp[0][0]] << int(tmp[0][2])
                print("{} LSHIFT {} -> {} ({})".format(tmp[0][0], tmp[0][2], tmp[1], network[tmp[1].rstrip("\r\n")]))

        # Debug print content of the network dictionary
        for key in network.keys():
            print("key: -{}-".format(key))
            if network[key] < 0:
                tmp = network[key] + 2**16
            else:
                tmp = network[key]
            print("{}: {}".format(key.rstrip("\n\r"), tmp))

    #print("x: {}".format(network['i']))
"""
TODO:
Vaför finns inte key "i". Hur kommer det sig att det finns med ett line-break???
"""

if __name__ == "__main__":
    main()
