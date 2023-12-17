#include "GroceryItemMap.h";

//add new element to a map
void GroceryItemMap::addValueAndQuantity(string c_name, int& c_quantity) {
	c_myMap[c_name] = c_quantity;
}

//get quantity of the specific element
void GroceryItemMap::getQuantity(string c_name) {
	bool isMatch = false;		

	//iterate throug the map and compare the key with the input
	for (auto& pair : c_myMap) {

		if (pair.first == c_name) {
			//if the inout value matches the key value of the map, get the quantity and break out of the loop
			isMatch = true;

			addNewLine();
			displayQuantityInSymb('_', 50);
			addNewLine();
			addNewLine();
			cout << "The quantity of " << c_name << " is " << pair.second << endl;
			displayQuantityInSymb('_', 50);
			addNewLine();
			addNewLine();
			break;
		}
	}

	//output the error if there is no match
	if (!isMatch) {
		addNewLine();
		displayQuantityInSymb('_', 50);
		addNewLine();
		addNewLine();
		cout << "There is no such grocery item in the list." << endl;
		displayQuantityInSymb('_', 50);
		addNewLine();
		addNewLine();
	}
}

//function to display all the key and values that stored in the map
void GroceryItemMap::displayGroceryItemMap() {
	displayQuantityInSymb('_', 50);
	addNewLine();
	addNewLine();

	for (auto& pair : c_myMap) {
		cout << setw(20) << pair.first << "    " << pair.second << endl;
	}

	displayQuantityInSymb('_', 50);
	addNewLine();
	addNewLine();
};

//declare a function to fill in the empty space with characters
void GroceryItemMap::displayQuantityInSymb(char c_symbol, int c_num) {
	char symbol;
	int num;
	unsigned int i;

	symbol = c_symbol;
	num = c_num;

	for (i = 0; i < num; ++i) {
		cout << symbol;
	}
}

//display all the grocery list in a form of histogram
void GroceryItemMap::displayGroceryItemMapHist() {
	displayQuantityInSymb('_', 50);
	addNewLine();
	addNewLine();

	//using the above function - turn every value element from the map into characters
	for (auto& pair : c_myMap) {
		cout << setw(20) << pair.first << "    ";
		displayQuantityInSymb('*', pair.second);
		addNewLine();
	}
	displayQuantityInSymb('_', 50);
	addNewLine();
	addNewLine();
}

//check if the input item is not yet in the map
bool GroceryItemMap::checkUniqueness(string c_groceryName) {
	for (auto& pair : c_myMap) {
		//if there is a match, return false and break out of the loop
		if (c_groceryName == pair.first) {
			return false;
			break;
		}
	}
	//return true if there were no match
	return true;
}

//function to write a map to a file with the reference to the output file as a parametr
void GroceryItemMap::outputMapToFile(ofstream& c_file) {
	for (auto& pair : c_myMap) {
		c_file << pair.first << "  " << pair.second << endl;
	}
}

//adds new line 
void GroceryItemMap::addNewLine() {
	cout << endl;
}