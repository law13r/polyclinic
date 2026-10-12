#include "appoint.h"

Appoint::Appoint(int docID, int patID, std::string date, std::string time) : date(date), time(time), docID(docID), patID(patID) {
}

Appoint::Appoint(int docID, std::string date, std::string time) : date(date), time(time), docID(docID) {
}

Appoint::Appoint(int docID) : docID(docID) {
	date = "default";
	time = "default";
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

void Appoint::setDate(std::string date) {
	this->date = date;
	return;
}

void Appoint::setTime(std::string time) {
	this->time = time;
	return;
}

bool Appoint::hasPatient() {
	if (patID)
		return true;
	return false;
}