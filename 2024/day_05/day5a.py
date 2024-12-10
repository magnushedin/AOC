f = open('data.txt', 'r')

def check_rule(update, rules):
    for rule in rules:
        if (rule[0] in update) and (rule[1] in update):
            idx_low = update.index(rule[0])
            idx_high = update.index(rule[1])
            if (idx_high < idx_low):
                print(f'fail: {rule}')
                return False

    return True


def get_midpoint(update):
    return int(update[int(len(update)/2)])


rules = []
updates = []

print('reading file')
for i, line in enumerate(f):
    line = line.rstrip()
    if '|' in line:
        # print(f'rule: {line}')
        d = line.split('|')
        rules.append((d[0], d[1]))
        # print(f'{i}: {line}')
    elif line != '':
        updates.append(line.split(','))
        # print(f'update: {line}')

print('done reading file')

for rule in rules:
    print(rule)

# for update in updates:
#     print(update)

print('Start the algorithm')
sum = 0
for update in updates:
    print(update)
    if check_rule(update, rules):
        mid = get_midpoint(update)
        sum += mid
        print(f'pass: {mid}')

print(sum)
