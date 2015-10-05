# -*- coding:utf-8 -*-

import argparse
import math


class Sphere(object):

    VOLUME_FACTOR = 4 * math.pi / 3

    def __init__(self, radius):
        self.radius = radius

    def volume(self):
        # return 4 * math.pi * math.pow(self.radius, 3) / 3
        return self.VOLUME_FACTOR * math.pow(self.radius, 3)

    def __str__(self):
        return '%s(%f)' % (self.__class__.__name__, self.radius)


PARSER = argparse.ArgumentParser(description='Sphere volume computation')
PARSER.add_argument('radius', type=float, help='Sphere radius')


def main():
    """ Compute sphere volume """
    opts = PARSER.parse_args()

    my_sphere = Sphere(opts.radius)
    volume = my_sphere.volume()
    print "%s volume is %f" % (my_sphere, volume)


if __name__ == '__main__':
    main()
