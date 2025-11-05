#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Node.h"
#include "Data.h"
#include "List.h"
#include <fstream>
#include <sstream>

using std::ifstream;
using std::ofstream;
using std::stringstream;


class Menu
{
private:

	List<Data>& masterList;
	string GatherTime(); // Helper
	bool Checking(const string& str); // Helper


public:

	//Constructor Copy Constructor and Destructor
	//Menu(); //Not Needed
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