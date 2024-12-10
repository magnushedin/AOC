import re

f = open('data_real.txt', 'r')

data = []
for line in f:
    print(line.rstrip())
    data.append(line.rstrip())
f.close()
print(f'data{data}')

one_line_hor = ''
for itm in data:
    one_line_hor += itm.rstrip()
print(f'one line horisontal: {one_line_hor}')

vert_lines = []
for idx in range(len(data[0])):
    vert_lines.append(one_line_hor[idx::len(data[0])])

print(f'vertical lines: {vert_lines}')

data_diag = []
fill = '.' * len(data[0])
for line in data:
    txt = fill + line + fill
    data_diag.append(txt)
print(data_diag)

one_line_diag = ""
for line in data_diag:
    one_line_diag += line
print(one_line_diag)

diag_lines = []
for idx in range(len(data_diag[0])):
    diag_lines.append(one_line_diag[idx::len(data_diag[0])+1])
print(f'diag_lines: {diag_lines}')

for idx in range(len(data_diag[0])):
    diag_lines.append(one_line_diag[idx::len(data_diag[0])-1])
print(f'diag_lines: {diag_lines}')

sum_hor = 0
for line in data:
    x = re.findall("XMAS", line)
    sum_hor += len(x)
    x = re.findall("SAMX", line)
    sum_hor += len(x)
    if len(x) > 0:
        print(f'horisontal: {x}')

sum_vert = 0
for line in vert_lines:
    x = re.findall("XMAS", line)
    sum_vert += len(x)
    x = re.findall("SAMX", line)
    sum_vert += len(x)
    if len(x) > 0:
        print(f'vertical: {x}')

sum_diag = 0
for line in diag_lines:
    x = re.findall("XMAS", line)
    sum_diag += len(x)
    x = re.findall("SAMX", line)
    sum_diag += len(x)
    if len(x) > 0:
        print(f'diag: {x}')

sum = sum_hor + sum_vert + sum_diag
print(f'{sum_hor} + {sum_vert} + {sum_diag} = {sum}')

# vert = []
# start = 1
# offset = -1
# print(m[start::offset])
