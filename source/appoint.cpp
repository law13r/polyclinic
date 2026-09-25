#include "appoint.h"

Appoint::Appoint(int doc, int pat, struct date day, int hour, int minute) {
	this->doc = doc;
	this->pat = pat;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
}

Appoint::~Appoint() {
	std::cout << "Запись удалена." << std::endl;
}