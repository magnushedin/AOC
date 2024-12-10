# day 2
filename = 'data.txt'

def increasing(itm1, itm2):
    return itm1 > itm2

def read_data(file, splitter=' '):
    data = []
    for line in file:
        data.append([int(x) for x in line.rstrip().split(splitter)])
    return data


def all_xreasing(level, increasing, delta_min, delta_max):
    if increasing:
        prev = level[0] - 2
        for item in level:
            # print(item)
            if ((item - prev) < delta_min) or ((item - prev) > delta_max):
                print(f'fail (inc): {level}, {prev} -> {item}')
                return False
            prev = item
    else:
        prev = level[0] + 2
        for item in level:
            if (((item - prev) > -delta_min) or (item - prev) < -delta_max):
                print(f'fail (dec): {level}, {prev} -> {item}')
                return False
            prev = item
    print(f'pass ({increasing}): {level}')
    return True


def algorithm(data):
    # print(data)
    safe = 0
    delta_min = 1
    delta_max = 3

    for level in data:
        # print(level)
        increasing = level[0] < level[1]


        if all_xreasing(level, increasing, delta_min, delta_max):
            safe += 1
        else:
            print('Trying to remove item')
            for idx in range(len(level)):
                level_cpy = level.copy()
                level_cpy.pop(idx)
                increasing = level_cpy[0] < level_cpy[1]
                if all_xreasing(level_cpy, increasing, delta_min, delta_max):
                    safe += 1
                    print('Success')
                    break

    return safe


if __name__ == "__main__":
    file = open(filename, 'r')
    data = read_data(file)
    file.close()
    print(algorithm(data))
