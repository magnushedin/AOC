def compress(data):
    length = len(data)
    for i, d in enumerate(data):
        if (i > length):
            break
        if d == '.':
            length -= 1
            tmp = data[length]
            data[length] = '.'
            while tmp == '.':
                length -= 1
                tmp = data[length]
                data[length] = '.'
            data[i] = tmp
            # print(''.join(data))
        # print(f'{i}, {d}: {length}')

def checksum(data):
    sum = 0
    for i,d in enumerate(data):
        if d != '.':
            sum += i * int(d)
    return sum

if __name__ == '__main__':
    f = open('data.txt', 'r')

    for line in f:
        data = line.rstrip()

    unpack = []
    file = True

    i = 0
    for d in data:
        # print(f'running: {d}')
        if file:
            file = False
            length = int(d)
            # print(f'{i}, {d}')
            for l in range(length):
                unpack.append(str(i))
            i += 1
        else:
            file = True
            length = int(d)
            for l in range(length):
                unpack.append('.')

    print(data)
    # print(''.join(unpack))


    compress(unpack)
    while unpack[-1] == '.':
        unpack.pop()
    print(''.join(unpack))

    unpack.pop(len(unpack) -2)

    print(checksum(unpack))
