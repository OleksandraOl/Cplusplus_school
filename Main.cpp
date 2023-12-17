#include "ReadFromFile.h"
#include "DisplayMenu.h"


int main() {
	//read the file 
	readFromFile();
	//create an output file for backup
	createBackup();

	//display menu and get the user's input
	handleMenuInput();
	
	return 0;
}