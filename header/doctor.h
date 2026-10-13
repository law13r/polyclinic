#pragma once
#include "lab.h"
#include "person.h"

class Doctor : public Person {
private:
	std::string speciality;
	std::string office;
public:
	Doctor(int, const std::string&, const std::string&, const std::string&, std::string_view, const std::vector<Appoint*>&);
	Doctor(int, const std::string&, const std::string&, const std::string&, std::string_view);
	explicit Doctor(int);

	std::string getSpec() const;
	std::string getOffice() const;

	void setSpec(std::string_view);
	void setOffice(std::string_view);

	bool hasPatient(const int&);
	void setPatient(const int&, const Patient&);
};