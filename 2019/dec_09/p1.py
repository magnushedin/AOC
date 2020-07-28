""" dec_09 of AOC2019 """

import sys
import ic

FILENAME = "./2019/dec_09/input"

if len(sys.argv) > 1:
    FILENAME = sys.argv[1]

my_ic = ic.Ic(FILENAME, verbose=True)
my_ic.add_input(2)
my_ic.start_computer()
