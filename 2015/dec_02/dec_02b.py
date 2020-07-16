class parcel:
    def __init__(self, l, w, h):
        self.l = l
        self.w = w
        self.h = h

    def measures(self):
        return "{}, {}, {}".format(self.l, self.w, self.h)

    def needed_paper(self):
        return 2*self.l*self.w + 2*self.w*self.h + 2*self.h*self.l + min(self.l*self.w, self.w*self.h, self.h*self.l)

    def needed_ribbon(self):
        tmp = [self.l, self.w, self.h]
        tmp.sort()
        needed_ribbon = tmp[0]*2 + tmp[1]*2 + tmp[0]*tmp[1]*tmp[2]
        return needed_ribbon

def read_file(filename):
    data = []
    f = open(filename)
    for line in f:
        tmp = line.split('x')
        data.append(parcel(int(tmp[0]), int(tmp[1]), int(tmp[2])))
    f.close()
    return data

def main():
    data = read_file("input")
    ribbon_needed = 0
    for d in data:
        print("This line: {} ({})".format(d.needed_ribbon(), d.measures()))
        ribbon_needed += d.needed_ribbon()

    print("Total amount of ribbon needed: {}".format(ribbon_needed))

if __name__ == "__main__":
    main()
