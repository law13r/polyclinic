#include "appoint.h"

Appoint::Appoint(int doctor, int patient, struct date day, int hour, int minute) : doctor(doctor), patient(patient), day(day), hour(hour), minute(minute) {

}

Appoint::~Appoint() {
	std::cout << "Запись удалена." << std::endl;
}