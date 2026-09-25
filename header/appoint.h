#include "lab.h"

class Appoint {
private:
	struct date day;
	int hr;
	int mt;
	int pat;
	int doc;
public:
	Appoint(int, int, struct date, int, int);
	~Appoint();
};