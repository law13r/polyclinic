#include "lab.h"

class Patient {
private:
	int id;
	std::string name;
	struct date doB;
	long long phone;
public:
	Patient(int, const std::string&, struct date, long long);
	explicit Patient(int);
	void get() const;
	void get1() const;
	void set();
	void set1();
};