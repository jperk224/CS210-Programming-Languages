/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

#include <iostream>				// Library needed for cin and cout objects
#include <jni.h>
#include <vector>				// Library needed for vector use

// Include class headers to ensure class declarations are seen and can
// be compiled.  Only the sub-type class headers need to be included, as those
// header files include the header files for their parent classes.
// Including them here would be redundant.
#include "Crocodile.h"
#include "Goose.h"
#include "Pelican.h"
#include "Bat.h"
#include "Whale.h"
#include "SeaLion.h"

// Include TheZoo function declarations
#include "TheZoo.h"

using namespace std;

int main()
{
	// Declare a vector to hold animals created, those read from file, those
	// added, removed, etc.  When declaring the vector, the type is a pointer
	// to an Animal class object.  Declaring a vector of pointers to the base class
	// allows the vector to leverage runtime polymorphism and hold pointers to
	// any class type that is either of the base class or a class derived from the
	// base.  This approach leverages derived/base class pointer conversion where a
	// pointer to a base class can be converted to a pointer to a derived class
	// at runtime based on the object type to which the pointer refers.
	// (Zybooks - Programming Languages: 8.4 Polymorphism and Virtual Member Functions)
	vector<Animal*> zooAnimals;
	ZooInterface(zooAnimals);
	cout << endl << "Goodbye.  Thanks for visiting Wildlife Zoo!" << endl;
	return 0;
}
