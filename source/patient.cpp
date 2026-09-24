#include "patient.h"

Patient::Patient(int id, std::string name, struct date doB, long long phone) {
	this->id = id;
	this->name = name;
	this->doB = doB;
	this->phone = phone;
}

Patient::Patient(int id) {
	this->id = id++;
	name = "default";
	doB.day = 1;
	doB.month = 1;
	doB.year = 1900;
	phone = 80000000000;
	set();
}

void Patient::get() const {
	std::cout << "Имя пациента: " << name << "\tДата рождения: " << doB.day << "." << doB.month << "." << doB.year << std::endl;
	std::cout << "Номер телефона: " << phone << std::endl;
	return;
}

void Patient::get1() const {
	int choice;
	std::cout << "Какую характеристику вывести?" << std::endl;
	std::cout << "1 - вывести имя" << std::endl;
	std::cout << "2 - вывести дату рождения" << std::endl;
	std::cout << "3 - вывести номер телефона" << std::endl;
	std::cout << "4 - отменить" << std::endl;
	do {
		std::cin >> choice;
	} while (choice < 1 || choice > 4);
	switch (choice) {
	case 1:
		std::cout << "Имя пациента: " << name << std::endl;
		break;
	case 2:
		std::cout << "Дата рождения пациента: " << doB.day << "." << doB.month << "." << doB.year << std::endl;
		break;
	case 3:
		std::cout << "Номер телефона: " << phone << std::endl;
		break;
	case 4:
		return;
	}
	return;
}

void Patient::set() {
	std::cout << "Введите ФИО пациента: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "Введите дату рождения пациента (дд мм гггг): ";
	std::cin >> doB.day;
	std::cin >> doB.month;
	std::cin >> doB.year;
	std::cout << "Введите номер телефона пациента в формате 8XXXXXXXXXX: ";
	std::cin >> phone;
}

void Patient::set1() {
	int choice;
	std::cout << "Какую характеристику ввести?" << std::endl;
	std::cout << "1 - ввести имя" << std::endl;
	std::cout << "2 - ввести дату рождения" << std::endl;
	std::cout << "3 - ввести номер телефона" << std::endl;
	std::cout << "4 - отменить" << std::endl;
	do {
		std::cin >> choice;
	} while (choice < 1 || choice > 4);
	switch (choice) {
	case 1:
		std::cout << "Введите ФИО пациента: ";
		std::cin.ignore();
		std::getline(std::cin, name);
		break;
	case 2:
		std::cout << "Введите дату рождения пациента (дд мм гггг): ";
		std::cin >> doB.day;
		std::cin >> doB.month;
		std::cin >> doB.year;
		break;
	case 3:
		std::cout << "Введите номер телефона пациента в формате 8XXXXXXXXXX: ";
		std::cin >> phone;
		break;
	case 4:
		return;
	}
	return;
}

Patient::~Patient() {
	std::cout << "Пациент " << this->id << " удален." << std::endl;
}