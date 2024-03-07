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

using namespace std;

struct Student {
    string name;
    string sur;
    double final_avg;
    double median;
    vector<int> grades;
    int exam_results;
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
#endif 
