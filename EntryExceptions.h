/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

// See notes in "Animal.h" concerning class header files and #define guards.

#ifndef THEZOO_SRC_ENTRYEXCEPTIONS_H_
#define THEZOO_SRC_ENTRYEXCEPTIONS_H_

int inputTrackNumber();
std::string inputAnimalName();
std::string inputAnimalType();
std::string inputAnimalSubType(std::string animalType);
int inputEggs(std::string animalType);
int inputNurse(std::string animalType);
int displayStats(std::vector<Animal*> zooAnimals);
bool matchFound(std::vector<Animal*> zooAnimals, int trackNumber);

#endif /* THEZOO_SRC_ENTRYEXCEPTIONS_H_ */
