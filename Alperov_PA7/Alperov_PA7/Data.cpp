#include "Data.h"

Data::Data()
{
	Number = 0;
	ID = 0;
	Name = "";
	Email = "";
	Units = "";
	Program = "";
	Level = "";
	Absences_Num = 0;
	Absences_Date;
}

Data::Data(int number, int id, const string& name, const string& email, const string& units, const string& program, const string& level)
{
	this->Number = number;
	this->ID = id;
	this->Name = name;
	this->Email = email;
	this->Units = units;
	this->Program = program;
	this->Level = level;
	this->Absences_Num = 0;
	Absences_Date;
}

Data::~Data()
{
	//cout << "Destructor Activated" << endl; // Remember to delete this
}

int Data::getNumber() const
{
	return this->Number;
}

int Data::getID() const
{
	return this->ID;
}

string Data::getName() const
{
	return this->Name;
}

string Data::getEmail() const
{
	return this->Email;
}

string Data::getUnits() const
{
	return this->Units;
}

string Data::getProgram() const
{
	return this->Program;
}

string Data::getLevel() const
{
	return this->Level;
}

int Data::getAbsences_Num() const
{
	return this->Absences_Num;
}

stack<string> Data::getAbsencesDate() const
{
	return this->Absences_Date;
}


void Data::setNumber(int number)
{
	this->Number = number;
}

void Data::setID(int id)
{
	this->ID = id;
}

void Data::setName(const string& name)
{
	this->Name = name;
}

void Data::setEmail(const string& email)
{
	this->Email = email;
}

void Data::setUnits(const string& units)
{
	this->Units = units;
}

void Data::setProgram(const string& program)
{
	this->Program = program;
}

void Data::setLevel(const string& level)
{
	this->Level = level;
}

void Data::setAbsences_Num(int num)
{
	this->Absences_Num = num;
}

void Data::pushAbsences_Date(const string& date)
{
	this->Absences_Date.push(date);
	this->Absences_Num++;
}

string Data::peekAbsences_Date() const
{
	if (!this->Absences_Date.empty())
	{
		return this->Absences_Date.top();
	}
	return "No absences";
}

