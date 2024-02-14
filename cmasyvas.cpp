#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm> // for sorting

using namespace std;

struct Student {
    string name, sur;
    double final_avg, median;
    int* grades;
    int exam_results;

    // Constructor to initialize grades pointer to nullptr
    Student() : grades(nullptr) {}
};

// Function to calculate median
double calculateMedian(int arr[], int size) {
    sort(arr, arr + size); // Sort the array

    if (size % 2 != 0) // If size is odd
        return arr[size / 2];
    else // If size is even
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
}

// Function to enter data manually
void enterDataManually(Student students[], int s, double hw) {
    for (int i = 0; i < s; ++i) {
        cout << "Enter " << i + 1 << " student's name and surname: ";
        cin >> students[i].name >> students[i].sur;

        // Dynamically allocate memory for grades array
        students[i].grades = new int[static_cast<int>(hw)];
        double total_grades = 0.0;

        for (int j = 0; j < hw; ++j) {
            do {
                cout << "Enter student's grades for " << j + 1 << " homework: ";
                cin >> students[i].grades[j];
                if (students[i].grades[j] < 1 || students[i].grades[j] > 10) {
                    cout << "Error: Grade must be between 1 and 10." << endl;
                }
            } while (students[i].grades[j] < 1 || students[i].grades[j] > 10);
            total_grades += students[i].grades[j];
        }

        // Calculate final average
        students[i].final_avg = total_grades / hw;

        // Calculate median
        students[i].median = calculateMedian(students[i].grades, hw);

        // Enter exam result
        do {
            cout << "Enter " << i + 1 << " student's exam grade: ";
            cin >> students[i].exam_results;
            if (students[i].exam_results < 1 || students[i].exam_results > 10) {
                cout << "Error: Grade must be between 1 and 10." << endl;
            }
        } while (students[i].exam_results < 1 || students[i].exam_results > 10);

        // Calculate final average with exam result
        students[i].final_avg = 0.4 * students[i].final_avg + 0.6 * students[i].exam_results;
    }
}

// Function to generate random grades
void generateRandomGrades(Student students[], int s, double hw) {
    for (int i = 0; i < s; ++i) {
        // Dynamically allocate memory for grades array
        students[i].grades = new int[static_cast<int>(hw)];
        double total_grades = 0.0;

        for (int j = 0; j < hw; ++j) {
            students[i].grades[j] = rand() % 10 + 1; // Generate random grade
            total_grades += students[i].grades[j];
        }

        // Calculate final average
        students[i].final_avg = total_grades / hw;

        // Calculate median
        students[i].median = calculateMedian(students[i].grades, hw);

        // Generate random exam result
        students[i].exam_results = rand() % 10 + 1;

        // Calculate final average with exam result
        students[i].final_avg = 0.4 * students[i].final_avg + 0.6 * students[i].exam_results;
    }
}

// Function to generate random names, surnames, and grades
void generateRandomData(Student students[], int s, double hw) {
    string first_names[] = {"Jonas", "Ema", "Mikas", "Greta", "Vilius", "Sofija", "Tomas", "Eva", "Benas", "Izabelė"};
    string last_names[] = {"Pavardukas", "Pavardelis", "Pavardyte", "Pavardenis", "Pavardenaite", "Pavardyte", "Pavardaite", "Pavardis", "Pavpav", "Pavardeliukas"};

    for (int i = 0; i < s; ++i) {
        // Generate random name and surname
        students[i].name = first_names[rand() % 10];
        students[i].sur = last_names[rand() % 10];

        // Dynamically allocate memory for grades array
        students[i].grades = new int[static_cast<int>(hw)];
        double total_grades = 0.0;

        for (int j = 0; j < hw; ++j) {
            students[i].grades[j] = rand() % 10 + 1; // Generate random grade
            total_grades += students[i].grades[j];
        }

        // Calculate final average
        students[i].final_avg = total_grades / hw;

        // Calculate median
        students[i].median = calculateMedian(students[i].grades, hw);

        // Generate random exam result
        students[i].exam_results = rand() % 10 + 1;

        // Calculate final average with exam result
        students[i].final_avg = 0.4 * students[i].final_avg + 0.6 * students[i].exam_results;
    }
}

int main() {
    int s;
    double hw;

    char choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Enter data manually" << endl;
        cout << "2. Generate random grades" << endl;
        cout << "3. Generate random names, surnames, and grades" << endl;
        cout << "4. End the program" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                cout << "How many students in a group? ";
                while (!(cin >> s) || s <= 0) {
                    cout << "Error: Please enter a positive number for the count of students." << endl;
                    cout << "How many students in a group? ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "How much homework? ";
                while (!(cin >> hw) || hw < 0) {
                    cout << "Error: Please enter a positive number for the count of homework." << endl;
                    cout << "How much homework? ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                // Dynamically allocate memory for array of Student objects
                Student* students = new Student[s];

                // Call function to enter data manually
                enterDataManually(students, s, hw);
                cout << "Data entered manually successfully." << endl;

                // Ask whether to show median or final average
                char displayChoice;
                cout << "Do you want to see the final average (A) or the median (M)? ";
                cin >> displayChoice;

                // Display data
                cout << left << setw(20) << "Name" << setw(20) << "Surname";
                if (displayChoice == 'A' || displayChoice == 'a')
                    cout << setw(20) << "Final Average";
                else if (displayChoice == 'M' || displayChoice == 'm')
                    cout << setw(20) << "Median";
                cout << endl;

                cout << "------------------------------------------------------------" << endl;
                for (int i = 0; i < s; i++) {
                    cout << left << setw(20) << students[i].name << setw(20) << students[i].sur;
                    if (displayChoice == 'A' || displayChoice == 'a')
                        cout << setw(20) << fixed << setprecision(2) << students[i].final_avg;
                    else if (displayChoice == 'M' || displayChoice == 'm')
                        cout << setw(20) << fixed << setprecision(2) << students[i].median;
                    cout << endl;
                }

                // Deallocate memory for each student's grades array
                for (int i = 0; i < s; ++i) {
                    delete[] students[i].grades;
                }

                // Deallocate memory for array of Student objects
                delete[] students;
                break;
            }
            case '2': {
                cout << "How many students in a group? ";
                while (!(cin >> s) || s <= 0) {
                    cout << "Error: Please enter a positive number for the count of students." << endl;
                    cout << "How many students in a group? ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "How much homework? ";
                while (!(cin >> hw) || hw < 0) {
                    cout << "Error: Please enter a positive number for the count of homework." << endl;
                    cout << "How much homework? ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                // Dynamically allocate memory for array of Student objects
                Student* students = new Student[s];

                // Call function to generate random grades
                generateRandomGrades(students, s, hw);
                cout << "Random grades generated successfully." << endl;

                // Ask whether to show median or final average
                char displayChoice;
                cout << "Do you want to see the final average (A) or the median (M)? ";
                cin >> displayChoice;

                // Display data
                if (displayChoice == 'A' || displayChoice == 'a')
                    cout << setw(20) << fixed << "Final Average";
                else if (displayChoice == 'M' || displayChoice == 'm')
                    cout << setw(20) << fixed << "Median";
                cout << endl;

                cout << "----------------------------" << endl;
                for (int i = 0; i < s; i++) {
                    if (displayChoice == 'A' || displayChoice == 'a')
                        cout << setw(20) << fixed << setprecision(2) << students[i].final_avg;
                    else if (displayChoice == 'M' || displayChoice == 'm')
                        cout << setw(20) << fixed << setprecision(2) << students[i].median;
                    cout << endl;
                }

                // Deallocate memory for each student's grades array
                for (int i = 0; i < s; ++i) {
                    delete[] students[i].grades;
                }

                // Deallocate memory for array of Student objects
                delete[] students;
                break;
            }
            case '3': {
                cout << "How many students in a group? ";
                while (!(cin >> s) || s <= 0) {
                    cout << "Error: Please enter a positive number for the count of students." << endl;
                    cout << "How many students in a group? ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "How much homework? ";
                while (!(cin >> hw) || hw < 0) {
                    cout << "Error: Please enter a positive number for the count of homework." << endl;
                    cout << "How much homework? ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                // Dynamically allocate memory for array of Student objects
                Student* students = new Student[s];

                // Call function to generate random data
                generateRandomData(students, s, hw);
                cout << "Random data generated successfully." << endl;

                // Ask whether to show median or final average
                char displayChoice;
                cout << "Do you want to see the final average (A) or the median (M)? ";
                cin >> displayChoice;

                // Display data
                cout << left << setw(20) << "Name" << setw(20) << "Surname";
                if (displayChoice == 'A' || displayChoice == 'a')
                    cout << setw(20) << "Final Average";
                else if (displayChoice == 'M' || displayChoice == 'm')
                    cout << setw(20) << "Median";
                cout << endl;

                cout << "------------------------------------------------------------" << endl;
                for (int i = 0; i < s; i++) {
                    cout << left << setw(20) << students[i].name << setw(20) << students[i].sur;
                    if (displayChoice == 'A' || displayChoice == 'a')
                        cout << setw(20) << fixed << setprecision(2) << students[i].final_avg;
                    else if (displayChoice == 'M' || displayChoice == 'm')
                        cout << setw(20) << fixed << setprecision(2) << students[i].median;
                    cout << endl;
                }

                // Deallocate memory for each student's grades array
                for (int i = 0; i < s; ++i) {
                    delete[] students[i].grades;
                }

                // Deallocate memory for array of Student objects
                delete[] students;
                break;
            }
            case '4': {
                cout << "Ending the program." << endl;
                break;
            }
            default:
                cout << "Invalid option. Please choose again." << endl;
        }
    } while (choice != '4');

    return 0;
}
