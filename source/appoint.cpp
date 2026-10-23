#include "appoint.h"

Appoint::Appoint(std::shared_ptr<Doctor> doctor, std::shared_ptr<Patient> patient, const std::string& date, const std::string& time) : date(date), time(time), doctor(doctor), patient(patient) {
}

Appoint::Appoint(std::shared_ptr<Doctor> doctor, const std::string& date, const std::string& time) : date(date), time(time), doctor(doctor) {
}

Appoint::Appoint(std::shared_ptr<Doctor> doctor) : date("default"), time("default"), doctor(doctor) {
	return;
}

std::shared_ptr<Doctor> Appoint::getDoctor() const {
	return doctor;
}

std::shared_ptr<Patient> Appoint::getPatient() const {
	return patient;
}

std::string Appoint::getDate() const {
	return date;
}

std::string Appoint::getTime() const {
	return time;
}

void Appoint::setDoctor(std::shared_ptr<Doctor> doc) {
	doctor = doc;
	return;
}

void Appoint::setPatient(std::shared_ptr<Patient> pat) {
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
	return patient != nullptr;
}