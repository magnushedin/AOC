input_file = open('input')

lines = []
line_coords = []

for line in input_file:
	lines.append(line.rstrip().split(','))

for line in lines:
	coords = []
	x = 0
	y = 0
	for instruction in line:
		direction = instruction[0]
		steps = int(instruction[1:])
		
		if direction == 'U':
			for step in range(steps):
				y += 1
				coords.append((x, y))
		elif direction == 'R':
			for step in range(steps):
				x += 1
				coords.append((x,y))
		elif direction == 'D':
			for step in range(steps):
				y -= 1
				coords.append((x,y))			
		elif direction == 'L':
			for step in range(steps):
				x -= 1
				coords.append((x,y))
		else:
			print('Error, invalid command: {}'.format(direction))

	tmp_set = set(coords)
	coords = list(tmp_set)
	line_coords.append(coords)
	#print(line_coords)

line_1 = line_coords[0]
line_2 = line_coords[1]

shortest = 99999999999

print("Done adding coordinates")

for coord in line_1:
	#print(coord)
	if coord in line_2:
		tmp = abs(coord[0]) + abs(coord[1])
		#print(tmp)
		if tmp < shortest:
			shortest = tmp
			print(shortest)
print(shortest)
