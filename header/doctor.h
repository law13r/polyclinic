#include "lab.h"

class Doctor {
private:
	int id;
	std::string name;
	std::string speciality;
	std::string office;
public:
	Doctor(int);
	void get();
	void get1();
	void set();
	void set1();
	~Doctor();
};