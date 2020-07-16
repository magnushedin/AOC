class instruction():
    def __init__(self, action, x, y):
        self.action = action
        self.x = x
        self.y = y

    def x_start(self):
        return self.x[0]

    def x_stop(self):
        return self.x[1]

    def y_start(self):
        return self.y[0]

    def y_stop(self):
        return self.y[1]
    
    def get_action(self):
        return self.action


def read_file(filename):
    f = open(filename)
    data = []
    for line in f:
        data.append(line)
    f.close()
    return data


def parse_data(data):
    instructions = []
    for d in data:
        tmp = d.split(' ')
        if tmp[0] == 'turn':
            action = tmp[1]
            start = tmp[2].split(',')
            stop = tmp[4].split(',')
        elif tmp[0] == 'toggle':
            action = tmp[0]
            start = tmp[1].split(',')
            stop = tmp[3].split(',')
        # print("adding action: {}".format(action))
        instructions.append(instruction(action, (int(start[0]), int(stop[0])), (int(start[1]), int(stop[1]))))

    return instructions


def set_light(x, y, action, light_matrix):
    if action == 'on':
        light_matrix[x][y] = 1
    elif action == 'off':
        light_matrix[x][y] = 0
    elif action == 'toggle':
        light_matrix[x][y] = not light_matrix[x][y]
    # print("setting led {}".format(action))


def set_light_range(instruction, light_matrix):
    for x in range(instruction.x_start(), instruction.x_stop()+1):
        for y in range(instruction.y_start(), instruction.y_stop()+1):
            set_light(x, y, instruction.get_action(), light_matrix)


def main():
    filename = "input"
    light_matrix = [x[:] for x in [[False] * 1000] * 1000]

    raw_data = read_file(filename)
    instructions = parse_data(raw_data)

    for instruction in instructions:
        set_light_range(instruction, light_matrix)

    count = 0
    for i in range(len(light_matrix)):
        for j in range(1000):
            count += light_matrix[i][j]
    print(count)


if __name__ == "__main__":
    main()
