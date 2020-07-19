""" Problem 6a - 2019 """
import sys

def traverse(planetary_system, this_planet, from_planet, steps):
    """ Recursive function for traversing the planatary system """
    steps += 1

    destination_planets = [dp for dp in planetary_system[this_planet] if dp != from_planet]
    # print("From_planet: {}, This planet: {}, Destination planets: {} ({})".format(from_planet, this_planet, destination_planets, steps))

    for planets in destination_planets:
        if planets == "SAN":
            print("Found santa: {}".format(steps))
        traverse(planetary_system, planets, this_planet, steps)

def create_planetary_system(data_array):
    """ Create dict to represent the planetary system """
    planetary_system = dict()
    for data in data_array:
        [base, orbit] = data.split(')')
        if not base in planetary_system:
            planetary_system[base] = []
        if not orbit in planetary_system:
            planetary_system[orbit] = []

        planetary_system[base].append(orbit)
        planetary_system[orbit].append(base)
    return planetary_system

# Init
FILE_NAME = "./2019/dec_06/input_ex2"

if len(sys.argv) > 1:
    FILE_NAME = sys.argv[1]

print("file_name: {}".format(FILE_NAME))

# Read file and extract data
file = open(FILE_NAME)
file_content = file.read()
data_array = [line for line in file_content.split("\n") if line.strip() != ""]

planetary_system = create_planetary_system(data_array)
# print("Planatary system: {}".format(planetary_system))

traverse(planetary_system, planetary_system["YOU"][0], "YOU", -1)

