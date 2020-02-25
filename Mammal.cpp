/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

// See "Animal.cpp" for notes regarding header file inclusion
#include "Mammal.h"

// Constructor
Mammal::Mammal() {
	this->nurse = 0;			// Default to not nursing
	this->type = "Mammal";		// This should not be changed and has no associated setter
}

// Getters
int Mammal::getNurse() const {
	return this->nurse;
}

// Setters
void Mammal::setNurse(int nurse) {
	this->nurse = nurse;
	return;
}
