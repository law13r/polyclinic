#pragma once
#include "lab.h"

class IncomparableAppointmentsException : public std::runtime_error {
public:
	using std::runtime_error::runtime_error;
};