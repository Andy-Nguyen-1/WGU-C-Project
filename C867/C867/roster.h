#pragma once
#include <iostream>
#include <string>

#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

using namespace std;

class Roster {

	int rosterArraySize = sizeof(classRosterArray) / sizeof(classRosterArray[0]);

public:

	int getSize() {
		return rosterArraySize;
	}
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree);
	void printAll();
	void printByDegreeProgram(int degree);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void remove(string studentID);
	
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	
	~Roster();

};


