#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student {

private:

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[3];
	Degree DegreeType;

public:

	int daysArraySize = 3;

	//getters
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysInCourse();
	Degree getDegreeType();

	//setters
	void setStudentId(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int[3]);
	void setDegreeType(Degree);

	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysToComplete, Degree);
	
	
	//Destructor
	~Student();

	virtual void print();
	virtual Degree getDegreeProgram();

};

#endif
