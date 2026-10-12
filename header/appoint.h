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
	Appoint(int, int, const std::string&, const std::string&);
	Appoint(int, const std::string&, const std::string&);
	explicit Appoint(int);

	int getDocID() const;
	std::optional<int> getPatID() const;
	std::string getDate() const;
	std::string getTime() const;

	void setDocID(const int&);
	void setPatID(const int&);
	void setDate(std::string_view);
	void setTime(std::string_view);

	bool hasPatient() const;
};