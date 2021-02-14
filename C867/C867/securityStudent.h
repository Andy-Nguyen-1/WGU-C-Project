#pragma once
#ifndef SECURITY_H
#define SECURITY_H

#include "student.h"

class SecurityStudent : public Student {

public:
	virtual Degree getDegreeProgram() override;
	using Student::Student;

private:
	Degree DegreeType = SECURITY;

};

#endif
