"""This is a Python file"""

input_file = open('./2019/dec_02/input')

line = input_file.read()
input_array = line.split(',')

input_array[1] = 12
input_array[2] = 2

#print(input_array)

PC = 0
while int(input_array[PC]) != 99:
    #print("PC: {}, op: {}, {} +* {} => {}".format(PC, input_array[PC], input_array[PC+1],
    #input_array[PC+2], input_array[PC+3]))
    if int(input_array[PC]) == 1:
        input_array[int(input_array[PC+3])] = int(input_array[int(input_array[PC+1])]) + \
                                              int(input_array[int(input_array[PC+2])])
        #print('add, s: {}'.format(input_array[PC+3]))
    elif int(input_array[PC]) == 2:
        input_array[int(input_array[PC+3])] = int(input_array[int(input_array[PC+1])]) * \
                                              int(input_array[int(input_array[PC+2])])
    else:
        print('Wrong OP code {}'.format(input_array[PC]))
        exit()
    PC += 4
    #print(input_array)

#print(input_array)
print("answer is: {}".format(input_array[0]))
