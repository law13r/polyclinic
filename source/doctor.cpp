#include "doctor.h"
#include "appoint.h"

Doctor::Doctor(int id, const std::string& name, const std::string& speciality, const std::string& office, std::string_view phone, const std::vector<Appoint*>& appoints) : Person(id, name, phone, appoints), speciality(speciality), office(office) {
}

Doctor::Doctor(int id, const std::string& name, const std::string& speciality, const std::string& office, std::string_view phone) : Person(id, name, phone), speciality(speciality), office(office) {
}

Doctor::Doctor(int id) : Person(id, "default", "default"), speciality("default"), office("default") {
}

std::string Doctor::getSpec() const {
	return speciality;
}

std::string Doctor::getOffice() const {
	return office;
}

void Doctor::setSpec(std::string_view spec) {
	speciality = spec;
	return;
}

void Doctor::setOffice(std::string_view nOffice) {
	office = nOffice;
	return;
}

bool Doctor::hasPatient(const int& num) {
	if (appoints[num]->hasPatient())
		return true;
	return false;
}

void Doctor::setPatient(const int& num, const Patient& patient) {
	if (appoints[num]->hasPatient())
		return;
	appoints[num]->setPatient(patient);
	return;
}