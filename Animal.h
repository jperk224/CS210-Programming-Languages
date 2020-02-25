/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

/*
 * The header file contains the class definition, including
 * data members (fields) and member function declarations (method signatures).
 * (Programming Languages, ZyBooks, 7.8: Separate files for classes)
 * all header files should have #define guards to prevent
 * multiple inclusion.  The format of the symbol name should be
 * <PROJECT>_<PATH>_<FILE>_H_.  To guarantee uniqueness, they should be
 * based on the full path in a project's source tree.
 */

#ifndef THEZOO_SRC_ANIMAL_H_
#define THEZOO_SRC_ANIMAL_H_

#include <string>

// Define the animal class, the base class of the zoo class hierarchy
class Animal {
	// Public members accessible outside of the class
	public:
		// Constructor
		/*
		 * Constructors initialize data members at class instantiation.  For the Animal
		 * class, not Animal objects will be instantiated, only objects of inherited sub type
		 * classes.  Only the default constructor is needed.
		 */
		Animal();
		// Destructor
		/*
		 * Destructors explicitly deallocate memory occupied by the associated object
		 * and their use is best practice to avoid memory leaks.
		 * The destructor here is virtual to satisfy the compiler, as no Animal object will
		 * be created.  This is needed as virtual member functions are defined in this class.
		 * (https://stackoverflow.com/questions/10024796/c-virtual-functions-but-no-virtual-destructors)
		 */
		virtual ~Animal() = 0;

		/*
		* Setters and Getters promote encapsulation by restricting direct access
		* to the class' data members from outside users of the class (e.g. main.cpp).
		* Getters return the value of the data member but do not modify member values,
		* while setters allow for manipulation of the data member's value.
		* Setters can use exception handling techniques
		* to validate the input and ensure the class is not put in a corrupt state.
		* For this program, the exception handling is defined in the functions used
		* to capture user input to set to the member fields.  In general, however,
		* employing exception handling in the setter function is an option.
		*/

		// Getters
		/*
		 * Getters are usually defined as const to make clear that the data members
		 * won't be changed.  This also promotes secure coding, as the compiler
		 * will throw an error if the function modifies a data member (Programming Languages,
		 * ZyBooks, 7.5: Mutators, accessors, private helpers).
		 */
		std::string getName() const;			// return name data member
		int getTrackNum() const;				// return trackNum data member
		std::string getType() const;			// return type
		std::string getSubType() const;			// return sub type

		/*
		 * A virtual function is a member function that can be overridden
		 * in a derived class by a function of the same name. At runtime,
		 * when a virtual function is called using a pointer or reference
		 * to an object, the call is dynamically determined based on the
		 * actual object type.  The virtual functions here are used
		 * to look to the sub classes for each animal type to return that
		 * instance's number of eggs or nursing flag
		 * (ZyBooks Programming Languages 8.4: Polymorphism and Virtual Member Functions)
		 */
		virtual int getNumberOfEggs() const;
		virtual int getNurse() const;

		// Setters
		void setName(std::string name);						// set the animal's name
		void setTrackNum(int trackNum);						// set the aniaml's tracknum
		virtual void setNumberOfEggs(int numberOfEggs);		// should trigger Oviparous' method when called
		virtual void setNurse(int nurse);					// should trigger Mammal's method when called
	private:
		std::string name;
		int trackNum;
	protected:							// These fields are protected so they can
										// be accessed at the subclass level.
		std::string type;				// type to be defined at subclass level
		std::string subType;			// sub-type to be defined at subclass level
};

#endif /* THEZOO_SRC_ANIMAL_H_ */
