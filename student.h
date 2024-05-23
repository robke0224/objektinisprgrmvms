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

// Abstrakti bazinė klasė žmogui
class Zmogus {
protected:
    string name;
    string surname;

public:
    // Abstraktūs metodai, kuriuos reikės realizuoti išvestinėse klasėse
    virtual void setName(const string& vardas) = 0;
    virtual string getName() const = 0;
    virtual void setSurname(const string& pavarde) = 0;
    virtual string getSurname() const = 0;

    // Virtualus destruktorius, nes tai abstrakti bazinė klasė
    virtual ~Zmogus() {}
};

// Studento klasė, kuri paveldi iš žmogaus bazinės klasės
class Student : public Zmogus {
private:
    vector<int> grades;
    int exam_result;
    double final_avg;
    double final_median;

public:
    // Konstruktorius
    Student() :
        grades(),
        exam_result(0),
        final_avg(0.0),
        final_median(0.0) {}

    // Destruktorius
    ~Student() {}

    // Metodai, kurie realizuoja abstrakčius metodus iš bazinės klasės
    void setName(const string& vardas) override {
        name = vardas;
    }

    string getName() const override {
        return name;
    }

    void setSurname(const string& pavarde) override {
        surname = pavarde;
    }

    string getSurname() const override {
        return surname;
    }

    // Papildomi metodai skirti darbui su studento duomenimis
    void setExamResult(int egzaminas) {
        exam_result = egzaminas;
    }

    int getExamResult() const {
        return exam_result;
    }

    void setFinalAvg(double Gal_vid) {
        final_avg = Gal_vid;
    }

    double getFinalAvg() const {
        return final_avg;
    }

    void setFinalMedian(double Gal_med) {
        final_median = Gal_med;
    }

    double getFinalMedian() const {
        return final_median;
    }

    void setSingleGrade(int naujasnd) {
        grades.push_back(naujasnd);
    }

    int getSingleGrade(int i) const {
        return grades[i];
    }

    void setGrades(const vector<int>& ND) {
        grades = ND;
    }

    vector<int> getGrades() const {
        return grades;
    }

    void clearData() {
        grades.clear();
        exam_result = 0;
        final_avg = 0.0;
        final_median = 0.0;
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
