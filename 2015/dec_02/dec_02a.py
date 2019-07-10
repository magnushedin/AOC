class parcel:
    def __init__(self, l, w, h):
        self.l = l
        self.w = w
        self.h = h

    def measures(self):
        return "{}, {}, {}".format(self.l, self.w, self.h)

    def needed_paper(self):
        return 2*self.l*self.w + 2*self.w*self.h + 2*self.h*self.l + min(self.l*self.w, self.w*self.h, self.h*self.l)

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
    paper_needed = 0
    for d in data:
        print("This line: {} ({})".format(d.needed_paper(), d.measures()))
        paper_needed += d.needed_paper()

    print("Total amount of paper needed: {}".format(paper_needed))

if __name__ == "__main__":
    main()
