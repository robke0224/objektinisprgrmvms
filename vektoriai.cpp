#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <sstream>
#include <numeric>
#include <chrono>

using namespace std;

struct Student {
    string name, sur;
    double final_avg, median;
    vector<int> grades;
    int exam_results;
};

double calculateMedian(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int size = arr.size();
    if (size % 2 != 0)
        return arr[size / 2];
    else
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
}

bool compareByName(const Student& a, const Student& b) {
    return a.name < b.name;
}

bool compareBySurname(const Student& a, const Student& b) {
    return a.sur < b.sur;
}

bool compareByMedian(const Student& a, const Student& b) {
    return a.median < b.median;
}

bool compareByAvg(const Student& a, const Student& b) {
    return a.final_avg < b.final_avg;
}

void readDataFromFile(vector<Student>& students, double& hw, int N) {
    ifstream file;
    file.open("studentai10000.txt");

    if (!file) {
        cout << "Error opening the file" << endl;
        return;
    }

    string line;
    getline(file, line); // Skipping the first line

    int count = 0;
    while (getline(file, line) && count < N) {
        istringstream iss(line);
        Student student;
        iss >> student.name >> student.sur;
        int grade;
        while (iss >> grade) {
            student.grades.push_back(grade);
        }
        student.exam_results = student.grades.back();
        student.grades.pop_back();
        double finalAvg = 0.0;
        double median = 0.0;
        if (!student.grades.empty()) {
            finalAvg = accumulate(student.grades.begin(), student.grades.end(), 0.0) / student.grades.size();
            sort(student.grades.begin(), student.grades.end());
            int size = student.grades.size();
            if (size % 2 != 0)
                median = student.grades[size / 2];
            else
                median = (student.grades[size / 2 - 1] + student.grades[size / 2]) / 2.0;
        }
        student.final_avg = finalAvg;
        student.median = median;
        students.push_back(student);
        count++;
    }

    file.close();

    char sortChoice;
    cout << "Sort by (N)ame, (S)urname, (M)edian or (A)verage: ";
    cin >> sortChoice;
    switch (sortChoice){
        case 'N':
        case 'n':
            sort(students.begin(), students.end(), compareByName);
            break;
        case 'S':
        case 's':
            sort (students.begin(), students.end(), compareBySurname);
            break;
        case 'M':
        case 'm':
            sort (students.begin(), students.end(), compareByMedian);
            break;
        case 'A':
        case 'a':
            sort (students.begin(), students.end(), compareByAvg);
            break;
        default:
            cout << "Invalid choice. Data will be displayed unsorted." << endl;
            break;
    }
}

void enterDataManually(vector<Student>& students, double hw) {
    for (int i = 0; i < students.size(); ++i) {
        cout << "Enter " << i + 1 << " student's name and surname: ";
        cin >> students[i].name >> students[i].sur;

        students[i].grades.resize(static_cast<int>(hw));
        double total_grades = 0.0;

        for (int j = 0; j < hw; ++j) {
            do {
                cout << "Enter student's grades for " << j + 1 << " homework: ";
                cin >> students[i].grades[j];
                if (cin.fail()) {
                    cout << "Error: Please enter a valid number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else if (students[i].grades[j] < 1 || students[i].grades[j] > 10) {
                    cout << "Error: Grade must be between 1 and 10." << endl;
                }
            } while (students[i].grades[j] < 1 || students[i].grades[j] > 10);
            total_grades += students[i].grades[j];
        }

        students[i].final_avg = total_grades / hw;
        students[i].median = calculateMedian(students[i].grades);

        do {
            cout << "Enter " << i + 1 << " student's exam grade: ";
            cin >> students[i].exam_results;
            if (cin.fail()) {
                cout << "Error: Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (students[i].exam_results < 1 || students[i].exam_results > 10) {
                cout << "Error: Grade must be between 1 and 10." << endl;
            }
        } while (students[i].exam_results < 1 || students[i].exam_results > 10);

        students[i].final_avg = 0.4 * students[i].final_avg + 0.6 * students[i].exam_results;
    }
}

void generateRandomGrades(vector<Student>& students, double hw) {
    for (int i = 0; i < students.size(); ++i) {
        // Generate random grades
        students[i].grades.resize(static_cast<int>(hw));
        for (int j = 0; j < hw; ++j) {
            students[i].grades[j] = rand() % 10 + 1;
        }

        // Generate random exam result
        students[i].exam_results = rand() % 10 + 1;

        // Calculate final average and median
        double total_grades = accumulate(students[i].grades.begin(), students[i].grades.end(), 0.0);
        students[i].final_avg = (total_grades / hw) * 0.4 + (students[i].exam_results) * 0.6;
        students[i].median = calculateMedian(students[i].grades);
    }
}

void generateRandomData(vector<Student>& students, double hw) {
    string first_names[] = {"Jonas", "Ema", "Mikas", "Greta", "Vilius", "Sofija", "Tomas", "Eva", "Benas", "Izabelė"};
    string last_names[] = {"Pavardukas", "Pavardelis", "Pavardyte", "Pavardenis", "Pavardenaite", "Pavardyte", "Pavardaite", "Pavardis", "Pavpav", "Pavardeliukas"};

    for (int i = 0; i < students.size(); ++i) {
        students[i].name = first_names[rand() % 10];
        students[i].sur = last_names[rand() % 10];

        students[i].grades.resize(static_cast<int>(hw));
        double total_grades = 0.0;

        for (int j = 0; j < hw; ++j) {
            students[i].grades[j] = rand() % 10 + 1;
            total_grades += students[i].grades[j];
        }

        students[i].final_avg = total_grades / hw;
        students[i].median = calculateMedian(students[i].grades);

        students[i].exam_results = rand() % 10 + 1;

        students[i].final_avg = 0.4 * students[i].final_avg + 0.6 * students[i].exam_results;
    }
}

int main() {
    int s;
    double hw;

    char choice;
    vector<Student> students;

    do {
        cout << "Menu:" << endl;
        cout << "1. Enter data manually" << endl;
        cout << "2. Enter names and surnames manually and then generate random grades" << endl;
        cout << "3. Generate random names, surnames, and grades" << endl;
        cout << "4. Read data from file" << endl;
        cout << "5. End the program" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                cout << "How many students in a group? ";
                cin >> s;
                students.resize(s);

                cout << "How much homework? ";
                cin >> hw;

                enterDataManually(students, hw);
                cout << "Data entered manually successfully." << endl;

                char displayChoice;
                cout << "Do you want to see the final average (A) or the median (M)? ";
                cin >> displayChoice;

                cout << left << setw(20) << "Name" << setw(20) << "Surname";
                if (displayChoice == 'A' || displayChoice == 'a')
                    cout << setw(20) << "Final Average";
                else if (displayChoice == 'M' || displayChoice == 'm')
                    cout << setw(20) << "Median";
                cout << endl;

                cout << "------------------------------------------------------------" << endl;
                for (int i = 0; i < students.size(); i++) {
                    cout << left << setw(20) << students[i].name << setw(20) << students[i].sur;
                    if (displayChoice == 'A' || displayChoice == 'a')
                        cout << setw(20) << fixed << setprecision(2) << students[i].final_avg;
                    else if (displayChoice == 'M' || displayChoice == 'm')
                        cout << setw(20) << fixed << setprecision(2) << students[i].median;
                    cout << endl;
                }
                break;
            }
            case '2': {
                cout << "How many students in a group? ";
                cin >> s;
                students.resize(s);

                cout << "How much homework? ";
                cin >> hw;

                // Only enter names and surnames manually
                for (int i = 0; i < students.size(); ++i) {
                    cout << "Enter " << i + 1 << " student's name and surname: ";
                    cin >> students[i].name >> students[i].sur;
                }

                // Generate random grades
                generateRandomGrades(students, hw);

                char displayChoice;
                cout << "Do you want to see the final average (A) or the median (M)? ";
                cin >> displayChoice;

                cout << left << setw(20) << "Name" << setw(20) << "Surname";
                if (displayChoice == 'A' || displayChoice == 'a')
                    cout << setw(20) << "Final Average";
                else if (displayChoice == 'M' || displayChoice == 'm')
                    cout << setw(20) << "Median";
                cout << endl;

                cout << "------------------------------------------------------------" << endl;
                for (int i = 0; i < students.size(); i++) {
                    cout << left << setw(20) << students[i].name << setw(20) << students[i].sur;
                    if (displayChoice == 'A' || displayChoice == 'a')
                        cout << setw(20) << fixed << setprecision(2) << students[i].final_avg;
                    else if (displayChoice == 'M' || displayChoice == 'm')
                        cout << setw(20) << fixed << setprecision(2) << students[i].median;
                    cout << endl;
                }
                break;
            }
            case '3': {
                cout << "How many students in a group? ";
                cin >> s;
                students.resize(s);

                cout << "How much homework? ";
                cin >> hw;

                generateRandomData(students, hw);
                cout << "Random data generated successfully." << endl;

                char displayChoice;
                cout << "Do you want to see the final average (A) or the median (M)? ";
                cin >> displayChoice;

                cout << left << setw(20) << "Name" << setw(20) << "Surname";
                if (displayChoice == 'A' || displayChoice == 'a')
                    cout << setw(20) << "Final Average";
                else if (displayChoice == 'M' || displayChoice == 'm')
                    cout << setw(20) << "Median";
                cout << endl;

                cout << "------------------------------------------------------------" << endl;
                for (int i = 0; i < students.size(); i++) {
                    cout << left << setw(20) << students[i].name << setw(20) << students[i].sur;
                    if (displayChoice == 'A' || displayChoice == 'a')
                        cout << setw(20) << fixed << setprecision(2) << students[i].final_avg;
                    else if (displayChoice == 'M' || displayChoice == 'm')
                        cout << setw(20) << fixed << setprecision(2) << students[i].median;
                    cout << endl;
                }
                break;
            }
            case '4': {
                int N;
                cout << "Enter how many data entries you want to read: ";
                cin >> N;

                readDataFromFile(students, hw, N);

                char displayChoice;
                cout << "Do you want to see the final average (A) or the median (M)? ";
                cin >> displayChoice;

                cout << left << setw(20) << "Name" << setw(20) << "Surname";
                if (displayChoice == 'A' || displayChoice == 'a')
                    cout << setw(20) << "Final Average";
                else if (displayChoice == 'M' || displayChoice == 'm')
                    cout << setw(20) << "Median";
                cout << endl;

                cout << "------------------------------------------------------------" << endl;
                for (int i = 0; i < students.size(); i++) {
                    cout << left << setw(20) << students[i].name << setw(20) << students[i].sur;
                    if (displayChoice == 'A' || displayChoice == 'a')
                        cout << setw(20) << fixed << setprecision(2) << students[i].final_avg;
                    else if (displayChoice == 'M' || displayChoice == 'm')
                        cout << setw(20) << fixed << setprecision(2) << students[i].median;
                    cout << endl;
                }
                break;
            }
            case '5': {
                cout << "Ending the program." << endl;
                break;
            }
            default:
                cout << "Invalid option. Please choose again." << endl;
        }
    } while (choice != '5');

    return 0;
}
