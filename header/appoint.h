#pragma once
#include "lab.h"
#include "patient.h"
#include "doctor.h"

class Appoint {
private:
	std::string date;
	std::string time;
	Doctor doctor;
	std::optional<Patient> patient;
public:
	Appoint(const Doctor&, Patient&, const std::string&, const std::string&);
	Appoint(const Doctor&, const std::string&, const std::string&);
	explicit Appoint(const Doctor&);

	Doctor getDoctor() const;
	std::optional<Patient> getPatient() const;
	std::string getDate() const;
	std::string getTime() const;

	void setDoctor(const Doctor&);
	void setPatient(const Patient&);
	void setDate(std::string_view);
	void setTime(std::string_view);

	bool hasPatient() const;

	friend std::ostream& operator<<(std::ostream& os, const Appoint& appoint) {
		os << appoint.date << ' ' << appoint.time;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Appoint& appoint) {
		is >> appoint.date >> appoint.time;
		return is;
	}
};