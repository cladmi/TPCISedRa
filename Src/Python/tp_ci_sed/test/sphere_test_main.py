# -*- coding:utf-8 -*-
""" Test for sphere main function """

# It can be in the same file as 'sphere_test' but it is easier for the exercise
# to have put it in a seperate file

# It's would be better to mock `print` either than checking stdout
# but it requires original code modification
#     http://stackoverflow.com/a/12999087/395687
#
# So for now, I will show methods using StringIO and also a Mock object

import unittest
from cStringIO import StringIO
import mock

from tp_ci_sed import sphere


class TestSphereMain(unittest.TestCase):

    def setUp(self):
        self.stderr = StringIO()
        # Replace stderr by a StringIO File in all tests
        mock.patch('sys.stderr', self.stderr).start()

    def tearDown(self):
        mock.patch.stopall()

    def test_simple_call(self):
        """ Test main function """

        # Mock stdout using Mock object instead of a StringIO as it also works
        with mock.patch('sys.stdout') as stdout_mock:
            # Replace 'sys.argv' with a custom value
            with mock.patch('sys.argv', ['sphere', '1.5']):
                sphere.main()

            # Assert stdout.write was called with expected text
            calls = stdout_mock.write.mock_calls
            self.assertEquals(
                calls, [mock.call('Sphere(1.500000) volume is 14.137167'),
                        mock.call('\n')])

            # Other method to check any call
            stdout_mock.write.assert_any_call(
                'Sphere(1.500000) volume is 14.137167')

        # Assert no error has been printed to stderr
        err_output = self.stderr.getvalue()
        self.assertEquals('', err_output)

    def test_no_arguments(self):
        """ Test that main fails if no arguments """
        # Replace 'sys.argv' with a custom value
        with mock.patch('sys.argv', ['sphere']):
            self.assertRaises(SystemExit, sphere.main)

        # We verify that the error has been printed to stderr
        err_output = self.stderr.getvalue()
        self.assertIn('too few arguments', err_output)
