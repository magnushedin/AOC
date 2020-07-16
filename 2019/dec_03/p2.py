input_file = open('input')

lines = []
line_coords = []

for line in input_file:
	lines.append(line.rstrip().split(','))

for line in lines:
	coords = dict()
	x = 0
	y = 0
	dist = 0
	for instruction in line:
		direction = instruction[0]
		steps = int(instruction[1:])

		if direction == 'U':
			for step in range(steps):
				y += 1
				dist += 1
				if not (x, y) in coords:
					coords[(x, y)] = dist
				else:
					pass
					#dist = coords[(x, y)]
		elif direction == 'R':
			for step in range(steps):
				x += 1
				dist += 1
				if not (x, y) in coords:
					coords[(x, y)] = dist
				else:
					pass
					#dist = coords[(x, y)]
		elif direction == 'D':
			for step in range(steps):
				y -= 1
				dist += 1
				if not (x, y) in coords:
					coords[(x, y)] = dist
				else:
					pass
					#dist = coords[(x, y)]
		elif direction == 'L':
			for step in range(steps):
				x -= 1
				dist += 1
				if not (x, y) in coords:
					coords[(x, y)] = dist
				else:
					pass
					#dist = coords[(x, y)]
		else:
			print('Error, invalid command: {}'.format(direction))

	line_coords.append(coords)
	#print(line_coords)

line_1 = line_coords[0]
line_2 = line_coords[1]

shortest = 0

print("Done adding coordinates")
print("Length line_1: {}, lenght line_2: {}".format(len(line_1), len(line_2)))

for coord in line_1:
	#print(coord)
	if coord in line_2:
		tmp = line_1[coord] + line_2[coord]
		#print(tmp)
		if (tmp < shortest) or (shortest == 0):
			shortest = tmp
			print(shortest)
print("Shortest found: {}".format(shortest))
