/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

/*
 * A file that uses the class must include the .h file.  Its contents are
 * sufficient to allow compilation, as long as the corresponding .cpp file
 * is compiled into the program too.
 * (Programming Languages, ZyBooks, 7.8: Separate files for classes)
 */
#include "Animal.h"

// Constructor
Animal::Animal() {
	this->name = "None";
	this->trackNum = 0;			// Per requirements TrackNum should be 6 digits, but
								// less than 6 is padded in the Java class that writes
								// to the file, so a single 0 is sufficient.
}

// Destructor
Animal::~Animal() {};

// Getters
std::string Animal::getName() const {
	return this->name;
}

int Animal::getTrackNum() const {
	return this->trackNum;
}

std::string Animal::getType() const {
	return this->type;
}

std::string Animal::getSubType() const {
	return this->subType;
}

int Animal::getNurse() const {
	return 0;
}

int Animal::getNumberOfEggs() const {
	return 0;
}

// Setters
void Animal::setName(std::string name) {	// Exception handling addressed in functions to
	this->name = name;						// capture user input that will feed into this setter
	return;
}

void Animal::setTrackNum(int trackNum) {	// Exception handling addressed in functions to
	this->trackNum = trackNum;				// capture user input that will feed into this setter
	return;
}

void Animal::setNumberOfEggs(int numberOfEggs) {
	return;									// No statements as it's a virtual function,
}											// sub class methods of this type should be executed only

void Animal::setNurse(int nurse) {
	return;
}
