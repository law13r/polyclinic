#pragma once
#include "lab.h"
#include "person.h"

class Patient : public Person {
private:
	std::string doB;
public:
	Patient(int, const std::string&, const std::string&, std::string_view, const std::vector<Appoint*>&);
	Patient(int, const std::string&, const std::string&, std::string_view);
	explicit Patient(int);

	std::string getDoB() const;

	void setDoB(std::string_view);
};