/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

// See "Animal.cpp" for notes regarding header file inclusion
#include "Pelican.h"

Pelican::Pelican() {
	Oviparous();				// First call parent constructor to set eggs = 0
	this->subType = "Pelican";	// Set Subtype = Pelican; this should not be changed
								// and therefore has no associated setter
}

Pelican::Pelican(int numberOfEggs) {
	Oviparous();
	this->subType = "Pelican";
	this->setNumberOfEggs(numberOfEggs);
}
