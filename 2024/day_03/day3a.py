import re

file = open('data.txt', 'r')
txt = file.read()
file.close()

x = re.findall("mul\([0-9]+,[0-9]+\)", txt)

sum = 0
for instruction in x:
    numbers = instruction.lstrip('mul(').rstrip().rstrip(')').split(',')
    sum += int(numbers[0]) * int(numbers[1])

print(sum)
