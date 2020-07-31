""" dec_11 of AOC2019 """

import sys
import ic

FILENAME = "./2019/dec_11/input"
WIDTH = 50
HEIGHT = 50

class robot:
    """ Robot class """
    def __init__(self, intcomp, grid):
        self.int_comp = intcomp
        self.grid = grid

    def start_robot(self):
        while True:
            next_instruction = self.int_comp.start_computer()
            if next_instruction == ???:
                self.print_grid()
                break

    def get_grid(self):
        """ Returns the current grid """
        return self.grid

    def print_grid(self):
        """ Print grid to stdout """
        for y in range(HEIGHT):
            for x in range(WIDTH):
                print("{}".format(self.grid[x][y]), end='')
            print("")

if len(sys.argv) > 1:
    FILENAME = sys.argv[1]

the_grid = [['.' for x in range(WIDTH)] for y in range(HEIGHT)]

#print_grid(the_grid)

rob_ic = ic.Ic(FILENAME)

my_rob = robot(rob_ic, the_grid)
my_rob.print_grid()
