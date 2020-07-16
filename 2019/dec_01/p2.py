input_file = open('input')

total_fuel = 0
for line in input_file:
	fuel = int(int(line)/3)-2
	while fuel > 0:
		total_fuel += fuel
		fuel = int(fuel/3)-2 

print(total_fuel)