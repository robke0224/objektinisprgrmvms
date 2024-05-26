/**
 * @file student.h
 * @brief This file contains the declaration of the Zmogus and Student classes and related functions.
 * 
 * The file provides a detailed description of the Zmogus base class and the Student derived class,
 * along with several functions for handling student data.
 */

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
#include <chrono>


using namespace std;
using namespace std::chrono;

/**
 * @class Zmogus
 * @brief Abstract base class for a person.
 * 
 * The Zmogus class provides a base for derived classes representing people,
 * with pure virtual methods for setting and getting names and surnames.
 */
class Zmogus {
protected:
    string name;    ///< Name of the person.
    string surname; ///< Surname of the person.

public:
    /**
     * @brief Set the name of the person.
     * @param vardas The name to set.
     */
    virtual void setName(const string& vardas) = 0;

    /**
     * @brief Get the name of the person.
     * @return The name of the person.
     */
    virtual string getName() const = 0;

    /**
     * @brief Set the surname of the person.
     * @param pavarde The surname to set.
     */
    virtual void setSurname(const string& pavarde) = 0;

    /**
     * @brief Get the surname of the person.
     * @return The surname of the person.
     */
    virtual string getSurname() const = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~Zmogus() {}
};

/**
 * @class Student
 * @brief Class representing a student, derived from Zmogus.
 * 
 * The Student class contains additional attributes and methods specific to a student,
 * including grades, exam results, and methods to calculate averages and medians.
 */
class Student : public Zmogus {
private:
    vector<int> grades;    ///< Vector of grades.
    int exam_result;       ///< Exam result.
    double final_avg;      ///< Final average.
    double final_median;   ///< Final median.

public:
    /**
     * @brief Default constructor.
     */
    Student() : grades(), exam_result(0), final_avg(0.0), final_median(0.0) {}

    /**
     * @brief Destructor.
     */
    ~Student() {}

    // Implementing abstract methods from Zmogus
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

    // Additional methods for Student
    /**
     * @brief Set the exam result.
     * @param egzaminas The exam result to set.
     */
    void setExamResult(int egzaminas) {
        exam_result = egzaminas;
    }

    /**
     * @brief Get the exam result.
     * @return The exam result.
     */
    int getExamResult() const {
        return exam_result;
    }

    /**
     * @brief Set the final average.
     * @param Gal_vid The final average to set.
     */
    void setFinalAvg(double Gal_vid) {
        final_avg = Gal_vid;
    }

    /**
     * @brief Get the final average.
     * @return The final average.
     */
    double getFinalAvg() const {
        return final_avg;
    }

    /**
     * @brief Set the final median.
     * @param Gal_med The final median to set.
     */
    void setFinalMedian(double Gal_med) {
        final_median = Gal_med;
    }

    /**
     * @brief Get the final median.
     * @return The final median.
     */
    double getFinalMedian() const {
        return final_median;
    }

    /**
     * @brief Add a single grade.
     * @param naujasnd The grade to add.
     */
    void setSingleGrade(int naujasnd) {
        grades.push_back(naujasnd);
    }

    /**
     * @brief Get a single grade by index.
     * @param i The index of the grade.
     * @return The grade at the specified index.
     */
    int getSingleGrade(int i) const {
        return grades[i];
    }

    /**
     * @brief Set all grades.
     * @param ND Vector of grades to set.
     */
    void setGrades(const vector<int>& ND) {
        grades = ND;
    }

    /**
     * @brief Get all grades.
     * @return A vector of all grades.
     */
    vector<int> getGrades() const {
        return grades;
    }

    /**
     * @brief Clear all student data.
     */
    void clearData() {
        grades.clear();
        exam_result = 0;
        final_avg = 0.0;
        final_median = 0.0;
    }

    /**
     * @brief Input operator for Student.
     * @param in Input stream.
     * @param student Student object to input data into.
     * @return Reference to the input stream.
     */
    friend std::istream& operator>>(istream& in, Student& student) {
        string vardas, pavarde;
        int egzaminas;

        if (!(in >> vardas >> pavarde >> egzaminas)){
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            return in;
        }
        student.setName(vardas);
        student.setSurname(pavarde);
        student.setExamResult(egzaminas);

        return in;
    }

    /**
     * @brief Output operator for Student.
     * @param out Output stream.
     * @param student Student object to output data from.
     * @return Reference to the output stream.
     */
    friend ostream& operator<<(ostream& out, const Student& student) {
        out << "Vardas: " << student.getName() << endl;
        out << "Pavarde: " << student.getSurname() << endl;
        out << "Egzamino rezultatas: " << student.getExamResult() << endl;
        out << "Pazymiai: ";
        vector<int> grades = student.getGrades();
        for (int i = 0; i < grades.size(); i++){
            out << grades[i] << " ";
        }
        out << endl;
        return out;
    }
};

// Function declarations with brief descriptions

/**
 * @brief Generate random grades for a list of students.
 * @param students Vector of students.
 * @param hw Homework weight.
 */
void generateRandomGrades(vector<Student>& students, double hw);

/**
 * @brief Generate random data for a list of students.
 * @param students Vector of students.
 * @param hw Homework weight.
 */
void generateRandomData(vector<Student>& students, double hw);

/**
 * @brief Calculate the median of a vector of integers.
 * @param arr Vector of integers.
 * @return The median value.
 */
double calculateMedian(vector<int>& arr);

/**
 * @brief Read student data from a file.
 * @param students Vector to store student data.
 * @param hw Homework weight.
 * @param N Number of students.
 */
void readDataFromFile(vector<Student>& students, double& hw, int N);

/**
 * @brief Enter student data manually.
 * @param students Vector to store student data.
 * @param hw Homework weight.
 */
void enterDataManually(vector<Student>& students, double hw);

/**
 * @brief Compare two students by name.
 * @param a First student.
 * @param b Second student.
 * @return True if a's name is less than b's name.
 */
bool compareByName(const Student& a, const Student& b);

/**
 * @brief Compare two students by surname.
 * @param a First student.
 * @param b Second student.
 * @return True if a's surname is less than b's surname.
 */
bool compareBySurname(const Student& a, const Student& b);

/**
 * @brief Compare two students by median grade.
 * @param a First student.
 * @param b Second student.
 * @return True if a's median is less than b's median.
 */
bool compareByMedian(const Student& a, const Student& b);

/**
 * @brief Compare two students by average grade.
 * @param a First student.
 * @param b Second student.
 * @return True if a's average is less than b's average.
 */
bool compareByAvg(const Student& a, const Student& b);

/**
 * @brief Generate a random number within a range.
 * @param min Minimum value.
 * @param max Maximum value.
 * @return A random number between min and max.
 */
int generateRandomNumber(int min, int max);

/**
 * @brief Calculate the average of a vector of integers.
 * @param pazymiai Vector of integers.
 * @return The average value.
 */
double calculateAverage(const vector<int>& pazymiai);

/**
 * @brief Generate student data files.
 * @param studentu_kiekis Number of students.
 * @param failo_pavadinimas File name.
 */
void failuGeneravimas(int studentu_kiekis, const std::string& failo_pavadinimas);

/**
 * @brief Read student data from a file.
 * @param failo_pavadinimas File name.
 * @param students Vector to store student data.
 * @param studentukiekis Number of students.
 * @return True if successful, false otherwise.
 */
bool Nuskaitymas(const std::string& failo_pavadinimas, std::vector<Student>& students, int studentukiekis);

/**
 * @brief Get the current time point.
 * @return Current time point.
 */
std::chrono::steady_clock::time_point DabartinisLaikas();

/**
 * @brief Calculate the time difference between two time points.
 * @param pradzia Start time point.
 * @param pabaiga End time point.
 * @return Time difference in seconds.
 */
double LaikoSkirtumas(const std::chrono::steady_clock::time_point& pradzia, const std::chrono::steady_clock::time_point& pabaiga);

/**
 * @brief Calculate results for a list of students.
 * @param stud Vector of students.
 */
void calculateResults(std::vector<Student>& stud);

/**
 * @brief Calculate the average of grades.
 * @param pazymiai Vector of grades.
 * @return The average grade.
 */
double skaiciuotiVidurki(const std::vector<int>& pazymiai);

/**
 * @brief Check if a student is a good student.
 * @param student Student to check.
 * @return True if the student is good, false otherwise.
 */
bool arGerasStudentas(const Student& student);

/**
 * @brief Compare two students by average grade.
 * @param a First student.
 * @param b Second student.
 * @return True if a's average is greater than b's average.
 */
bool lygintiPagalVidurki(const Student& a, const Student& b);

/**
 * @brief Sort students and write to files.
 * @param students Vector of students.
 */
void rūšiuoja_ir_rašo_failus(std::vector<Student>& students);

/**
 * @brief Run test functions.
 */
void testas();

#endif // STUDENT_H
