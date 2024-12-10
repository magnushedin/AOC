import re

f = open('data_real.txt', 'r')

data = []
for line in f:
    print(line.rstrip())
    data.append(line.rstrip())
f.close()
# print(f'data{data}')

rows = len(data[0])
cols = len(data)

print(f'{rows}, {cols}')

sum = 0
for idc in range(1, cols - 1):
    # print(data[idc])
    for idr in range(1, rows - 1):
        # print(data[idc][idr])
        if data[idc][idr] == 'A':
            # print('found A')
            diag1 = data[idc-1][idr-1] + data[idc][idr] + data[idc+1][idr+1]
            diag2 = data[idc+1][idr-1] + data[idc][idr] + data[idc-1][idr+1]
            if (('MAS' in diag1) or ('SAM' in diag1)) and (('MAS' in diag2) or ('SAM' in diag2)):
                # print('found MAS')
                sum += 1
print(sum)
