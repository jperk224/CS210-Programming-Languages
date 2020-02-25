/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

// See "Animal.cpp" for notes regarding header file inclusion
#include "Whale.h"

Whale::Whale() {
	Mammal();					// First call parent constructor to set nurse = 0
	this->subType = "Whale";	// Set Subtype = Whale; this should not be changed
								// and therefore has no associated setter
}

Whale::Whale(int nurse) {
	Mammal();
	this->subType = "Whale";
	this->setNurse(nurse);
}
