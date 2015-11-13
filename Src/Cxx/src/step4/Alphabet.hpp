#ifndef Alphabet_hpp
#define Alphabet_hpp

#include <string>

class Alphabet
{
public:
  static bool IsVowel(char c);

  static bool IsConsonant(char c);

  static unsigned int CountVowels(const std::string& s);

  static unsigned int CountConsonants(const std::string& s);

};

#endif
