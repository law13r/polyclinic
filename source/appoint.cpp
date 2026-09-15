#include "appoint.h"

Appoint::Appoint(int doctor, int patient, struct date day, int hour, int minute) {
	this->doctor = doctor;
	this->patient = patient;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
}

Appoint::~Appoint() {
	std::cout << "Запись удалена." << std::endl;
}