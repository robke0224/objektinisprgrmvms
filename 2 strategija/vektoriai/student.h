#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
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
    vector<int> grades;
    int exam_results;
    vector<int> pazymiai;
    double egzaminoRezultatas;
    double gal_vid;
    double gal_med;

};

void generateRandomGrades (vector<Student>& students, double hw);
void generateRandomData (vector<Student>& students, double hw);
double calculateMedian (vector<int>& arr);
void readDataFromFile (vector<Student>& students, double& hw, int N);
void enterDataManually (vector<Student>& students, double hw);
bool compareByName(const Student& a, const Student& b);
bool compareBySurname(const Student& a, const Student& b);
bool compareByMedian(const Student& a, const Student& b);
bool compareByAvg(const Student& a, const Student& b);
int generateRandomNumber(int min, int max);
double calculateAverage(const vector<int>& pazymiai);
void failuGeneravimas(int studentu_kiekis, const std::string& failo_pavadinimas);
bool Nuskaitymas(const std::string& failo_pavadinimas, std::vector<Student>& students, int studentukiekis);
std::chrono::steady_clock::time_point DabartinisLaikas();
double LaikoSkirtumas(const std::chrono::steady_clock::time_point& pradzia, const std::chrono::steady_clock::time_point& pabaiga);
void calculateResults(std::vector<Student>& stud);
void rūšiuoja_ir_rašo_failus(std::vector<Student>& students); 
double skaiciuotiVidurki(const std::vector<int>& pazymiai);
bool arGerasStudentas(const Student& student);
bool lygintiPagalVidurki(const Student& a, const Student& b);


#endif
