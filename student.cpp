#include "student.h"

/**
 * @brief Generates random grades for students.
 * 
 * @param students Vector of Student objects.
 * @param hw Number of homework assignments.
 */
void generateRandomGrades(vector<Student>& students, double hw) {
    for (int i = 0; i < students.size(); ++i) {
        // Random grades for each student
        vector<int> new_grades;
        for (int j = 0; j < hw; ++j) {
            new_grades.push_back(rand() % 10 + 1); // Generating random grade for each homework
        }
        students[i].setGrades(new_grades);

        // Random exam result for each student
        students[i].setExamResult(rand() % 10 + 1);

        // Calculate final average and median for each student
        double total_grades = accumulate(new_grades.begin(), new_grades.end(), 0.0);
        students[i].setFinalAvg((total_grades / hw) * 0.4 + (students[i].getExamResult()) * 0.6);
        students[i].setFinalMedian(calculateMedian(new_grades));
    }
}

/**
 * @brief Generates random data for students.
 * 
 * @param students Vector of Student objects.
 * @param hw Number of homework assignments.
 */
void generateRandomData(vector<Student>& students, double hw) {
    // Array of first names
    string first_names[] = {"Jonas", "Emanuelis", "Mikas", "Adomas", "Vilius", "Lukas", "Tomas", "Juozas", "Benas", "Edas"};
    // Array of last names
    string last_names[] = {"Pavardukas", "Pavardelis", "Pavardytelis", "Pavardenis", "Pavardziukas", "Pavv", "Pavardaitis", "Pavardis", "Pavpav", "Pavardeliukas"};

    for (int i = 0; i < students.size(); ++i) {
        // Assign random first name and last name for each student
        students[i].setName(first_names[rand() % 10]);
        students[i].setSurname(last_names[rand() % 10]);

        // Random grades for each student
        vector<int> new_grades;
        double total_grades = 0.0;
        for (int j = 0; j < hw; ++j) {
            int grade = rand() % 10 + 1;
            new_grades.push_back(grade);
            total_grades += grade;
        }
        students[i].setGrades(new_grades);

        // Calculate final average and median for each student
        students[i].setFinalAvg(total_grades / hw);
        students[i].setFinalMedian(calculateMedian(new_grades));

        // Random exam result for each student
        students[i].setExamResult(rand() % 10 + 1);

        // Calculate final average using weights for each student
        students[i].setFinalAvg(0.4 * students[i].getFinalAvg() + 0.6 * students[i].getExamResult());
    }
}

/**
 * @brief Calculates the median of a vector of integers.
 * 
 * @param arr Vector of integers.
 * @return Median value.
 */
double calculateMedian(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (n % 2 == 0) {
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    } else {
        return arr[n/2];
    }
}

/**
 * @brief Reads data from a file and populates a vector of Student objects.
 * 
 * @param students Vector of Student objects.
 * @param hw Number of homework assignments.
 * @param N Maximum number of students to read.
 */
void readDataFromFile(vector<Student>& students, double& hw, int N) {
    try {
        ifstream file;
        file.open("studentai1000000.txt");

        if (!file) {
            throw runtime_error("Nepavyko atidaryti failo"); // Throw an exception if file opening fails
        }

        string line;
        getline(file, line); // Read and discard the first line

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
        cerr << e.what() << endl; // Print error message if an exception occurs
    }
}

/**
 * @brief Manually enters data for students.
 * 
 * @param students Vector of Student objects.
 * @param hw Number of homework assignments.
 */


/**
 * @brief Function to manually enter student data.
 * 
 * This function allows manual entry of student data, including names,
 * homework grades, and exam results. It calculates the final average
 * grade for each student based on the provided weights.
 * 
 * @param students A vector of Student objects to store student data.
 * @param hw The number of homework assignments.
 */
void enterDataManually(vector<Student>& students, double hw) {
    try {
        // Iterate over each student in the vector
        for (int i = 0; i < students.size(); ++i) {
            cout << "Enter the name and surname of student " << i + 1 << ": ";
            string name, surname;
            cin >> name >> surname;
            students[i].setName(name);
            students[i].setSurname(surname);

            vector<int> grades;
            double total_grades = 0.0;

            // Input grades for each homework assignment
            for (int j = 0; j < hw; ++j) {
                cout << "Enter the grade for homework " << j + 1 << ": ";

                while (true) {
                    int grade;
                    if (!(cin >> grade)) {
                        cout << "Error. Please enter a number." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else if (grade < 1 || grade > 10) {
                        cout << "Error. Grade must be between 1 and 10." << endl;
                    } else {
                        grades.push_back(grade);
                        total_grades += grade;
                        break;  // Exit loop if input is correct
                    }
                }
            }

            students[i].setGrades(grades);

            // Input exam result with error handling
            do {
                cout << "Enter the exam result for student " << i + 1 << ": ";
                int exam_result;
                if (!(cin >> exam_result)) {
                    cout << "Error. Please enter a number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else if (exam_result < 1 || exam_result > 10) {
                    cout << "Error. Exam result must be between 1 and 10." << endl;
                } else {
                    students[i].setExamResult(exam_result);
                }
            } while (cin.fail() || students[i].getExamResult() < 1 || students[i].getExamResult() > 10);

            // Calculate final average grade (weighted average)
            students[i].setFinalAvg(0.4 * (total_grades / hw) + 0.6 * students[i].getExamResult());
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

/**
 * @brief Comparator function to compare students by name.
 */
bool compareByName(const Student& a, const Student& b) {
    return a.getName() < b.getName();
}

/**
 * @brief Comparator function to compare students by surname.
 */
bool compareBySurname(const Student& a, const Student& b) {
    return a.getSurname() < b.getSurname();
}

/**
 * @brief Comparator function to compare students by final median grade.
 */
bool compareByMedian(const Student& a, const Student& b) {
    return a.getFinalMedian() < b.getFinalMedian();
}

/**
 * @brief Comparator function to compare students by final average grade.
 */
bool compareByAvg(const Student& a, const Student& b) {
    return a.getFinalAvg() < b.getFinalAvg();
}

/**
 * @brief Function to generate a random number within a specified range.
 * 
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 * @return int A random integer within the specified range.
 */
int generateRandomNumber(int min, int max) {
    static mt19937 rng(time(nullptr));
    uniform_int_distribution<int> distribution(min, max);
    return distribution(rng);
}

/**
 * @brief Function to calculate the average of a vector of integers.
 * 
 * @param pazymiai A vector of integers representing grades.
 * @return double The average grade.
 */
double calculateAverage(const vector<int>& pazymiai) {
    double sum = 0;
    for (size_t j = 0; j < pazymiai.size(); ++j) {
        sum += pazymiai[j];
    }
    return sum / pazymiai.size();
}

/**
 * @brief Function to generate a file with student data.
 * 
 * This function generates a file containing student data with randomly
 * generated grades for each homework assignment and exam.
 * 
 * @param studentu_kiekis The number of students.
 * @param failo_pavadinimas The filename for the generated file.
 */
void failuGeneravimas(int studentu_kiekis, const std::string& failo_pavadinimas) {
    ofstream outFile(failo_pavadinimas);

    if (!outFile.is_open()) {
        cerr << "Failed to open file: " << failo_pavadinimas << endl;
        return;
    }

    // Write headers to the file
    outFile << left << setw(20) << "Name" << setw(20) << "Surname";
    for (int i = 0; i < 10; i++) {
        outFile << left << setw(5) << "HW" << i + 1 << "   ";
    }
    outFile << endl;
    outFile << "--------------------------------------------------------------------------------------------------" << endl;

    // Generate student data with random grades
    for (int i = 0; i < studentu_kiekis; i++) {
        outFile << "Name" << i + 1 << "           " << "Surname" << i + 1 << "              " << fixed << setprecision(20);
        for (int j = 0; j < 11; j++) {
            int grade = generateRandomNumber(1, 10); // Generate a random grade between 1 and 10
            outFile << setw(6) << grade; // Write the grade to the file
        }
        outFile << endl; // Move to the next line after each student's data
    }

    outFile.close();
    cout << "File " << failo_pavadinimas << " created successfully." << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Reads student data from a file and populates a vector of Student objects.
 *
 * This function reads student data from a specified file, extracts student names
 * and grades, calculates exam results, and populates a vector of Student objects.
 *
 * @param failo_pavadinimas The name of the file to read student data from.
 * @param students          Reference to a vector of Student objects to populate.
 * @param studentukiekis    The number of students expected in the file.
 * @return True if the file is successfully opened and data is read, false otherwise.
 */
bool Nuskaitymas(const std::string& failo_pavadinimas, std::vector<Student>& students, int studentukiekis) {
    // Open the file
    std::ifstream inFile(failo_pavadinimas);
    
    // Check if the file is opened successfully
    if (!inFile.is_open()) {
        std::cerr << "Nepavyko atidaryti failo: " << failo_pavadinimas << std::endl;
        return false;
    }

    // Skip the headers
    std::string header1, header2;
    getline(inFile, header1); // Skip first line
    getline(inFile, header2); // Skip second line

    // Read student data from the file
    std::string line;
    while (getline(inFile, line)) {
        std::istringstream iss(line);
        Student studentas;
        std::string grade;
        
        // Extract student name and surname
        std::string name, surname;
        iss >> name >> surname;
        studentas.setName(name);
        studentas.setSurname(surname);
        
        // Extract and process grades
        while (iss >> grade) {
            try {
                int pazymys = std::stoi(grade);
                if (pazymys >= 0 && pazymys <= 10) {
                    studentas.setSingleGrade(pazymys);
                }
            } catch (std::exception& e) {
                // Ignore invalid grades
            }
        }

        // Set exam result and push the student to the vector
        if (!studentas.getGrades().empty()) {
            studentas.setExamResult(studentas.getGrades().back());
            studentas.getGrades().pop_back();
        }
        students.push_back(studentas);
    }

    inFile.close();
    return true;
}

/**
 * @brief Returns the current system time.
 *
 * @return The current system time as a steady_clock::time_point object.
 */
std::chrono::steady_clock::time_point DabartinisLaikas() {
    return std::chrono::steady_clock::now();
}

/**
 * @brief Calculates the time difference between two time points.
 *
 * @param pradzia  The starting time point.
 * @param pabaiga  The ending time point.
 * @return The time difference between the two time points in seconds.
 */
double LaikoSkirtumas(const std::chrono::steady_clock::time_point& pradzia, const std::chrono::steady_clock::time_point& pabaiga) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga - pradzia).count() / 1000.0;
}

/**
 * @brief Calculates final results for each student.
 *
 * This function calculates final average and median grades for each student based
 * on their individual grades and exam results. It updates the Student objects
 * accordingly.
 *
 * @param stud Reference to a vector of Student objects.
 */
void calculateResults(std::vector<Student>& stud) {
    for (int i = 0; i < stud.size(); ++i) {
        std::vector<int> pazymiai = stud[i].getGrades();

        // Check if the student has grades
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
            int mid = pazymiai.size() / 2;
            gal_med = (pazymiai[mid - 1] + pazymiai[mid]) / 2.0; // Median of two middle values
        } else {
            gal_med = pazymiai[pazymiai.size() / 2]; // Middle value
        }

        // Apply weight for exam result
        gal_vid = 0.4 * gal_vid + 0.6 * stud[i].getExamResult();
        gal_med = 0.4 * gal_med + 0.6 * stud[i].getExamResult();

        // Set calculated values
        stud[i].setFinalAvg(gal_vid);
        stud[i].setFinalMedian(gal_med);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief Function to calculate the average based on student grades.
 * 
 * @param pazymiai Vector of integers representing student grades.
 * @return double The calculated average of the grades.
 */
double skaiciuotiVidurki(const std::vector<int>& pazymiai) {
    double sum = 0.0;
    for (int pazymys : pazymiai) {
        sum += pazymys;
    }
    return sum / pazymiai.size();
}

/**
 * @brief Function to check if a student is good based on the average grade.
 * 
 * @param student The Student object to evaluate.
 * @return bool True if the student's average grade is greater than or equal to 5.0, false otherwise.
 */
bool arGerasStudentas(const Student& student) {
    return skaiciuotiVidurki(student.getGrades()) >= 5.0;
}

/**
 * @brief Function to compare two students based on their average grades.
 * 
 * @param a The first Student object.
 * @param b The second Student object.
 * @return bool True if the average grade of student 'a' is greater than that of student 'b', false otherwise.
 */
bool lygintiPagalVidurki(const Student& a, const Student& b) {
    return skaiciuotiVidurki(a.getGrades()) > skaiciuotiVidurki(b.getGrades());
}

/**
 * @brief Function to sort students, separate them into good and bad, and write to files.
 * 
 * @param students Vector of Student objects.
 */
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
};

/**
 * @brief Function to display test results.
 * 
 * @param success Indicates whether the test passed (true) or failed (false).
 * @param testName The name of the test.
 */
void testavimoRezultatai(bool success, const std::string& testName) {
    if (success) {
        std::cout << "Test '" << testName << "' passed" << std::endl;
    } else {
        std::cerr << "Test '" << testName << "' failed" << std::endl;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief A function to test various operations of the Student class.
 * 
 * This function tests the default constructor, setters, getters, copy constructor,
 * move constructor, copy assignment, and move assignment of the Student class.
 */
void testas() {
    // Test default constructor
    Student s;
    assert(s.getName().empty()); ///< Assert that name is empty
    assert(s.getSurname().empty()); ///< Assert that surname is empty
    assert(s.getExamResult() == 0); ///< Assert that exam result is 0
    assert(s.getFinalAvg() == 0.0); ///< Assert that final average is 0.0
    assert(s.getFinalMedian() == 0.0); ///< Assert that final median is 0.0

    // Test setters and getters
    string name = "J";
    string surname = "D";
    int examResult = 8;
    double finalAvg = 7;
    double finalMedian = 8;

    s.setName(name); ///< Set name
    assert(s.getName() == name); ///< Assert that name is set correctly

    s.setSurname(surname); ///< Set surname
    assert(s.getSurname() == surname); ///< Assert that surname is set correctly

    s.setExamResult(examResult); ///< Set exam result
    assert(s.getExamResult() == examResult); ///< Assert that exam result is set correctly

    s.setFinalAvg(finalAvg); ///< Set final average
    assert(s.getFinalAvg() == finalAvg); ///< Assert that final average is set correctly

    s.setFinalMedian(finalMedian); ///< Set final median
    assert(s.getFinalMedian() == finalMedian); ///< Assert that final median is set correctly

    // Test copy constructor
    Student originalus;
    
    originalus.setName(name);
    originalus.setSurname(surname);
    originalus.setExamResult(7);
    Student kopija = originalus;
    assert(kopija.getName() == "J"); ///< Assert that copied name is correct
    assert(kopija.getSurname() == "D"); ///< Assert that copied surname is correct
    assert(kopija.getExamResult() == 7); ///< Assert that copied exam result is correct
    testavimoRezultatai(true, "kopijavimo konstruktorius"); ///< Test copy constructor

    // Test move constructor
    Student movintas = std::move(originalus);
    assert(movintas.getName() == "J"); ///< Assert that moved name is correct
    assert(movintas.getSurname() == "D"); ///< Assert that moved surname is correct
    assert(movintas.getExamResult() == 7); ///< Assert that moved exam result is correct
    testavimoRezultatai(true, "move konstruktorius"); ///< Test move constructor

    // Test copy assignment
    Student originalus2;
    originalus2.setName(name);
    originalus2.setSurname(surname);
    originalus2.setExamResult(7);
    Student kopija2;
    kopija2 = originalus2;
    assert(kopija2.getName() == "J"); ///< Assert that copied name is correct
    assert(kopija2.getSurname() == "D"); ///< Assert that copied surname is correct
    assert(kopija2.getExamResult() == 7); ///< Assert that copied exam result is correct
    testavimoRezultatai(true, "kopijavimo assignmentas"); ///< Test copy assignment

    // Test move assignment
    Student movintas2;
    movintas2 = std::move(originalus2);
    assert(movintas2.getName() == "J"); ///< Assert that moved name is correct
    assert(movintas2.getSurname() == "D"); ///< Assert that moved surname is correct
    assert(movintas2.getExamResult() == 7); ///< Assert that moved exam result is correct
    testavimoRezultatai(true, "move assignmentas"); ///< Test move assignment
}
