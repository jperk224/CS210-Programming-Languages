/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

// See notes in "Animal.h" concerning class header files and #define guards.

#ifndef THEZOO_SRC_OVIPAROUS_H_
#define THEZOO_SRC_OVIPAROUS_H_

#include "Animal.h"

// Define the Oviparous class- the egg layers.  Inherits Animal base class
// using a public interface.  This makes all member components in Animal
// publicly available to Oviparous if the member component is itself defined
// as public in the Animal class.

class Oviparous : public Animal {
	public:
		// Constructor
		Oviparous();

		// Refer to "Animal.h" for discussion on getters and setters

		// Getters
		int getNumberOfEggs() const;			// Return number of eggs

		// Setters
		void setNumberOfEggs(int numberOfEggs);	// Set the number of eggs
	private:
		int numberOfEggs;
};

#endif /* THEZOO_SRC_OVIPAROUS_H_ */
