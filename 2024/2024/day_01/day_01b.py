# Day 1

print("day 1, b")

f = open('data.txt', 'r')

data = []

for line in f:
    data.append(line.rstrip())

dl = []
dr = []
for d in data:
    tmp = d.split('   ')
    dl.append(int(tmp[0]))
    dr.append(int(tmp[1]))

dl.sort()
dr.sort()


sum = 0
while len(dl) > 0:
    d1 = dl.pop(0)
    d2 = len([x for x in dr if x == d1])
    sum += abs(d1 * d2)

print(sum)
