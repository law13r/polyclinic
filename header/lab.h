#pragma once
#include <iostream>
#include <string>
#include <locale>
#include <windows.h>
#include <vector>

class Patient;
class Doctor;
class Appoint;

void mainMenu();
void patientMenu();
void doctorMenu();
void adminMenu(std::vector<Patient>&, std::vector<Doctor>&, std::vector<Appoint>&);
void printPatients(std::vector<Patient>&);
void printDoctors(std::vector<Doctor>&);

struct date {
	int day;
	int month;
	int year;
};