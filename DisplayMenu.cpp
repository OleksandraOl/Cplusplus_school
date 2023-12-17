#include "DisplayMenu.h";

void displayMenu() {
	//display menu 
	cout << endl;
	fillInChar('=', 10);
	cout << "  Corner Grocer Application  ";
	fillInChar('=', 10);
	cout << endl;
	cout << endl;
	cout << "Menu:" << endl;
	cout << endl;
	cout << "<1> Check a frequency of the specific item" << endl;
	cout << "<2> Print the list of all items purchased" << endl;
	cout << "<3> Print the list of all items purchased (histogram)" << endl;
	cout << "<9> Exit the application" << endl;
	cout << endl;
	cout << "Please make your choice:" << endl;
	cout << endl;
}

//declare the function to handle input
void handleMenuInput() {
	int menuOption;					//menu option input
	bool loopCondition = true;		//the while loop condition to iterate
	string userGroceryInput;		//grocery item name input

	//the while loop to iterate unless a user press 9
	while (loopCondition) {

		displayMenu();

		//take the menu option choice from the user
		cin >> menuOption;
		cout << endl;

		//validate if the input is the number
		while (cin.fail()) {
			cout << "Error. Please enter a number." << endl;

			//clear the rest of the input
			clearInput();

			//get the input till it's the valid type
			cin >> menuOption;
			cout << endl;
		}

		//switch-case to proceed with the menu choice accordingly
		switch (menuOption) {

		//prompt a user for an input
		case 1:
			cout << "Please enter the grocery name: " << endl;
			cin >> userGroceryInput;

			//validate the user input
			while (cin.fail()) {
				cout << "Error. Please enter a grocery name." << endl;

				//clear the rest of the input
				clearInput();

				//get the input till it's the valid type
				cin >> userGroceryInput; 
			}

			//capitalize the input
			userGroceryInput = capitalizeWord(userGroceryInput);

			//get and display the quantity of the item
			displayQunatity(userGroceryInput);
			break;
		//display all the available groceries
		case 2:
			displayAllGroceries();
			break;
		//display all the available groceries in a form of histogram
		case 3:
			displayAllGroceriesHist();
			break;
		//exit the loop if user chose 9
		case 9:
			cout << "Thank you for using the application. See you later!" << endl;
			loopCondition = false;
			break;
		//handle othe possible inputs
		default:
			cout << "Error. Please choose out of the available options!" << endl;
			cout << endl;
			break;
		}

	}
}

//declare the function to clear the input
void clearInput() {
	cin.clear();
	cin.ignore(256, '\n');
}

//declare the function to fill in the space with characters
void fillInChar(char symbol, int num) {
	char chosenSymbol;
	int numRepetition;
	unsigned int i;

	chosenSymbol = symbol;
	numRepetition = num;

	for (i = 0; i < numRepetition; ++i) {
		cout << chosenSymbol;
	}
}

//function to capitalize the word
string capitalizeWord(string& inputString) {
	string transformedString;

	transformedString = inputString;

	//loop through a word and change every letter to a lowercase
	for (auto& x : transformedString) {
		x = tolower(x);
	}

	//change the first letter of the word to a capital letter
	transformedString[0] = transformedString[0] + ('A' - 'a');

	return transformedString;
}