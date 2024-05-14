#include "student.h"

void generateRandomGrades(vector<Student>& students, double hw) {
    for (int i = 0; i < students.size(); ++i) {
        // Random grades
        vector<int> new_grades;
        for (int j = 0; j < hw; ++j) {
            new_grades.push_back(rand() % 10 + 1);
        }
        students[i].setGrades(new_grades);

        // Random exam result
        students[i].setExamResult(rand() % 10 + 1);

        // Calculate final average and median
        double total_grades = accumulate(new_grades.begin(), new_grades.end(), 0.0);
        students[i].setFinalAvg((total_grades / hw) * 0.4 + (students[i].getExamResult()) * 0.6);
        students[i].setFinalMedian(calculateMedian(new_grades));
    }
}

void generateRandomData(vector<Student>& students, double hw) {
    string first_names[] = {"Jonas", "Emanuelis", "Mikas", "Adomas", "Vilius", "Lukas", "Tomas", "Juozas", "Benas", "Edas"};
    string last_names[] = {"Pavardukas", "Pavardelis", "Pavardytelis", "Pavardenis", "Pavardziukas", "Pavv", "Pavardaitis", "Pavardis", "Pavpav", "Pavardeliukas"};

    for (int i = 0; i < students.size(); ++i) {
        students[i].setName(first_names[rand() % 10]);
        students[i].setSurname(last_names[rand() % 10]);

        // Random grades
        vector<int> new_grades;
        double total_grades = 0.0;
        for (int j = 0; j < hw; ++j) {
            int grade = rand() % 10 + 1;
            new_grades.push_back(grade);
            total_grades += grade;
        }
        students[i].setGrades(new_grades);

        students[i].setFinalAvg(total_grades / hw);
        students[i].setFinalMedian(calculateMedian(new_grades));

        students[i].setExamResult(rand() % 10 + 1);

        students[i].setFinalAvg(0.4 * students[i].getFinalAvg() + 0.6 * students[i].getExamResult());
    }
}


double calculateMedian(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (n % 2 == 0) {
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    } else {
        return arr[n/2];
    }
}

void readDataFromFile(vector<Student>& students, double& hw, int N) {
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
            string name, sur;
            iss >> name >> sur;
            student.setName(name);
            student.setSurname(sur);
            int grade;
            while (iss >> grade) {
                student.setSingleGrade(grade);
            }
            student.setExamResult(student.getGrades().back());
            student.getGrades().pop_back();

            double finalAvg = 0.0;
            double median = 0.0;
            if (!student.getGrades().empty()) {
                finalAvg = accumulate(student.getGrades().begin(), student.getGrades().end(), 0.0) / student.getGrades().size();
                vector<int> sortedGrades = student.getGrades();
                sort(sortedGrades.begin(), sortedGrades.end());
                int size = sortedGrades.size();
                if (size % 2 != 0)
                    median = sortedGrades[size / 2];
                else
                    median = (sortedGrades[size / 2 - 1] + sortedGrades[size / 2]) / 2.0;
            }
            student.setFinalAvg(finalAvg);
            student.setFinalMedian(median);
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
            cout << "Iveskite " << i + 1 << " mokinio varda ir pavarde: ";
            string name, surname;
            cin >> name >> surname;
            students[i].setName(name);
            students[i].setSurname(surname);

            vector<int> grades;
            double total_grades = 0.0;

            for (int j = 0; j < hw; ++j) {
                cout << "Iveskite mokinio pazymi uz " << j + 1 << " namu darbus: ";

                while (true) {
                    int grade;
                    if (!(cin >> grade)) {
                        cout << "Klaida. Iveskite skaiciu." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else if (grade < 1 || grade > 10) {
                        cout << "Klaida. Skaicius privalo priklausyti intervalui nuo 1 iki 10." << endl;
                    } else {
                        grades.push_back(grade);
                        total_grades += grade;
                        break;  // exit loop if input is correct
                    }
                }
            }

            students[i].setGrades(grades);

            do {
                cout << "Iveskite " << i + 1 << " mokinio egzamino rezultata: ";
                int exam_result;
                if (!(cin >> exam_result)) {
                    cout << "Klaida. Iveskite skaiciu." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else if (exam_result < 1 || exam_result > 10) {
                    cout << "Klaida. Skaicius privalo priklausyti intervalui nuo 1 iki 10." << endl;
                } else {
                    students[i].setExamResult(exam_result);
                }
            } while (cin.fail() || students[i].getExamResult() < 1 || students[i].getExamResult() > 10);

            students[i].setFinalAvg(0.4 * (total_grades / hw) + 0.6 * students[i].getExamResult()); //vidurkis
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}


bool compareByName(const Student& a, const Student& b) {
    return a.getName() < b.getName();
}
bool compareBySurname(const Student& a, const Student& b) {
    return a.getSurname() < b.getSurname();
}

bool compareByMedian(const Student& a, const Student& b) {
    return a.getFinalMedian() < b.getFinalMedian();
}

bool compareByAvg(const Student& a, const Student& b) {
    return a.getFinalAvg () < b.getFinalAvg();
}

int generateRandomNumber(int min, int max) {
    static mt19937 rng(time(nullptr));
    uniform_int_distribution<int> distribution(min, max);
    return distribution(rng);
}
double calculateAverage(const vector<int>& pazymiai) {
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


bool Nuskaitymas(const std::string& failo_pavadinimas, std::vector<Student>& students, int studentukiekis) {
    std::ifstream inFile(failo_pavadinimas);

    if (!inFile.is_open()) {
        std::cerr << "Nepavyko atidaryti failo: " << failo_pavadinimas << std::endl;
        return false;
    }

    // Praleidžiame pirmą ir antrą eilutes
    std::string header1, header2;
    getline(inFile, header1); // Skip first line
    getline(inFile, header2); // Skip second line

    std::string line;
    while (getline(inFile, line)) {
        std::istringstream iss(line);
        Student studentas;
        std::string grade;

        std::string name, surname;
        iss >> name >> surname;
        studentas.setName(name);
        studentas.setSurname(surname);

        while (iss >> grade) {
            try {
                int pazymys = std::stoi(grade);
                if (pazymys >= 0 && pazymys <= 10) {
                    studentas.setSingleGrade(pazymys);
                }
            }
            catch (std::exception& e) {
                // Ignoruojame netinkamus pažymius
            }
        }

        // Paskutinis pažymys yra egzamino pažymys
        if (!studentas.getGrades().empty()) {
            studentas.setExamResult(studentas.getGrades().back());
            studentas.getGrades().pop_back();
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
void calculateResults(std::vector<Student>& stud) {
    for (int i = 0; i < stud.size(); ++i) {
        std::vector<int> pazymiai = stud[i].getGrades();

        // Check if the grades vector is empty
        if (pazymiai.empty()) {
            std::cerr << "Klaida. Šis studentas neturi pažymių: " << stud[i].getName() << " " << stud[i].getSurname() << std::endl;
            continue;  // Skip this student and move to the next one
        }

        // Calculate average
        double sum = std::accumulate(pazymiai.begin(), pazymiai.end(), 0.0);
        double avg = sum / pazymiai.size();
        double gal_vid = 0.4 * avg + 0.6 * stud[i].getExamResult();

        // Calculate median
        std::sort(pazymiai.begin(), pazymiai.end());
        double gal_med = 0.0;
        if (pazymiai.size() % 2 == 0) {
            // Even number of grades
            int mid = pazymiai.size() / 2;
            gal_med = (pazymiai[mid - 1] + pazymiai[mid]) / 2.0; // Median of two middle values
        } else {
            // Odd number of grades
            gal_med = pazymiai[pazymiai.size() / 2]; // Middle value
        }

        // Apply the weight for the exam result
        gal_vid = 0.4 * gal_vid + 0.6 * stud[i].getExamResult();
        gal_med = 0.4 * gal_med + 0.6 * stud[i].getExamResult();

        // Set the calculated values
        stud[i].setFinalAvg(gal_vid);
        stud[i].setFinalMedian(gal_med);
    }
}


// Function to calculate average based on student grades
double skaiciuotiVidurki(const std::vector<int>& pazymiai) {
    double sum = 0.0;
    for (int pazymys : pazymiai) {
        sum += pazymys;
    }
    return sum / pazymiai.size();
}

// Function to check if a student is good based on average grade
bool arGerasStudentas(const Student& student) {
    return skaiciuotiVidurki(student.getGrades()) >= 5.0;
}

// Function to compare students based on average grade
bool lygintiPagalVidurki(const Student& a, const Student& b) {
    return skaiciuotiVidurki(a.getGrades()) > skaiciuotiVidurki(b.getGrades());
}

// Function to sort students, separate them into good and bad, and write to files
void rūšiuoja_ir_rašo_failus(std::vector<Student>& students) {
    std::vector<Student> tempStudents = students;

    // Sort students based on average grade
    std::sort(tempStudents.begin(), tempStudents.end(), lygintiPagalVidurki);

    // Partition students into good and bad
    auto partition_point = std::partition(tempStudents.begin(), tempStudents.end(), arGerasStudentas);

    std::vector<Student> geriMokiniai(tempStudents.begin(), partition_point);
    std::vector<Student> blogiMokiniai(partition_point, tempStudents.end());

    // Write good students to file
    std::ofstream geri_failas("geruciai.txt");
    if (geri_failas.is_open()) {
        geri_failas << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
        geri_failas << std::left << std::setw(10) << "Galutinis" << std::endl;
        geri_failas << "--------------------------------------------------------------------------------------" << std::endl;

        for (const auto& student : geriMokiniai) {
            geri_failas << std::left << std::setw(20) << student.getName() << std::setw(20) << student.getSurname();
            geri_failas << std::left << std::setw(10) << std::fixed << std::setprecision(1) << skaiciuotiVidurki(student.getGrades()) << std::endl;
        }
        geri_failas.close();
    } else {
        std::cerr << "Nepavyko atidaryti failo geruciai.txt" << std::endl;
    }

    // Write bad students to file
    std::ofstream blogi_failas("bloguciai.txt");
    if (blogi_failas.is_open()) {
        blogi_failas << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
        blogi_failas << std::left << std::setw(10) << "Galutinis" << std::endl;
        blogi_failas << "--------------------------------------------------------------------------------" << std::endl;

        for (const auto& student : blogiMokiniai) {
            blogi_failas << std::left << std::setw(20) << student.getName() << std::setw(20) << student.getSurname();
            blogi_failas << std::left << std::setw(10) << std::fixed << std::setprecision(1) << skaiciuotiVidurki(student.getGrades()) << std::endl;
        }
        blogi_failas.close();
    } else {
        std::cerr << "Nepavyko atidaryti failo bloguciai.txt";
    }
}
