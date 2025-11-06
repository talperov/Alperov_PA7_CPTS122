#include "Menu.h"





Menu::Menu(List<Data>& list) : masterList(list)
{
	//cout << "Constructor for Menu Class" << endl; //Remember to delete this
}

Menu::~Menu()
{
	//cout << "Destructor Activated" << endl; //Remember to delete this
}

void Menu::DisplayScreen()
{
	cout << "Attendance Tracker Sheet" << endl;
	cout << "1. Import List of the Courses" << endl;
	cout << "2.Load the Master List" << endl;
	cout << "3.Store the Master List" << endl;
	cout << "4. Mark the Absences" << endl;
	cout << "5. Edit Absences" << endl;
	cout << "6. Generate Report" << endl;
	cout << "7. Exit Program" << endl;
	cout << "Select A Choice From Above: " << endl;

}

void Menu::App()
{
	int choice = 0;
	while (choice != 7)
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

			break;
		case 5:
			EditAbsences();

			break;
		case 6:
			GenerateReport();

			break;
		case 7:
			cout << "Exiting. . ." << endl;

			break;


		default:
			cout << "Select Again" << endl;
		}
	}
}

void Menu::ImportCourseList() // CASE 1
{
	masterList.destroyList();

	ifstream infile;
	string line;
	stringstream input;
	string token, name, email, units, program, level;
	int number = 0, id = 0;
	int import = 0;

	infile.open("classList.csv");

	if (!infile.is_open())
	{
		cout << "Error Opening classList.csv\n\n";
		system("pause");
		return;
	}

	getline(infile, line); // skip header

	while (true)
	{
		if (!getline(infile, line))
		{
			break;
		}

		if (line == "")
		{
			continue;
		}

		input.clear();
		input.str(line);

		getline(input, token, ',');
		if (token.empty())
		{
			continue;
		}
		number = stoi(token);

		getline(input, token, ',');
		if (token.empty())
		{
			continue;

		}
		id = stoi(token);

		getline(input, name, ',');
		getline(input, email, ',');
		getline(input, units, ',');
		getline(input, program, ',');
		getline(input, level, ',');

		if (name.empty() || email.empty() || units.empty() || program.empty() || level.empty())
		{
			continue;
		}

		Data student(number, id, name, email, units, program, level);
		masterList.insertAtFront(student);

import++;
		cout << "Course List #" << import << " Imported\n";
	}

	infile.close();
	cout << endl;  cout << "Done Importing..." << endl << endl;
	system("pause");
}


void Menu::LoadCourseList() // CASE 2
{

	masterList.destroyList();

	ifstream infile("master.csv");
	string line;
	int count = 0;

	if (!infile.is_open())
	{
		cout << "Error Opening master.csv" << endl << endl;
		return;
	}

	getline(infile, line); // skip header

	while (getline(infile, line))
	{
		if (line.empty())
		{
			continue;
		}

		if (!isdigit(line[0]))
		{
			continue;
		}

		stringstream input(line);
		string number, id, name, email, units, program, level, absence;

		getline(input, number, ',');
		getline(input, id, ',');
		getline(input, name, ',');
		getline(input, email, ',');
		getline(input, units, ',');
		getline(input, program, ',');
		getline(input, level, ',');
		getline(input, absence);

		Data tempStudent;

		if (Checking(number))
		{
			tempStudent.setNumber(stoi(number));
		}
		else
		{
			tempStudent.setNumber(0);
		}

		if (Checking(id))
		{
			tempStudent.setID(stoi(id));
		}
		else
		{
			tempStudent.setID(0);
		}

		if (Checking(absence))
		{
			tempStudent.setAbsences_Num(stoi(absence));
		}
		else
		{
			tempStudent.setAbsences_Num(0);
		}

		tempStudent.setName(name);
		tempStudent.setEmail(email);
		tempStudent.setUnits(units);
		tempStudent.setProgram(program);
		tempStudent.setLevel(level);

		masterList.insertAtFront(tempStudent);
		count++;
	}

	infile.close();
	cout << endl << "Amount of Students Loaded is " << count << endl;
	cout << "Master List Loaded into master.csv" << endl << endl;
	system("pause");

}




void Menu::StoreCourseList() // CASE 3
{
	ofstream outfile("master.csv");
	Node<Data>* pCur;
	int time = 0;

	if (!outfile.is_open())
	{
		cout << "Error Opening master.csv\n\n";
		return;
	}

	pCur = masterList.getHead();

	while (pCur != nullptr)
	{
		Data student = pCur->getData();

		outfile << student.getNumber() << "," << student.getID() << "," << student.getName() << "," << student.getEmail() << "," << student.getUnits() << "," << student.getProgram() << "," << student.getLevel() << "," << student.getAbsences_Num() << endl;

		if (!student.getAbsencesDate().empty())
		{
			outfile << student.peekAbsences_Date() << endl;
		}

		time++;
		cout << "Master List stored #" << time << endl;

		pCur = pCur->getNext();
	}

	outfile.close();
	cout << endl; cout << "master.csv Successfully Stored" << endl << endl;
	system("pause");
}


void Menu::MarkAbsences() // CASE 4
{
	Node<Data>* pCur;
	bool found = false;
	int checkID = 0;
	char pick = '\0';
	string TodaysDate;

	cout << "Enter ID to mark absence: " << endl;
	cin >> checkID;

	pCur = masterList.getHead();

	while (pCur != nullptr)
	{
		Data& student = pCur->getData();

		if (student.getID() == checkID)
		{
			found = true;

			cout << "Was student named " << student.getName() << " absent today?" << endl;
			cout << "(Y) Yes or (N) No: " << endl;
			cin >> pick;

			if (pick == 'Y' || pick == 'y')
			{
				TodaysDate = GatherTime();
				student.pushAbsences_Date(TodaysDate);
				student.setAbsences_Num(student.getAbsences_Num() + 1);

				cout << "Absence Marked for " << student.getName() << " on " << TodaysDate << endl << endl;
			}
			else
			{
				cout << "No absence was marked." << endl << endl;
			}

			break;
		}

		pCur = pCur->getNext();
	}

	if (!found)
	{
		cout << "Student ID #" << checkID << " DNE." << endl << endl;
	}

	system("pause");
}

void Menu::EditAbsences() // CASE 5
{
	Node<Data>* pCur = masterList.getHead();
	int choice = 0;
	string input;

	cout << "What would you want to Edit. . ." << endl;
	cout << "1. Search with ID" << endl;
	cout << "2. Search with Name" << endl;
	cin >> choice;
	cin.ignore();

	cout << "Student List: " << endl;

	while (pCur)
	{
		Data& find = pCur->getData();
		cout << "ID: " << find.getID() << ", Name: " << find.getName() << endl;
		pCur = pCur->getNext();
	}

	if (choice == 1)
	{
		cout << "Enter the ID: ";
		cin >> input;
		cin.ignore();
	}
	else
	{
		cout << "Enter the Name exactly as shown in the Student List with Quotes: " << endl;
		getline(cin, input);
	}

	pCur = masterList.getHead();
	
	bool found = false;
	
	while (pCur)
	{
		Data& student = pCur->getData();

		string name = student.getName();

		if (!name.empty() && name[0] == '"')
		{
			name = name.substr(1); // takes away " when entering name
		}

		if ((choice == 1 && Checking(input) && student.getID() == stoi(input)) ||(choice == 2 && name == input))
		{
			found = true;

			if (student.getAbsences_Num() == 0)
			{
				cout << student.getName() << " has no Absences." << endl;
			}
			else
			{
				student.popAbsences_Date();
				student.setAbsences_Num(student.getAbsences_Num() - 1);

				cout << "Most recent absence removed for " << student.getName() << "." << endl;
			}
			break;

		}
		pCur = pCur->getNext();

	}
	if (!found)
	{
		cout << "N/A" << endl;
	}
	system("pause");
}



void Menu::GenerateReport() // CASE 6
{
	Node<Data>* pCur;
	Data student;
	int choice = 0;
	int count = 0;

	do
	{
		cout << "Menu for Generating Report" << endl;
		cout << "1. Report Most Recent Absence" << endl;
		cout << "2. Report Students with absences meeting/exceeding requested input" << endl;
		cout << "3. Exit out" << endl;
		cout << "Pick your choice: " << endl;
		cin >> choice;

		if (choice == 1)
		{
			pCur = masterList.getHead();

			cout << "Report in progress..." << endl;
			cout << "Number, ID, Name, Email, Units, Program, Level, Most Recent Absence" << endl << endl;

			while (pCur)
			{
				student = pCur->getData();

				cout << student.getNumber() << ", "
					<< student.getID() << ", "
					<< student.getName() << ", "
					<< student.getEmail() << ", "
					<< student.getUnits() << ", "
					<< student.getProgram() << ", "
					<< student.getLevel() << ", ";

				if (!student.getAbsencesDate().empty())
				{
					cout << student.peekAbsences_Date() << endl << endl;
				}
				else
				{
					cout << "Nothing was found" << endl << endl;
				}

				pCur = pCur->getNext();
			}

			system("pause");
		}
		else if (choice == 2)
		{
			cout << "Enter amount of absences to filter: " << endl;
			cin >> count;

			pCur = masterList.getHead();

			cout << "Report for Students with absences >= " << count << endl;
			cout << "Number, ID, Name, Email, Units, Program, Level, Absences" << endl << endl;

			while (pCur)
			{
				student = pCur->getData();

				if (student.getAbsences_Num() >= count)
				{
					cout << student.getNumber() << ", "
						<< student.getID() << ", "
						<< student.getName() << ", "
						<< student.getEmail() << ", "
						<< student.getUnits() << ", "
						<< student.getProgram() << ", "
						<< student.getLevel() << ", "
						<< student.getAbsences_Num() << endl << endl;
				}

				pCur = pCur->getNext();
			}

			system("pause");
		}
		else if (choice == 3)
		{
			cout << "Exiting Report Menu..." << endl << endl;
		}
		else
		{
			cout << "Invalid choice, try again." << endl << endl;
		}

	} while (choice != 3);
}





string Menu::GatherTime() // Helper Function for Case 4
{
	time_t t = time(0); // get time now
	struct tm* now = localtime(&t);
	cout << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday
		<< endl;

	std::ostringstream output;

	output << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday;

	return output.str();
}

bool Menu::Checking(const string& str) // Helper Function
{
	if (str.empty())
	{
		return false;
	}

	for (int i = 0; i < str.length(); i++)
	{
		char real = str[i];

		if (!isdigit(real))
		{
			return false;
		}
	}
	return true;
}
