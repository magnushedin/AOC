def get_input(filename='8_data.txt'):
    f = open(filename)
    data = []
    for line in [x.rstrip() for x in f]:
        data.append(line)
    
    f.close()
    return data


def is_visible(line, idx):
    if (idx == 0) or (idx == len(line)-1):
        return True

    left = [int(x) for x in list(line[0:idx])]
    right = [int(x) for x in list(line[idx+1:])]

    if max(left) < int(line[idx]):
        # print(f'line: {line}, idx: {idx}, left: {left},  next: {line[idx]}')
        return True
    elif max(right) < int(line[idx]):
        # print(f'line: {line}, idx: {idx}, right: {right},  next: {line[idx]}')
        return True
    else:
        return False

def view_distance(line, idx):
    cnt_right = 0
    cnt_left = 0
    right = [int(x) for x in list(line[idx+1:])] 
    left = [int(x) for x in list(line[0:idx])]
    left = left[::-1]
    
    if (idx != len(line)-1):
        for tree in right:
            if tree < int(line[idx]):
                cnt_right += 1
            else:
                cnt_right += 1
                break
    
    if (idx != 0):
        for tree in left:
            if tree < int(line[idx]):
                cnt_left += 1
            else:
                cnt_left += 1
                break

    print(f'line: {line}, idx: {idx}, tree: {line[idx]}')
    # print(f'right: {right}')
    # print(f'left: {left}')
    

    cnt = cnt_right * cnt_left
    return cnt


data = get_input()

rows = []
cols = []
for line in data:
    rows.append(line)
    for i, c in enumerate(line):
        try:
            cols[i] += c
        except:
            cols.append(c)


print(f'col: {len(cols)}, row: {len(rows)}')

cnt = 0
for c in range(len(cols)):
    for r in range(len(rows)):
        if is_visible(cols[c], r) or is_visible(rows[r], c):
            cnt += 1

print(f'rows: {rows}')
print(f'cols: {cols}')

max_dist_value = 0
for c in range(len(cols)):
    for r in range(len(rows)):
        tmp =  view_distance(cols[c], r) * view_distance(rows[r], c)
        if tmp > max_dist_value:
            max_dist_value = tmp
            print(f'--- max_distanse: {max_dist_value}, c: {c}, r: {r}')



print(f'view distance: {view_distance(rows[0], 2)}')
print(f'max view distance: {max_dist_value}')

print(f'cnt: {cnt}')