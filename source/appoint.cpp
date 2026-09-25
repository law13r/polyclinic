#include "appoint.h"

Appoint::Appoint(int doc, int pat, struct date day, int hr, int mt) {
	this->doc = doc;
	this->pat = pat;
	this->day = day;
	this->hr = hr;
	this->mt = mt;
}

Appoint::~Appoint() {
	std::cout << "Запись удалена." << std::endl;
}