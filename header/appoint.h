#include "lab.h"

class Appoint {
private:
	struct date day;
	int hour;
	int minute;
	int pat;
	int doc;
public:
	Appoint(int, int, struct date, int, int);
	~Appoint();
};