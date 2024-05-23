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
#include <cstring>
#include <cassert>
#include <utility>


using namespace std;

class Student {
private:
    vector<int> grades;
    vector<int> pazymiai;
    string name, vardas;
    string sur, pavarde;
    int exam_results, egzaminas;
    double egzaminoRezultatas;
    double gal_vid;
    double gal_med;

public:
    // Default constructor
    Student() :
        grades(),
        pazymiai(),
        name(),
        sur(),
        exam_results(0),
        egzaminoRezultatas(0.0),
        gal_vid(0.0),
        gal_med(0.0) {}

    // Destructor
    ~Student() {
        
    }

    // Copy constructor
    Student(const Student& other) :
        grades(other.grades),
        pazymiai(other.pazymiai),
        name(other.name),
        sur(other.sur),
        exam_results(other.exam_results),
        egzaminoRezultatas(other.egzaminoRezultatas),
        gal_vid(other.gal_vid),
        gal_med(other.gal_med) {}

    // Copy assignment operator
    Student& operator=(const Student& other) {
        if (this != &other) {
            grades = other.grades;
            pazymiai = other.pazymiai;
            name = other.name;
            sur = other.sur;
            exam_results = other.exam_results;
            egzaminoRezultatas = other.egzaminoRezultatas;
            gal_vid = other.gal_vid;
            gal_med = other.gal_med;
        }
        return *this;
    }

      // Move constructor
    Student(Student&& other) :
        grades(std::move(other.grades)),
        pazymiai(std::move(other.pazymiai)),
        name(std::move(other.name)),
        sur(std::move(other.sur)),
        exam_results(other.exam_results),
        egzaminoRezultatas(other.egzaminoRezultatas),
        gal_vid(other.gal_vid),
        gal_med(other.gal_med) {
        other.exam_results = 0;
        other.egzaminoRezultatas = 0.0;
        other.gal_vid = 0.0;
        other.gal_med = 0.0;
        other.name.clear();
        other.sur.clear();
    }

    // Move assignment operator
    Student& operator=(Student&& other){
        if (this != &other) {
            grades = std::move(other.grades);
            pazymiai = std::move(other.pazymiai);
            name = std::move(other.name);
            sur = std::move(other.sur);
            exam_results = other.exam_results;
            egzaminoRezultatas = other.egzaminoRezultatas;
            gal_vid = other.gal_vid;
            gal_med = other.gal_med;

            other.exam_results = 0;
            other.egzaminoRezultatas = 0.0;
            other.gal_vid = 0.0;
            other.gal_med = 0.0;
            other.name.clear();
            other.sur.clear();
        }
        return *this;
    }

    // Setters and Getters
    void setName( string& vardas) {
        name = vardas;
    }

    string getName() const {
        return name;
    }

    void setSurname(string& pavarde) {
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


 // Input operatorius
 
    friend std::istream& operator>>(istream& in, Student& student) {
        string vardas, pavarde;
        int egzaminas;

        if (!(in >> vardas >> pavarde >> egzaminas)){
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            return in;
        }
        in >> vardas >> pavarde >> egzaminas;
        student.setName(vardas);
        student.setSurname(pavarde);
        student.setExamResult(egzaminas);

        /*student.pazymiai.clear();
        cout << "ivesti pazymius (norint baigti ivesti -1): ";
        int grade;
        while (in >> grade && grade != -1) {
            student.pazymiai.push_back(grade);
        }

        if (in.fail() && !in.eof()){
            in.clear();
            in.ignore(numeric_limits<streamsize>::max()), '\n';
*/
        return in;
    }

  
//output operatorius

friend ostream& operator<<(ostream& out, const Student& student) {
    out << "Vardas: " << student.getName() << endl;
    out << "Pavarde: " << student.getSurname() << endl;
    out << "Egzamino rezultatas: " << student.getExamResult() << endl;
    out << "Pazymiai: ";
    vector<int> grades = student.getGrades();
    for (int i = 0; i<grades.size(); i++){
        out << grades[i] << " ";
    }
    out << endl;
    return out;
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
void testas();




#endif
