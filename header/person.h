#pragma once
#include "lab.h"

class Person {
protected:
	int id;
	std::string name;
	std::string phone;
	std::vector<Appoint*> appoints;
public:
	Person(int, std::string_view, std::string_view, std::vector<Appoint*>);
	Person(int, std::string_view, std::string_view);
	explicit Person(int);

	virtual int getID() const;
	virtual std::string getName() const;
	virtual std::string getPhone() const;
	virtual std::vector<Appoint*> getAppoints() const;

	virtual void setID(const int&);
	virtual void setName(std::string_view);
	virtual void setPhone(std::string_view);
	virtual void setAppoints(std::vector<Appoint*>&);

	virtual bool hasNoAppoints() const;
	virtual void writeAppoints() const;
	virtual void delAppoint(std::vector<Appoint>&, const int&);

	friend std::ostream& operator<<(std::ostream&, const Person&);
	friend std::istream& operator>>(std::istream&, Person&);
	Person& operator+=(Appoint* appoint);
	Person& operator-=(Appoint* appoint);
};