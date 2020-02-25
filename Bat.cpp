/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

// See "Animal.cpp" for notes regarding header file inclusion
#include "Bat.h"

Bat::Bat() {
	Mammal();				// First call parent constructor to set nurse = 0
	this->subType = "Bat";	// Set Subtype = Bat; this should not be changed
							// and therefore has no associated setter
}

Bat::Bat(int nurse) {
	Mammal();
	this->subType = "Bat";
	this->setNurse(nurse);
}
