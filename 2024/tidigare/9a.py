def get_input(filename='9_testdata.txt'):
    f = open(filename)
    data = []
    for line in [x.rstrip() for x in f]:
        data.append(line)
    
    f.close()
    return data


def move_T(Hx, Hy, Tx, Ty):
    print(f'H: ({Hx},{Hy}), T: ({Tx},{Ty})')
    if Hx == Tx:
        print(f'x is same')
        if abs(Hy - Ty) <= 1:
            return Tx, Ty
        else:
            return Tx, Ty + int((Hy - Ty)/abs(Hy - Ty))
    elif Hy == Ty:
        print(f'y is same')
        if abs(Hx - Tx) <= 1:
            return Tx, Ty
        else:
            return Tx + int((Hx - Tx)/abs(Hx - Tx)), Ty
    elif  (abs(Hx-Tx) > 1) or (abs(Hy-Ty) > 1):
        print('moving diagonaly')
        return Tx + 1 * int((Hx - Tx)/(abs(Hx - Tx))), Ty + 1 * int(((Hy - Ty)/abs(Hy - Ty)))
    else:
        print('--- something unexpected happend ---')
        return Tx, Ty


def print_board(Hx, Hy, Tx=0, Ty=0, board_size=6): 
    for ix in range(board_size):
        for iy in range(board_size):
            if (Hx == ix) and (Hy == iy):
                print('H', end='')
            elif (Tx == ix) and (Ty == iy):
                print('T', end='')
            else:
                print('.', end='')
        print('')
    print('')

moves = get_input()

Hx = 0
Hy = 0
Tx = 0
Ty = 0
visited = dict()
visited[(Tx, Ty)] = 1

print('--- start ---')
print_board(Hx, Hy)

for move in moves:
    print(f'== this move: {move} ==')
    direction, steps = move.split(' ')
    steps = int(steps)
    if 'R' in direction:
        for m in range(steps):
            Hy += 1
            Tx, Ty = move_T(Hx, Hy, Tx, Ty)
            if (Tx, Ty) in visited:
                visited[(Tx, Ty)] += 1
            else:
                visited[(Tx, Ty)] = 1
            print_board(Hx, Hy, Tx, Ty)
    elif 'L' in direction:
        for m in range(steps):
            Hy -= 1
            Tx, Ty = move_T(Hx, Hy, Tx, Ty)
            if (Tx, Ty) in visited:
                visited[(Tx, Ty)] += 1
            else:
                visited[(Tx, Ty)] = 1
            print_board(Hx, Hy, Tx, Ty)
    elif 'U' in direction:
        for m in range(steps):
            Hx += 1
            Tx, Ty = move_T(Hx, Hy, Tx, Ty)
            if (Tx, Ty) in visited:
                visited[(Tx, Ty)] += 1
            else:
                visited[(Tx, Ty)] = 1
            print_board(Hx, Hy, Tx, Ty)
    elif 'D' in direction:
        for m in range(steps):
            Hx -= 1
            Tx, Ty = move_T(Hx, Hy, Tx, Ty)
            if (Tx, Ty) in visited:
                visited[(Tx, Ty)] += 1
            else:
                visited[(Tx, Ty)] = 1
            print_board(Hx, Hy, Tx, Ty)


print(f'visited: {len(visited)}')
    