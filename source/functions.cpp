#include "lab.h"
#include "patient.h"
#include "doctor.h"
#include "appoint.h"

void mainMenu() {
	int choice;
	std::vector<Patient> patients;
	std::vector<Doctor> doctors;
	std::vector<Appoint> apps;
	while (1) {
		std::cout << "\t\t\tПоликлиника\n1 - вход как пациент\n2 - вход как врач\n3 - вход как админ\n4 - выход\n";
		do {
			std::cin >> choice;
		} while (choice < 1 || choice > 4);
		switch (choice) {
		case 1:
			patientMenu();
			break;
		case 2:
			doctorMenu();
			break;
		case 3:
			adminMenu(patients, doctors, apps);
			break;
		case 4:
			return;
		}
	};
}

void patientMenu() {
	std::cout << "В процессе..." << std::endl;
}

void doctorMenu() {
	std::cout << "В процессе..." << std::endl;
}

void adminMenu(std::vector<Patient> &patients, std::vector<Doctor> &doctors, std::vector<Appoint> &apps) {
	int choice;
	int choice1;
	int choice2;
	int index;
	int docID = 0;
	int patID = 0;
	while (1) {
		std::cout << "\t\t\tАдмин меню\n1 - вывести список врачей\n2 - вывести список пациентов\n3 - отменить\n";
		do {
			std::cin >> choice;
		} while (choice < 1 || choice > 3);
		switch (choice) {
		case 1:
			printDoctors(doctors);
			std::cout << "1 - создать новый объект\n2 - редактировать объект\n3 - удалить объект\n4 - отменить\n";
			do {
				std::cin >> choice1;
			} while (choice1 < 1 || choice1 > 4);
			switch (choice1) {
			case 1: {
				Doctor docNew(docID++);
				doctors.push_back(docNew);
				break;
			}
			case 2:
				std::cout << "Введите номер объекта в списке: ";
				std::cin >> index;
				index--;
				do {
					std::cout << "Ввести полный профиль или конкретную характеристику?\n1 - полный профиль\n2 - отдельную характеристику\n";
					std::cin >> choice2;
				} while (choice2 < 1 || choice2 > 2);
				if (choice2 == 1)
					doctors[index].set();
				else
					doctors[index].set1();
				break;
			case 3:
				std::cout << "Введите номер объекта в списке: ";
				std::cin >> index;
				doctors.erase(doctors.begin() + --index);
				break;
			case 4:
				break;
			}
			break;
		case 2:
			printPatients(patients);
			std::cout << "1 - создать новый объект\n2 - редактировать объект\n3 - удалить объект\n4 - отменить\n";
			do {
				std::cin >> choice1;
			} while (choice1 < 1 || choice1 > 4);
			switch (choice1) {
			case 1: {
				Patient patNew(patID++);
				patients.push_back(patNew);
				break;
			}
			case 2:
				std::cout << "Введите номер объекта в списке: ";
				std::cin >> index;
				index--;
				do {
					std::cout << "Ввести полный профиль или конкретную характеристику?\n1 - полный профиль\n2 - отдельную характеристику\n";
					std::cin >> choice2;
				} while (choice2 < 1 || choice2 > 2);
				if (choice2 == 1)
					patients[index].set();
				else
					patients[index].set1();
				break;
			case 3:
				std::cout << "Введите номер объекта в списке: ";
				std::cin >> index;
				patients.erase(patients.begin() + --index);
				break;
			case 4:
				break;
			}
			break;
		case 3:
			return;
		}
	}
}

void printPatients(std::vector<Patient>& patients) {
	int i = 0;
	if (patients.empty()) {
		std::cout << "Список пуст." << std::endl;
	}
	else {
		for (; i < patients.size(); i++) {
			std::cout << i + 1 << ". ";
			patients[i].get();
		}
	}
	return;
}

void printDoctors(std::vector<Doctor>& doctors) {
	int i = 0;
	if (doctors.empty()) {
		std::cout << "Список пуст." << std::endl;
	}
	else {
		for (; i < doctors.size(); i++) {
			std::cout << i + 1 << ". ";
			doctors[i].get();
		}
	}
	return;
}