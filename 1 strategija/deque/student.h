#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <deque>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <random>
#include <ctime>

using namespace std;

struct Student {
    string name;
    string sur;
    double final_avg;
    double median;
    deque<int> grades; // Changed vector to deque
    int exam_results;
    deque<int> pazymiai; // Changed vector to deque
    double egzaminoRezultatas;
    double gal_vid;
    double gal_med;

};

void generateRandomGrades(deque<Student>& students, double hw); // Changed vector to deque
void generateRandomData(deque<Student>& students, double hw); // Changed vector to deque
double calculateMedian(deque<int>& arr); // Changed vector to deque
void readDataFromFile(deque<Student>& students, double& hw, int N); // Changed vector to deque
void enterDataManually(deque<Student>& students, double hw); // Changed vector to deque
bool compareByName(const Student& a, const Student& b);
bool compareBySurname(const Student& a, const Student& b);
bool compareByMedian(const Student& a, const Student& b);
bool compareByAvg(const Student& a, const Student& b);
int generateRandomNumber(int min, int max);
double calculateAverage(const deque<int>& pazymiai); // Changed vector to deque
void failuGeneravimas(int studentu_kiekis, const std::string& failo_pavadinimas);
bool Nuskaitymas(const std::string& failo_pavadinimas, std::deque<Student>& students, int studentukiekis); // Changed vector to deque
std::chrono::steady_clock::time_point DabartinisLaikas();
double LaikoSkirtumas(const std::chrono::steady_clock::time_point& pradzia, const std::chrono::steady_clock::time_point& pabaiga);
void calculateResults(std::deque<Student>& stud); // Changed vector to deque
void rūšiuoja_ir_rašo_failus(const std::deque<Student>& students); // Changed vector to deque
double skaiciuotiVidurki(const std::deque<int>& pazymiai); // Changed vector to deque
bool arGerasStudentas(const Student& student);
bool lygintiPagalVidurki(const Student& a, const Student& b);

#endif
