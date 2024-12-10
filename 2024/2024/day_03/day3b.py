import re

file = open('data.txt', 'r')
txt = file.read()
file.close()

x = re.findall("mul\([0-9]+,[0-9]+\)|do\(\)|don't\(\)", txt)
# print(x)
print(len(x))

sum = 0
do = True
for inst in x:
    if "do()" in inst:
        print(f"do: {inst}")
        do = True
    elif "don't()" in inst:
        print(f"don't: {inst}")
        do = False
    elif do:
        print(inst)
        numbers = inst.lstrip('mul(').rstrip().rstrip(')').split(',')
        sum += int(numbers[0]) * int(numbers[1])
    else:
        # do nothing
        pass

print(sum)
