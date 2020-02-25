/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

// See "Animal.cpp" for notes regarding header file inclusion
#include "Oviparous.h"

// Constructor
Oviparous::Oviparous() {
	this->numberOfEggs = 0;		// Default to no eggs
	this->type = "Oviparous";	// This should not be changed and has no associated setter
}

// Getters
int Oviparous::getNumberOfEggs() const {
	return this->numberOfEggs;
}

// Setters
void Oviparous::setNumberOfEggs(int numberOfEggs) {
	this->numberOfEggs = numberOfEggs;
	return;
}
