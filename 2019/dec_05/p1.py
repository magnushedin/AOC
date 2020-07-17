""" Problem 5a """
import ic
import sys

# For debugger to find the input file
file_name = "./2019/dec_05/input"

if len(sys.argv) > 1:
    file_name = sys.argv[1]

my_ic = ic.Ic(file_name)

my_ic.start_computer(0)
