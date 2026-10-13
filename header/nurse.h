#pragma once
#include "lab.h"
#include "person.h"
#include "doctor.h"

class Nurse : public Person {
private:
	std::string office;
	std::optional<Doctor> connectedDoc;
public:
	Nurse(int, std::string_view, std::string_view, std::string_view, const Doctor&, const std::vector<Appoint*>&);
	Nurse(int, std::string_view, std::string_view, std::string_view, const Doctor&);
	Nurse(int, std::string_view, std::string_view, std::string_view, const std::vector<Appoint*>&);
	Nurse(int, std::string_view, std::string_view, std::string_view);
	explicit Nurse(int);

	std::string getOffice() const;
	std::optional<Doctor> getDoctor() const;

	void setOffice(std::string_view);
	void setDoctor(const Doctor&);

	bool hasDoctor() const;
	void setPatient(const int&, const Patient&);
};