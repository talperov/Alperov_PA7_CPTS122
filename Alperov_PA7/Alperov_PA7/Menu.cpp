#include "Menu.h"


Menu::Menu(List<Data>& list) : masterList(list)
{
	cout << "Constructor for Menu Class" << endl;
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
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:

			time_t t = time(0); // get time now
			struct tm* now = localtime(&t);
			cout << (now->tm_year + 1900) << '-'
				<< (now->tm_mon + 1) << '-'
				<< now->tm_mday
				<< endl;

			break;
		case 5:
			break;
		case 6:
			break;

		default:
			cout << "Select Again" << endl;
		}
	}
}
