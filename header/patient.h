#include "lab.h"

class Patient {
private:
	int id;
	std::string name;
	struct date doB;
	long long phone;
public:
	Patient(int, std::string, struct date, long long);
	Patient(int);
	void get();
	void get1();
	void set();
	void set1();
	~Patient();
};