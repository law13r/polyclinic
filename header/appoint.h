#include "lab.h"

class Appoint {
private:
	struct date day;
	int hour;
	int minute;
	int patient;
	int doctor;
public:
	Appoint(int, int, struct date, int, int);
	Appoint(const Appoint&) = default;
	Appoint& operator=(const Appoint&) = default;
	Appoint& operator=(Appoint&&) noexcept = default;
	Appoint(Appoint&&) noexcept = default;
	~Appoint();
};