import itertools


def read_file(filename):
    f = open(filename)
    data = []
    for line in f:
        data.append(line.rstrip("\r\n"))
    f.close()
    return data


def parse_data(raw_data):
    data = dict()
    for line in raw_data:
        tmp = line.split(" to ")
        city_1 = tmp[0]
        tmp = tmp[1].split(" = ")
        city_2 = tmp[0]
        distance = tmp[1]
        
        if not city_1 in data.keys():
            data[city_1] = dict()
        if not city_2 in data.keys():
            data[city_2] = dict()
        
        data[city_1][city_2] = int(distance)
        data[city_2][city_1] = int(distance)

    return data


def calculate_route_length(route, data):
    length = 0
    for i in range(len(route)-1):
        length += data[route[i]][route[i+1]]
    return length


def main(filename):
    raw_data = read_file(filename)
    data = parse_data(raw_data)
    
    # Debug print distances for each city
    '''
    for key in data.keys():
        print("city {}".format(key))
        for key_2 in data[key].keys():
            print("--- {}: {}".format(key_2, data[key][key_2]))
    '''

    # Generate all permutations of cities and calculate the length of
    # each route
    shortest_route_length = 9999999999
    longest_route_length = 0
    permutations = list(itertools.permutations(data.keys()))
    for route in permutations:
        route_length = calculate_route_length(route, data)
       # print("rout: {}: {}".format(route, route_length))
        if shortest_route_length > route_length:
            shortest_route_length = route_length
        if longest_route_length < route_length:
            longest_route_length = route_length

    print("Shortest route length is: {}".format(shortest_route_length))
    print("longest route length is: {}".format(longest_route_length))
    

if __name__ == "__main__":
    main("input")
