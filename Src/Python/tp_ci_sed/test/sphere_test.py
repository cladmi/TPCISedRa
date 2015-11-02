# -*- coding:utf-8 -*-
#
# This file is a part of TPCI_SEDRA project
# Copyright (c) INRIA 2015
#
# Contributor (s) : Gaetan Harter
# Contacts : gaetan.harter@inria.fr
# 
# This project is headed by SED Rhone-Alpes service at INRIA.
#

import unittest
from tp_ci_sed import sphere

class TestSphere(unittest.TestCase):

    def test_volume(self):
        my_sphere = sphere.Sphere(1.5)
        vol = my_sphere.volume()

        # self.assertEqual(14.137166941154069, vol)
        self.assertAlmostEqual(14.137166941154069, vol)


if __name__ == '__main__':
    unittest.main()
