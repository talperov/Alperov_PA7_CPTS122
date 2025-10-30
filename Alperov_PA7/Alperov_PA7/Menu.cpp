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

void Menu::ImportCourseList() // CASE 1
{
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
	ifstream infile("master.csv");
	string line;
	int count = 0;

	if (!infile.is_open())
	{
		cout << "Error Opening master.csv\n\n";
		return;
	}

	getline(infile, line); // skip header

	while (getline(infile, line))
	{
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

		tempStudent.setNumber(stoi(number));
		tempStudent.setID(stoi(id));
		tempStudent.setName(name);
		tempStudent.setEmail(email);
		tempStudent.setUnits(units);
		tempStudent.setProgram(program);
		tempStudent.setLevel(level);
		tempStudent.setAbsences_Num(stoi(absence));

		masterList.insertAtFront(tempStudent);
		count++;
	}

	infile.close();
	cout << endl; cout << "Students loaded #" << count << endl;
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



void Menu::GenerateReport() // CASE 5
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
