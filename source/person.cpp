#include "lab.h"
#include "person.h"
#include "appoint.h"

Person::Person(int id, std::string_view name, std::string_view phone, const std::vector<std::shared_ptr<Appoint>>& appoints) : id(id), name(name), phone(phone), appoints(appoints) {}

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

std::vector<std::shared_ptr<Appoint>> Person::getAppoints() const {
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

void Person::setAppoints(std::vector<std::shared_ptr<Appoint>>& appointsNew) {
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
	for (int i = 0; i < appoints.size(); ++i)
		std::cout << i + 1 << ") " << *appoints[i] << '\n';
	return;
}

void Person::delAppoint(std::vector<std::shared_ptr<Appoint>>& list, int num) {
	if (num < 0 || num >= static_cast<int>(appoints.size()))
		return;
	auto target = appoints[num];
	appoints.erase(appoints.begin() + num);
	if (auto it = std::ranges::find(list, target); it != list.end())
		list.erase(it);
	return;
}

Person& Person::operator+=(std::shared_ptr<Appoint> appoint) {
	if (appoint == nullptr)
		return *this;
	appoints.push_back(appoint);
	return *this;
}

Person& Person::operator-=(std::shared_ptr<Appoint> appoint) {
	if (std::ranges::find(appoints, appoint) != appoints.end())
		std::erase(appoints, appoint);
	return *this;
}