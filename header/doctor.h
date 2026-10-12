#pragma once
#include "lab.h"

class Doctor {
private:
	int id;
	std::string name;
	std::string speciality;
	std::string office;
	std::vector<Appoint*> appoints;
public:
	Doctor(int, const std::string&, const std::string&, const std::string&, const std::vector<Appoint*>&);
	Doctor(int, const std::string&, const std::string&, const std::string&);
	explicit Doctor(int);

	std::string getName() const;
	std::string getSpec() const;
	std::string getOffice() const;
	std::vector<Appoint*> getAppoints() const;
	int getID() const;

	void setName(std::string_view);
	void setSpec(std::string_view);
	void setOffice(std::string_view);
	void setAppoint(Appoint*);
	void setID(const int&);

	bool hasNoAppoints() const;
	void writeAppoints() const;
	bool hasPatient(const int&);
	void setPatient(const int&, const int&);
	void deleteAppoint(std::vector<Appoint>&, const int&);
};