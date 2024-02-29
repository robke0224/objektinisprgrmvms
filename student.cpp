#include "student.h"

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

double calculateMedian(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int size = arr.size();
    if (size % 2 != 0)
        return arr[size / 2];
    else
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
}

void readDataFromFile(vector<Student>& students, double& hw, int N) {
    try {
        ifstream file;
        file.open("studentai10000.txt");

        if (!file) {
            throw runtime_error("Error opening the file");
        }
      string line;
      getline(file, line);

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
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

void enterDataManually(vector<Student>& students, double hw) {
    try {
        for (int i = 0; i < students.size(); ++i) {
            cout << "Enter " << i + 1 << " student's name and surname: ";
            cin >> students[i].name >> students[i].sur;

            students[i].grades.resize(static_cast<int>(hw));
            double total_grades = 0.0;

            for (int j = 0; j < hw; ++j) {
                cout << "Enter student's grades for " << j + 1 << " homework: ";
                while (!(cin >> students[i].grades[j])|| students[i].grades[j] < 1 || students[i].grades[j] > 10){
                    if (!(cin >> students[i].grades[j])) {
                        cout << "Error: Please enter a number." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }else if (students[i].grades[j] < 1 || students[i].grades[j] > 10) {
                        cout << "Error: Grade must be between 1 and 10." << endl;
                        cin.clear();
                        cin.ignore();
                    }
                } ;
                total_grades += students[i].grades[j];
            }
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}


