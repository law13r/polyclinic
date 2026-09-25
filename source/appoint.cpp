#include "appoint.h"

Appoint::Appoint(int doctor, int patient, struct date day, int hour, int minute) : day(day), hour(hour), minute(minute), patient(patient), doctor(doctor) {

}

Appoint::~Appoint() {
	std::cout << "Запись удалена." << std::endl;
}