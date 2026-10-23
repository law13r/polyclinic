#include "patient.h"
#include "appoint.h"

Patient::Patient(int id, const std::string& name, const std::string& doB, std::string_view phone, const std::vector<std::shared_ptr<Appoint>>& appoints) : Person(id, name, phone, appoints), doB(doB) {
}

Patient::Patient(int id, const std::string& name, const std::string& doB, std::string_view phone) : Person(id, name, phone), doB(doB) {
}

Patient::Patient(int id) : Person(id) {
}

std::string Patient::getDoB() const {
	return doB;
}

void Patient::setDoB(std::string_view nDoB) {
	doB = nDoB;
	return;
}