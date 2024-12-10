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
        print(f'line: {line}, idx: {idx}, left: {left},  next: {line[idx]}')
        return True
    elif max(right) < int(line[idx]):
        print(f'line: {line}, idx: {idx}, right: {right},  next: {line[idx]}')
        return True
    else:
        return False


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


print(f'cnt: {cnt}')