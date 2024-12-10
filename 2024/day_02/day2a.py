# day 2
filename = 'data.txt'


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
        if level[0] < level[1]:
            # print('increasing')
            increasing = True
        else:
            # print('decreasing')
            increasing = False

        if all_xreasing(level, increasing, delta_min, delta_max):
            safe += 1

    return safe


if __name__ == "__main__":
    file = open(filename, 'r')
    data = read_data(file)
    file.close()
    print(algorithm(data))
