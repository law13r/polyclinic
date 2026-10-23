#include "lab.h"
#include "nurse.h"
#include "appoint.h"

Nurse::Nurse(int id, std::string_view name, std::string_view office, std::string_view phone, std::shared_ptr<Doctor> connectedDoc, const std::vector<std::shared_ptr<Appoint>>&appoints) : Person(id, name, phone, appoints), office(office), connectedDoc(connectedDoc) {}

Nurse::Nurse(int id, std::string_view name, std::string_view office, std::string_view phone, std::shared_ptr<Doctor> connectedDoc) : Person(id, name, phone), office(office), connectedDoc(connectedDoc) {}

Nurse::Nurse(int id, std::string_view name, std::string_view office, std::string_view phone, const std::vector<std::shared_ptr<Appoint>>& appoints) : Person(id, name, phone, appoints), office(office) {}

Nurse::Nurse(int id, std::string_view name, std::string_view office, std::string_view phone) : Person(id, name, phone), office(office) {}

Nurse::Nurse(int id) : Person(id), office("default") {}

std::string Nurse::getOffice() const {
	return office;
}

std::shared_ptr<Doctor> Nurse::getDoctor() const {
	return connectedDoc.lock();
}

void Nurse::setOffice(std::string_view officeNew) {
	office = officeNew;
	return;
}

void Nurse::setDoctor(std::shared_ptr<Doctor> doctor) {
	connectedDoc = doctor;
	return;
}

bool Nurse::hasDoctor() const {
	return !connectedDoc.expired();
}

void Nurse::setPatient(const int& num, std::shared_ptr<Patient> patient) {
	if (num < 0 || num >= appoints.size() || appoints[num]->hasPatient())
		return;
	appoints[num]->setPatient(patient);
	return;
}