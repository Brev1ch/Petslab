#include <iostream>
#include "familypets.hpp"

int main()
{
  FamilyPets familypets;
  int maxNPets = 0;
  std::cin >> maxNPets;
  familypets.input_max(maxNPets);
  if (maxNPets < 0 || maxNPets > 7)
  {
    std::cerr << "ERROR: Incorrect number of pets specified\n";
    return 1;
  }
  std::cin >> familypets;
  if (familypets.maxCheck())
  {
    std::cerr  << "ERROR: The number of pets exceeds the maximum\n";
    return 1;
  }
  familypets.names();
  familypets.voice();
  char inputname[10000] = {};
  std::cin >> inputname;
  std::cout << familypets.getNumberRepetitionsName(inputname) << "\n";
  std::cout << familypets.findTheEasiest() << "\n";
  std::cout << familypets;
  return 0;
}
