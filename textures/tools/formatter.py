#!/usr/bin/python3
from PIL import Image
import sys

file_in = sys.argv[1]
file_out = file_in.split('.')[0] + "_conv.png"

count_x = int(sys.argv[2])
count_y = int(sys.argv[3])

tilesize_x = int(sys.argv[4])
tilesize_y = int(sys.argv[5])
tilespace = int(sys.argv[6])

color = [int(c) for c in sys.argv[7].split(',')]
print (color)

def cmp_color(col1, col2):
    if col1[0] == col2[0] and col1[1] == col2[1] and col1[2] == col2[2]:
        return (True)
    return (False)

im_in = Image.open(file_in)
im_out = Image.new("RGBA", (count_x * tilesize_x, count_y * tilesize_y), color=0)

for tx in range(count_x):
    for  ty in range(count_y):
        left = tx * (tilesize_x + tilespace)
        top = ty * (tilesize_y + tilespace)
        tile = im_in.crop((left, top, left + tilesize_x, top + tilesize_y))
        left -= tilespace * tx
        top -= tilespace * ty
        im_out.paste(tile, (left, top, left + tilesize_x, top + tilesize_y))

pixels = im_out.load()

for y in range(im_out.size[1]):
    for x in range(im_out.size[0]):
        comp = cmp_color(pixels[x, y], color)
        if comp == True:
            pixels[x, y] = (0,0,0,0)

im_out.save(file_out)
