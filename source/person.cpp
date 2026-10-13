#include "lab.h"
#include "person.h"
#include "appoint.h"

Person::Person(int id, std::string_view name, std::string_view phone, const std::vector<Appoint*>& appoints) : id(id), name(name), phone(phone), appoints(appoints) {}

Person::Person(int id, std::string_view name, std::string_view phone) : id(id), name(name), phone(phone) {}

Person::Person(int id) : id(id), name("default"), phone("default") {}

int Person::getID() const {
	return id;
}

std::string Person::getName() const {
	return name;
}

std::string Person::getPhone() const {
	return phone;
}

std::vector<Appoint*> Person::getAppoints() const {
	return appoints;
}

void Person::setID(const int& idNew) {
	id = idNew;
	return;
}

void Person::setName(std::string_view nameNew) {
	name = nameNew;
	return;
}

void Person::setPhone(std::string_view phoneNew) {
	phone = phoneNew;
	return;
}

void Person::setAppoints(std::vector<Appoint*>& appointsNew) {
	appoints = appointsNew;
	return;
}

bool Person::hasNoAppoints() const {
	if (appoints.empty())
		return true;
	return false;
}

void Person::writeAppoints() const {
	if (appoints.empty())
		return;
	int i = 1;
	for (const auto& appoint : appoints)
		std::cout << i++ << ") " << *appoint << '\n';
	return;
}

void Person::delAppoint(std::vector<Appoint>& list, const int& num) {
	if (!appoints[num])
		return;
	Appoint* ptr = appoints[num];
	if (auto target = std::ranges::find_if(list, [ptr](const Appoint& appoint) {
		return &appoint == ptr;
		});
		target != list.end())
		list.erase(target);
	*this -= ptr;
	return;
}

Person& Person::operator+=(Appoint* appoint) {
	if (appoint == nullptr)
		return *this;
	appoints.push_back(appoint);
	return *this;
}

Person& Person::operator-=(Appoint* appoint) {
	if (std::ranges::find(appoints, appoint) != appoints.end())
		std::erase(appoints, appoint);
	return *this;
}