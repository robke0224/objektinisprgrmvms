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
#include <vector>
#include <string>

using namespace std;

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
    Student();

    /**
     * @brief Destructor.
     */
    ~Student();

    // Implementing abstract methods from Zmogus
    void setName(const string& vardas) override;
    string getName() const override;
    void setSurname(const string& pavarde) override;
    string getSurname() const override;

    // Additional methods for Student
    void setExamResult(int egzaminas);
    int getExamResult() const;
    void setFinalAvg(double Gal_vid);
    double getFinalAvg() const;
    void setFinalMedian(double Gal_med);
    double getFinalMedian() const;
    void setSingleGrade(int naujasnd);
    int getSingleGrade(int i) const;
    void setGrades(const vector<int>& ND);
    vector<int> getGrades() const;
    void clearData();
};

#endif // STUDENT_H
