/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

// See notes in "Animal.h" concerning class header files and #define guards.

#ifndef THEZOO_SRC_MAMMAL_H_
#define THEZOO_SRC_MAMMAL_H_

#include "Animal.h"

// Define the Mammal class.  Inherits Animal base class
// using a public interface.  This makes all member components in Animal
// publicly available to Oviparous if the member component is itself defined
// as public in the Animal class.

class Mammal : public Animal {
	public:
		Mammal();
		// Nurse data member should be 1 (nursing) or 0 (not nursing).
		// In lieu of a boolean type for true/false, an int type is used
		// to avoid the need for explicit casting and exception handling
		// is employed to ensure only 1 or 0 are provided by the user.

		// Refer to "Animal.h" for discussion on getters and setters

		// Getters
		int getNurse() const;			// Return nurse flag (i.e. 1 or 0)

		// Setters
		void setNurse(int nurse);		// Set nurse value (i.e. 1 or 0)
	private:
		int nurse;
};

#endif /* THEZOO_SRC_MAMMAL_H_ */
