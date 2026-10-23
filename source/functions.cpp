#include "lab.h"
#include "patient.h"
#include "doctor.h"
#include "appoint.h"

void mainMenu(std::vector<std::shared_ptr<Patient>>& patients, std::vector<std::shared_ptr<Doctor>>& doctors, std::vector<std::shared_ptr<Appoint>>& appoints) {
	int choice;
	while (true) {
		std::cout << "\t\tPolyclinic\n1 - sign in as patient\n2 - sign in as doctor\n3 - sign in as admin\n4 - quit program\n";
		std::cin >> choice;
		switch (choice) {
		case 1:
			patientMenu();
			break;
		case 2:
			doctorMenu();
			break;
		case 3:
			adminMenu(patients, doctors, appoints);
			break;
		case 4:
			return;
		default:
			break;
		}
	}
}

void patientMenu() {
	std::cout << "In progress..." << '\n';
}

void doctorMenu() {
	std::cout << "In progress..." << '\n';
}

void adminMenu(std::vector<std::shared_ptr<Patient>> &patients, std::vector<std::shared_ptr<Doctor>> &doctors, std::vector<std::shared_ptr<Appoint>> &appoints) {
	int choice;
	while (true) {
		std::cout << "\t\tAdmin menu\n1 - display doctors list\n2 - display patients list\n3 - cancel\n";
		std::cin >> choice;
		switch (choice) {
		case 1:
			doctorsManagement(doctors, patients, appoints);
			break;
		case 2:
			patientsManagement(patients);
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}
void doctorsManagement(std::vector<std::shared_ptr<Doctor>>& doctors, std::vector<std::shared_ptr<Patient>>& patients, std::vector<std::shared_ptr<Appoint>>& appoints) {
	int choice;
	int choice1;
	int index;
	auto docID = static_cast<int>(doctors.size());
	printDoctors(doctors);
	std::cout << "1 - create new object\n2 - edit existing object\n3 - delete object\n4 - show appointments to doctor\n5 - cancel\n";
	std::cin >> choice;
	switch (choice) {
	case 1: {
		auto docNew = std::make_shared<Doctor>(docID++);
		doctors.push_back(docNew);
		break;
	}
	case 2:
		do {
			std::cout << "Enter object number from the list: ";
			std::cin >> index;
		} while (index < 1 || index > static_cast<int>(doctors.size()));
		index--;
		do {
			std::cout << "Enter the whole profile or a single characteristic?\n1 - whole profile\n2 - single characteristic\n";
			std::cin >> choice1;
		} while (choice1 < 1 || choice1 > 2);
		if (choice1 == 1)
			enter(doctors[index]);
		else
			enter1(doctors[index]);
		break;
	case 3:
		do {
			std::cout << "Enter object number from the list: ";
			std::cin >> index;
		} while (index < 1 || index > static_cast<int>(doctors.size()));
		doctors.erase(doctors.begin() + --index);
		break;
	case 4:
		do {
			std::cout << "Enter object number from the list: ";
			std::cin >> index;
		} while (index < 1 || index > static_cast<int>(doctors.size()));
		docAppointManagement(doctors[index], patients, appoints);
		break;
	case 5:
		break;
	default:
		break;
	}
}

void patientsManagement(std::vector<std::shared_ptr<Patient>>& patients) {
	int choice;
	int choice1;
	int index;
	auto patID = static_cast<int>(patients.size());
	printPatients(patients);
	std::cout << "1 - create new object\n2 - edit existing object\n3 - delete object\n4 - cancel\n";
	do {
		std::cin >> choice;
	} while (choice < 1 || choice > 4);
	switch (choice) {
	case 1: {
		auto patNew = std::make_shared<Patient>(patID++);
		patients.push_back(patNew);
		break;
	}
	case 2:
		do {
			std::cout << "Enter object number from the list: ";
			std::cin >> index;
		} while (index < 1 || index > static_cast<int>(patients.size()));
		index--;
		do {
			std::cout << "Enter the whole profile or a single characteristic?\n1 - whole profile\n2 - single characteristic\n";
			std::cin >> choice1;
		} while (choice1 < 1 || choice1 > 2);
		if (choice1 == 1)
			enter(patients[index]);
		else
			enter1(patients[index]);
		break;
	case 3:
		do {
			std::cout << "Enter object number from the list: ";
			std::cin >> index;
		} while (index < 1 || index > static_cast<int>(patients.size()));
		patients.erase(patients.begin() + --index);
		break;
	case 4:
		break;
	default:
		break;
	}
}

void printPatients(const std::vector<std::shared_ptr<Patient>>& patients) {
	int i = 0;
	if (patients.empty()) {
		std::cout << "List is empty..." << '\n';
	}
	else {
		for (; i < patients.size(); i++) {
			std::cout << i + 1 << ". ";
			std::cout << "Patient name: " << patients[i]->getName() << '\n';
			std::cout << "Date of birth: " << patients[i]->getDoB() << '\n';
			std::cout << "Phone number: " << patients[i]->getPhone() << '\n';
		}
	}
	return;
}

void printDoctors(const std::vector<std::shared_ptr<Doctor>>& doctors) {
	int i = 0;
	if (doctors.empty()) {
		std::cout << "List is empty..." << '\n';
	}
	else {
		for (; i < doctors.size(); i++) {
			std::cout << i + 1 << ". ";
			std::cout << "Doctor name: " << doctors[i]->getName() << '\n';
			std::cout << "Speciality: " << doctors[i]->getSpec() << '\n';
			std::cout << "Office " << doctors[i]->getOffice() << '\n';
		}
	}
	return;
}

bool dateisValid(const std::string& date) {
	std::istringstream str{ date };
	std::chrono::year_month_day ymd;
	str >> std::chrono::parse("%d.%m.%Y", ymd);
	return !str.fail() && str.eof() && ymd.ok();
}

bool timeisValid(const std::string& time) {
	std::istringstream str{ time };
	int h = 0;
	int m = 0;
	if (char c = 0; str >> h >> c >> m && c == ':' && str.eof())
		return h >= 0 && h < 24 && m >= 0 && m < 60;
	return false;
}

void write1(const std::shared_ptr<Patient>& patient) {
	int choice;
	std::cout << "Which characteristic to display?" << '\n';
	std::cout << "1 - display name" << '\n';
	std::cout << "2 - display date of birth" << '\n';
	std::cout << "3 - display phone number" << '\n';
	std::cout << "4 - cancel" << '\n';
	std::cin >> choice;
	switch (choice) {
	case 1:
		std::cout << "Patient name: " << patient->getName() << '\n';
		break;
	case 2:
		std::cout << "Date of birth: " << patient->getDoB() << '\n';
		break;
	case 3:
		std::cout << "Phone number: " << patient->getPhone() << '\n';
		break;
	case 4:
		return;
	default:
		break;
	}
	return;
}

void write1(const std::shared_ptr<Doctor>& doctor) {
	int choice;
	std::cout << "Which characteristic to display?" << '\n';
	std::cout << "1 - display name" << '\n';
	std::cout << "2 - display speciality" << '\n';
	std::cout << "3 - display office" << '\n';
	std::cout << "4 - cancel" << '\n';
	std::cin >> choice;
	switch (choice) {
	case 1:
		std::cout << "Doctor name: " << doctor->getName() << '\n';
		break;
	case 2:
		std::cout << "Speciality: " << doctor->getSpec() << '\n';
		break;
	case 3:
		std::cout << "Office " << doctor->getOffice() << '\n';
		break;
	case 4:
		return;
	default:
		break;
	}
	return;
}

void enter1(std::shared_ptr<Patient>& patient) {
	int choice;
	std::string name;
	std::string date;
	std::string phone;
	std::cout << "Which characteristic to enter?" << '\n';
	std::cout << "1 - enter name" << '\n';
	std::cout << "2 - enter date of birth" << '\n';
	std::cout << "3 - enter phone number" << '\n';
	std::cout << "4 - cancel" << '\n';
	std::cin >> choice;
	switch (choice) {
	case 1:
		std::cout << "Enter patient name: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, name);
		patient->setName(name);
		break;
	case 2:
		do {
			std::cout << "Enter date of birth (dd.mm.yyyy): ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, date);
		} while (!dateisValid(date));
		patient->setDoB(date);
		break;
	case 3:
		do {
			std::cout << "Entere phone number (8XXXXXXXXXX): ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, phone);
		} while (!phoneisValid(phone));
		patient->setPhone(phone);
		break;
	case 4:
		return;
	default:
		break;
	}
	return;
}

void enter1(const std::shared_ptr<Doctor>& doctor) {
	int choice;
	std::string buffer;
	std::cout << "Which characteristic to enter?" << '\n';
	std::cout << "1 - enter name" << '\n';
	std::cout << "2 - enter speciality" << '\n';
	std::cout << "3 - enter office" << '\n';
	std::cout << "4 - cancel" << '\n';
	do {
		std::cin >> choice;
	} while (choice < 1 || choice > 4);
	switch (choice) {
	case 1:
		std::cout << "Enter doctor name: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, buffer);
		doctor->setName(buffer);
		break;
	case 2:
		std::cout << "Enter speciality: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, buffer);
		doctor->setSpec(buffer);
		break;
	case 3:
		std::cout << "Enter office: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, buffer);
		doctor->setOffice(buffer);
		break;
	case 4:
		return;
	default:
		break;
	}
	return;
}

void enter(std::shared_ptr<Patient>& patient) {
	std::string name;
	std::string date;
	std::string phone;
	std::cout << "Enter patient name: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, name);
	patient->setName(name);
	do {
		std::cout << "Enter date of birth (dd.mm.yyyy): ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, date);
	} while (!dateisValid(date));
	patient->setDoB(date);
	do {
		std::cout << "Enter phone number (8XXXXXXXXXX): ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, phone);
	} while (!phoneisValid(phone));
	patient->setPhone(phone);
	return;
}

void enter(const std::shared_ptr<Doctor>& doctor) {
	std::string buffer;
	std::cout << "Enter doctor name: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, buffer);
	doctor->setName(buffer);
	std::cout << "Enter speciality: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, buffer);
	doctor->setSpec(buffer);
	std::cout << "Enter office: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, buffer);
	doctor->setOffice(buffer);
}

void docAppointManagement(std::shared_ptr<Doctor>& doctor, std::vector<std::shared_ptr<Patient>>& patients, std::vector<std::shared_ptr<Appoint>>& appoints) {
	if (!doctor) return;
	int choice;
	int num;
	int patID;
	while (true) {
		if (doctor->hasNoAppoints())
			std::cout << "This doctor does not have appointments." << '\n';
		else
			doctor->writeAppoints();
		std::cout << "1 - add appointment\n2 - add patient to appointment\n3 - delete appointment\n4 - cancel\n";
		std::cin >> choice;
		switch (choice) {
		case 1: {
			auto newAppoint = std::make_shared<Appoint>(addAppoint(doctor));
			appoints.push_back(newAppoint);
			*doctor += newAppoint;
			break;
		}
		case 2:
			do {
				std::cout << "Enter number of the appointment from the list: ";
				std::cin >> num;
			} while (num < 1 || num >= appoints.size());
			num--;
			if (doctor->hasPatient(num)) {
				std::cout << "This appointment is occupied.\n";
				break;
			}
			do {
				std::cout << "Enter patient ID: ";
				std::cin >> patID;
			} while (!patientExist(patients, patID));
			if (auto patientPtr = findPatient(patients, patID))
				doctor->setPatient(num, patientPtr);
			else
				std::cout << "Unexpected error: user with such ID does not exist.\n";
			break;
		case 3:
			do {
				std::cout << "Enter number of the appointment from the list: ";
				std::cin >> num;
			} while (num < 1 || num >= appoints.size());
			num--;
			doctor->delAppoint(appoints, num);
			break;
		case 4:
			return;
		default:
			break;
		}
	}
}

Appoint addAppoint(std::shared_ptr<Doctor>& doctor) {
	Appoint newAppoint{ doctor };
	std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');
	do {
		std::cout << "Enter date (dd.mm.yyyy) and time (hh:mm) of the appointment: ";
		std::cin >> newAppoint;
		if (std::cin.fail()) {
			std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');
			std::cin.clear();
			continue;
		}
	} while (!dateisValid(newAppoint.getDate()) || !timeisValid(newAppoint.getTime()));
	return newAppoint;
}

bool patientExist(std::vector<std::shared_ptr<Patient>>& patients, int id) {
	if (auto target = std::ranges::find_if(patients, [id](const std::shared_ptr<Patient>& patient) {
		return patient && patient->getID() == id;
		}); target != patients.end())
		return true;
	return false;
}

std::shared_ptr<Patient> findPatient(std::vector<std::shared_ptr<Patient>>& patients, int id) {
	if (auto target = std::ranges::find_if(patients, [id](const std::shared_ptr<Patient>& patient) {
		return patient && patient->getID() == id;
		}); target != patients.end())
		return *target;
	return nullptr;
}

bool phoneisValid(std::string_view phone) {
	if (phone.length() != 12)
		return false;
	if (phone[0] != '8')
		return false;
	return true;
}