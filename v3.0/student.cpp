/**
 * @file student_grades.cpp
 * @brief Implementation of functions to generate and read student data, including random grades generation and reading from a file.
 */

#include "student.h"
#include "vektorius.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * @brief Generates random grades for each student in the provided vector.
 * 
 * @param students Vector of students for whom random grades will be generated.
 * @param hw Number of homework assignments to generate grades for.
 */
void generateRandomGrades(Vector<Student>& students, double hw) {
    for (int i = 0; i < students.size(); ++i) {
        // Generate random grades for homework assignments
        Vector<int> new_grades;
        for (int j = 0; j < hw; ++j) {
            new_grades.push_back(rand() % 10 + 1);
        }
        students[i].setGrades(new_grades);

        // Generate random exam result
        students[i].setExamResult(rand() % 10 + 1);

        // Calculate final average and median
        double total_grades = accumulate(new_grades.begin(), new_grades.end(), 0.0);
        students[i].setFinalAvg((total_grades / hw) * 0.4 + (students[i].getExamResult()) * 0.6);
        students[i].setFinalMedian(calculateMedian(new_grades));
    }
}

/**
 * @brief Generates random data for each student in the provided vector, including names and grades.
 * 
 * @param students Vector of students for whom random data will be generated.
 * @param hw Number of homework assignments to generate grades for.
 */
void generateRandomData(Vector<Student>& students, double hw) {
    string first_names[] = {"Jonas", "Emanuelis", "Mikas", "Adomas", "Vilius", "Lukas", "Tomas", "Juozas", "Benas", "Edas"};
    string last_names[] = {"Pavardukas", "Pavardelis", "Pavardytelis", "Pavardenis", "Pavardziukas", "Pavv", "Pavardaitis", "Pavardis", "Pavpav", "Pavardeliukas"};

    for (int i = 0; i < students.size(); ++i) {
        students[i].setName(first_names[rand() % 10]);
        students[i].setSurname(last_names[rand() % 10]);

        // Generate random grades for homework assignments
        Vector<int> new_grades;
        double total_grades = 0.0;
        for (int j = 0; j < hw; ++j) {
            int grade = rand() % 10 + 1;
            new_grades.push_back(grade);
            total_grades += grade;
        }
        students[i].setGrades(new_grades);

        // Calculate final average and median for homework
        students[i].setFinalAvg(total_grades / hw);
        students[i].setFinalMedian(calculateMedian(new_grades));

        // Generate random exam result
        students[i].setExamResult(rand() % 10 + 1);

        // Calculate final average including the exam result
        students[i].setFinalAvg(0.4 * students[i].getFinalAvg() + 0.6 * students[i].getExamResult());
    }
}

/**
 * @brief Calculates the median of the given vector of integers.
 * 
 * @param arr Vector of integers for which the median will be calculated.
 * @return Median value of the vector.
 */
double calculateMedian(Vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (n % 2 == 0) {
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    } else {
        return arr[n/2];
    }
}

/**
 * @brief Reads student data from a file and stores it in the provided vector.
 * 
 * @param students Vector to store the read student data.
 * @param hw Reference to store the number of homework assignments.
 * @param N Number of students to read from the file.
 */
void readDataFromFile(Vector<Student>& students, double& hw, int N) {
    try {
        ifstream file("studentai1000000.txt");

        if (!file) {
            throw runtime_error("Failed to open file");
        }

        string line;
        getline(file, line);  // Skip header line

        int count = 0;
        while (getline(file, line) && count < N) {
            istringstream iss(line);
            Student student;
            string name, surname;
            iss >> name >> surname;
            student.setName(name);
            student.setSurname(surname);

            int grade;
            while (iss >> grade) {
                student.setSingleGrade(grade);
            }
            student.setExamResult(student.getGrades().back());
            student.getGrades().pop_back();

            // Calculate final average and median for homework
            double finalAvg = 0.0;
            double median = 0.0;
            if (!student.getGrades().empty()) {
                finalAvg = accumulate(student.getGrades().begin(), student.getGrades().end(), 0.0) / student.getGrades().size();
                Vector<int> sortedGrades = student.getGrades();
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



/**
 * @brief Manually enter data for each student.
 *
 * This function prompts the user to enter the name, surname, homework grades, and exam result
 * for each student in the provided vector. It calculates the final average for each student
 * based on the homework grades and exam result, and updates the corresponding student objects.
 *
 * @param students A vector of Student objects to be populated with data.
 * @param hw The number of homework assignments per student.
 *
 * @note This function assumes that each Student object in the vector already has default or
 *       initialized values for other attributes (e.g., ID).
 * @note Exception handling is implemented to handle input errors gracefully.
 */
void enterDataManually(Vector<Student>& students, double hw) {
    try {
        for (int i = 0; i < students.size(); ++i) {
            cout << "Iveskite " << i + 1 << " mokinio varda ir pavarde: ";
            string name, surname;
            cin >> name >> surname;
            students[i].setName(name);
            students[i].setSurname(surname);

            Vector<int> grades;
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


/**
 * @brief Compares two students by their names.
 * 
 * @param a The first student to compare.
 * @param b The second student to compare.
 * @return true if the name of student a is less than the name of student b, false otherwise.
 */
bool compareByName(const Student& a, const Student& b) {
    return a.getName() < b.getName();
}

/**
 * @brief Compares two students by their surnames.
 * 
 * @param a The first student to compare.
 * @param b The second student to compare.
 * @return true if the surname of student a is less than the surname of student b, false otherwise.
 */
bool compareBySurname(const Student& a, const Student& b) {
    return a.getSurname() < b.getSurname();
}

/**
 * @brief Compares two students by their final median grades.
 * 
 * @param a The first student to compare.
 * @param b The second student to compare.
 * @return true if the final median grade of student a is less than that of student b, false otherwise.
 */
bool compareByMedian(const Student& a, const Student& b) {
    return a.getFinalMedian() < b.getFinalMedian();
}

/**
 * @brief Compares two students by their final average grades.
 * 
 * @param a The first student to compare.
 * @param b The second student to compare.
 * @return true if the final average grade of student a is less than that of student b, false otherwise.
 */
bool compareByAvg(const Student& a, const Student& b) {
    return a.getFinalAvg () < b.getFinalAvg();
}

/**
 * @brief Generates a random number between given min and max values.
 * 
 * @param min The minimum value for the random number.
 * @param max The maximum value for the random number.
 * @return A random number between min and max (inclusive).
 */
int generateRandomNumber(int min, int max) {
    static mt19937 rng(time(nullptr)); // Static instance of random number generator
    uniform_int_distribution<int> distribution(min, max); // Uniform distribution between min and max
    return distribution(rng); // Generate and return the random number
}

/**
 * @brief Calculates the average of grades in a vector.
 * 
 * @param pazymiai Vector containing grades.
 * @return The average of grades in the vector.
 */
double calculateAverage(const Vector<int>& pazymiai) {
    double sum = 0; // Initialize sum
    for (size_t j = 0; j < pazymiai.size(); ++j) {
        sum += pazymiai[j]; // Add each grade to the sum
    }
    return sum / pazymiai.size(); // Calculate and return the average
}

/**
 * @brief Generates student data and writes it to a file.
 * 
 * This function generates student data consisting of names, surnames, and grades, and writes it to a specified file.
 * 
 * @param studentu_kiekis The number of students to generate data for.
 * @param failo_pavadinimas The name of the file to write the data to.
 */
void failuGeneravimas(int studentu_kiekis, const std::string& failo_pavadinimas) {
    std::ofstream outFile(failo_pavadinimas);

    if (!outFile.is_open()) {
        std::cerr << "Nepavyko atidaryti failo: " << failo_pavadinimas << std::endl;
        return;
    }

    outFile << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
    for (int i = 0; i< 10; i++){
        outFile << std::left << std::setw(2) << "ND" << i+1 << "   ";
    }
    outFile << std::endl;
    outFile << "--------------------------------------------------------------------------------------------------" << std::endl;

    for (int i = 0; i < studentu_kiekis; i++) {
        outFile << "Vardas" << i + 1 << "           " << "Pavarde" << i + 1 << "              " << std::fixed << std::setprecision(20);
        for (int j = 0; j < 11; j++) {
            int pazymys = rand() % 10 + 1; // Generuojame pažymį nuo 1 iki 10
            outFile << std::setw(6) << pazymys; // Įrašome pažymį į failą
        }
        outFile << std::endl; // Nauja eilutė po kiekvieno studento duomenų
    }

    outFile.close();
    std::cout << "Failas " << failo_pavadinimas << " sukurtas sekmingai." << std::endl;
}

/**
 * @brief Reads student data from a file.
 * 
 * This function reads student data from a specified file and populates a vector of Student objects.
 * 
 * @param failo_pavadinimas The name of the file to read the data from.
 * @param students A vector to store the Student objects.
 * @param studentukiekis The number of students in the file.
 * @return True if the file was successfully read, false otherwise.
 */
bool Nuskaitymas(const std::string& failo_pavadinimas, Vector<Student>& students, int studentukiekis) {
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief Returns the current time as a steady clock time point.
 * 
 * @return std::chrono::steady_clock::time_point The current time.
 */
std::chrono::steady_clock::time_point DabartinisLaikas() {
    return std::chrono::steady_clock::now();
}

/**
 * @brief Calculates the difference in seconds between two steady clock time points.
 * 
 * @param pradzia The starting time point.
 * @param pabaiga The ending time point.
 * @return double The time difference in seconds.
 */
double LaikoSkirtumas(const std::chrono::steady_clock::time_point& pradzia, const std::chrono::steady_clock::time_point& pabaiga) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga - pradzia).count() / 1000.0;
}

/**
 * @brief Calculates final results for each student based on their grades and exam result.
 * 
 * @param stud Vector of Student objects to calculate results for.
 */
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Calculates the average based on student grades.
 * 
 * @param pazymiai Vector of student grades.
 * @return double The calculated average.
 */
double skaiciuotiVidurki(const Vector<int>& pazymiai) {
    double sum = 0.0;
    for (int pazymys : pazymiai) {
        sum += pazymys;
    }
    return sum / pazymiai.size();
}

/**
 * @brief Checks if a student is considered good based on average grade.
 * 
 * @param student The student object.
 * @return true if the student is considered good (average grade >= 5.0), false otherwise.
 */
bool arGerasStudentas(const Student& student) {
    return skaiciuotiVidurki(student.getGrades()) >= 5.0;
}

/**
 * @brief Compares two students based on their average grade.
 * 
 * @param a First student object.
 * @param b Second student object.
 * @return true if the average grade of student 'a' is greater than that of student 'b', false otherwise.
 */
bool lygintiPagalVidurki(const Student& a, const Student& b) {
    return skaiciuotiVidurki(a.getGrades()) > skaiciuotiVidurki(b.getGrades());
}

/**
 * @brief Sorts students, separates them into good and bad, and writes them to files.
 * 
 * @param students Vector of student objects.
 */
void rusiuoja_ir_raso_failus(Vector<Student>& students) {
    Vector<Student> tempStudents = students;

    // Sort students based on average grade
    std::sort(tempStudents.begin(), tempStudents.end(), lygintiPagalVidurki);

    // Partition students into good and bad
    auto partition_point = std::partition(tempStudents.begin(), tempStudents.end(), arGerasStudentas);

    Vector<Student> geriMokiniai(tempStudents.begin(), partition_point);
    Vector<Student> blogiMokiniai(partition_point, tempStudents.end());

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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Displays the result of a test.
 * 
 * This function prints a message indicating whether a test passed or failed.
 * 
 * @param success Flag indicating whether the test passed (true) or failed (false).
 * @param testName The name of the test.
 * 
 * @return void
 */
void testavimoRezultatai(bool success, const std::string& testName) {
    if (success) {
        std::cout << "Test '" << testName << "' passed" << std::endl;
    } else {
        std::cerr << "Test '" << testName << "' failed" << std::endl;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Test function for the Student class.
 *
 * This function tests the default constructor, setters, getters, copy constructor,
 * move constructor, copy assignment, and move assignment of the Student class.
 * It includes assertions to ensure that the class functions correctly.
 */
void testas() {
    // Test default constructor
    Student s;
    assert(s.getName().empty());
    assert(s.getSurname().empty());
    assert(s.getExamResult() == 0);
    assert(s.getFinalAvg() == 0.0);
    assert(s.getFinalMedian() == 0.0);

    // Test setters and getters
    string name = "J";
    string surname = "D";
    int examResult = 8;
    double finalAvg = 7;
    double finalMedian = 8;

    s.setName(name);
    assert(s.getName() == name);

    s.setSurname(surname);
    assert(s.getSurname() == surname);

    s.setExamResult(examResult);
    assert(s.getExamResult() == examResult);

    s.setFinalAvg(finalAvg);
    assert(s.getFinalAvg() == finalAvg);

    s.setFinalMedian(finalMedian);
    assert(s.getFinalMedian() == finalMedian);

    // Test copy constructor
    Student originalus;
    originalus.setName(name);
    originalus.setSurname(surname);
    originalus.setExamResult(7);
    Student kopija = originalus;
    assert(kopija.getName() == "J");
    assert(kopija.getSurname() == "D");
    assert(kopija.getExamResult() == 7);
    testavimoRezultatai(true, "kopijavimo konstruktorius");

    // Test move constructor
    Student movintas = std::move(originalus);
    assert(movintas.getName() == "J");
    assert(movintas.getSurname() == "D");
    assert(movintas.getExamResult() == 7);
    testavimoRezultatai(true, "move konstruktorius");

    // Test copy assignment
    Student originalus2;
    originalus2.setName(name);
    originalus2.setSurname(surname);
    originalus2.setExamResult(7);
    Student kopija2;
    kopija2 = originalus2;
    assert(kopija2.getName() == "J");
    assert(kopija2.getSurname() == "D");
    assert(kopija2.getExamResult() == 7);
    testavimoRezultatai(true, "kopijavimo assignmentas");

    // Test move assignment
    Student movintas2;
    movintas2 = std::move(originalus2);
    assert(movintas2.getName() == "J");
    assert(movintas2.getSurname() == "D");
    assert(movintas2.getExamResult() == 7);
    testavimoRezultatai(true, "move assignmentas");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief Test the performance of std::vector<Student> and Vector<Student>.
 *
 * This function compares the performance of std::vector<Student> and Vector<Student>
 * by measuring the time taken to initialize vectors of different sizes.
 * 
 * @note Requires the definition of DabartinisLaikas() and LaikoSkirtumas() functions.
 */
void testStdVectorPerformance() {
    unsigned int sizes[] = {10000, 100000, 1000000, 10000000, 100000000};

    cout << "std::vector<Student>:" << endl;
    for (unsigned int size : sizes) {
        auto pradziaV = DabartinisLaikas();
        vector<Student> v(size);
        auto pabaigaV = DabartinisLaikas();
        cout << "Laikas, skirtas std::vector su " << size << " dydziu: " << LaikoSkirtumas(pradziaV, pabaigaV) << " sekundziu." << endl;
    }
}

/**
 * @brief Test the performance of Vector<Student>.
 *
 * This function measures the time taken to initialize Vector<Student> with different sizes.
 * 
 * @note Requires the definition of DabartinisLaikas() and LaikoSkirtumas() functions.
 */
void testCustomVectorPerformance() {
    unsigned int sizes[] = {10000, 100000, 1000000, 10000000, 100000000};

    cout << "Vector<Student>:" << endl;
    for (unsigned int size : sizes) {
        auto pradziaV2 = DabartinisLaikas();
        Vector<Student> v2(size);
        auto pabaigaV2 = DabartinisLaikas();
        cout << "Laikas, skirtas Vector su " << size << " dydziu: " << LaikoSkirtumas(pradziaV2, pabaigaV2) << " sekundziu." << endl;
    }
}
