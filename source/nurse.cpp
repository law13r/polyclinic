#include "lab.h"
#include "nurse.h"
#include "appoint.h"

Nurse::Nurse(int id, std::string_view name, std::string_view office, std::string_view phone, const Doctor & connectedDoc, const std::vector<Appoint*>&appoints) : Person(id, name, phone, appoints), office(office), connectedDoc(connectedDoc) {}

Nurse::Nurse(int id, std::string_view name, std::string_view office, std::string_view phone, const Doctor& connectedDoc) : Person(id, name, phone), office(office), connectedDoc(connectedDoc) {}

Nurse::Nurse(int id, std::string_view name, std::string_view office, std::string_view phone, const std::vector<Appoint*>& appoints) : Person(id, name, phone, appoints), office(office) {}

Nurse::Nurse(int id, std::string_view name, std::string_view office, std::string_view phone) : Person(id, name, phone), office(office) {}

Nurse::Nurse(int id) : Person(id), office("default") {}

std::string Nurse::getOffice() const {
	return office;
}

std::optional<Doctor> Nurse::getDoctor() const {
	return connectedDoc;
}

void Nurse::setOffice(std::string_view officeNew) {
	office = officeNew;
	return;
}

void Nurse::setDoctor(const Doctor& doctor) {
	connectedDoc = doctor;
	return;
}

bool Nurse::hasDoctor() const {
	if (connectedDoc.has_value())
		return true;
	return false;
}

void Nurse::setPatient(const int& num, const Patient& patient) {
	if (appoints[num]->hasPatient())
		return;
	appoints[num]->setPatient(patient);
	return;
}