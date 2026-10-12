#pragma once
#include "lab.h"

class Patient {
private:
	int id;
	std::string name;
	std::string doB;
	long long phone;
	std::vector<Appoint*> appoints;
public:
	Patient(int, const std::string&, const std::string&, long long, const std::vector<Appoint*>&);
	Patient(int, const std::string&, const std::string&, long long);
	explicit Patient(int);

	std::string getName() const;
	std::string getDoB() const;
	long long getPhone() const;
	std::vector<Appoint*> getAppoints() const;
	int getID() const;

	void setName(std::string_view);
	void setDoB(std::string_view);
	void setPhone(const long long&);
	void setAppoint(Appoint*);
	void setID(const int&);
};