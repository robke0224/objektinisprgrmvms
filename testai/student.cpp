#include "student.h"

using namespace std;

// Constructor
Student::Student() : grades(), exam_result(0), final_avg(0.0), final_median(0.0) {}

// Destructor
Student::~Student() {}

// Implementing abstract methods from Zmogus
void Student::setName(const string& vardas) {
    name = vardas;
}

string Student::getName() const {
    return name;
}

void Student::setSurname(const string& pavarde) {
    surname = pavarde;
}

string Student::getSurname() const {
    return surname;
}

// Additional methods for Student
void Student::setExamResult(int egzaminas) {
    exam_result = egzaminas;
}

int Student::getExamResult() const {
    return exam_result;
}

void Student::setFinalAvg(double Gal_vid) {
    final_avg = Gal_vid;
}

double Student::getFinalAvg() const {
    return final_avg;
}

void Student::setFinalMedian(double Gal_med) {
    final_median = Gal_med;
}

double Student::getFinalMedian() const {
    return final_median;
}

void Student::setSingleGrade(int naujasnd) {
    grades.push_back(naujasnd);
}

int Student::getSingleGrade(int i) const {
    return grades[i];
}

void Student::setGrades(const vector<int>& ND) {
    grades = ND;
}

vector<int> Student::getGrades() const {
    return grades;
}

void Student::clearData() {
    grades.clear();
    exam_result = 0;
    final_avg = 0.0;
    final_median = 0.0;
}
