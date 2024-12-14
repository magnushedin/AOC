import re

class machine():
    def __init__(self, btnA, btnB, prize):
        self.btnA = btnA
        self.btnB = btnB
        self.prize = prize
        self.cost = 0

    def __str__(self):
        return f'A: {self.btnA}, B: {self.btnB}, Prize: {self.prize}, cost: {self.cost}'


def parse_data(data, offset=0):
    m = []
    for row in data:
        if 'Button A' in row:
            ax, ay = re.findall('\d+', row)
        elif 'Button B' in row:
            bx, by = re.findall('\d+', row)
        elif 'Prize' in row:
            px, py = re.findall('\d+', row)
        elif row == '':
            m.append(machine((int(ax),int(ay)),(int(bx),int(by)),(int(offset)+int(px),int(offset)+int(py))))
    return m


def check_input(machine, ia, ib):
     pos_x = (machine.btnA[0] * ia + machine.btnB[0] * ib)
     pos_y = (machine.btnA[1] * ia + machine.btnB[1] * ib)
     print(f'{machine.btnA[0]} * {ia} + {machine.btnB[0]} * {ib} = {pos_x} -- {machine.btnA[1]} * {ia} + {machine.btnB[1]} * {ib} = {pos_y}')
     if (pos_x == machine.prize[0]) and (pos_y == machine.prize[1]):
         return True
     else:
         return False



def partA(machines):
    for machine in machines:
        done = False
        # print(machine)
        ia = 0
        while not done:
            ia += 1
            if not done:
                ib = 0
                while not done:
                    ib += 1
                    if ((machine.btnA[0] * ia + machine.btnB[0] * ib) == machine.prize[0]) and (machine.btnA[1] * ia + machine.btnB[1] * ib) == machine.prize[1]:
                        machine.cost = ia * 3 + ib * 1
                        done = True
                    elif ((machine.btnA[0] * ia + machine.btnB[0] * ib) > machine.prize[0]) or (machine.btnA[1] * ia + machine.btnB[1] * ib) > machine.prize[1]:
                        done = True
            else:
                break

    print('Done')
    sum = 0
    for machine in machines:
        if machine.cost > 0:
            sum += machine.cost

    print(sum)


def partB(machines):
    sum = 0
    for machine in machines:
        print(machine)
        a = machine.btnA
        b = machine.btnB
        p = machine.prize

        def verify(i, j):
            if i < 0 or j < 0:
                print(f'{i},{j}')
                return False
            print((a[0] * i + b[0] * j == p[0]) and (a[1] * i + b[1] * j == p[1]))
            print(f'{(a[0] * i + b[0] * j)} == {p[0]} -- {a[1] * i + b[1] * j} == {p[1]}')
            return (a[0] * i + b[0] * j == p[0]) and (a[1] * i + b[1] * j == p[1])

        # i = (p[0] * b[1] - b[0] * p[1]) // (b[1] * a[0] - b[0] *a[1])
        # j = (p[1] - a[1] * i) // b[1]
        i = (p[0] * b[1] - p[1] * b[0]) // (a[0] * b[1] - a[1] * b[0])
        j = (a[0] * p[1] - a[1] * p[0]) // (a[0] * b[1] - a[1] * b[0])

        if verify(i, j):
            machine.cost = 3*int(i) + int(j)
            sum += 3*int(i) + int(j)

    print(sum)


if __name__ == '__main__':
    f = open('input.txt', 'r')

    data = []
    for line in f:
        line = line.rstrip()
        data.append(line)
    data.append('')

    machines = parse_data(data, offset=10000000000000)

    # partA(machines)
    partB(machines)

    # for machine in machines:
    #     print(machine)
