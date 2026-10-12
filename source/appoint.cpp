#include "appoint.h"

Appoint::Appoint(int docID, int patID, const std::string& date, const std::string& time) : date(date), time(time), docID(docID), patID(patID) {
}

Appoint::Appoint(int docID, const std::string& date, const std::string& time) : date(date), time(time), docID(docID) {
}

Appoint::Appoint(int docID) : date("default"), time("default"), docID(docID) {
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

void Appoint::setDocID(const int& id) {
	docID = id;
	return;
}

void Appoint::setPatID(const int& id) {
	patID = id;
	return;
}

void Appoint::setDate(std::string_view nDate) {
	date = nDate;
	return;
}

void Appoint::setTime(std::string_view nTime) {
	time = nTime;
	return;
}

bool Appoint::hasPatient() const {
	if (patID.has_value())
		return true;
	return false;
}