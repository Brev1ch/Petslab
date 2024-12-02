#ifndef FAMILYPETS_HPP
#define FAMILYPETS_HPP
#include <istream>
class FamilyPets
{
  FamilyPets family_[1000];
  int count_of_members_ = 0;
  int maxNPets_;
public:
  FamilyPets(){}
  friend std::istream& operator + (std::istream& in, FamilyPets fp);
  bool maxCheck();
  void input_max(int maxNPets);
  void voice();
  void names();
  int getNumberRepetitionsName(char inputname[]);
  char[] findTheEasiest();
  friend std::ostream& operator << (std::ostream& out, FamilyPets fp);
};
class Dog::FamilyPets
{
  char type_[10000];
  char nickname_[10000];
  char voice_[10000];
  int weight_;
};
class Cat::FamilyPets
{
  char type_[10000];
  char nickname_[10000];
  char voice_[10000];
  int weight_;
};
#endif