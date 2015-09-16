#! /usr/bin/env python
# -*- coding:utf-8 -*-

import os
from setuptools import setup, find_packages

PACKAGE = 'abc_and_sphere'
# GPL compatible http://www.gnu.org/licenses/license-list.html#CeCILL
LICENSE = 'CeCILL v2.1'

SCRIPTS = ['sphere']


# Read version without importing for coverage issues
def get_version(package):
    """ Extract package version without importing file

    Importing module alter coverage results and may import some non-installed
    dependencies. So read the file directly

    Inspired from pep8 setup.py
    """
    with open(os.path.join(package, '__init__.py')) as init_fd:
        for line in init_fd:
            if line.startswith('__version__'):
                return eval(line.split('=')[-1])  # pylint:disable=eval-used


setup(
    name=PACKAGE,
    description='Alphabet and Sphere package',
    author='Inria SED - Rhones-Alpes',
    # author_email='',
    # url='',
    license=LICENSE,
    # download_url='',
    packages=find_packages(),
    scripts=SCRIPTS,
    classifiers=['Development Status :: 2 - Pre-Alpha',
                 'Programming Language :: Python :: 2'],
    install_required=['argparse'],
)
