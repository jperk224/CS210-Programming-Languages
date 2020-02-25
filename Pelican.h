/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

// See notes in "Animal.h" concerning class header files and #define guards.

#ifndef THEZOO_SRC_PELICAN_H_
#define THEZOO_SRC_PELICAN_H_

#include "Oviparous.h"

// Pelican inherits Oviparous and has no class specific data members or
// methods defined.  Uses the public interface.  For notes on the use of the
// public interface, see "Mammal.h" or "Oviparous.h".

class Pelican : public Oviparous {
	public:
		Pelican();
		Pelican(int numberOfEggs);	// overriding constructor with numberOfEggs parameter
};

#endif /* THEZOO_SRC_PELICAN_H_ */
