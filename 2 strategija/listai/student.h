#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <list>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <random>
#include <ctime>
#include <chrono>


 using namespace std;

struct Student {
    string name, vardas;
    string sur, pavarde;
    double final_avg;
    double median;
    list<int> grades;
    double exam_results;
    list<int> pazymiai;
    double egzaminoRezultatas;
    double gal_vid;
    double gal_med;

};

void generateRandomGrades(list<Student>& students, double hw);
void generateRandomData(list<Student>& students, double hw);
double calculateMedian(list<int>& arr);
void readDataFromFile(list<Student>& students, double& hw, int N);
void enterDataManually(list<Student>& students, double hw);
bool compareByName(const Student& a, const Student& b);
bool compareBySurname(const Student& a, const Student& b);
bool compareByMedian(const Student& a, const Student& b);
bool compareByAvg(const Student& a, const Student& b);
int generateRandomNumber(int min, int max);
double calculateAverage(const list<int>& pazymiai);
void failuGeneravimas(int studentu_kiekis, const string& failo_pavadinimas);
bool Nuskaitymas(const string& failo_pavadinimas, list<Student>& students, int studentukiekis);
chrono::steady_clock::time_point DabartinisLaikas();
double LaikoSkirtumas(const chrono::steady_clock::time_point& pradzia, const chrono::steady_clock::time_point& pabaiga);
void calculateResults(list<Student>& stud);
void rūšiuoja_ir_rašo_failus(std::list<Student>& students);
double skaiciuotiVidurki(const list<int>& pazymiai);
bool arGerasStudentas(const Student& student);
bool lygintiPagalVidurki(const Student& a, const Student& b);

#endif // STUDENT_H
