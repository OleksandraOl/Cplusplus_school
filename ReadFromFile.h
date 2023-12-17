#pragma once
#ifndef CORNERGROCER_READFROMFILE_H_
#define CORNERGROCER_READFROMFILE_H_ 

#include <vector>

#include "GroceryItemMap.h";

void readFromFile();						//initialize a function to read from a file
void createBackup();						//initialize a function to output to a new file as a backup

void displayQunatity(string groceryName);	//display the quantity of a chosen grocery item
void displayAllGroceries();					//display all the groceries
void displayAllGroceriesHist();				//display all the groceries in a form of a histogram


#endif
