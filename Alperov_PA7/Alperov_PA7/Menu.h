#pragma once

#include "Node.h"
#include "Data.h"
#include "List.h"

class Menu
{
private:

	List<Data>& masterList;

public:

//Constructor Copy Constructor and Destructor
// Menu(); //Not needed
Menu(List<Data>& list);
~Menu();


//getters
	//none needed

//setters
	//none needed

//members
void DisplayScreen();
void App();
};
