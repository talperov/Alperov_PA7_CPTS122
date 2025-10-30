#include "Menu.h"


Menu::Menu(List<Data>& list) : masterList(list)
{
	//cout << "Constructor for Menu Class" << endl; //Remember to delete this
}

Menu::~Menu()
{
	cout << "Destructor Activated" << endl;
}

void Menu::DisplayScreen()
{
	cout << "Attendance Tracker Sheet" << endl;
	cout << "1. Import List of the Courses" << endl;
	cout << "2.Load the Master List" << endl;
	cout << "3.Store the Master List" << endl;
	cout << "4. Mark the Absences" << endl;
	cout << "5. Generate Report" << endl;
	cout << "6. Exit" << endl;
	cout << "Select A Choice From Above: " << endl;
		
}

void Menu::App()
{
	int choice = 0;
	while (choice != 6)
	{
		DisplayScreen();
		cin >> choice;

		switch (choice)
		{
		case 1:
			ImportCourseList();

			break;
		case 2:
			LoadCourseList();

			break;
		case 3:
			StoreCourseList();

			break;
		case 4:
			MarkAbsences();

			//UNCOMMENT LATER WHEN CASE COMPLETE
			/*time_t t = time(0); // get time now
			struct tm* now = localtime(&t);
			cout << (now->tm_year + 1900) << '-'
				<< (now->tm_mon + 1) << '-'
				<< now->tm_mday
				<< endl;
				*/

			break;
		case 5:
			GenerateReport();

			break;
		case 6:
			cout << "Exiting. . ." << endl;

			break;

		default:
			cout << "Select Again" << endl;
		}
	}
}

void Menu::ImportCourseList()
{
	string line;
	ifstream  infile("classList.csv");
	if (infile.is_open() != true)
	{
		cout << "Error Opening InFile" << endl;
		return;
	}
	while (getline(infile, line))
	{
		int number = 0, id = 0;
		string name, email, units, program, units, token;
		stringstream input(line);

		//getline(input, token, ",");
	}
}

void Menu::LoadCourseList()
{

}

void Menu::StoreCourseList()
{

}

void Menu::MarkAbsences()
{

}

void Menu::GenerateReport()
{
		
}
