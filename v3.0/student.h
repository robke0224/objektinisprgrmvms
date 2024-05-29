/**
 * @file Student.h
 * @brief Header file containing the definitions for the Zmogus and Student classes, and associated functions.
 *
 * This file defines the abstract base class Zmogus and the derived class Student, 
 * along with various utility functions for handling student data.
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
 * @brief Abstract base class representing a person.
 */
class Zmogus {
protected:
    string name;    /**< Name of the person */
    string surname; /**< Surname of the person */

public:
    /**
     * @brief Sets the name of the person.
     * @param vardas The name to set.
     */
    virtual void setName(const string& vardas) = 0;

    /**
     * @brief Gets the name of the person.
     * @return The name of the person.
     */
    virtual string getName() const = 0;

    /**
     * @brief Sets the surname of the person.
     * @param pavarde The surname to set.
     */
    virtual void setSurname(const string& pavarde) = 0;

    /**
     * @brief Gets the surname of the person.
     * @return The surname of the person.
     */
    virtual string getSurname() const = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~Zmogus() {}
};

/**
 * @brief Class representing a student, derived from Zmogus.
 */
class Student : public Zmogus {
private:
    Vector<int> grades; /**< Grades of the student */
    int exam_result;    /**< Exam result of the student */
    double final_avg;   /**< Final average of the student */
    double final_median;/**< Final median of the student */

public:
    /**
     * @brief Constructor initializing the student with default values.
     */
    Student();

    /**
     * @brief Destructor.
     */
    ~Student();

    // Implementation of abstract methods from Zmogus
    void setName(const string& vardas) override;
    string getName() const override;
    void setSurname(const string& pavarde) override;
    string getSurname() const override;

    /**
     * @brief Sets the exam result of the student.
     * @param egzaminas The exam result to set.
     */
    void setExamResult(int egzaminas);

    /**
     * @brief Gets the exam result of the student.
     * @return The exam result.
     */
    int getExamResult() const;

    /**
     * @brief Sets the final average grade of the student.
     * @param Gal_vid The final average grade to set.
     */
    void setFinalAvg(double Gal_vid);

    /**
     * @brief Gets the final average grade of the student.
     * @return The final average grade.
     */
    double getFinalAvg() const;

    /**
     * @brief Sets the final median grade of the student.
     * @param Gal_med The final median grade to set.
     */
    void setFinalMedian(double Gal_med);

    /**
     * @brief Gets the final median grade of the student.
     * @return The final median grade.
     */
    double getFinalMedian() const;

    /**
     * @brief Adds a single grade to the student's grades.
     * @param naujasnd The grade to add.
     */
    void setSingleGrade(int naujasnd);

    /**
     * @brief Gets a single grade of the student.
     * @param i The index of the grade to get.
     * @return The grade at index i.
     */
    int getSingleGrade(int i) const;

    /**
     * @brief Sets the grades of the student.
     * @param ND The grades to set.
     */
    void setGrades(const Vector<int>& ND);

    /**
     * @brief Gets the grades of the student.
     * @return The grades of the student.
     */
    Vector<int> getGrades() const;

    /**
     * @brief Clears all data of the student.
     */
    void clearData();

    // Friend functions for input and output operations
    friend std::istream& operator>>(istream& in, Student& student);
    friend std::ostream& operator<<(ostream& out, const Student& student);
};

// Function declarations
void generateRandomGrades(Vector<Student>& students, double hw);
void generateRandomData(Vector<Student>& students, double hw);
double calculateMedian(Vector<int>& arr);
void readDataFromFile(Vector<Student>& students, double& hw, int N);
void enterDataManually(Vector<Student>& students, double hw);
bool compareByName(const Student& a, const Student& b);
bool compareBySurname(const Student& a, const Student& b);
bool compareByMedian(const Student& a, const Student& b);
bool compareByAvg(const Student& a, const Student& b);
int generateRandomNumber(int min, int max);
double calculateAverage(const Vector<int>& pazymiai);
void failuGeneravimas(int studentu_kiekis, const std::string& failo_pavadinimas);
bool Nuskaitymas(const std::string& failo_pavadinimas, Vector<Student>& students, int studentukiekis);
std::chrono::steady_clock::time_point DabartinisLaikas();
double LaikoSkirtumas(const std::chrono::steady_clock::time_point& pradzia, const std::chrono::steady_clock::time_point& pabaiga);
void calculateResults(Vector<Student>& stud);
double skaiciuotiVidurki(const Vector<int>& pazymiai);
bool arGerasStudentas(const Student& student);
bool lygintiPagalVidurki(const Student& a, const Student& b);
void rusiuoja_ir_raso_failus(Vector<Student>& students);
void testas();
void testStdVectorPerformance();
void testCustomVectorPerformance();

#endif // STUDENT_H
