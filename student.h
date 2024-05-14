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

class Student {
private:
    vector<int> grades;
    vector<int> pazymiai;
    string name;
    string sur;
    int exam_results;
    double egzaminoRezultatas;
    double gal_vid;
    double gal_med;

public:
    Student() {}
    ~Student() {}

    void setName(const string& vardas) {
        name = vardas;
    }

    string getName() const {
        return name;
    }

    void setSurname(const string& pavarde) {
        sur = pavarde;
    }

    string getSurname() const {
        return sur;
    }

    void setExamResult(int egzaminas) {
        exam_results = egzaminas;
    }

    int getExamResult() const {
        return exam_results;
    }

    void setFinalAvg(double Gal_vid) {
        gal_vid = Gal_vid;
    }

    double getFinalAvg() const {
        return gal_vid;
    }

    void setFinalMedian(double Gal_med) {
        gal_med = Gal_med;
    }

    double getFinalMedian() const {
        return gal_med;
    }

    void setSingleGrade(int naujasnd) {
        pazymiai.push_back(naujasnd);
    }

    int getSingleGrade(const vector<int>& ND, int i) const {
        return pazymiai[i];
    }

    void setGrades(const vector<int>& ND) {
        pazymiai = ND;
    }

    vector<int> getGrades() const {
        return pazymiai;
    }

    void clearData() {
        grades.clear();
        pazymiai.clear();
        name.clear();
        sur.clear();
        exam_results = 0;
        egzaminoRezultatas = 0.0;
        gal_vid = 0.0;
        gal_med = 0.0;
    }
};

void generateRandomGrades(vector<Student>& students, double hw);
void generateRandomData(vector<Student>& students, double hw);
double calculateMedian(vector<int>& arr);
void readDataFromFile(vector<Student>& students, double& hw, int N);
void enterDataManually(vector<Student>& students, double hw);
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
double skaiciuotiVidurki(const std::vector<int>& pazymiai);
bool arGerasStudentas(const Student& student);
bool lygintiPagalVidurki(const Student& a, const Student& b);
void rūšiuoja_ir_rašo_failus(std::vector<Student>& students);




#endif
