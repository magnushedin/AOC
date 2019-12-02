input_file = open('input')

total_fuel = 0
for line in input_file:
	total_fuel = int(int(line)/3)-2

print(total_fuel)