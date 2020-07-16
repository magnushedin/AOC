"""
Problem 1a using Int Code Computer implemented is a class
"""

import ic
import sys

# For debugger to find the input file
file_name = "./2019/dec_02/input"

if len(sys.argv) > 1:
    file_name = sys.argv[1]

# Create the Int Code Computer
my_ic = ic.Ic(file_name)

my_ic.write_value(1, 12)
my_ic.write_value(2, 2)

my_ic.start_computer(0)

print("Value at position 0: {}".format(my_ic.get_value(0)))
