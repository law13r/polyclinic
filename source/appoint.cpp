#include "appoint.h"

Appoint::Appoint(const Doctor& doctor, Patient& patient, const std::string& date, const std::string& time) : date(date), time(time), doctor(doctor), patient(patient) {
}

Appoint::Appoint(const Doctor& doctor, const std::string& date, const std::string& time) : date(date), time(time), doctor(doctor) {
}

Appoint::Appoint(const Doctor& doctor) : date("default"), time("default"), doctor(doctor) {
	return;
}

Doctor Appoint::getDoctor() const {
	return doctor;
}

std::optional<Patient> Appoint::getPatient() const {
	return patient;
}

std::string Appoint::getDate() const {
	return date;
}

std::string Appoint::getTime() const {
	return time;
}

void Appoint::setDoctor(const Doctor& doc) {
	doctor = doc;
	return;
}

void Appoint::setPatient(const Patient& pat) {
	patient = pat;
	return;
}

void Appoint::setDate(std::string_view dateNew) {
	date = dateNew;
	return;
}

void Appoint::setTime(std::string_view timeNew) {
	time = timeNew;
	return;
}

bool Appoint::hasPatient() const {
	if (patient.has_value())
		return true;
	return false;
}