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

my_picture = list()

"""
Go through pixels for all pages simultaniously (pixel by pixel) and append
the first color found to my new page
"""
for pixels in range(PAGE):
    start = pixels
    step = PAGE
    pixel_to_add = 2
    debug_map = data[start::step]
    for pixel in data[start::step]:
        if pixel < 2:
            pixel_to_add = pixel
            break
    my_picture.append(pixel_to_add)

# Print the picture
for num,pixel in enumerate(my_picture):
    if num%25 == 0:
        print('')
    if pixel == 1:
        print("#", end='')
    else:
        print(' ', end='')

print('')
