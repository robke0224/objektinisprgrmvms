#include <deque>
#include "student.h"

void generateRandomGrades(std::deque<Student>& students, double hw) {
    for (int i = 0; i < students.size(); ++i) {
        // random pazymiukai
        students[i].grades.resize(static_cast<int>(hw));
        for (int j = 0; j < hw; ++j) {
            students[i].grades[j] = rand() % 10 + 1;
        }

        // random egzas
        students[i].exam_results = rand() % 10 + 1;

        // galutinio mediana arba vidurkis
        double total_grades = accumulate(students[i].grades.begin(), students[i].grades.end(), 0.0);
        students[i].final_avg = (total_grades / hw) * 0.4 + (students[i].exam_results) * 0.6;
        students[i].median = calculateMedian(students[i].grades);
    }
}

void generateRandomData(std::deque<Student>& students, double hw) {
    string first_names[] = {"Jonas", "Emanuelis", "Mikas", "Adomas", "Vilius", "Lukas", "Tomas", "Juozas", "Benas", "Edas"};
    string last_names[] = {"Pavardukas", "Pavardelis", "Pavardytelis", "Pavardenis", "Pavardziukas", "Pavv", "Pavardaitis", "Pavardis", "Pavpav", "Pavardeliukas"};

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

double calculateMedian(std::deque<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (n % 2 == 0) {
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    } else {
        return arr[n/2];
    }
}

void readDataFromFile(std::deque<Student>& students, double& hw, int N) {
    try {
        ifstream file;
        file.open("studentai1000000.txt");

        if (!file) {
            throw runtime_error("Nepavyko atidaryti failo");
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
void enterDataManually(std::deque<Student>& students, double hw) {
    try {
        for (int i = 0; i < students.size(); ++i) {
            cout << "Iveskite " << i + 1 << " mokinio varda ir pavarde: ";
            cin >> students[i].name >> students[i].sur;

            students[i].grades.resize(static_cast<int>(hw));
            double total_grades = 0.0;

            for (int j = 0; j < hw; ++j) {
                cout << "Iveskite mokinio pazymi uz " << j + 1 << " namu darbus: ";

                while (true) {
                    if (!(cin >> students[i].grades[j])) {
                        cout << "Klaida. Iveskite skaiciu." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else if (students[i].grades[j] < 1 || students[i].grades[j] > 10) {
                        cout << "Klaida. Skaicius privalo priklausyti intervalui nuo 1 iki 10." << endl;
                    } else {
                        break;  // iseina is loopo jeigu neteisingas inputas
                    }
                }

                total_grades += students[i].grades[j];
            }

            do {
                cout << "Iveskite " << i + 1 << " mokinio egzamino rezultata: ";
                if (!(cin >> students[i].exam_results)) {
                    cout << "Klaida. Iveskite skaiciu." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else if (students[i].exam_results < 1 || students[i].exam_results > 10) {
                    cout << "Klaida. Skaicius privalo priklausyti intervalui nuo 1 iki 10." << endl;
                }
            } while (cin.fail() || students[i].exam_results < 1 || students[i].exam_results > 10);

            students[i].final_avg = 0.4 * (total_grades / hw) + 0.6 * students[i].exam_results; //vidurkis
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
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

int generateRandomNumber(int min, int max) {
    static mt19937 rng(time(nullptr));
    uniform_int_distribution<int> distribution(min, max);
    return distribution(rng);
}
double calculateAverage(const deque<int>& pazymiai) {
    double sum = 0;
    for (size_t j = 0; j < pazymiai.size(); ++j) {
        sum += pazymiai[j];
    }
    return sum / pazymiai.size();
}
void failuGeneravimas(int studentu_kiekis, const std::string& failo_pavadinimas) {
    ofstream outFile(failo_pavadinimas);

    if (!outFile.is_open()) {
        cerr << "Nepavyko atidaryti failo: " << failo_pavadinimas << endl;
        return;
    }

    outFile << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 0; i< 10; i++){
    outFile << left << setw(2) << "ND" << i+1 << "   ";
    }
    outFile << endl;
    outFile << "--------------------------------------------------------------------------------------------------" << endl;


    for (int i = 0; i < studentu_kiekis; i++) {
        outFile << "Vardas" << i + 1 << "           " << "Pavarde" << i + 1 << "              " << fixed << setprecision(20);
        for (int j = 0; j < 11; j++) {
            int pazymys = rand() % 10 + 1; // Generuojame pažymį nuo 1 iki 10
            outFile << setw(6) << pazymys; // Įrašome pažymį į failą
        }
        outFile << endl; // Nauja eilutė po kiekvieno studento duomenų
    }

    outFile.close();
    cout << "Failas " << failo_pavadinimas << " sukurtas sekmingai." << endl;
}


bool Nuskaitymas(const std::string& failo_pavadinimas, std::deque<Student>& students, int studentukiekis) {
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

        iss >> studentas.name >> studentas.sur;

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

        // Paskutinis pažymys yra egzamino pažymys
        if (!studentas.pazymiai.empty()) {
            studentas.exam_results = studentas.pazymiai.back();
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

void calculateResults(std::deque<Student>& stud) {
    for (int i = 0; i < stud.size(); ++i) {
        // Apskaičiuojame vidurkį
        double sum = std::accumulate(stud[i].pazymiai.begin(), stud[i].pazymiai.end(), 0.0);
        double vid = sum / stud[i].pazymiai.size();
        stud[i].gal_vid = (0.4 * vid + 0.6 * stud[i].exam_results);

        // Apskaičiuojame medijaną
        std::sort(stud[i].pazymiai.begin(), stud[i].pazymiai.end());
        if (!stud[i].pazymiai.empty()) {
            if (stud[i].pazymiai.size() % 2 == 0) {
                stud[i].gal_med = ((stud[i].pazymiai[stud[i].pazymiai.size() / 2 - 1] + stud[i].pazymiai[stud[i].pazymiai.size() / 2]) / 2.0 * 0.4) + 0.6 * stud[i].exam_results;
            } else {
                stud[i].gal_med = (stud[i].pazymiai[stud[i].pazymiai.size() / 2] * 0.4) + (0.6 * stud[i].exam_results);
            }
        } else {
            stud[i].gal_med = 0.6 * stud[i].exam_results;
        }

        stud[i].final_avg = stud[i].gal_vid; // Nustatome galutinį vidurkį kaip final_avg
    }
}

// Funkcija skaičiuoja vidurkį pagal studento pažymius
double skaiciuotiVidurki(const std::deque<int>& pazymiai) {
    double sum = 0.0;
    for (int pazymys : pazymiai) {
        sum += pazymys;
    }
    return sum / pazymiai.size();
}

// Funkcija, kuri tikrina, ar studento vidurkis yra >= 5.0
bool arGerasStudentas(const Student& student) {
    return skaiciuotiVidurki(student.pazymiai) >= 5.0;
}

// Funkcija, kuri lygina studentus pagal vidurkį
bool lygintiPagalVidurki(const Student& a, const Student& b) {
    return skaiciuotiVidurki(a.pazymiai) > skaiciuotiVidurki(b.pazymiai);
}

void rūšiuoja_ir_rašo_failus(const std::deque<Student>& students) {
    // Kopijuojame studentus į laikiną konteinerį
    std::deque<Student> tempStudents = students;

    // Surūšiuojame studentus pagal vidurkį
    std::sort(tempStudents.begin(), tempStudents.end(), lygintiPagalVidurki);

    // Naudojame partition point, kad išskirtume gerus mokinius
    auto partition_point = std::partition(tempStudents.begin(), tempStudents.end(), arGerasStudentas);

    // Studentai su vidurkiu 5 ir daugiau
    std::deque<Student> geriMokiniai(tempStudents.begin(), partition_point);
    // Studentai su vidurkiu mažesniu nei 5
    std::deque<Student> blogiMokiniai(partition_point, tempStudents.end());

    // Rašome studentus į atskirus failus

    // geri i faila
    std::ofstream kietiakai("geruciai.txt");
    if (kietiakai.is_open()) {
        kietiakai << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
        kietiakai << std::left << std::setw(10) << "Galutinis" << std::endl;
        kietiakai << "--------------------------------------------------------------------------------------" << std::endl;

        for (const auto& student : geriMokiniai) {
            kietiakai << std::left << std::setw(20) << student.name << std::setw(20) << student.sur;
            kietiakai << std::left << std::setw(10) << skaiciuotiVidurki(student.pazymiai) << std::endl;
        }
        kietiakai.close();
    } else {
        std::cerr << "Nepavyko atidaryti failo geruciai.txt" << std::endl;
    }

    // blogi i faila
    std::ofstream bloguciai("bloguciai.txt");
    if (bloguciai.is_open()) {
        bloguciai << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
        bloguciai << std::left << std::setw(10) << "Galutinis" << std::endl;
        bloguciai << "--------------------------------------------------------------------------------" << std::endl;

        for (const auto& student : blogiMokiniai) {
            bloguciai << std::left << std::setw(20) << student.name << std::setw(20) << student.sur;
            bloguciai << std::left << std::setw(10) << skaiciuotiVidurki(student.pazymiai) << std::endl;
        }
        bloguciai.close();
    } else {
        std::cerr << "Nepavyko atidaryti failo bloguciai.txt";
    }
}
