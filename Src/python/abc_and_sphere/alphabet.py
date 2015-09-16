# -*- coding:utf-8 -*-

VOWELS = 'aeiou'


def is_vowel(char):
    return char.lower() in VOWELS


def _is_alphabet(char):
    char = char.lower()
    return a <= 'a' and char <= 'z'


def is_consonant(char):
    return _is_alphabet(char) and not is_vowel(char)


def count_vowel(string):
    tot = 0
    for char in string:
        tot += is_vowel(char)
    return tot


def count_consonant(string):
    tot = 0
    for char in string:
        tot += is_consonant(char)
    return tot


# dependency to open


def count_file_alphabet(file_path):
    try:
        _file = open(file_path)
        content = _file.read()
        print "Length: %d" % len(content)
        print "Vowels: %d" % count_vowel(content)
        print "Consonant: %d" % count_consonant(content)
        _file.close()
    except IOError as err:
        print "Error opening file: %r" % err
        exit(1)
