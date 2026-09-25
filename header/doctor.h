#include "lab.h"

class Doctor {
private:
	int id;
	std::string name;
	std::string speciality;
	std::string office;
public:
	explicit Doctor(int);
	void get() const;
	void get1() const;
	void set();
	void set1();
};