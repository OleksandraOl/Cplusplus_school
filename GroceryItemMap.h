#pragma once
#ifndef CORNERGROCER_GROCERYITEMMAP_H_
#define CORNERGROCER_GROCERYITEMMAP_H_ 

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <fstream>
using namespace std;

class GroceryItemMap {
	//create public functions
	public:
		void addValueAndQuantity(string c_name, int& c_quantity);		//add new element to a map
		void getQuantity(string c_name);								//get quantity of a specific item
		void displayGroceryItemMap();									//display grocery items in a list
		void displayGroceryItemMapHist();								//display grocery items in a form of histogram
		void displayQuantityInSymb(char c_symbol, int c_num);			//function to fill in the empty pace with characters
		bool checkUniqueness(string c_groceryName);						//check if the item name is not yet in the map
		void outputMapToFile(ofstream& c_file);							//output the created map to a file
		void addNewLine();												//add a new line
	//initialize private map
	private:
		map<string, int> c_myMap;
};


#endif