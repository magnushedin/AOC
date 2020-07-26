""" dec_08 of AOC2019 """
import sys

FILENAME = "./2019/dec_08/input"

WIDTH = 25
HEIGHT = 6
PAGE = WIDTH * HEIGHT

if len(sys.argv) > 1:
    FILENAME = sys.argv[1]

input_file = open(FILENAME)
file_content = input_file.read().strip()
data = [int(value) for value in file_content]

num_of_pages = int(len(data) / PAGE)

min_zeroes = len(data)

for page in range(num_of_pages):
    start = page * PAGE
    stop = page * PAGE + PAGE
    num_zeroes = data[start:stop].count(0)
    if min_zeroes >= num_zeroes:
        min_zeroes = num_zeroes
        ones = data[start:stop].count(1)
        twos = data[start:stop].count(2)
        print("New min: {}, 1: {}, 2: {}, sum: {}".format(min_zeroes, ones, twos, ones*twos))
