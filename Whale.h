/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

// See notes in "Animal.h" concerning class header files and #define guards.

#ifndef THEZOO_SRC_WHALE_H_
#define THEZOO_SRC_WHALE_H_

#include "Mammal.h"

// Whale inherits Mammal and has no class specific data members or
// methods defined.  Uses the public interface.  For notes on the use of the
// public interface, see "Mammal.h" or "Oviparous.h".

class Whale : public Mammal {
	public:
		Whale();
		Whale(int nurse);		// overriding constructor with nurse parameter
};

#endif /* THEZOO_SRC_WHALE_H_ */
