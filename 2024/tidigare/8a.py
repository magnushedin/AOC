def get_input(filename='8_testdata.txt'):
    f = open(filename)
    data = []
    for line in [x.rstrip() for x in f]:
        data.append(line)
    
    f.close()
    return data

def print_forest(forest):
    for tree_line in forest:
        for tree in tree_line:
            print(tree, end='')
        print('')

def get_cnt_left(forest):
    cnt = 0
    for tree_line in forest:
        # print(f'tree_line: {tree_line}')
        for idx in range(len(tree_line)-1):
            if tree_line[idx] < tree_line[idx+1]:
                cnt += 1
            else:
                break
    return cnt

def get_cnt_right(forest):
    cnt = 0
    for tree_line in forest:
        # print(f'tree_line: {tree_line}')
        for idx in range(len(tree_line)-1, 0, -1):
            # print(f'{tree_line[idx]}, {tree_line[idx-1]}')
            if tree_line[idx] < tree_line[idx-1]:
                # print(idx)
                cnt += 1
            else:
                break
    return cnt

def get_cnt_up(forest):
    cnt = 0
    for idy in range(len(forest[0])):
        for idx in range(len(forest)-1):
            if forest[idx][idy] > forest[idx+1][idy]:
                cnt += 1
            else:
                break
    return cnt

def get_cnt_down(forest):
    cnt = 0
    for idy in range(len(forest[0])):
        for idx in range(len(forest)-1, 0, -1):
            if forest[idx][idy] > forest[idx-1][idy]:
                cnt += 1
            else:
                break
    return cnt


data = get_input()

forest = []

for line in data:
    forest.append([])
    for c in line:
        forest[-1].append(int(c))

print_forest(forest)

cnt_left  = get_cnt_left(forest)
cnt_right = get_cnt_right(forest)
cnt_up    = get_cnt_up(forest)
cnt_down    = get_cnt_down(forest)

print(f'cnt_left: {cnt_left}')
print(f'cnt_right: {cnt_right}')
print(f'cnt_up: {cnt_up}')
print(f'cnt_down: {cnt_down}')
print(f'total trees: {cnt_left + cnt_right + cnt_up + cnt_down}')