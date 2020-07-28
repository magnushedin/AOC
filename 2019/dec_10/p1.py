""" dec_10 of AOC2019 """

import sys
import math
import fractions as fr

FILENAME = "./2019/dec_10/input_ex1"

if len(sys.argv) > 1:
    FILENAME = sys.argv[1]

# Init variables
astroids = []
max_astroids = 0

input_file = open(FILENAME)
lines = input_file.readlines()

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
for monitor_station in astroids:
    #print("\nMonitor station: {}".format(monitor_station))
    astroid_directions = dict()
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
                tmp_direction = (y_sign * tmp_fraction.numerator, x_sign * tmp_fraction.denominator)
                # print(" - -", end='')
            except ZeroDivisionError:
                # print(" - z", end='')
                if abs(y_vector) > 0:
                    y_vector = int(y_vector/abs(y_vector))
                if abs(x_vector) > 0:
                    x_vector = int(x_vector/abs(x_vector))
                tmp_direction = (y_vector, x_vector)

            if tmp_direction in astroid_directions:
                if astroid_directions[tmp_direction] > tmp_distance:
                    astroid_directions[tmp_direction] = tmp_distance
                    # print(" - Updating: {}".format(tmp_direction))
                else:
                    pass
                    # print(" - Further away {}".format(tmp_direction))
            else:
                astroid_directions[tmp_direction] = tmp_distance
                # print(" - Adding: {}".format(tmp_direction))
        else:
            pass
            # print(" - - - My self")
    if max_astroids < len(astroid_directions):
        max_astroids = len(astroid_directions)
        print("Stations: {}, Number of astroids: {}".format(monitor_station, len(astroid_directions)))
