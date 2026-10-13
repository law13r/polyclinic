#include "lab.h"
#include "patient.h"
#include "doctor.h"
#include "appoint.h"

int main() {
	std::vector patients = {
			Patient(0, "Mongol Oleg Vitalievich", "12.2.2009", "80293336769"),
			Patient(1, "Zhmyshenko Valerii Albertovich", "4.5.1945", "80331422888"),
			Patient(2, "Tsal Vitalii Olegovich", "19.11.1991", "80447773456")
	};
	std::vector doctors = {
			Doctor(0, "Kupitman Ivan Natanovich", "venereologist", "69", "80442282828"),
			Doctor(1, "Bykov Andrei Evgenievich", "therapist", "67",  "80298870994"),
			Doctor(2, "Lobanov Semyon Semyonovich", "therapist", "42", "80333333333")
	};
	std::vector<Appoint> appoints;
	mainMenu(patients, doctors, appoints);
	return 0;
}