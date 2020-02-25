/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

// See "Animal.cpp" for notes regarding header file inclusion
#include "Crocodile.h"

Crocodile::Crocodile() {
	Oviparous();					// First call parent constructor to set eggs = 0
	this->subType = "Crocodile";	// Set Subtype = Crocodile; this should not be changed
									// and therefore has no associated setter
}

Crocodile::Crocodile(int numberOfEggs) {
	Oviparous();
	this->subType = "Crocodile";
	this->setNumberOfEggs(numberOfEggs);
}
