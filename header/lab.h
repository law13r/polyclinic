#pragma once
#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <optional>
#include <sstream>
#include <chrono>
#include <algorithm>

class Appoint;
class Person;
class Doctor;
class Nurse;
class Patient;

void mainMenu(std::vector<Patient>&, std::vector<Doctor>&, std::vector<Appoint>&);
void patientMenu();
void doctorMenu();
void adminMenu(std::vector<Patient>&, std::vector<Doctor>&, std::vector<Appoint>&);
void doctorsManagement(std::vector<Doctor>&, std::vector<Patient>&, std::vector<Appoint>&);
void patientsManagement(std::vector<Patient>&);
void printPatients(const std::vector<Patient>&);
void printDoctors(const std::vector<Doctor>&);
bool dateisValid(const std::string&);
bool timeisValid(const std::string&);
void write1(const Patient&);
void write1(const Doctor&);
void enter1(Patient&);
void enter1(Doctor&);
void enter(Patient&);
void enter(Doctor&);
void docAppointManagement(Doctor&, std::vector<Patient>&, std::vector<Appoint>&);
Appoint addAppoint(Doctor&);
bool patientExist(std::vector<Patient>&, int);
std::optional<Patient> findPatient(std::vector<Patient>&, int);
bool phoneisValid(std::string_view);