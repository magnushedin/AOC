def get_input(filename='9_data.txt'):
    f = open(filename)
    data = []
    for line in [x.rstrip() for x in f]:
        data.append(line)
    
    f.close()
    return data


def move_T(H, T):
    Hx, Hy = H
    Tx, Ty = T
    print(f'H: ({Hx},{Hy}), T: ({Tx},{Ty})')

    if Hx == Tx:
        # print(f'x is same')
        if abs(Hy - Ty) <= 1:
            return Tx, Ty
        else:
            return Tx, Ty + int((Hy - Ty)/abs(Hy - Ty))
    elif Hy == Ty:
        # print(f'y is same')
        if abs(Hx - Tx) <= 1:
            return Tx, Ty
        else:
            return Tx + int((Hx - Tx)/abs(Hx - Tx)), Ty
    elif  (abs(Hx-Tx) > 1) or (abs(Hy-Ty) > 1):
        # print('moving diagonaly')
        return Tx + 1 * int((Hx - Tx)/(abs(Hx - Tx))), Ty + 1 * int(((Hy - Ty)/abs(Hy - Ty)))
    else:
        # print('--- something unexpected happend ---')
        return Tx, Ty


def what_to_print(ix, iy, tail):
    # for i, t in enumerate(tail):
    # if (t[0] == ix) and (t[1] == iy):
    #     print(str(i), end='')
    # else:
    #     print('.', end='')
    return '.'

def print_board(tail, board_size=6): 
    for ix in range(board_size):
        for iy in range(board_size):
            print(what_to_print(ix, iy, tail))
        print('end')
    print('')


def update_tail(tail, visited):
    print(tail)
    for idx in range(1, 10):
        tail[idx] = move_T(tail[idx - 1], tail[idx])
    if tail[9] in visited:
        visited[tail[9]] += 1
    else:
        visited[tail[9]] = 1
    print_board(tail)


moves = get_input()

Hx = 0
Hy = 0
Tx = 0
Ty = 0
tail = []
for i in range(10):
    tail.append((0, 0))

for i, t in enumerate(tail):
    print(f'{i}: {t}')
print()

visited = dict()
visited[(Tx, Ty)] = 1

print('--- start ---')
print_board(tail)

for move in moves:
    print(f'== this move: {move} ==')
    direction, steps = move.split(' ')
    steps = int(steps)
    if 'R' in direction:
        for m in range(steps):
            tail[0] = (tail[0][0], tail[0][1] + 1)
            update_tail(tail, visited)
    elif 'L' in direction:
        for m in range(steps):
            tail[0] = (tail[0][0], tail[0][1] - 1)
            update_tail(tail, visited)
    elif 'U' in direction:
        for m in range(steps):
            tail[0] = (tail[0][0] + 1, tail[0][1])
            update_tail(tail, visited)
    elif 'D' in direction:
        for m in range(steps):
            tail[0] = (tail[0][0] - 1, tail[0][1])
            update_tail(tail, visited)
    # input('press a key...')


print(f'visited: {len(visited)}')    