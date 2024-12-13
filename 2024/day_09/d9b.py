class sector():
    def __init__(self, type, size, id):
        self.type = type
        self.size = size
        self.id = id

    def copy(self):
        return sector(self.type, self.size, self.id)


def checksum(fs):
    sum = 0
    i = 0
    for itm in fs:
        for j in range(itm.size):
            if itm.type == 'file':
                # print(f'{itm.id}: {itm.id}*{i}')
                sum += int(itm.id) * i
            else:
                pass
                # print('.')
            i += 1

    return sum


def checksum_string(fs):
    fs_str = fs_string_repr(fs)
    sum = 0
    i = 0
    for itm in fs_str:
        if itm != '.':
            sum += int(itm) * i
            i += 1
        else:
            i += 1
    return sum


def fs_string_repr(fs):
    tmp_str = ''
    for itm in fs:
        if itm.type == 'file':
            tmp_str += (itm.id * itm.size)
        else:
            tmp_str += '.' * itm.size
    return tmp_str


def print_file_system(fs):
    tmp_str = fs_string_repr(fs)
    print(tmp_str)


def compress(fs):
    for idx in range(len(fs)-1,1,-1) :
        if fs[idx].type == 'file':
            # print(f'working on idx: {idx}')
            for i,itm in enumerate(fs):
                if idx <= i:
                    break
                if itm.type == 'empty' and itm.size >= fs[idx].size:
                    # print(f'this should move {fs[idx].id}:({fs[idx].size}) -> {itm.size}')
                    itm.size = itm.size - fs[idx].size
                    fs.insert(i, fs[idx].copy())
                    fs[idx+1].type = 'empty'
                    # print_file_system(fs)
                    break

def unpack(input):
    fs = []
    file = True
    id = 0
    for itm in input:
        if file:
            fs.append(sector('file', int(itm), str(id)))
            id += 1
            file = False
        else:
            fs.append(sector('empty', int(itm), '0'))
            file = True
    return fs


if __name__ == '__main__':
    f = open('input.txt', 'r')

    for line in f:
        input = line.rstrip()

    fs = unpack(input)

    compress(fs)
    print_file_system(fs)

    print(checksum_string(fs))
    print(checksum(fs))
