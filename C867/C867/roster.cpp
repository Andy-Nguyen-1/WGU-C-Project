#include <iostream>
#include <sstream>
#include "roster.h"

using namespace std;
	//Adds new student to roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree)
{
	int daysSpent[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	for (int i = 0; i < rosterArraySize; i++) {
		if (classRosterArray[i] == nullptr) {
			if (degree == NETWORK) {
				classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysSpent, degree);
			}
			else if (degree == SECURITY) {
				classRosterArray[i] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysSpent, degree);
			}
			else if (degree == SOFTWARE) {
				classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysSpent, degree);
			}
			else {
				classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysSpent, degree);
			}
			break;
		}
	}

}
	//Checks for valid email
void Roster::printInvalidEmails()
{
	for (int i = 0; i < rosterArraySize; i++) {
		string email = classRosterArray[i]->getEmail();
		//bool validEmail = false;
		if (email.find("@") == string::npos) {
			cout << "The following email, " << email << " is an invalid email. The '@' symbol is required.\n";
		}
		if (email.find(".") == string::npos) {
			cout << "The following email, " << email << " is an invalid email. The '.' symbol is required.\n";
		}
		if (email.find(" ") != string::npos) {
			cout << "The following email, " << email << " is an invalid email. Spaces are not allowed.\n";
		}
	}
}
	//Remove Student by StudentID
void Roster::remove(string studentID)
{
	for (int i = 0; i < rosterArraySize; ++i) {
		if (classRosterArray[i] == nullptr) {
			cout << "The student ID '" << studentID << "' does not exist" << endl;
		}
		else if (studentID == classRosterArray[i]->getStudentId()) {
			classRosterArray[i] = nullptr;
			cout << "The student ID " << studentID << " has been removed.\n\n";
		}
	}
}
void Roster::printAverageDaysInCourse(string studentID)
{
	float average = 0;
	float averageDays = 0;
	int daysArraySize = 3;

	for (int i = 0; i < rosterArraySize; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentId() == studentID) {
			int* daysInCourse = classRosterArray[i]->getDaysInCourse();
			for (int x = 0; x < daysArraySize; x++) {
				average = average + daysInCourse[x];
				averageDays = average / daysArraySize;
			}
			cout << "Student ID " << classRosterArray[i]->getStudentId() << ": Average number of days spent on a course is " << averageDays << "\n";
			break;
		}
	}
}

void Roster::printByDegreeProgram(int degree)
{
	for (int i = 0; i < rosterArraySize; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degree) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printAll()
{
	for (int i = 0; i < rosterArraySize; i++) {
		classRosterArray[i]->print();
	}
}

Roster::~Roster()
{
}

int main() {

	Roster classRoster;

	cout << "Scripting and Programming - C867" << endl;
	cout << "C++" << endl;
	cout << "Student ID: 001095861" << endl;
	cout << "Andy Nguyen" << endl;
	cout << endl;



	cout << "The following students will be added to the student roster:" << endl;
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Andy,Nguyen,angu131@wgu.edu,21,30,40,30,SOFTWARE"
	};

	int sizeOfData = sizeof(studentData) / sizeof(studentData[0]);

	for (int i = 0; i < sizeOfData; i++) {
		string userInput = studentData[i];
		istringstream parse(userInput);
		string newValue;
		string add[9];

		int x = 0;
		while (getline(parse, newValue, ',')) {
			add[x] = newValue;
			++x;
		}

		Degree degreeProgram;
		if (add[8] == "NETWORK") {
			degreeProgram = NETWORK;
		}
		else if (add[8] == "SECURITY") {
			degreeProgram = SECURITY;
		}
		else if (add[8] == "SOFTWARE") {
			degreeProgram = SOFTWARE;
		}
		else {
			degreeProgram = UNDECIDED;
		}
		
		classRoster.add(add[0], add[1], add[2], add[3], stoi(add[4]), stoi(add[5]), stoi(add[6]), stoi(add[7]), degreeProgram);
	}

	classRoster.printAll();
	cout << endl;

	classRoster.printInvalidEmails();
	cout << endl;


	int size = classRoster.getSize();
	for (int i = 0; i < size; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
	}
	cout << endl;

	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	classRoster.remove("A3");
	classRoster.remove("A3");
	classRoster.~Roster();
	system("PAUSE");
	return 0;
}