#include "patient.h"
#include "appoint.h"

Patient::Patient(int id, const std::string& name, const std::string& doB, long long phone, const std::vector<Appoint*>& appoints) : id(id), name(name), doB(doB), phone(phone), appoints(appoints) {
}

Patient::Patient(int id, const std::string& name, const std::string& doB, long long phone) : id(id), name(name), doB(doB), phone(phone) {
}

Patient::Patient(int id) : id(id), name("default"), doB("default"), phone(0) {
}

std::string Patient::getName() const {
	return name;
}

std::string Patient::getDoB() const{
	return doB;
}

long long Patient::getPhone() const {
	return phone;
}

std::vector<Appoint*> Patient::getAppoints() const {
	return appoints;
}

int Patient::getID() const {
	return id;
}

void Patient::setName(std::string_view nName) {
	name = nName;
	return;
}

void Patient::setDoB(std::string_view nDoB) {
	doB = nDoB;
	return;
}

void Patient::setPhone(const long long& nPhone) {
	phone = nPhone;
	return;
}

void Patient::setAppoint(Appoint* appoint) {
	appoints.push_back(appoint);
	return;
}

void Patient::setID(const int& nID) {
	id = nID;
	return;
}