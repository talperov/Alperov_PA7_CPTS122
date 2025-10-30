#pragma once

#include "Node.h"
#include "Data.h"
#include "List.h"
#include <fstream>
#include <sstream>

using std::ifstream;
using std::stringstream;


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
void ImportCourseList(); //Case 1
void LoadCourseList(); //Case 2
void StoreCourseList(); //Case 3
void MarkAbsences(); //Case 4
void GenerateReport(); //Case 5
};
