#include "familypets.hpp"
#include <iostream>

bool checkinput(char input[])
{
  return input[0] == '<' && input[1] == 'E' && input[2] == 'N' && input[3] == 'D' && input[4] == '>';
}

std::istream& operator >> (std::istream& in, FamilyPets fp)
{
  in >> fp.family_[0].type_;
  if (!checkinput(fp.family_[fp.count_of_members_].type_))
  {
    in >> fp.family_[fp.count_of_members_].nickname_ >> fp.family_[fp.count_of_members_].voice_ >> fp.family_[fp.count_of_members_].weight_ >> fp.family_[fp.count_of_members_ + 1].type_;
    fp.count_of_members_++;
  }
  return in;
}

void FamilyPets::input_max(int maxNPets)
{
  maxNPets_ = maxNPets;
}

bool FamilyPets::maxCheck()
{
  return count_of_members_ > maxNPets_;
}

void FamilyPets::voice()
{
  if (count_of_members_ > 0)
  {
    std::cout << family_[0].voice_;
  }
  for (size_t i = 1; i < count_of_members_; i++)
  {
    std::cout << " " << family_[i].voice_;
  }
  std::cout << "\n";
}

void FamilyPets::names()
{
  if (count_of_members_ > 0)
  {
    std::cout << family_[0].nickname_;
  }
  for (size_t i = 1; i < count_of_members_; i++)
  {
    std::cout << " " << family_[i].nickname_;
  }
  std::cout << "\n";
}

int FamilyPets::getNumberRepetitionsName(char inputname[])
{
  int currentanswer = 0;
  for (size_t i = 0; i < count_of_members_; i++)
  {
    if (family_[i].nickname_ == inputname)
    {
      currentanswer++;
    }
  }
  return currentanswer;
}

char[] FamilyPets::findTheEasiest()
{
  if (count_of_members_ == 0)
  {
    return 0;
  }
  char currentanswer[10000] = family_[0].nickname_;
  int min_weight = family_[0].weight_;
  for (size_t i = 1; i < count_of_members_; i++)
  {
    if (min_weight > family_[i].weight_)
    {
      currentanswer = family_[i].nickname_;
      min_weight = family_[i].weight_;
    }
  }
  return currentanswer;
}

std::ostream& operator << (std::ostream& out, FamilyPets fp)
{
  for (size_t i = 0; i < count_of_members_; i++)
  {
    out << fp.family_[i].type_ << " " << family_[i].nickname_ << " " << family_[i].voice_ << " " << family_[i].weight_ << "\n";
  }
  return out;
}
