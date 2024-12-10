from time import sleep


def print_map(map, coord):
    for line in map:
        print(''.join(line))


def reprint_map(map, coord):
    n = len(map)
    LINE_UP = '\033[1A'
    LINE_CLEAR = '\x1b[2K'
    for i in range(n):
        print(LINE_UP, end=LINE_CLEAR)

    print_map(map, coord)


def find_start(map):
    for row, line in enumerate(map):
        for col, c in enumerate(line):
            if c == '^':
                return [row, col, 'u']


def move(map, coord, obs):
    row = coord[0]
    col = coord[1]
    dir = coord[2]
    if dir == 'u':
        if (row - 1) >= 0:
            if map[row - 1][col] != '#':
                map[row][col] = 'x'
                coord[0] -= 1
            elif coord[2] in obs[row - 1][col]:
                    return False
            else:
                coord[2] = 'r'
                map[row - 1][col] = '#'
                obs[row - 1][col] += 'u'
        else:
            coord[0] -= 1
    elif dir == 'r':
        if (col + 1) < len(map):
            if map[row][col + 1] != '#':
                map[row][col] = 'x'
                coord[1] += 1
            elif coord[2] in obs[row][col + 1]:
                    return False
            else:
                coord[2] = 'd'
                map[row][col + 1] = '#'
                obs[row][col + 1] += 'r'
        else:
            coord[1] += 1
    elif dir == 'd':
        if (row + 1) < len(map):
            if map[row + 1][col] != '#':
                map[row][col] = 'x'
                coord[0] += 1
            elif coord[2] in obs[row + 1][col]:
                    return False
            else:
                coord[2] = 'l'
                map[row + 1][col] = '#'
                obs[row + 1][col] += 'd'
        else:
            coord[0] += 1
    elif dir == 'l':
        if (col - 1) >= 0:
            if map[row][col - 1] != '#':
                map[row][col] = 'x'
                coord[1] -= 1
            elif coord[2] in obs[row][col - 1]:
                    return False
            else:
                coord[2] = 'u'
                map[row][col - 1] = '#'
                obs[row][col - 1] += 'l'
        else:
            coord[1] -= 1
    return True


def in_map(map, coord):
    if (coord[0] < 0) or (coord[0] > len(map)):
        # print(f'out of map {coord[0]},{coord[1]}')
        return False
    elif (coord[1] < 0) or (coord[1] > len(map[0])):
        # print(f'out of map {coord[0]},{coord[1]}')
        return False
    else:
        return True


def count(map, c):
    sum = 0
    for line in map:
        for i in line:
            if i == c:
                sum += 1
    return sum


def is_loop(map, coord):
    dir = coord[2]
    if dir == 'u':
        if dir in (map[coord[0] - 1][coord[1]]):
            return True
    elif dir == 'r':
        if dir in (map[coord[0]][coord[1] + 1]):
            return True
    elif dir == 'd':
        if dir in (map[coord[0] + 1][coord[1]]):
            return True
    elif dir == 'l':
        if dir in (map[coord[0]][coord[1] - 1]):
            return True
    else:
        return False


def contains_loop(map, row, col):
    map_tmp = []
    for line in map:
        map_tmp.append(line.copy())
    obs = []
    for line in map:
        obs.append(line.copy())
    coord = find_start(map_tmp)
    map_tmp[row][col] = '#'
    # print('new map')
    # print_map(map_tmp, coord)
    while in_map(map_tmp, coord):
        if not move(map_tmp, coord, obs):
            return True
        # sleep(0.1)
        # reprint_map(map_tmp, coord)
    return False


if __name__ == '__main__':
    f = open('data.txt', 'r')

    map = []
    for line in f:
        line = line.rstrip()
        tmp = []
        for c in line:
            tmp.append(c)
        map.append(tmp.copy())

    coord = find_start(map)
    print_map(map, coord)

    # print(coord)

    obs = []
    for line in map:
        obs.append(line.copy())
    loop_sum = 0

    for row, line in enumerate(map):
        for col, c in enumerate(line):
            if contains_loop(map, row, col):
                loop_sum += 1
                print(f'{row},{col}')

    # print(contains_loop(map, 6, 3))

    # print_map(map)

    # print(count(map, 'x'))
    print(loop_sum)
