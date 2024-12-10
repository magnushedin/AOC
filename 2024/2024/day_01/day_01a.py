# Day 1

print("day 1, a")

f = open('data.txt', 'r')

data = []

for line in f:
    data.append(line.rstrip())

dl = []
dr = []
for d in data:
    tmp = d.split('   ')
    print(tmp)
    dl.append(int(tmp[0]))
    dr.append(int(tmp[1]))

dl.sort()
dr.sort()

print(dl)
print(dr)



sum = 0
while len(dl) > 0:
    d1 = dl.pop(0)
    d2 = dr.pop(0)
    sum += abs(d1 - d2)

print(sum)
