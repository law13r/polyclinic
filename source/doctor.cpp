#include "doctor.h"
#include "appoint.h"

Doctor::Doctor(int id, const std::string& name, const std::string& speciality, const std::string& office, std::vector<Appoint*> appoints) : id(id), name(name), speciality(speciality), office(office), appoints(appoints) {
}

Doctor::Doctor(int id, const std::string& name, const std::string& speciality, const std::string& office) : id(id), name(name), speciality(speciality), office(office) {
	appoints = {};
}

Doctor::Doctor(int id) : id(id){
	name = "default";
	speciality = "default";
	office = "default";
	appoints = {};
}

std::string Doctor::getName() const {
	return name;
}

std::string Doctor::getSpec() const {
	return speciality;
}

std::string Doctor::getOffice() const {
	return office;
}

std::vector<Appoint*> Doctor::getAppoints() const {
	return appoints;
}

int Doctor::getID() const {
	return id;
}

void Doctor::setName(std::string name) {
	this->name = name;
	return;
}

void Doctor::setSpec(std::string spec) {
	speciality = spec;
	return;
}

void Doctor::setOffice(std::string office) {
	this->office = office;
	return;
}

void Doctor::setAppoint(Appoint* appoint) {
	appoints.push_back(appoint);
}
void Doctor::setID(int id) {
	this->id = id;
	return;
}

bool Doctor::hasNoAppoints() {
	if (appoints.empty())
		return true;
	else
		return false;
}

void Doctor::writeAppoints() {
	int i = 1;
	if (appoints.empty())
		return;
	for (const auto& appoint : appoints) {
		std::cout << i++ << ") ";
		std::cout << appoint->getDate() << ' ';
		std::cout << appoint->getTime() << '\n';
	}
	return;
}

bool Doctor::hasPatient(int num) {
	if (appoints[num]->hasPatient())
		return true;
	return false;
}

void Doctor::setPatient(int num, int patID) {
	if (appoints[num]->hasPatient())
		return;
	appoints[num]->setPatID(patID);
	return;
}

void Doctor::deleteAppoint(std::vector<Appoint>& appoints, int num) {
	if (!this->appoints[num])
		return;
	Appoint* ptr = this->appoints[num];
	auto target = std::find_if(appoints.begin(), appoints.end(), [ptr](const Appoint& appoint) {
		return &appoint == ptr;
		});
	if (target != appoints.end())
		appoints.erase(target);
	return;
}