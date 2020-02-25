/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

// See "Animal.cpp" for notes regarding header file inclusion
#include "SeaLion.h"

SeaLion::SeaLion() {
	Mammal();					// First call parent constructor to set nurse = 0
	this->subType = "Sea Lion";	// Set Subtype = Sea Lion; this should not be changed
								// and therefore has no associated setter
}

SeaLion::SeaLion(int nurse) {
	Mammal();
	this->subType = "Sea Lion";
	this->setNurse(nurse);
}
