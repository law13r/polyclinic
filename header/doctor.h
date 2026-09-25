#include "lab.h"

class Doctor {
private:
	int id;
	std::string name;
	std::string speciality;
	std::string office;
public:
	explicit Doctor(int);
	Doctor(const Doctor&) = default;
	Doctor(Doctor&&) noexcept = default;
	Doctor& operator=(const Doctor&) = default;
	Doctor& operator=(Doctor&&) noexcept = default;
	void get() const;
	void get1() const;
	void set();
	void set1();
	~Doctor();
};