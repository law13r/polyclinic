#pragma once
#include "lab.h"
#include "patient.h"
#include "doctor.h"
#include "incomparableAppointmentsException.h"

class Appoint {
private:
	std::string date;
	std::string time;
	std::shared_ptr<Doctor> doctor;
	std::shared_ptr<Patient> patient;
public:
	Appoint(std::shared_ptr<Doctor>, std::shared_ptr<Patient>, const std::string&, const std::string&);
	Appoint(std::shared_ptr<Doctor>, const std::string&, const std::string&);
	explicit Appoint(std::shared_ptr<Doctor>);

	std::shared_ptr<Doctor> getDoctor() const;
	std::shared_ptr<Patient> getPatient() const;
	std::string getDate() const;
	std::string getTime() const;

	void setDoctor(std::shared_ptr<Doctor>);
	void setPatient(std::shared_ptr<Patient>);
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

	auto operator<=>(const Appoint& other) const {
		if (doctor != other.doctor || patient != other.patient)
			throw IncomparableAppointmentsException("Nothing to compare\n");
		return time <=> other.time;
	}

	bool operator==(const Appoint& other) const {
		if (doctor != other.doctor || patient != other.patient)
			throw IncomparableAppointmentsException("Nothing to compare\n");
		return time == other.time;
	}
};