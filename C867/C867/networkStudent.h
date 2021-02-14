#ifndef NETWORK_H
#define NETWORK_H

#include "student.h"

class NetworkStudent : public Student {

public:
	virtual Degree getDegreeProgram() override;
	using Student::Student;

private:
	Degree DegreeType = NETWORK;

};

#endif