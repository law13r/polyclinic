#include "doctor.h"
#include "appoint.h"

Doctor::Doctor(int id, const std::string& name, const std::string& speciality, const std::string& office, const std::vector<Appoint*>& appoints) : id(id), name(name), speciality(speciality), office(office), appoints(appoints) {
}

Doctor::Doctor(int id, const std::string& name, const std::string& speciality, const std::string& office) : id(id), name(name), speciality(speciality), office(office) {
}

Doctor::Doctor(int id) : id(id), name("default"), speciality("default"), office("default") {
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

void Doctor::setName(std::string_view nName) {
	name = nName;
	return;
}

void Doctor::setSpec(std::string_view spec) {
	speciality = spec;
	return;
}

void Doctor::setOffice(std::string_view nOffice) {
	office = nOffice;
	return;
}

void Doctor::setAppoint(Appoint* appoint) {
	appoints.push_back(appoint);
	return;
}

void Doctor::setID(const int& nID) {
	id = nID;
	return;
}

bool Doctor::hasNoAppoints() const {
	if (appoints.empty())
		return true;
	else
		return false;
}

void Doctor::writeAppoints() const {
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

bool Doctor::hasPatient(const int& num) {
	if (appoints[num]->hasPatient())
		return true;
	return false;
}

void Doctor::setPatient(const int& num, const int& patID) {
	if (appoints[num]->hasPatient())
		return;
	appoints[num]->setPatID(patID);
	return;
}

void Doctor::deleteAppoint(std::vector<Appoint>& list, const int& num) {
	if (!appoints[num])
		return;
	const Appoint* ptr = appoints[num];
	if (auto target = std::ranges::find_if(list, [ptr](const Appoint& appoint) {
		return &appoint == ptr;
		}); target != list.end())
		list.erase(target);
	return;
}