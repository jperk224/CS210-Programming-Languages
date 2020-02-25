/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

// See "Animal.cpp" for notes regarding header file inclusion
#include "Goose.h"

Goose::Goose() {
	Oviparous();				// First call parent constructor to set eggs = 0
	this->subType = "Goose";	// Set Subtype = Goose; this should not be changed
								// and therefore has no associated setter
}

Goose::Goose(int numberOfEggs) {
	Oviparous();
	this->subType = "Goose";
	this->setNumberOfEggs(numberOfEggs);
}
