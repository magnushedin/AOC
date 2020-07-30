""" dec_10 of AOC2019 """

import sys
import math
import operator
import fractions as fr

FILENAME = "./2019/dec_10/input_ex1"

if len(sys.argv) > 1:
    FILENAME = sys.argv[1]

# Init variables
astroids = []
max_astroids = 0

input_file = open(FILENAME)
lines = input_file.readlines()

def get_angel(coordinates):
    """ Both x and y can't be zero at the same time """
    x = coordinates[0]
    y = coordinates[1]

    if x == 0:
        if y < 0:
            return 0
        else:
            return math.pi

    if y == 0:
        if x < 0:
            return (3 * math.pi) / 2
        else:
            return math.pi / 2

    if x >= 0:
        if y >= 0:
            return ((math.pi / 2) + math.atan(abs(y)/abs(x)))
        else:
            return math.atan(abs(x)/abs(y))
    else:
        if y >= 0:
            return math.pi + math.atan(abs(x)/abs(y))
        else:
            return  (3/2) * math.pi + math.atan(abs(y)/abs(x))

"""
for x in range(-1, 2):
    for y in range(-1, 2):
        print("({},{}): {}".format(x, y, get_angel((y, x))))
"""

# Find astroids in map and store to list
for y, line in enumerate(lines):
    for x, dot in enumerate(line):
        # print("the line ({}, {}): {}".format(x, y, dot))
        if dot == "#":
            astroids.append((x, y))

"""
Go through all possible monitor stations and for each station, got through all astroids and calculate direction and
distance. Save uniqe 'direction - distance' combinations to a dict. When all astroids have been worked through,
count entries in the dict with 'direction - distance' combinations.
"""

base_station = (29,28)
#base_station = (11, 13)

for monitor_station in [base_station]:
    #print("\nMonitor station: {}".format(monitor_station))
    astroid_directions = []
    for target_astroid in astroids:
        # print("   Target astroid: {}".format(target_astroid), end='')
        if target_astroid != monitor_station:
            x_vector = (target_astroid[0] - monitor_station[0])
            y_vector = (target_astroid[1] - monitor_station[1])

            # Calculate distance
            tmp_distance = math.sqrt(math.pow(x_vector, 2) + math.pow(y_vector, 2))

            # Calculate direction
            try:
                y_sign = int(y_vector/abs(y_vector))
                x_sign = int(x_vector/abs(x_vector))
                tmp_fraction = fr.Fraction(abs(y_vector), abs(x_vector))
                tmp_direction = (x_sign * tmp_fraction.denominator, y_sign * tmp_fraction.numerator)
                # print(" - -", end='')
            except ZeroDivisionError:
                # print(" - z", end='')
                if abs(y_vector) > 0:
                    y_vector = int(y_vector/abs(y_vector))
                if abs(x_vector) > 0:
                    x_vector = int(x_vector/abs(x_vector))
                tmp_direction = (x_vector, y_vector)

            # Add astroid to list
            # Calculate the angle (direction) and save in the list.
            rad = get_angel(tmp_direction)
            astroid_directions.append((rad, target_astroid, tmp_direction, tmp_distance))
        else:
            pass
            # print(" - - - My self")

astroid_directions.sort()

laser_hit_by_angle = dict()

for astroid in astroid_directions:
    # add list in a dictionary, key should be angle. Get list with keys from dictionary and run through
    # that list. Pop items and remove entry in dict if no more items in list.
    print(astroid)
    if astroid[0] in laser_hit_by_angle:
        laser_hit_by_angle[astroid[0]].append(astroid)
        laser_hit_by_angle[astroid[0]] = sorted(laser_hit_by_angle[astroid[0]], key=operator.itemgetter(3))
    else:
        laser_hit_by_angle[astroid[0]] = [astroid]

print("\nlaser_hit_by_angle")
for idx, key in enumerate(laser_hit_by_angle.keys()):
    print("{} ({:.2f}): {}".format(idx+1, 360 * (laser_hit_by_angle[key][0][0] / (2 * math.pi)), laser_hit_by_angle[key].pop(0)))
