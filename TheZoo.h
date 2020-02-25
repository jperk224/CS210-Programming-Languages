/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

// See notes in "Animal.h" concerning class header files and #define guards.

#ifndef THEZOO_SRC_THEZOO_H_
#define THEZOO_SRC_THEZOO_H_

// Function declarations for functions found in "TheZoo.cpp"
// Used to support modularity and break out "main.cpp"

void PrintField(std::string str, int fieldLength);
void PrintField(std::string str, int fieldLength, std::ofstream &outputFile);
void PrintTrackNumber(int trackNumber, int padLength);
void PrintTrackNumber(int trackNumber, int padLength, std::ofstream &outputFile);
std::string ConvertTrackNumberToString(int trackNumber, int padLength);
void GenerateData();
void AddAnimal(std::vector<Animal*>& zooAnimals);
void RemoveAnimal(std::vector<Animal*>& zooAnimals);
bool readFileInput(std::ifstream inputFile, std::string inputVariable);
bool readFileInput(std::ifstream inputFile, int inputVariable);
void updateAnimalFile(std::ifstream &inputFile, int trackNumber, char* fileName);
void LoadDataFromFile(std::string fileName, std::vector<Animal*>& zooAnimals);
void SaveDataToFile(std::vector<Animal*>& zooAnimals, char* fileName);
void DisplayAnimalData(std::vector<Animal*>& zooAnimals);
void DisplayMenu();
void ZooInterface(std::vector<Animal*> zooAnimals);

#endif /* THEZOO_SRC_THEZOO_H_ */
