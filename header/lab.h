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
void adminMenu(std::vector<Patient>&, std::vector<Doctor>&);
void doctorsManagement(std::vector<Doctor>&);
void patientsManagement(std::vector<Patient>&);
void printPatients(const std::vector<Patient>&);
void printDoctors(const std::vector<Doctor>&);
int correct(struct date);

struct date {
	int day;
	int month;
	int year;
};