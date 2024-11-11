/*
	Name: Student Class
	Copyright: 2024
	Author: Caleb Adekoya
	Date: 29/09/24 22:07
	Description: This program makes a Student class(name, emplid, GPA) with
	methods: 2 constructors (default and with parameters) getters and
	setters, display, and letterGrade that returns letter grade based on the GPA.
	It then passes a file with student information into an instance and prints
	out the data.
*/

#include "Student.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

void searchStudent(vector<Student>& studList) {
	string emp;
	cout << "Enter the EMPLID to search for: ";
	cin >> emp;

	bool found = false;
	for (int i = 0; i < studList.size(); i++) {
		if (studList.at(i).getEmplid() == emp) {
			studList.at(i).display();
			found = true;
		}
	}
	if (!found)
		cout << "Student not found.\n";
}


// Function to display the Student Lists
void displayStudents(const vector<Student>& studLists) {
	if (studLists.empty()) {
		cout << "No Students to display.\n";
	}
	else {
		for (int i = 0; i < studLists.size(); i++) {
			studLists.at(i).display();
		}
	}
}

// Function to add a as many students to the list 
void addStudent(vector<Student>& studList) {
	int num;
	string name, emp;
	float gpa;

	cout << "Enter the Student details starting with: "
		<< "Name, Emplid, and the GPA respectively."
		<< endl;
	cout << "How many Students are you adding?\n";
	cin >> num;
	cin.ignore();

	// while (num > 0) {
		for (int i = 0; i < num; i++) {
			cout << "Name: ";
			getline(cin, name);
			cout << "Emplid: ";
			cin >> emp;
			cout << "GPA: ";
			cin >> gpa;
			cin.ignore();
			Student myStud(name, emp, gpa);
			studList.push_back(myStud);
		}
}

void displayMenu(vector<Student>& studentLists) {

	enum choices { DUMMY, Search, Add, Display, Done };
	int choice;
	do {
		cout << "Enter which of these MENU you want.\n";
		cout << "1. Search\n" << "2. Add\n" << "3. Display\n" << "4. Done\n"
			<< "Choice: ";
		cin >> choice;

		switch (choice) {
		case Search:
			searchStudent(studentLists);
			break;
		case Add:
			addStudent(studentLists);
			break;
		case Display:
			displayStudents(studentLists);
			break;
		case Done:
			cout << "Done.\n";
				break;
		default:
			cout << "Invalid number. Number must be between 1 and 4."
				<< endl;
		}
	} while (choice != Done);

}

// Main
int main() {
	// Declearation of on object and a vector of type Student
	Student aStudent;
	vector<Student> studentLists;
	// opening the student.txt file
	ifstream myStudents;
	myStudents.open("students.txt");
	if (!myStudents) {
		cout << "Error opening File\n";
		return 1;
	}
	// Displaying each of the Student information
	while (myStudents >> aStudent) {
		studentLists.push_back(aStudent);
	}
	// Closing File
	myStudents.close();
	// Displaying the Menu
	displayMenu(studentLists);
	return 0;
}