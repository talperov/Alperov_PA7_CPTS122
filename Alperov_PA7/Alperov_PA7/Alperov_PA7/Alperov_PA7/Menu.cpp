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

void Menu::ImportCourseList() // CASE 1
{
	int import = 0;
	string line;
	ifstream  infile("classList.csv");
	if (!infile.is_open())
	{
		cout << "Error Opening InFile" << endl;
		return;
	}
	while (getline(infile, line))
	{
		int number = 0, id = 0;
		string name, email, units, program, units, level, token;
		stringstream input(line);

		getline(input, token, ','); // Record Number getter
		number = stoi(token);
		getline(input, token, ','); // ID getter
		id = stoi(token);
		getline(input, name, ','); // Name getter
		getline(input, email, ','); // Email getter	
		getline(input, units, ','); // Unit Getter
		getline(input, program, ','); // Program Getter
		getline(input, level, ','); // Level Getter

		Data student(number, id, name, email, units, program, level);

		masterList.insertAtFront(student);

		import++;
		cout << "Course List #" << import << "Imported" << endl;
	}
	infile.close();
	cout << "Done Importing. . ." << endl;
	
}

void Menu::LoadCourseList() // CASE 2
{
	ifstream infile("master.csv");
	string line;

	if (!infile.is_open())
	{
		cout << "Error Opening InFile" << endl;
		return;
	}
	getline(infile, line);
	int count = 0;
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
	cout << "Students loaded #" << count << endl;
	cout << "Master List Loaded into master.csv" << endl;
	
}

void Menu::StoreCourseList() // CASE 3
{

	ofstream outfile("master.csv");
	if (!outfile.is_open())
	{
		cout << "Error Opening OutFile" << endl;
		return;
	}


	Node<Data>* pCur = masterList.getHead();
	int time = 0;

	while (pCur != nullptr)
	{
		Data student = pCur->getData();
		
		outfile << student.getNumber() << "," << student.getID() << "," << student.getEmail() << "," << student.getUnits() << student.getProgram() << "," << student.getLevel() << "," << student.getAbsences_Num() << endl;
		if (!student.getAbsencesDate().empty())
		{
			outfile << student.peekAbsences_Date();
		}
		outfile << endl;

		time++;
		cout << "Master List stored #" << time << endl;

		pCur = pCur->getNext();

	}

	outfile.close();
	cout << "master.csv Successfully Stored" << endl;

}

void Menu::MarkAbsences() // CASE 4
{

}

void Menu::GenerateReport() // CASE 5
{
		
}
