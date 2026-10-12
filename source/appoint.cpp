#include "appoint.h"

Appoint::Appoint(int docID, int patID, const std::string& date, const std::string& time) : date(date), time(time), docID(docID), patID(patID) {
}

Appoint::Appoint(int docID, const std::string& date, const std::string& time) : date(date), time(time), docID(docID) {
}

Appoint::Appoint(int docID) : docID(docID), date("default"), time("default") {
	return;
}

int Appoint::getDocID() const {
	return docID;
}

std::optional<int> Appoint::getPatID() const {
	return patID;
}

std::string Appoint::getDate() const {
	return date;
}

std::string Appoint::getTime() const {
	return time;
}

void Appoint::setDocID(int id) {
	docID = id;
	return;
}

void Appoint::setPatID(int id) {
	patID = id;
	return;
}

void Appoint::setDate(const std::string date) {
	this->date = date;
	return;
}

void Appoint::setTime(const std::string time) {
	this->time = time;
	return;
}

bool Appoint::hasPatient() const {
	if (patID.has_value())
		return true;
	return false;
}