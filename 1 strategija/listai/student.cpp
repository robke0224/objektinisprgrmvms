#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <random>
#include <ctime>
#include <iomanip>
#include "student.h"


void generateRandomGrades(std::list<Student>& students, double hw) {
    for (auto& student : students) {
        // random pazymiukai
        for (int j = 0; j < hw; ++j) {
            student.grades.push_back(rand() % 10 + 1);
        }

        // random egzas
        student.exam_results = rand() % 10 + 1;

        // galutinio mediana arba vidurkis
        double total_grades = std::accumulate(student.grades.begin(), student.grades.end(), 0.0);
        student.final_avg = (total_grades / hw) * 0.4 + (student.exam_results) * 0.6;
        student.median = calculateMedian(student.grades);
    }
}

void generateRandomData(std::list<Student>& students, double hw) {
    std::string first_names[] = {"Jonas", "Emanuelis", "Mikas", "Adomas", "Vilius", "Lukas", "Tomas", "Juozas", "Benas", "Edas"};
    std::string last_names[] = {"Pavardukas", "Pavardelis", "Pavardytelis", "Pavardenis", "Pavardziukas", "Pavv", "Pavardaitis", "Pavardis", "Pavpav", "Pavardeliukas"};

    for (auto& student : students) {
        student.name = first_names[rand() % 10];
        student.sur = last_names[rand() % 10];

        double total_grades = 0.0;

        for (int j = 0; j < hw; ++j) {
            student.grades.push_back(rand() % 10 + 1);
            total_grades += student.grades.back();
        }

        student.final_avg = total_grades / hw;
        student.median = calculateMedian(student.grades);

        student.exam_results = rand() % 10 + 1;

        student.final_avg = 0.4 * student.final_avg + 0.6 * student.exam_results;
    }
}

double calculateMedian(list<int>& arr) {
    arr.sort();
    int n = arr.size();
    auto it = arr.begin();
    advance(it, n / 2);
    if (n % 2 == 0) {
        auto it2 = it;
        --it2;
        return static_cast<double>(*it + *it2) / 2.0;
    } else {
        return *it;
    }
}

void readDataFromFile(std::list<Student>& students, double& hw, int N) {
    try {
        std::ifstream file("studentai1000000.txt");
        if (!file.is_open()) {
            throw std::runtime_error("Nepavyko atidaryti failo");
        }
      
        std::string line;
        std::getline(file, line); // Assuming the first line is a header

        int count = 0;
        while (std::getline(file, line) && count < N) {
            std::istringstream iss(line);
            Student student;
            iss >> student.name >> student.sur;
            int grade;
            while (iss >> grade) {
                student.grades.push_back(grade);
            }
            if (!student.grades.empty()) {
                student.exam_results = student.grades.back();
                student.grades.pop_back();
                double finalAvg = std::accumulate(student.grades.begin(), student.grades.end(), 0.0) / student.grades.size();
                student.grades.sort();
                int size = student.grades.size();
                double median;
                if (size % 2 != 0) {
                    auto it = student.grades.begin();
                    std::advance(it, size / 2);
                    median = *it;
                } else {
                    auto it1 = student.grades.begin();
                    std::advance(it1, size / 2 - 1);
                    auto it2 = student.grades.begin();
                    std::advance(it2, size / 2);
                    median = (*it1 + *it2) / 2.0;
                }
                student.final_avg = finalAvg;
                student.median = median;
            }
            students.push_back(student);
            count++;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void enterDataManually(list<Student>& students, double hw) {
    try {
        int student_index = 1;
        for (auto& student : students) {
            cout << "Iveskite " << student_index << " mokinio varda ir pavarde: ";
            cin >> student.name >> student.sur;

            double total_grades = 0.0;

            for (int j = 0; j < hw; ++j) {
                cout << "Iveskite mokinio pazymi uz " << j + 1 << " namu darbus: ";

                while (true) {
                    double grade;
                    if (!(cin >> grade)) {
                        cout << "Klaida. Iveskite skaiciu." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else if (grade < 1 || grade > 10) {
                        cout << "Klaida. Skaicius privalo priklausyti intervalui nuo 1 iki 10." << endl;
                    } else {
                        student.grades.push_back(grade);
                        total_grades += grade;
                        break;
                    }
                }
            }

            do {
                cout << "Iveskite " << student_index << " mokinio egzamino rezultata: ";
                if (!(cin >> student.exam_results)) {
                    cout << "Klaida. Iveskite skaiciu." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else if (student.exam_results < 1 || student.exam_results > 10) {
                    cout << "Klaida. Skaicius privalo priklausyti intervalui nuo 1 iki 10." << endl;
                }
            } while (cin.fail() || student.exam_results < 1 || student.exam_results > 10);

            student.final_avg = 0.4 * (total_grades / hw) + 0.6 * student.exam_results; //vidurkis
            student_index++;
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
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
int generateRandomNumber(int min, int max) {
    static mt19937 rng(time(nullptr));
    uniform_int_distribution<int> distribution(min, max);
    return distribution(rng);
}

double calculateAverage(const std::list<int>& pazymiai) {
    return std::accumulate(pazymiai.begin(), pazymiai.end(), 0.0) / pazymiai.size();
}

void failuGeneravimas(int studentu_kiekis, const std::string& failo_pavadinimas) {
    std::ofstream outFile(failo_pavadinimas);

    if (!outFile.is_open()) {
        std::cerr << "Nepavyko atidaryti failo: " << failo_pavadinimas << std::endl;
        return;
    }

    outFile << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
    for (int i = 0; i < 10; i++) {
        outFile << std::left << std::setw(5) << "ND" << i + 1 << " ";
    }
    outFile << std::endl;
    outFile << "------------------------------------------------------------" << std::endl;

    for (int i = 0; i < studentu_kiekis; i++) {
        outFile << "Vardas" << i + 1 << "       " << "Pavarde" << i + 1 << "       " << std::fixed << std::setprecision(20);
        for (int j = 0; j < 11; j++) {
            int pazymys = generateRandomNumber(1, 10);
            outFile << std::setw(6) << pazymys;
        }
        outFile << std::endl;
    }

    outFile.close();
    std::cout << "Failas " << failo_pavadinimas << " sukurtas sekmingai." << std::endl;
}

bool Nuskaitymas(const std::string& failo_pavadinimas, std::list<Student>& students, int studentukiekis) {
    std::ifstream inFile(failo_pavadinimas);

    if (!inFile.is_open()) {
        std::cerr << "Nepavyko atidaryti failo: " << failo_pavadinimas << std::endl;
        return false;
    }

    std::string header;
    getline(inFile, header); // Skip header line

    std::string line;
    while (getline(inFile, line)) {
        std::istringstream iss(line);
        Student studentas;
        std::string grade;

        iss >> studentas.vardas >> studentas.pavarde;

        while (iss >> grade) {
            try {
                int pazymys = std::stoi(grade);
                if (pazymys >= 0 && pazymys <= 10) {
                    studentas.pazymiai.push_back(pazymys);
                }
            }
            catch (std::exception& e) {
                // Ignoruojame netinkamus pažymius
            }
        }

        if (!studentas.pazymiai.empty()) {
            studentas.egzaminoRezultatas = studentas.pazymiai.back();
            studentas.pazymiai.pop_back();
        }

        students.push_back(studentas);
    }

    inFile.close();
    return true;
}

std::chrono::steady_clock::time_point DabartinisLaikas() {
    return std::chrono::steady_clock::now();
}

double LaikoSkirtumas(const std::chrono::steady_clock::time_point& pradzia, const std::chrono::steady_clock::time_point& pabaiga) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga - pradzia).count() / 1000.0;
}

void calculateResults(std::list<Student>& stud) {
    for (auto& student : stud) {
        double sum = std::accumulate(student.pazymiai.begin(), student.pazymiai.end(), 0.0);
        double vid = sum / student.pazymiai.size();
        student.gal_vid = (0.4 * vid + 0.6 * student.egzaminoRezultatas);

        student.pazymiai.sort();
        if (!student.pazymiai.empty()) {
            if (student.pazymiai.size() % 2 == 0) {
                student.gal_med = ((std::prev(std::next(student.pazymiai.begin(), student.pazymiai.size() / 2)), 1) + *std::next(student.pazymiai.begin(), student.pazymiai.size() / 2)) / 2.0 * 0.4 + 0.6 * student.egzaminoRezultatas;
            } else {
                student.gal_med = (*std::next(student.pazymiai.begin(), student.pazymiai.size() / 2) * 0.4) + (0.6 * student.egzaminoRezultatas);
            }
        } else {
            student.gal_med = 0.6 * student.egzaminoRezultatas;
        }

        student.gal_vid = student.gal_vid;
    }
}

double skaiciuotiVidurki(const std::list<int>& pazymiai) {
    double sum = std::accumulate(pazymiai.begin(), pazymiai.end(), 0.0);
    return sum / pazymiai.size();
}

bool arGerasStudentas(const Student& student) {
    return skaiciuotiVidurki(student.pazymiai) >= 5.0;
}

bool lygintiPagalVidurki(const Student& a, const Student& b) {
    return skaiciuotiVidurki(a.pazymiai) > skaiciuotiVidurki(b.pazymiai);
}

void rūšiuoja_ir_rašo_failus(const std::list<Student>& students) {
    std::list<Student> tempStudents = students;

    tempStudents.sort(lygintiPagalVidurki);

    auto partition_point = std::partition(tempStudents.begin(), tempStudents.end(), arGerasStudentas);

    std::list<Student> geriMokiniai(tempStudents.begin(), partition_point);
    std::list<Student> blogiMokiniai(partition_point, tempStudents.end());

    std::ofstream kietiakai("geruciai.txt");
    if (kietiakai.is_open()) {
        kietiakai << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
        kietiakai << std::left << std::setw(10) << "Galutinis" << std::endl;
        kietiakai << "--------------------------------------------------------------------------------------" << std::endl;

        for (const auto& student : geriMokiniai) {
            kietiakai << std::left << std::setw(20) << student.vardas << std::setw(20) << student.pavarde;
            kietiakai << std::left << std::setw(10) << skaiciuotiVidurki(student.pazymiai) << std::endl;
        }
        kietiakai.close();
    } else {
        std::cerr << "Nepavyko atidaryti failo geruciai.txt" << std::endl;
    }

    std::ofstream bloguciai("bloguciai.txt");
if (bloguciai.is_open()) {
    bloguciai << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(10) << "Galutinis" << std::endl;
    bloguciai << "--------------------------------------------------------------------------------" << std::endl;

    for (const auto& student : blogiMokiniai) {
        bloguciai << std::left << std::setw(20) << student.vardas << std::setw(20) << student.pavarde << std::setw(10) << skaiciuotiVidurki(student.pazymiai) << std::endl;
    }
    bloguciai.close();
} else {
    std::cerr << "Nepavyko atidaryti failo bloguciai.txt";
}
}
