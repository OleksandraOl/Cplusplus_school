#include "ReadFromFile.h";

//create an object from available class to store the read information
GroceryItemMap groceryCounted;

void readFromFile() {
	ifstream inputGroceryList;				//read from the file
	string groceryName;
	int groceryQuantity;
	string currItemName;
	vector<string> groceryVector;			//vector ro store all the values read from the file

	//open the file for reading
	inputGroceryList.open("CS210_Project_Three_Input_File.txt");

	//check if the file is open
	if (!inputGroceryList.is_open()) {
		cout << "Couldn't open the file CS210_Project_Three_Input_File.txt" << endl;
	}

	//loop to read the file till the end end check if the input is not corrupted
	while (!inputGroceryList.eof() && inputGroceryList.good()) {
		inputGroceryList >> groceryName;
		groceryVector.push_back(groceryName);
	}

	//iterate through list to create a map of groceries and their corresponding quantities
	for (auto& x : groceryVector) {
		string currentItem;

		groceryQuantity = 0;
		currentItem = groceryVector[0];
		
		//check if the new item is not yet in the map
		if (groceryCounted.checkUniqueness(currentItem)) {
			//if the item is unique, count its quantity
			groceryQuantity = count(groceryVector.begin(), groceryVector.end(), currentItem);
			//add the new item with its quantity to the map
			groceryCounted.addValueAndQuantity(currentItem, groceryQuantity);
		}

		//erase the element that was already iterated through
		groceryVector.erase(groceryVector.begin());

	}

	//close the file for reading
	inputGroceryList.close();
}

//function to create a backup and write to the output file
void createBackup() {
	ofstream outputGroceryList;		//write to the file

	outputGroceryList.open("frequency.dat");

	//check if the file is open
	if (!outputGroceryList.is_open()) {
		cout << "Couldn't open the file frequency.dat" << endl;
	}

	//for loop to write the grocery item and the quantity into the file
	groceryCounted.outputMapToFile(outputGroceryList);

	//close the file for writing
	outputGroceryList.close();
}

//use the class method to get the qunatity of the input item
void displayQunatity(string groceryName) {
	groceryCounted.getQuantity(groceryName);
}

//use the class method to get the list of all groceries
void displayAllGroceries() {
	groceryCounted.displayGroceryItemMap();
}

//use the class method to get the list of all groceries in a form of histogram
void displayAllGroceriesHist() {
	groceryCounted.displayGroceryItemMapHist();
}