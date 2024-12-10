def get_input(filename='10_testdata.txt'):
    f = open(filename)
    data = []
    for line in [x.rstrip() for x in f]:
        data.append(line)
    
    f.close()
    return data



def check_register(cycle, x):
    checks =  [20, 60, 100, 140, 180, 220]
    if cycle in checks:
        print(f'cycle: {cycle}, x: {x}')
    print(f'{cycle}, {x}')

data = get_input()

instructions = []

cycles_to_run = 0
x = 1
new_x = 1

for cycle, instruction in enumerate(data):
    check_register(cycle, x)
    if cycles_to_run == 0:
        x = new_x
        if 'noop' in instruction:
            cycles_to_run = 1
            new_x = x
        elif 'addx' in instruction:
            instr, value = instruction.split(' ')
            new_x = x + int(value)
            cycles_to_run = 2
    else:
        cycles_to_run -= 1




