/*
 * Jeff Perkinson
 * CS210-J3528
 * February 2020
 * Project Three
 */

#include <iostream>				// Library needed for cin and cout objects
#include <fstream>				// Library needed to read input/push output from/to file
#include <jni.h>
#include <stdexcept>            // Library needed for the runtime_error object to be
                                // thrown/caught in exception handling cases
#include <string>				// C++ string class library
#include <cctype>				// Library needed for char functions (e.g. tolower())
#include <jni.h>
#include <vector>				// Library needed for vector use
#include <typeinfo>				// Library needed to determine class type at runtime

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
#include "EntryExceptions.h"

using namespace std;


void PrintField(string str, int fieldLength) {
	// Print string plus whitespace in output to screen
	int stringLength = str.length();						// find length as input to padding loop
	cout << str;											// print the string
	for (int i = stringLength; i < fieldLength; ++i) {		// Padding loop
		cout << " ";
	}
	return;
}

void PrintField(string str, int fieldLength, ofstream &outputFile) {
	// Overloaded method to print string plus whitespace to file
	int stringLength = str.length();
	outputFile << str;
	for (int i = stringLength; i < fieldLength; ++i) {
		outputFile << " ";
	}
	return;
}

// Function to print track number for DisplayAnimalData
// Will pad with 0's should the track number be less than 6
void PrintTrackNumber(int trackNumber, int padLength) {
	string leadingZeros;	// string to hold leading zeros
	// convert the trackNumber to a string for padding
	char buffer [10];
	string trackNumberAsString;
	trackNumberAsString = itoa((trackNumber), buffer, 10);
	for (int i = trackNumberAsString.length(); i < padLength; ++i) {
		leadingZeros += "0";
	}
	leadingZeros += trackNumberAsString;
	cout << leadingZeros;
	return;
}

void PrintTrackNumber(int trackNumber, int padLength, ofstream &outputFile) {
	// Overloaded method to print track number plus whitespace to file
	string leadingZeros;	// string to hold leading zeros
	// convert the trackNumber to a string for padding
	char buffer [10];
	string trackNumberAsString;
	trackNumberAsString = itoa((trackNumber), buffer, 10);
	for (int i = trackNumberAsString.length(); i < padLength; ++i) {
		leadingZeros += "0";
	}
	leadingZeros += trackNumberAsString;
	outputFile << leadingZeros;		// Print track number with leading zeros to file
	return;
}

// Convert track number to string
string ConvertTrackNumberToString(int trackNumber, int padLength) {
	string leadingZeros;	// string to hold leading zeros
	// convert the trackNumber to a string for padding
	char buffer [10];
	string trackNumberAsString;
	trackNumberAsString = itoa((trackNumber), buffer, 10);
	for (int i = trackNumberAsString.length(); i < padLength; ++i) {
		leadingZeros += "0";
	}
	leadingZeros += trackNumberAsString;
	return leadingZeros;
}

// Separate function to read string file input to avoid duplicate code
bool readFileInput(ifstream &inputFile, string &inputVariable) {
	bool isSuccessful = true;		// flag to return indicating success
	inputFile >> inputVariable;
	if(inputFile.fail()) {			// failure to read file input and populate variable
		// The below is somewhat misleading; intended to note an error when
		// some parts cannot be read, it is triggered in newline cases, where
		// a blank line is created.
		cout << "Error reading certain input from file." << endl;
		isSuccessful = false;
	}
	return isSuccessful;
}

/*
 * To remove a specific line from a file, use the ifstream class to read every line of the file.
 * While reading a line, check whether the line is to be deleted or not.
 * If it is not the line to be deleted, write it to a temporarily file using ofstream.
 * After completing reading and writing process, use the remove() function to delete
 * the source file and use the rename() function to rename the temporary file
 * to the source file.
 * (https://www.worldbestlearningcenter.com/tips/Cplusplus-remove-line-from-a-file.htm)
 */
void updateAnimalFile(ifstream &inputFile, int trackNumber, char* fileName) {
	ofstream tempFile;
	char tempFileName[100] = "tempfile.txt";		// temp file to write data to
	// convert trackNumber to padded string for comparison
	string trackNumberAsString = ConvertTrackNumberToString(trackNumber, 6);
	string tempTrackNumber;						// temp record to hold file field for match comparison
	int tempTrackNumberAsInt;
	string tempAnimalName;
	string tempAnimalType;
	string tempAnimalSubType;
	string tempEggCount;
	string tempNurse;
	// Open files (1) to read and (2) to write
	inputFile.open(fileName);
	tempFile.open(tempFileName, ios_base::app);
	// if the file can't be opened, cite as such and function ends, else
	// move forward in the process
	if(!inputFile.is_open()) {
		cout << "Could not open file " << fileName  << " to check for existing record." << endl;
	}
	else {
		// loop through the file, if a match by track number is found, delete the line,
		// else, write to temp file
		cout << "Checking existing file for current record to update." << endl;
		while(!inputFile.eof()) {	// continue looping so long as end of file is not reached
			if(!readFileInput(inputFile, tempTrackNumber)) {	// if failure, break out of the while loop
				break;
			}
			if(!readFileInput(inputFile, tempAnimalName)) {
				break;
			}
			if(!readFileInput(inputFile, tempAnimalType)) {
				break;
			}
			if(!readFileInput(inputFile, tempAnimalSubType)) {
				break;
			}
			if(!readFileInput(inputFile, tempEggCount)) {
				break;
			}
			if(!readFileInput(inputFile, tempNurse)) {
				break;
			}
			// convert the tempTrackNumber to int drop leading zeros for
			// accurate comparison to track number
			tempTrackNumberAsInt = stoi(tempTrackNumber);

			// if the track number matches tempRecord, delete the line, else write to temp file
			if(trackNumber == tempTrackNumberAsInt) {
				continue;	// Do nothing, don't write the match to the temp file becasue it will be replaced
			}
			else {		// write the line to the temp file
				// Write values to file
				PrintTrackNumber(tempTrackNumberAsInt, 6, tempFile);
				tempFile << " ";
				PrintField(tempAnimalName, 15, tempFile);
				tempFile << " ";
				PrintField(tempAnimalType, 15, tempFile);
				tempFile << " ";
				PrintField(tempAnimalSubType, 15, tempFile);
				tempFile << " ";
				tempFile << tempEggCount << " ";
				tempFile << tempNurse << " ";
				tempFile << endl;		// start on a new line in the open file
			}
		}
		// close the files
		inputFile.close();
		tempFile.close();

		// remove the file
		remove(fileName);

		// write the temp file to input file
		rename(tempFileName, fileName);

	}
	return;
}

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

void AddAnimal(vector<Animal*>& zooAnimals) {
// Prompt user to enter data, validate the input, and add the animal object to the vector
// Exception handling and functions are defined in EntryExceptions.cpp
	int trackNumber = inputTrackNumber();
	string animalName = inputAnimalName();
	string animalType = inputAnimalType();
	string animalSubType = inputAnimalSubType(animalType);
	int numberOfEggs = inputEggs(animalType);
	int nurse = inputNurse(animalType);
	char userConfirm;		// To capture user's confirmation of addition
	bool validEntry;		// Flag to drive confirmation exception handling

	cout << "Track Number: " << trackNumber << endl;
	cout << "Animal Name: " << animalName << endl;
	cout << "Animal Type: " << animalType << endl;
	cout << "Animal Sub Type: " << animalSubType << endl;
	cout << "Number of Eggs: " << numberOfEggs << endl;
	cout << "Nurse: " << nurse << endl;
	cout << endl;

	//Prompt user to confirm addition.  If user confirms, create animal object
	// and add pointer to vector
	cout << "Confirm data addition (Y) or cancel (N)." << endl;
    	do {
    		validEntry = true;
    		try {
    			cin >> userConfirm;
    			cin.ignore();
    			userConfirm = tolower(userConfirm);		// convert to lowercase to render case insensitivity
    			if((userConfirm != 'y') && userConfirm != 'n') {
    				throw runtime_error("Invalid entry.  Please enter Y/N.");
    			}
    		}
    		catch(runtime_error& excpt) {
    			cout << excpt.what() << endl << endl;
    			validEntry = false;
    		}
    	} while(!validEntry);

    	if(userConfirm == 'y') {
    		cout << "Confirmed data addition." << endl;
    		// create the Animal pointer, set to null and allocate
    		// space and point to object based on sub type entry
    		Animal* animal = nullptr;
    		if (animalSubType == "bat") {
    			animal = new Bat(nurse);
    		}
    		else if(animalSubType == "crocodile") {
    			animal = new Crocodile(numberOfEggs);
    		}
    		else if (animalSubType == "goose") {
    			animal = new Goose(numberOfEggs);
    		}
    		else if (animalSubType == "pelican") {
    			animal = new Pelican(numberOfEggs);
    		}
    		else if(animalSubType == "sea lion") {
    			animal = new SeaLion(nurse);
    		}
    		else if(animalSubType == "whale"){
    			animal = new Whale(nurse);
    		}
    		else {
    			// default case that will not be hit due to sub type enforcement
    			// in inputAnimalSubType
    			cout << "Invalid sub type.  Unable to add animal.";
    		}
    		animal->setTrackNum(trackNumber);
    		animal->setName(animalName);
    		zooAnimals.push_back(animal);
    		cout << "Animal successfully added." << endl << endl;
    	}
    	else {
    		cout << "Add animal cancelled." << endl << endl;
    	}

    return;
}

void RemoveAnimal(vector<Animal*>& zooAnimals) {
// Function to remove animal data from vector by track number
    string trackNumberAsString;
    int trackNumber;
    bool validEntry;		// Flag for exception handling
    bool matchFound;		// Flag to drive removal logic based on whether a match is found
    char userConfirm;		// To capture user's confirmation of removal
    cout << "Delete animal by track number:" << endl;

    /*
     * Exception handling to validate user entry.
     * A do-while loop is used because the prompt
     * should be displayed at least once and assume the user
     * enters valid input. Don't initiate a loop until an exception is thrown.
     */

    do {
    	validEntry = true;		// Assume the user makes a valid entry
    	try {
        	cout << "Please enter track number (don't enter leading zeros): "  << endl;
        	cin >> trackNumberAsString;

        	// Throw an error if the track number is greater than 6
        	if(trackNumberAsString.length() > 6) {
        		throw runtime_error("Invalid Entry.");
        	}

        	trackNumber = stoi(trackNumberAsString);	// Parse the entry and convert to int
        	/*
        	 * In the above conversion from a string to an int, leading zeros
        	 * will fall off and match what is stored in the objects pointed
        	 * to by the pointers in the vector.  As such, there's no need
        	 * to use logic to manually add or remove leading zeros to find a match
        	 * when looping through the vector below.
        	 */

        	if(trackNumber < 0) {
        		throw runtime_error("Invalid Entry.");
        	}

    	}
    	// Catch an invalid entry that is a negative number or greater than 6 characters
    	catch (runtime_error& excpt) {
    		cout << excpt.what() << endl << endl;
    		validEntry = false;
    	}
    	// Catch an invalid entry that doesn't parse into an int (e.g. string)
    	catch (invalid_argument& excpt) {
    		cout << "Invalid entry type, please enter a number." << endl << endl;
    		validEntry = false;
    	}
    } while(!validEntry);

    cout << "Track Number Entered: " << trackNumber << endl;
    matchFound = false;		// assume initially no match is found before
    						// looping through the array to find a match
    for(unsigned int i = 0; i < zooAnimals.size(); ++i) {
    	// track numbers are unique, so if a match is found, break out of the loop
    	if(trackNumber == zooAnimals.at(i)->getTrackNum()) {
    		matchFound = true;
    		break;
    	}
    }

    if(matchFound) {
    	cout << "Match Found. Confirm removal (Y/N)." << endl;
    	do {
    		validEntry = true;
    		try {
    			cin >> userConfirm;
    			userConfirm = tolower(userConfirm);		// convert to lowercase to render case insensitivity
    			if((userConfirm != 'y') && userConfirm != 'n') {
    				throw runtime_error("Invalid entry.  Please enter Y/N.");
    			}
    		}
    		catch(runtime_error& excpt) {
    			cout << excpt.what() << endl << endl;
    			validEntry = false;
    		}
    	} while(!validEntry);

    	// If removal is confirmed, remove animal and show success
    	if(userConfirm == 'y') {
    		// Loop through the vector, if a match is found, delete both
    		// the object and the pointer to avoid a memory leak
    		for (unsigned int i = 0; i < zooAnimals.size(); ++i) {
    			if(trackNumber == zooAnimals.at(i)->getTrackNum()) {
    				cout << "Found " << trackNumber << ". Deleting data." << endl;
    				delete zooAnimals.at(i);
    				zooAnimals.erase(zooAnimals.begin() + i);
    				break;
    			}
    		}
    		cout << "Animal Successfully Deleted." << endl;
    	}
    	else {
    		cout << "Removal not confirmed, no data removed." << endl;

    	}
    }
    else {
    	cout << "No Match Found.  Unable to remove data." << endl;
    }
    return;
}

void LoadDataFromFile(string fileName, vector<Animal*>& zooAnimals) {
// Load data from input file (generated using JNI) into vector.
	ifstream inputFile;				// input file stream from which to read data
	string trackNumberAsString;		// track number input from file
	int trackNumber;				// to store track number
	string animalName;				// to store animal name
	string animalType;				// to store mammal/oviparous
	string animalSubType;			// to store animal subtype
	string numberOfEggsAsString;	// egg input from file
	string nurseAsString;			// nurse input from file
	int numberOfEggs;				// to store egg count
	int nurse;						// to store 1 or 0 to indicate if nursing
	bool isUnique;					// Flag to drive whether or not to add
									// animal to file based on unique track number

	cout << "Opening file " << fileName << endl;
	inputFile.open(fileName);
	// if the file can't be opened, cite as such and function ends, else
	// move forward in the process
	if(!inputFile.is_open()) {
		cout << "Could not open file " << fileName << endl;
	}
	else {
		// read file contents and assign them to local variables
		// the structure of the file is such that each instance
		// of an animal is on a single line, therefore it's best
		// to loop through until the end of the file is reach (i.e.
		// continue reading from file and creating animal instances
		// until the end of the file is reached)
		while(!inputFile.eof()) {	// continue looping so long as end of file is not reached
			// layout of file is track number, name, type, subtype, eggs, nurse
			// input file contents in that order
			// if reading the file input and storing it fails, cite the error
			// and break out of the loop, else input the value into the variable
			if(!readFileInput(inputFile, trackNumberAsString)) {	// if failure, break out of the while loop
				break;
			}

			if(!readFileInput(inputFile, animalName)) {
				break;
			}

			if(!readFileInput(inputFile, animalType)) {
				break;
			}

			if(!readFileInput(inputFile, animalSubType)) {
				break;
			}

			if(!readFileInput(inputFile, numberOfEggsAsString)) {
				break;
			}

			if(!readFileInput(inputFile, nurseAsString)) {
				break;
			}

			// convert string values to ints where applicable
			trackNumber = stoi(trackNumberAsString);
			numberOfEggs = stoi(numberOfEggsAsString);
			nurse = stoi(nurseAsString);

			// based on sub-type read in, create appropriate object to add to the vector
			// create pointer to point to object created
			Animal* animal = nullptr;
			// below default constructors are used and object setters set values
			// this makes the code a bit less cumbersome and easier to read
			if(animalSubType == "Bat") {
				animal = new Bat(nurse);
			}
			else if(animalSubType == "Crocodile") {
				animal = new Crocodile(numberOfEggs);
			}
			else if(animalSubType == "Goose") {
				animal = new Goose(numberOfEggs);
			}
			else if(animalSubType == "Pelican") {
				animal = new Pelican(numberOfEggs);
			}
			else if(animalSubType == "SeaLion") {
				animal = new SeaLion(nurse);
			}
			else if(animalSubType == "Whale") {
				animal = new Whale(nurse);
			}
			else {		// can't generate an animal object, break out of the loop
				cout << "Error generating animal object."  << endl;
				break;
			}
			animal->setTrackNum(trackNumber);	// set track number
			animal->setName(animalName);		// set name
			// animal type and subtype will default from the class constructor
			// and do not need to be set here
			// number of eggs and nurse will be determined by constructors called as well

			// add the object to the vector only if doesn't already exist
			isUnique = true;	// assume record is unique
			for(unsigned int i = 0; i < zooAnimals.size(); ++i) {
				// if a match is found, break out of the loop and site entry already exists
				if(trackNumber == zooAnimals.at(i)->getTrackNum()) {
					isUnique = false;
					break;
				}
			}
			if(isUnique) {
				zooAnimals.push_back(animal);
			}
			else {
				cout << "Track number already exists.  Unable to add animal." << endl;
			}
		}
	}
	return;
}

void SaveDataToFile(vector<Animal*>& zooAnimals, char* fileName) {
	// Code to store vector/array to file.
	bool validEntry;				// Flag to drive exception handling
	string userOptions = 	"1 - Change name\n"
							"2 - Change number of eggs\n"
							"3 - Change nurse indicator\n"
							"4 - Display current animal data\n"
							"5 - Write data to file\n"
							"6 - Select new animal\n"
							"7 - Display Options\n"
							"8 - Return to main\n";
	string userSelectionAsString;			// To capture user input
	int userSelection;						// Convert entry to int for decision branching
	int currentTrackNumber;					// To track the current rack number for the
											// animal the user is working with
	Animal* animalPtr = nullptr;			// Pointer to point to current animal instance
	string newAnimalName;					// To temporarily hold new animal name should user opt to chage it
	string animalType;						// To temporarily hold animal type for file writing
	string animalSubType;					// To temporarily hold animal sub type for file writing
	int tempTrackNumber;					// To temporarily hold new animal track number should user opt to change it
	int tempEggCount;						// To temporarily hold new egg count should user opt to change it
	int tempNurse;							// To temporarily hold new nurse indicator should user opt to change it
	ofstream outputFile;					// Output file stream to write modified data to
	ifstream inputFile;						// Input file stream to read data from
	bool saveSuccessful = false;			// flag to drive whether success message is printed.


	currentTrackNumber = displayStats(zooAnimals);
	// assign the animal pointer
	for (unsigned int i = 0; i < zooAnimals.size(); ++i) {
		if(currentTrackNumber == zooAnimals.at(i)->getTrackNum()) {
			animalPtr = zooAnimals.at(i);
			break;		// break out of loop because match is found
		}
	}
	cout << endl;
	cout << userOptions << endl;	// display initial options menu
	cout << "Please make a selection. " << endl;

	while(userSelection !=8) {		// loop until user opts to return to main
									// a while loop is used because the number of
									// iterations is unknown
		do {
			validEntry = true;			// assume user will make a valid choice
			try {
				cin >> userSelectionAsString;
				cin.ignore();
				userSelection = stoi(userSelectionAsString);
				if((userSelection < 1) || (userSelection > 8)) {
					throw runtime_error("Invalid entry.  Please select between 1-8.");
				}
			}
			// Catch invalid choice
			catch(runtime_error& excpt) {
				cout << excpt.what() << endl << endl;
				validEntry = false;
			}
			// Catch invalid input (e.g. string in lieu of int)
			catch (invalid_argument& excpt) {
				cout << "Invalid entry type, please enter a number." << endl << endl;
				validEntry = false;
			}
		} while(!validEntry);

		switch(userSelection) {		// branching based on userSelection, a switch
									// statement is used because its cleaner given
									// the number of options
		case 1:	// change name
			cout << "Current Name: " << animalPtr->getName() << endl;
			newAnimalName = inputAnimalName();
			animalPtr->setName(newAnimalName);
			cout << "New Name: " << animalPtr->getName() << endl;
			cout << endl;
			cout << "Please make another selection. (7 for menu options) " << endl;
			break;
		case 2:	// Change number of eggs
			// inputEggs() checks for mammal type and sets eggs to 0
			// if type is mammal, therefore an additional check is not
			// needed here.
			tempEggCount = inputEggs(animalPtr->getType());
			cout << "Current egg count: " << animalPtr->getNumberOfEggs() << endl;
			animalPtr->setNumberOfEggs(tempEggCount);
			cout << "New egg count: " << animalPtr->getNumberOfEggs() << endl;
			cout << "Please make another selection. (7 for menu options) " << endl;
			break;
		case 3:	// Change nurse indicator
			// inputNurse() checks for Oviparous type and sets nurse to 0
			// if type is Oviparous, therefore an additional check is not
			// needed here.
			tempNurse = inputNurse(animalPtr->getType());
			cout << "Current nurse indicator: " << animalPtr->getNurse() << endl;
			animalPtr->setNurse(tempNurse);
			cout << "New nurse indicator: " << animalPtr->getNurse() << endl;
			cout << "Please make another selection. (7 for menu options) " << endl;
			break;
		case 4:	// Display current animal data
			cout << "Track Number: " << currentTrackNumber << endl;
			cout << "Animal Name: " << animalPtr->getName() << endl;
			cout << "Animal Type: " << animalPtr->getType() << endl;
			cout << "Animal Sub Type: " << animalPtr->getSubType() << endl;
			cout << "Egg Count: " << animalPtr->getNumberOfEggs() << endl;
			cout << "Nurse: " << animalPtr->getNurse() << endl;
			cout << endl;
			cout << "Please make another selection. (7 for menu options) " << endl;
			break;
		case 5:	// Write new animal data to file
			// Check for an existing entry, if exists, delete it.
			updateAnimalFile(inputFile, currentTrackNumber, fileName);

			// Open the file to write new entry to it
			outputFile.open(fileName, ios_base::app);	// second argument tells to append file
														// (https://stackoverflow.com/questions/2393345/how-to-append-text-to-a-text-file-in-c)
			// If the file doesn't exist, this action creates a new one, which is not
			// ideal for the purposes of this project.  This is mitigated somewhat
			// by the call to the function in ZooInterface() requiring passing
			// the file name as a parameter.  However, ideal state would be to have some
			// sort of exception handling around this if possible.  That is beyond scope here.
			// These identifiers are not the best for this context, but I'm leveraging
			// existing declared variables from other branches intended to hold values
			// temporarily for the branch under which they are utilized.
			tempTrackNumber = animalPtr->getTrackNum();
			newAnimalName = animalPtr->getName();
			animalType = animalPtr->getType();
			animalSubType = animalPtr->getSubType();
			tempEggCount = animalPtr->getNumberOfEggs();
			tempNurse = animalPtr->getNurse();

			// Write values to file
			PrintTrackNumber(tempTrackNumber, 6, outputFile);
			outputFile << " ";
			PrintField(newAnimalName, 15, outputFile);
			outputFile << " ";
			PrintField(animalType, 15, outputFile);
			outputFile << " ";
			PrintField(animalSubType, 15, outputFile);
			outputFile << " ";
			outputFile << tempEggCount << " ";
			outputFile << tempNurse << " ";
			saveSuccessful = true;
			outputFile << endl;		// start on a new line in the open file

			if(saveSuccessful) {
				cout << "Save Successfully Completed." << endl;
			}
			else {
				cout << "Error updating file." << endl;
			}
			// Close the file
			outputFile.close();
			cout << "Please make another selection. (7 for menu options) " << endl;
			break;
		case 6:	// Select new animal
			currentTrackNumber = displayStats(zooAnimals);
			// assign the animal pointer
			for (unsigned int i = 0; i < zooAnimals.size(); ++i) {
				if(currentTrackNumber == zooAnimals.at(i)->getTrackNum()) {
					animalPtr = zooAnimals.at(i);
					break;		// break out of loop because match is found
				}
			}
			cout << endl;
			cout << "Please make another selection. (7 for menu options) " << endl;
			break;
		case 7:	// Display options menu
			cout << userOptions << endl;
			cout << "Please make another selection. " << endl;
			break;
		default:	// Option 9 - Return to main
			break;
		}
	}
	return;
}

void DisplayAnimalData(vector<Animal*>& zooAnimals) {
	// Display data on the user's screen in tabular format.
	string headerRow = 	"Track# "				// Track # capped at 6 char length.
						"Name           "		// Name, type, and sub-type capped
						"Type           "		// at 15 char length.
						"Sub-Type       "
						"Eggs "
						"Nurse ";
	// Output the header row
	cout << headerRow << endl;
	// Loop through the vector and output the vector contents via cout
	for (unsigned int i = 0; i < zooAnimals.size(); ++i) {
		Animal* animal = zooAnimals.at(i);
		// Display track number
		PrintTrackNumber(animal->getTrackNum(), 6);
		cout << " ";
		PrintField(animal->getName(), 15);				// Field length capped at 15 per spec
		// Display Type
		PrintField(animal->getType(), 15);
		// Display Sub-Type
		PrintField(animal->getSubType(), 15);
		// Display Eggs
		cout << animal->getNumberOfEggs();
		if (animal->getNumberOfEggs() > 9) {
			cout << "   ";
		}
		else if (animal->getNumberOfEggs() > 99) {
			cout << "  ";
		}
		else {
			cout << "    ";
		}
		// Display Nurse
		cout << animal->getNurse() << "   ";
		// New line
		cout << endl;
	}
	cout << endl;
	return;
}

void DisplayMenu() {
    // Display menu to user to select from
	string menuOptions =	"1 - Load animal data from file\n"
							"2 - Generate animal data\n"
							"3 - Display animal data\n"
							"4 - Add animal record\n"
							"5 - Remove animal record\n"
							"6 - Save animal data to file\n"
							"7 - Exit program";
	cout << menuOptions << endl;
	return;
}

void ZooInterface(vector<Animal*> zooAnimals) {
	// Capture user input and execute the given functionality based
	// upon choice selected.  Exit when user opts to quit.

	// Local function variables
	string userSelectionAsString;		// Capture user input, will be parsed and converted
										// to int to drive function branching (i.e. switch statement)
	int userSelection;
	bool validSelection;				// Flag to drive exception handling

	/*
	 * Exception handling to validate user entry.
	 * A do-while loop is used because the prompt
	 * should be displayed at least once and assume the user
	 * enters valid input. Don't initiate a loop until an exception is thrown.
	 */

	cout << "Welcome to Wildlife Zoo! Please make your selection!" << endl << endl;
	/*
	 * Loop until user opts to quit (e.g. userSelection == 7).  A while loop is
	 * used because the number of loop iterations is unknown and is driven by user input.
	 */
	while(userSelection != 7) {
		do {
			validSelection = true;			// assume initial entry will be valid
			try {
				DisplayMenu();					// display the options menu
				cin >> userSelectionAsString;	// capture input for parsing
				userSelection = stoi(userSelectionAsString);	// convert user input to int
				if((userSelection < 1) || (userSelection > 7)) {
					throw runtime_error("Invalid entry.  Please enter a number between 1 and 7.");
				}
			}
			// Catch an invalid numerical choice
			catch(invalid_argument& excpt) {
				cout << "Invalid entry type, please enter a number." << endl << endl;
				validSelection = false;
			}
			// Catch invalid input (e.g. string in lieu of int)
			catch(runtime_error& excpt) {
				cout << excpt.what() << endl << endl;
				validSelection = false;
			}
		} while(!validSelection);

		/*
		* The user option chosen dictates the path taken.  A switch statement
		* is used in lieu of if-else because there is a larger set of options.
		* The switch statement keeps the code a bit cleaner here.
		*/
		switch(userSelection) {
			case 1:		// Load animal data from file
				LoadDataFromFile("zoodata.txt", zooAnimals);
				break;	// if a case is executed, break out of the switch statement so other cases aren't executed
			case 2:		// Generate animal data
				// The Generate Data function does not appear to have any
				// error handling built into it.  None was added as we were instructed
				// to not manipulate the java class or the integration code.
				// Additionally, smaller changes made for testing and error fixes did
				// not appear to commit, so modifications to the Java class appears
				// to be beyond the scope of this assignment.
				GenerateData();
				break;
			case 3:		// Display animal data
				DisplayAnimalData(zooAnimals);
				break;
			case 4:		// Add animal record
				AddAnimal(zooAnimals);
				break;
			case 5:		// Remove animal record
				RemoveAnimal(zooAnimals);
				break;
			case 6:		// Save animal data to file
				SaveDataToFile(zooAnimals, "zoodata.txt");
				break;
			default:	// Catches user's option to quit
				// Do nothing an break out
				break;
		}
	}

	return;
}
