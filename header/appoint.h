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
	Appoint(Doctor&, Patient&, const std::string&, const std::string&);
	Appoint(Doctor&, const std::string&, const std::string&);
	explicit Appoint(Doctor&);

	Doctor getDoctor() const;
	std::optional<Patient> getPatient() const;
	std::string getDate() const;
	std::string getTime() const;

	void setDoctor(const Doctor&);
	void setPatient(const Patient&);
	void setDate(std::string_view);
	void setTime(std::string_view);

	bool hasPatient() const;

	friend std::ostream& operator<<(std::ostream&, const Appoint&);
	friend std::istream& operator>>(std::istream&, Appoint&);
};