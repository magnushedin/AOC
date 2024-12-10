from time import sleep

def guard_in_maze(data, loc):
    if loc[0] < 0:
        return False
    elif loc[0] > (len(data) + 1):
        return False
    elif loc[1] < 0:
        return False
    elif loc[1] > (len(data[0]) + 1):
        return False
    else:
        return True


def is_empty(data, loc):
    try:
        if data[loc[0]][loc[1]] != '#':
            return True
        else:
            # print(f'{loc}: {data[loc[0]][loc[1]]}')
            return False
    except:
        return True

def print_line(line):
    print(''.join(line))


f = open('data.txt', 'r')

data = []
for line in f:
    tmp = []
    line = line.strip()
    for itm in line:
        tmp.append(itm)
    data.append(tmp.copy())
f.close()

print('---new---')
print(print_line(data[0]))
print('---end---')

start = [0,0]
for row, line in enumerate(data):
    # print(line)
    for col, itm in enumerate(line):
        if itm == '^':
            start = [row, col]

# data[start[0]][start[1]] = 'x'

dir = 'u'

loc = start.copy()
while guard_in_maze(data, loc):
    if dir == 'u':
        tmp = [loc[0] - 1, loc[1]]
        if is_empty(data, tmp):
            loc = tmp.copy()
            # print(f'up: {loc}')
        else:
            dir = 'r'
    elif dir == 'r':
        tmp = [loc[0], loc[1] + 1]
        if is_empty(data, tmp):
            loc = tmp.copy()
            # print(f'right: {loc}')
        else:
            dir = 'd'
    elif dir == 'd':
        tmp = [loc[0] + 1, loc[1]]
        if is_empty(data, tmp):
            loc = tmp.copy()
            # print(f'down: {loc}')
        else:
            dir = 'l'
    elif dir == 'l':
        tmp = [loc[0], loc[1] - 1]
        if is_empty(data, tmp):
            loc = tmp.copy()
            # print(f'left: {loc}')
        else:
            dir = 'u'
    try:
        # print(f'{loc}: {data[loc[0]][loc[1]]}, {dir}')
        data[loc[0]][loc[1]] = 'x'
    except:
        pass

    # print(f"\033[{len(data)+2}A")
    # print('new maze')
    # for line in data:
    #     print_line(line)
    # sleep(0.1)

sum = 0
for line in data:
    sum += line.count('x')
print(sum)

f = open('maze.txt', 'w')
for line in data:
    line.append("\n")
    f.write(''.join(line))
f.close()
