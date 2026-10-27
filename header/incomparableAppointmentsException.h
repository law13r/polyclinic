#pragma once
#include "lab.h"

class IncomparableAppointmentsException : public std::runtime_error {
public:
	IncomparableAppointmentsException() : std::runtime_error("Nothing to compare\n") {}
	explicit IncomparableAppointmentsException(const std::string& message) : std::runtime_error(message) {}
};