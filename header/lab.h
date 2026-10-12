#pragma once
#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <optional>
#include <sstream>
#include <chrono>

class Patient;
class Doctor;
class Appoint;

void mainMenu(std::vector<Patient>&, std::vector<Doctor>&, std::vector<Appoint>&);
void patientMenu(std::vector<Doctor>&);
void doctorMenu(std::vector<Patient>&, std::vector<Appoint>&);
void adminMenu(std::vector<Patient>&, std::vector<Doctor>&, std::vector<Appoint>&);
void doctorsManagement(std::vector<Doctor>&, std::vector<Patient>&, std::vector<Appoint>&);
void patientsManagement(std::vector<Patient>&, std::vector<Appoint>&);
void printPatients(const std::vector<Patient>&);
void printDoctors(const std::vector<Doctor>&);
bool dateisValid(std::string&);
bool timeisValid(std::string&);
void write1(const Patient&);
void write1(const Doctor&);
void enter1(Patient&);
void enter1(Doctor&);
void enter(Patient&);
void enter(Doctor&);
void docAppointManagement(Doctor&, std::vector<Patient>&, std::vector<Appoint>&);
Appoint addAppoint(Doctor&);
bool patientExist(std::vector<Patient>&, int);