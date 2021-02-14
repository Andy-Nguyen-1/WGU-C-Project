#pragma once
#ifndef SOFTWARE_H
#define SOFTWARE_H

#include "student.h"

class SoftwareStudent : public Student {

public:
	virtual Degree getDegreeProgram() override;
	using Student::Student;

private:
	Degree DegreeType = SOFTWARE;

};

#endif