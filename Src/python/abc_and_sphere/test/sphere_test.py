# -*- coding:utf-8 -*-

import unittest
from abc_and_sphere import sphere

class TestSphere(unittest.TestCase):

    def test_volume(self):
        my_sphere = sphere.Sphere(1.5)
        vol = my_sphere.volume()

        # self.assertEqual(14.137166941154069, vol)
        self.assertAlmostEqual(14.137166941154069, vol)


if __name__ == '__main__':
    unittest.main()
