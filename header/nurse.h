#pragma once
#include "lab.h"
#include "person.h"
#include "doctor.h"

class Nurse : public Person {
private:
	std::string office;
	std::weak_ptr<Doctor> connectedDoc;
public:
	Nurse(int, std::string_view, std::string_view, std::string_view, std::shared_ptr<Doctor>, const std::vector<std::shared_ptr<Appoint>>&);
	Nurse(int, std::string_view, std::string_view, std::string_view, std::shared_ptr<Doctor>);
	Nurse(int, std::string_view, std::string_view, std::string_view, const std::vector<std::shared_ptr<Appoint>>&);
	Nurse(int, std::string_view, std::string_view, std::string_view);
	explicit Nurse(int);

	std::string getOffice() const;
	std::shared_ptr<Doctor> getDoctor() const;

	void setOffice(std::string_view);
	void setDoctor(std::shared_ptr<Doctor>);

	bool hasDoctor() const;
	void setPatient(const int&, std::shared_ptr<Patient>);
};