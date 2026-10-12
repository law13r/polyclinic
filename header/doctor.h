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
	Doctor(int, const std::string&, const std::string&, const std::string&, std::vector<Appoint*>&);
	Doctor(int, const std::string&, const std::string&, const std::string&);
	explicit Doctor(int);

	std::string getName() const;
	std::string getSpec() const;
	std::string getOffice() const;
	std::vector<Appoint*> getAppoints() const;
	int getID() const;

	void setName(const std::string&);
	void setSpec(const std::string&);
	void setOffice(const std::string&);
	void setAppoint(Appoint*);
	void setID(int&);

	bool hasNoAppoints();
	void writeAppoints();
	bool hasPatient(int&);
	void setPatient(int&, int&);
	void deleteAppoint(std::vector<Appoint>&, int&);
};