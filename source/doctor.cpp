#include "doctor.h"

Doctor::Doctor(int id) : id(id){
	set();
}

void Doctor::get() const {
	std::cout << "Имя врача: " << name << "\tСпециальность: " << speciality << std::endl;
	std::cout << "Кабинет " << office << std::endl;
	return;
}

void Doctor::get1() const {
	int choice;
	std::cout << "Какую характеристику вывести?" << std::endl;
	std::cout << "1 - вывести имя" << std::endl;
	std::cout << "2 - вывести специальность" << std::endl;
	std::cout << "3 - вывести кабинет" << std::endl;
	std::cout << "4 - отменить" << std::endl;
	std::cin >> choice;
	switch (choice) {
	case 1:
		std::cout << "Имя врача: " << name << std::endl;
		break;
	case 2:
		std::cout << "Специальность врача: " << speciality << std::endl;
		break;
	case 3:
		std::cout << "Кабинет врача: " << office << std::endl;
		break;
	case 4:
		return;
	default:
		break;
	}
	return;
}

void Doctor::set() {
	std::cout << "Введите ФИО врача: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "Введите специальность врача: ";
	std::cin >> speciality;
	std::cout << "Введите номер кабинета: ";
	std::cin >> office;
}

void Doctor::set1() {
	int choice;
	std::cout << "Какую характеристику ввести?" << std::endl;
	std::cout << "1 - ввести имя" << std::endl;
	std::cout << "2 - ввести специальность" << std::endl;
	std::cout << "3 - ввести кабинет" << std::endl;
	std::cout << "4 - отменить" << std::endl;
	do {
		std::cin >> choice;
	} while (choice < 1 || choice > 4);
	switch (choice) {
	case 1:
		std::cout << "Введите ФИО врача: ";
		std::cin.ignore();
		std::getline(std::cin, name);
		break;
	case 2:
		std::cout << "Введите специальность врача: ";
		std::cin >> speciality;
		break;
	case 3:
		std::cout << "Введите номер кабинета: ";
		std::cin >> office;
		break;
	case 4:
		return;
	default:
		break;
	}
	return;
}

Doctor::~Doctor() {
	std::cout << "Врач " << this->id << " удален." << std::endl;
}