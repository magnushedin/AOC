input_file = open('input')

line = input_file.read()
input_array = line.split(',')

#print(input_array)

pc = 0
while int(input_array[pc]) != 99:
	# print("pc: {}, op: {}, {}, {}, {}".format(pc, input_array[pc], input_array[pc+1], input_array[pc+2], input_array[pc+3]))
	if int(input_array[pc]) == 1:
		input_array[int(input_array[pc+3])] = int(input_array[int(input_array[pc+1])]) + int(input_array[int(input_array[pc+2])])
		#print('add, s: {}'.format(input_array[pc+3]))
	elif int(input_array[pc]) == 2:
		input_array[int(input_array[pc+3])] = int(input_array[int(input_array[pc+1])]) * int(input_array[int(input_array[pc+2])])
	else:
		print('Wrong OP code {}'.format(input_array[pc]))
		exit()
	pc += 4
	#print(input_array)

#print(input_array)
print("answer is: {}".format(input_array[0]))
