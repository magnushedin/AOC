def read_file(filename):
    data = []
    f = open(filename)
    data = f.read()
    f.close()
    return data

def coord_in_list(houses, x, y):
    for house in houses:
        if house[0] == x and house[1] == y:
            return True
    return False

def main():
    data = read_file("input")

    x = 0
    y = 0

    houses = [(x, y)]
    for d in data:
        print("Moving: {}".format(d))
        if d == '>':
            x += 1
        elif d == '<':
            x -= 1
        elif d == '^':
            y += 1
        elif d == 'v':
            y -= 1
            
        if (not coord_in_list(houses, x, y)):
            houses.append((x, y))
            print("Added ({}, {}) to list".format(x, y))

    
    print("Number of houses visited: {}".format(len(houses)))

if __name__ == "__main__":
    main()
