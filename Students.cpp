// Class Definition
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

// Default constructor
Student::Student() : _name("NoName"), _emplid("NoEmplid"), _GPA(0.0) {
}

// Constructor
Student::Student(string name, string emplid, float GPA) : _name(name), _emplid(emplid), _GPA(GPA) {
}

// Mutator functions
void Student::setName(string name) {
	_name = name;
}

void Student::setEmplid(string emplid) {
	_emplid = emplid;
}

void Student::setGPA(float GPA) {
	_GPA = GPA;
}

// Accessor functions
string Student::getName() const { return _name; }
string Student::getEmplid() const { return _emplid; }
float Student::getGPA() const { return _GPA; }

// Function to return the Letter grade of the GPA
char Student::letterGrade() const {
	if (_GPA == 4.0) {
		return 'A';
	}
	else if (_GPA < 4.0 && _GPA >= 3.0) {
		return 'B';
	}
	else if (_GPA < 3.0 && _GPA >= 2.5) {
		return 'C';
	}
	else if (_GPA < 2.5 && _GPA >= 2.0) {
		return 'D';
	}
	else { return 'F'; }
}

// Overloading the >> operator to read in student info into an object
istream& operator>>(istream& in, Student& student) {
	getline(in, student._name);
	in >> student._emplid >> student._GPA;
	in.ignore();
	return in;
}

// Funtion to display the Student information
void Student::display() const {

		cout << "Student Name: " << _name << ", Emplid : "
			<< _emplid << ", GPA: " << _GPA << ", LetterGrade: " << letterGrade();
		cout << endl;
}

// Overloading the << operator to display student info from an object file
ostream& operator << (ostream& out, Student& student) {
	out << "Name: " << student._name
		<< " Emplid: " << student._emplid
		<< " GPA: " << student._GPA
		<< " LetterGrade: " << student.letterGrade() << endl;
	return out;
}