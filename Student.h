#pragma once
// Declearing a Class
#include <iostream>
#include <string>
using namespace std;

// Creating a class called Student
class Student {
private:
	// Private members
	string _name;
	string _emplid;
	float _GPA = 0.0;
public:
	// Default constructor
	Student();
	// Constructor
	Student(string, string, float);
	// The Mutators
	void setName(string);
	void setEmplid(string);
	void setGPA(float);
	// The Accessors
	string getName() const;
	string getEmplid() const;
	float getGPA() const;
	// letterGrade returns letter grade based on the GPA
	char letterGrade()const;
	// To display all the student informations
	void display()const;
	// class member that overloads the >> operator
	friend istream& operator >> (istream& in, Student& student);
	friend ostream& operator << (ostream& out, Student& student);

};