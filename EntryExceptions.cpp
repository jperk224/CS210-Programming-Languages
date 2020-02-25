/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

#include <iostream>
#include <stdexcept>            // Library needed for the runtime_error object to be
                                // thrown/caught in exception handling cases
#include <string>				// C++ string class library
#include <algorithm>			// Library needed for for_each to convert sting to lowercase
#include <vector>

#include "Animal.h"

using namespace std;

// All functions in this file employ exception handling controlled by flags,
// validation, and do-while loops.  Comments only accompany the first function
// describing the methodology and approach.

int inputTrackNumber() {
	string userEntryAsString;			// to capture user input that will be converted to int
	int trackNumber;					// to store track number as int; will be returned from function
	bool validEntry;					// flag to drive exception handling

	/*
	 * Exception handling to validate user entry.
	 * A do-while loop is used because the prompt
	 * should be displayed at least once and assume the user
	 * enters valid input. Don't initiate a loop until an exception is thrown.
	 */

	do {
		validEntry = true;		// assume user will enter a valid entry
		try {
			cout << "Enter track number (don't enter leading zeros): " << endl;
			cin >> userEntryAsString;
			cin.ignore();
			if(userEntryAsString.length() > 6) {
				throw runtime_error("Invalid entry.  Track numbers cannot exceed six characters.");
			}
			trackNumber = stoi(userEntryAsString);	// convert user entry to int
			if (trackNumber < 0) {
				throw runtime_error("Invalid entry.  Must be greater than zero.");
			}
		}
		// Catch an invalid entry (e.g. negative or more than 6 characters)
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}
		// Catch an invalid argument (e.g. user enters a string)
		catch(invalid_argument& excpt) {
			cout << "Invalid entry type, please enter a number." << endl << endl;
			validEntry = false;
		}
	} while(!validEntry);

	return trackNumber;
}

string inputAnimalName() {
	string animalName;
	bool validEntry;
	do {
		validEntry = true;
		try {
			cout << "Enter animal name: " << endl;
			getline(cin, animalName);
			if(animalName.length() > 15) {
				throw runtime_error("Invalid Name.  Cannot exceed 15 characters.");
			}
		}
		// catch an invalid entry
		catch(runtime_error& excpt) {
		cout << excpt.what() << endl << endl;
		validEntry = false;
		}
	} while(!validEntry);

	return animalName;
}

string inputAnimalType() {
	string animalType;
	bool validEntry;
	do {
		validEntry = true;
		try {
			cout << "Enter animal type: " << endl;
			getline(cin, animalType);
			// convert string to lower case to remove case sensitivity
			// iterate over each character in the string and to tolower()
			// for conversion.
			// (https://thispointer.com/converting-a-string-to-upper-lower-case-in-c-using-stl-boost-library/)
			for_each(animalType.begin(), animalType.end(), [](char & c){
				c = ::tolower(c);
			});
			if((animalType != "mammal") && (animalType != "oviparous")) {
				throw runtime_error("Invalid type.  Animal type must be mammal or oviparous.");
			}
		}
		// catch an invalid entry
		catch(runtime_error& excpt) {
		cout << excpt.what() << endl << endl;
		validEntry = false;
		}
	} while(!validEntry);

	return animalType;
}

string inputAnimalSubType(string animalType) {
	string animalSubType;
	bool validEntry;
	do {
		validEntry = true;
		try {
			cout << "Enter animal sub type: " << endl;
			getline(cin, animalSubType);
			// convert string to lower case to remove case sensitivity
			// refer to inputAnimalType() above for further details.
			for_each(animalSubType.begin(), animalSubType.end(), [](char & c){
				c = ::tolower(c);
			});
			if((animalType == "mammal") && (animalSubType != "bat") && (animalSubType != "sea lion")
				&& (animalSubType != "whale")) {
				throw runtime_error("Invalid sub type.  Type is mammal.  Sub type must be one of "
									"Bat, Sea Lion, or Whale.");
			}
			if((animalType == "oviparous") && (animalSubType != "crocodile") && (animalSubType != "goose")
				&& (animalSubType != "pelican")) {
				throw runtime_error("Invalid sub type.  Type is oviparous.  Sub type must be one of "
									"Crocodile, Goose, or Pelican.");
			}
		}
		// catch an invalid entry
		catch(runtime_error& excpt) {
		cout << excpt.what() << endl << endl;
		validEntry = false;
		}
	} while(!validEntry);

	return animalSubType;
}

int inputEggs(string animalType) {
	string userEntryAsString;
	int numberOfEggs;
	bool validEntry;

	if((animalType == "mammal") || (animalType == "Mammal")) {
		cout << "Animal is mammal.  Egg count is not applicable." << endl;
		numberOfEggs = 0;
	}
	else {
		do {
			validEntry = true;
			try {
				cout << "Enter Number of Eggs: " << endl;
				cin >> userEntryAsString;
				cin.ignore();
				numberOfEggs = stoi(userEntryAsString);
				if (numberOfEggs < 0) {
					throw runtime_error("Invalid entry.");
				}
			}
			// Catch an invalid entry (e.g. negative)
			catch(runtime_error& excpt) {
				cout << excpt.what() << endl << endl;
				validEntry = false;
			}
			// Catch an invalid argument (e.g. user enters a string)
			catch(invalid_argument& excpt) {
				cout << "Invalid entry type, please enter a number." << endl << endl;
				validEntry = false;
			}
		} while(!validEntry);
	}
	return numberOfEggs;
}

int inputNurse(string animalType) {
	string userEntryAsString;
	int nurse;
	bool validEntry;

	if((animalType == "oviparous") || (animalType == "Oviparous")) {
		cout << "Animal is oviparous.  Nurse defaults to 0 as it is not applicable." << endl;
		nurse = 0;
	}
	else {
		do {
			validEntry = true;
			try {
				cout << "Enter Nursing (1 for nursing, 0 for not): " << endl;
				cin >> userEntryAsString;
				cin.ignore();
				nurse = stoi(userEntryAsString);
				if ((nurse != 1) && (nurse != 0)) {
					throw runtime_error("Invalid entry. Please enter 1 or 0.");
				}
			}
			// Catch an invalid entry (e.g. negative)
			catch(runtime_error& excpt) {
				cout << excpt.what() << endl << endl;
				validEntry = false;
			}
			// Catch an invalid argument (e.g. user enters a string)
			catch(invalid_argument& excpt) {
				cout << "Invalid entry type, please enter a number." << endl << endl;
				validEntry = false;
			}
		} while(!validEntry);
	}
	return nurse;
}

// Function to display animal stats
// Uses exception handling to continue
int displayStats(vector<Animal*> zooAnimals) {
	bool matchFound;
	int currentTrackNumber;					// initially set current track number
											// to parameter passed in.  Will only
											// be modified if exception handling
											// is triggered
	bool validEntry;						// Flag to drive exception handling
	Animal* animalPtr = nullptr;			// Pointer reference to assign source animal to
	do {
		validEntry = true;
		matchFound = false;
		try {
			currentTrackNumber = inputTrackNumber();
			for(unsigned int i = 0; i < zooAnimals.size(); ++i) {
				animalPtr = zooAnimals.at(i);
				if(currentTrackNumber == animalPtr->getTrackNum()) {
					matchFound = true;
					cout << "Current Track Number: " << currentTrackNumber << endl;
					cout << "Animal Name: " << animalPtr->getName() << endl;
					cout << "Animal Type: " << animalPtr->getType() << endl;
					cout << "Animal Sub Type: " << animalPtr->getSubType() << endl;
					cout << "Egg Count: " << animalPtr->getNumberOfEggs() << endl;
					cout << "Nurse: " << animalPtr->getNurse() << endl;
					break;	// break out of the loop because match is found
							// and it exists with animalPtr pointing to the matching object
				}
			}
			if(!matchFound) {
				throw runtime_error("No match found. Please enter another track number.");
			}
		}
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}
	} while(!validEntry);
	return currentTrackNumber;
}

bool matchFound(vector<Animal*> zooAnimals, int trackNumber) {
	bool matchFound = false;		// flag to indicate if match is found
	for(unsigned int i = 0; i < zooAnimals.size(); ++i) {
		if(trackNumber == zooAnimals.at(i)->getTrackNum()) {
			matchFound = true;
			break;					// break out once match is found
		}
	}
	return matchFound;
}
