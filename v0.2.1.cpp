#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <sstream>
#include <numeric>
#include <limits>

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
    return stoi(a.name.substr(6,1)) < stoi(b.name.substr(6,1));
}

bool compareBySurname(const Student& a, const Student& b) {
    return stoi(a.sur.substr(7,1)) < stoi(b.sur.substr(7,1));
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
        cout << "nepavyko atidaryti failo" << endl;
        return;
    }

    string line;
    getline(file, line); // prasoka pirma eil

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
        cout << "iveskite " << i + 1 << " mokinio varda ir pavarde: ";
        cin >> students[i].name >> students[i].sur;

        students[i].grades.resize(static_cast<int>(hw));
        double total_grades = 0.0;

        for (int j = 0; j < hw; ++j) {
            cout << "iveskite pazymius uz " << j + 1 << " namu darbus: ";
            while (!(cin >> students[i].grades[j])|| students[i].grades[j] < 1 || students[i].grades[j] > 10){
                if (!(cin >> students[i].grades[j])) {
                    cout << "klaida. iveskite skaiciu." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }else if (students[i].grades[j] < 1 || students[i].grades[j] > 10) {
                    cout << "klaida.skaicius turi priklausyti intervalui nuo 1 iki 10." << endl;
                    cin.clear();
                    cin.ignore();
                }
            } ;
            total_grades += students[i].grades[j];
        }

        students[i].final_avg = total_grades / hw;
        students[i].median = calculateMedian(students[i].grades);

        do {
            cout << "iveskite " << i + 1 << " mokinio egzamino pazymi: ";
            if (!(cin >> students[i].exam_results)) {
                cout << "klaida. iveskite skaiciu" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (students[i].exam_results < 1 || students[i].exam_results > 10) {
                cout << "klaida. skaicius turi priklausyti intervalui nuo 1 iki 10" << endl;
            }
        } while (cin.fail() || students[i].exam_results < 1 || students[i].exam_results > 10);

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
        cout << "Meniu:" << endl;
        cout << "1. ivesti duomenis ranka" << endl;
        cout << "2. ivesti varda ir pavarde, o pazymius generuoti" << endl;
        cout << "3. generuoti vardus, pavardes ir skaicius" << endl;
        cout << "4. nuskaityti faila ir duomenis isvesti terminale" << endl;
        cout << "5. nuskaityti faila ir duomenis isvesti atskirame faile" << endl;
        cout << "6. baigti programa" << endl;
        cout << "jusu pasirinkimas: ";
        cin >> choice;

        switch (choice) {
         case '1': {
                 cout << "kiek studentu grupeje? ";
                 while (!(cin >> s)) {
                cout << "iveskite skaiciu." << endl;
                cin.clear();
                cin.ignore();
    }
                students.resize(s);

                 cout << "kiek namu darbu? ";
                 while (!(cin >> hw)) {
                cout << "klaida. iveskite skaiciu." << endl;
                cin.clear();
                cin.ignore();
    
                 }

    enterDataManually(students, hw);
    cout << "duomenys ivesti sekmingai." << endl;

    char displayChoice;
    cout << "rodyti vidurki (A) ar mediana (M)? ";
    cin >> displayChoice;

    if (!(displayChoice == 'A' || displayChoice == 'a' || displayChoice == 'M' || displayChoice == 'm')) {
        cout << "klaida. iveskite 'A' arba 'M'." << endl;
        break;
    }

    cout << left << setw(20) << "vardas" << setw(20) << "pavarde";
    if (displayChoice == 'A' || displayChoice == 'a')
        cout << setw(20) << "vidurkis";
    else if (displayChoice == 'M' || displayChoice == 'm')
        cout << setw(20) << "mediana";
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
    int s;
    double hw;

    // Ask the user for the number of students in a group
    cout << "kiek studentu grupeje? ";
    while (!(cin >> s) || s <= 0) {
        cout << "klaida. iveskite skaiciu didesni uz 0." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Ask the user for the number of homework
    cout << "kiek namu darbu? ";
    while (!(cin >> hw) || hw <= 0) {
        cout << "klaida iveskite skaiciu didesni uz 0." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Resize the students vector to accommodate 's' number of students
    students.resize(s);

    // Enter names and surnames manually for each student
    for (int i = 0; i < s; ++i) {
        cout << "iveskite " << i + 1 << " mokinio varda ir pavarde: ";
        cin >> students[i].name >> students[i].sur;
        
    }
generateRandomGrades(students, hw);
  

    // Ask the user whether to display the final average or median
    char displayChoice;
    cout << "rodyti vidurki (A) ar mediana (M)? ";
    cin >> displayChoice;

    // Display the selected information
    cout << left << setw(20) << "vardas" << setw(20) << "pavarde";
    if (displayChoice == 'A' || displayChoice == 'a')
        cout << setw(20) << "vidurkis";
    else if (displayChoice == 'M' || displayChoice == 'm')
        cout << setw(20) << "mediana";
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
                cout << "kiek mokiniu grupeje?";
                 while (!(cin >> s)) {
                 cout << "klaida. iveskite skaiciu" << endl;
                 cin.clear();
                cin.ignore();
        
                }
              students.resize(s);

            cout << "kiek namu darbu? ";
            while (!(cin >> hw)) {
            cout << "klaida. iveskite skaiciu" << endl;
            cin.clear();
            cin.ignore();
        
               }

                generateRandomData(students, hw);
                cout << "duomenys sugeneruoti sekmingai" << endl;

                char displayChoice;
                cout << "rodyti vidurki (A) ar mediana (M)? ";
                cin >> displayChoice;

                cout << left << setw(20) << "vardas" << setw(20) << "pavarde";
                if (displayChoice == 'A' || displayChoice == 'a')
                    cout << setw(20) << "vidurkis";
                else if(displayChoice == 'M' || displayChoice == 'm')
                    cout << setw(20) << "mediana";
                cout << endl;

                cout << "------------------------------------------------------------" << endl;
                for (int i = 0; i < students.size(); i++) {
                    cout << left << setw(20) << students[i].name << setw(20) << students[i].sur;
                    if (displayChoice == 'A' || displayChoice == 'a'){
                        cout << setw(20) << fixed << setprecision(2) << students[i].final_avg;
                    }
                    else{
                        cout << setw(20) << fixed << setprecision(2) << students[i].median;
                    }
                    cout << endl;
                }
                break;
            }
            case '4': {
                int N;
                cout << "Iveskite kieki studentu duomenu, kuri norite nuskaityti: ";
                while (!(cin >> N) || N <= 0){
                    cout << "Klaida. Iveskite skaiciu didesni uz 0"<< endl;
                    cin.clear();
                    cin.ignore();
                }

                readDataFromFile(students, hw, N);

                char displayChoice;
                cout << " Norite matyt vidurki (A) ar mediana (M)? ";
                 cin >> displayChoice;
                while (displayChoice != 'A' && displayChoice != 'a' && displayChoice != 'M' && displayChoice != 'm') {
                 cout << "Klaida. Iveskite 'A' arba 'M': ";
                cin >> displayChoice;
    }
                char sortChoice;
                cout << "Rusiuoti pagal (V) Varda, (P) Pavarde, (M) Mediana arba (A) Vidurki: ";
                cin >> sortChoice;
                while (sortChoice != 'V' && sortChoice != 'v' && sortChoice != 'P' && sortChoice != 'p' && sortChoice != 'M' && sortChoice != 'm' && sortChoice != 'A' && sortChoice != 'a'){
                cout << "Klaida. Prasome ivesti V jei norite rusiuoti pagal varda, P, jei pagal pavarde, M,  jei pagal mediana arba A, jei pagal vidurki " << endl;
                cin >> sortChoice;
   }
    switch (sortChoice){
        case 'V':
        case 'v':
            sort(students.begin(), students.end(), compareByName);
            break;
        case 'P':
        case 'p':
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
            cout << "Klaida. Duomenys bus rodomi neisrusiuoti." << endl;
            break;
    }

                cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
                if (displayChoice == 'A' || displayChoice == 'a')
                    cout << setw(20) << "Vidurkis";
                else if (displayChoice == 'M' || displayChoice == 'm')
                    cout << setw(20) << "Mediana";
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
            case '5':{
                ofstream out_file ("results.txt");
                if (!out_file){
                    cout << "nepavyko atidaryti failo" << endl;
                }
                int N;
                cout << "iveskite kiek duomenu norite nuskaityt: ";
                cin >> N;

                readDataFromFile(students, hw, N);

                char displayChoice;
                cout << "rodyti vidurki (A) ar mediana (M)? ";
                cin >> displayChoice;

                out_file << left << setw(20) << "vardas" << setw(20) << "pavarde";
                if (displayChoice == 'A' || displayChoice == 'a')
                    out_file << setw(20) << "vidurkis";
                else if (displayChoice == 'M' || displayChoice == 'm')
                    out_file << setw(20) << "mediana";
                out_file << endl;

                out_file << "------------------------------------------------------------" << endl;
                for (int i = 0; i < students.size(); i++) {
                    out_file << left << setw(20) << students[i].name << setw(20) << students[i].sur;
                    if (displayChoice == 'A' || displayChoice == 'a')
                        out_file << setw(20) << fixed << setprecision(2) << students[i].final_avg;
                    else if (displayChoice == 'M' || displayChoice == 'm')
                        out_file << setw(20) << fixed << setprecision(2) << students[i].median;
                    out_file << endl;
                }
                break;

            }
            case '6': {
                cout << "programa baigiama." << endl;
                break;
            }
            default:
                cout << "neteisinga ivestis." << endl;
        }
    } while (choice != '6');

    return 0;
}
