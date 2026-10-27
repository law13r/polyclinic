#pragma once
#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <optional>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <memory>

class Appoint;
class Person;
class Doctor;
class Nurse;
class Patient;

void mainMenu(std::vector<std::shared_ptr<Patient>>&, std::vector<std::shared_ptr<Doctor>>&, std::vector<std::shared_ptr<Appoint>>&);
void patientMenu();
void doctorMenu();
void adminMenu(std::vector<std::shared_ptr<Patient>>&, std::vector<std::shared_ptr<Doctor>>&, std::vector<std::shared_ptr<Appoint>>&);
void doctorsManagement(std::vector<std::shared_ptr<Doctor>>&, std::vector<std::shared_ptr<Patient>>&, std::vector<std::shared_ptr<Appoint>>&);
void patientsManagement(std::vector<std::shared_ptr<Patient>>&);
void printPatients(const std::vector<std::shared_ptr<Patient>>&);
void printDoctors(const std::vector<std::shared_ptr<Doctor>>&);
bool dateisValid(const std::string&);
bool timeisValid(const std::string&);
void write1(const std::shared_ptr<Patient>&);
void write1(const std::shared_ptr<Doctor>&);
void enter1(std::shared_ptr<Patient>&);
void enter1(const std::shared_ptr<Doctor>&);
void enter(std::shared_ptr<Patient>&);
void enter(const std::shared_ptr<Doctor>&);
void docAppointManagement(std::shared_ptr<Doctor>&, std::vector<std::shared_ptr<Patient>>&, std::vector<std::shared_ptr<Appoint>>&);
Appoint addAppoint(std::shared_ptr<Doctor>&);
bool patientExist(std::vector<std::shared_ptr<Patient>>&, int);
std::shared_ptr<Patient> findPatient(std::vector<std::shared_ptr<Patient>>&, int);
bool phoneisValid(std::string_view);
bool appointsOverlap(std::shared_ptr<Appoint>&, std::vector<std::shared_ptr<Appoint>>&);