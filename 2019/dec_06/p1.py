""" Problem 6a - 2019 """
import sys
import orbit

def traverse(planetary_system, key):
    """ Recursive function for traversing the planatary system """
    orbits = 1
    if planetary_system[key] != "COM":
        orbits += traverse(planetary_system, planetary_system[key])

    return orbits

def create_planetary_system(data):
    """ Create dict to represent the planetary system """
    planetary_system = dict()
    for data in data_array:
        print(data)
        [base, orbit] = data.split(')')
        planetary_system[orbit] = base
    return planetary_system

# Init
FILE_NAME = "./2019/dec_06/input_ex"

if len(sys.argv) > 1:
    FILE_NAME = sys.argv[1]

print("file_name: {}".format(FILE_NAME))

# Read file and extract data
file = open(FILE_NAME)
file_content = file.read()
data_array = [line for line in file_content.split("\n") if line.strip() != ""]

planetary_system = create_planetary_system(data_array)
print("Planatary system: {}".format(planetary_system))

orbits = 0
for key in planetary_system:
    orbits += traverse(planetary_system, key)
    print("Key: {}, orbits: {}".format(key, orbits))

print("indirect orbits: {}".format(orbits))
