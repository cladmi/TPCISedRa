/**
 * This file is a part of TPCI_SEDRA project
 * Copyright (c) INRIA 2015
 *
 * Contributor (s) : Maurice Bremond
 * Contacts : maurice.bremond@inria.fr
 * 
 * This project is headed by SED Rhone-Alpes service at INRIA.
 *
 */
#include "Alphabet.hpp"

#include <iostream>

bool Alphabet::IsVowel(char c)
{
  switch(c)
  {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
  case 'y':
  case 'A':
  case 'E':
  case 'I':
  case 'O':
  case 'U':
  case 'Y':
    return true;
  default:
    return false;
  }
}

bool Alphabet::IsConsonant(char c)
{
  return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) &&
    !Alphabet::IsVowel(c);
}

unsigned int Alphabet::CountVowels(const std::string& s)
{
  unsigned int counter = 0;
  for(std::string::const_iterator it = s.begin(); it != s.end(); ++it)
  {
    if (Alphabet::IsVowel(*it))
    {
      ++counter;
    }
  }
  return counter;
}

unsigned int Alphabet::CountConsonants(const std::string& s)
{
  unsigned int counter = 0;
  for(std::string::const_iterator it = s.begin(); it != s.end(); ++it)
  {
    if (Alphabet::IsConsonant(*it))
    {
      ++counter;
    }
  }
  return counter;
}
