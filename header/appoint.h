#pragma once
#include "lab.h"
#include "patient.h"
#include "doctor.h"

class Appoint {
private:
	std::string date;
	std::string time;
	int docID;
	std::optional<int> patID;
public:
	Appoint(int, int, std::string, std::string);
	Appoint(int, std::string, std::string);
	Appoint(int);

	int getDocID() const;
	std::optional<int> getPatID() const;
	std::string getDate() const;
	std::string getTime() const;

	void setDocID(int);
	void setPatID(int);
	void setDate(std::string);
	void setTime(std::string);

	bool hasPatient();
};