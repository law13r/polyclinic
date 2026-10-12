#include "patient.h"
#include "appoint.h"

Patient::Patient(int id, const std::string& name, std::string doB, long long phone, std::vector<Appoint*> appoints) : id(id), name(name), doB(doB), phone(phone), appoints(appoints) {
}

Patient::Patient(int id, const std::string& name, std::string doB, long long phone) : id(id), name(name), doB(doB), phone(phone) {
	appoints = {};
}

Patient::Patient(int id) : id(id) {
	name = "default";
	doB = "default";
	phone = 0;
	appoints = {};
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

void Patient::setName(std::string name) {
	this->name = name;
	return;
}

void Patient::setDoB(std::string doB) {
	this->doB = doB;
	return;
}

void Patient::setPhone(long long phone) {
	this->phone = phone;
	return;
}

void Patient::setAppoint(Appoint* appoint) {
	appoints.push_back(appoint);
	return;
}

void Patient::setID(int id) {
	this->id = id;
	return;
}