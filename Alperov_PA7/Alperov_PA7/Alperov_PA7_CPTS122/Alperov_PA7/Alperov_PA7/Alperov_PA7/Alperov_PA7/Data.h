#pragma once
#include <iostream>
#include <string>
#include <stack>

using std::string;
using std::stack;
using std::cout;
using std::cin;
using std::endl;

class Data
{
private: 
	int Number;
	int ID;
	string Name;
	string Email;
	string Units;
	string Program;
	string Level;
	int Absences_Num;
	stack<string> Absences_Date;

	


public:
	// Constructors Copy Constructors and Destructors
	Data();
	Data(int number, int id, const string& name, const string& email, const string& units, const string& program, const string& level);
	~Data();

	//getters
	int getNumber() const;
	int getID() const;
	string getName() const;
	string getEmail() const;
	string getUnits() const;
	string getProgram() const;
	string getLevel() const ;
	int getAbsences_Num() const;
	stack<string> getAbsencesDate() const;

	//setters

	void setNumber(int number);
	void setID(int id);
	void setName(const string& name);
	void setEmail(const string& email); 
	void setUnits(const string& units);
	void setProgram(const string& program);
	void setLevel(const string& level);
	void setAbsences_Num(int num);

	//members
	void pushAbsences_Date(const string& date);
	string peekAbsences_Date()const;
	


};

