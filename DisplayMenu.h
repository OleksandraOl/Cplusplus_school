#pragma once
#ifndef CORNERGROCER_DISPLAYMENU_H_
#define CORNERGROCER_DISPLAYMENU_H_ 

#include "ReadFromFile.h"

void displayMenu();							//initiliaze a function to display menu
void handleMenuInput();						//initiliaze a function to handle input
void clearInput();							//clear the rest of the input in case of a corrupted input
void fillInChar(char symbol, int num);		//initialize a function to fiil in the space with characters
string capitalizeWord(string& inputString); //initialize a function t ocapitalize the input word

#endif
