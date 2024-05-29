
/**
 * @file main.cpp
 * @brief A program for managing student data.
 */

#include "student.h"
#include "vektorius.h"

using namespace std;

/**
 * @brief Main function of the program.
 * @return 0 on successful execution.
 */
int main() {
    int studentukiekis; // Number of students
    double hw; // Number of homework assignments
    auto pradziaPrograma = DabartinisLaikas(); // Starting point for time generation
    char choice; // User choice for menu
    vector<Student> students; // Vector to store student data

    do {
        // Display menu options
        cout << "Meniu:" << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Ivesti vardus ir pavardes ranka, o pazymius generuoti atsitiktinai" << endl;
        cout << "3. Atsitiktinai generuoti viska" << endl;
        cout << "4. Nuskaityti duomenis is failo ir duomenis isvesti terminale" << endl;
        cout << "5. Nuskaityti duomenis is failo ir duomenis isvesti atskirame faile" << endl;
        cout << "6. Iveskite kieki studentu, kuri norite sugeneruoti " << endl;
        cout << "7. Vector konteinerio testavimas" << endl;
        cout << "8. Klases testavimas" << endl;
        cout << "9. Baigti programa" << endl;
        cout << "Jusu pasirinkimas: ";
        
        // Input validation for user choice
        while (!(cin >> choice)){
            cout << "Klaida. Prasome ivesti skaiciu, atitinkanti meniu opcijas" << endl;
            cin.clear();
            cin.ignore();
        }

        switch (choice) {
            case '1': {
                // Input the number of students
                cout << "Kiek studentu grupeje? ";
                while (!(cin >> studentukiekis) || studentukiekis < 0) {
                    cout << "Klaida. Iveskite tinkama skaiciu." << endl;
                    cin.clear();
                    cin.ignore();
                }
                students.resize(studentukiekis);

                // Input the number of homework assignments
                cout << "Kiek namu darbu? ";
                while (!(cin >> hw) || hw < 0) {
                    cout << "Klaida. Iveskite tinkama skaiciu." << endl;
                    cin.clear();
                    cin.ignore();
                }

                // Manually enter student data
                enterDataManually(students, hw);
                cout << "Duomenys ranka ivesti sekmingai." << endl;

                char displayChoice;
                // Choose to display average or median
                cout << "Norite matyt vidurki (A) ar mediana (M)? ";
                cin >> displayChoice;
                if (!(displayChoice == 'A' || displayChoice == 'a' || displayChoice == 'M' || displayChoice == 'm')) {
                    cout << "Klaida. Neteisingas pasirinkimas. Iveskite 'A' arba 'M'." << endl;
                    break;
                }

                // Display student data
                cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
                if (displayChoice == 'A' || displayChoice == 'a')
                    cout << setw(20) << "Vidurkis";
                else if (displayChoice == 'M' || displayChoice == 'm')
                    cout << setw(20) << "Mediana";
                cout << endl;
                cout << "------------------------------------------------------------" << endl;
                for (int i = 0; i < students.size(); i++) {
                    cout << left << setw(20) << students[i].getName() << setw(20) << students[i].getSurname();
                    if (displayChoice == 'A' || displayChoice == 'a')
                        cout << setw(20) << fixed << setprecision(2) << students[i].getFinalAvg();
                    else if (displayChoice == 'M' || displayChoice == 'm')
                        cout << setw(20) << fixed << setprecision(2) << students[i].getFinalMedian();
                    cout << endl;
                }
                break;
            }


           /**
 * @brief Perform actions for case '2'.
 * 
 * This function prompts the user to input the number of students in a group and the number of homework assignments.
 * It then resizes a vector to accommodate the specified number of students, prompts for each student's name,
 * generates random grades for the students, and displays either the average or median grades based on user choice.
 * 
 * @param students A vector containing objects representing students.
 * @param hw The number of homework assignments.
 */
void performCase2(std::vector<Student>& students, double hw) {
    int s; // Number of students
    double hw; // Number of homework assignments

    std::cout << "Kiek studentu grupeje? ";
    while (!(cin >> s) || s <= 0) {
        std::cout << "Klaida. Iveskite skaiciu didesni uz 0." << endl;
        cin.clear();
        cin.ignore();
    }

    std::cout << "Kiek namu darbu? ";
    while (!(cin >> hw) || hw <= 0) {
        std::cout << "Klaida. Iveskite skaiciu didesni uz 0." << endl;
        cin.clear();
        cin.ignore();
    }

    // Resize the vector to accommodate 's' students
    students.resize(s);

    for (int i = 0; i < s; ++i) {
        std::cout << "Iveskite " << i + 1 << " mokinio varda ir pavarde: ";
        string name, surname;
        cin >> name >> surname;
        students[i].setName(name);
        students[i].setSurname(surname);
    }

    generateRandomGrades(students, hw);

    char displayChoice;
    std::cout << "Norite matyt vidurki (A) ar mediana (M)? ";
    cin >> displayChoice;

    std::cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    if (displayChoice == 'A' || displayChoice == 'a')
        std::cout << setw(20) << "Vidurkis";
    else if (displayChoice == 'M' || displayChoice == 'm')
        std::cout << setw(20) << "Mediana";
    std::cout << endl;

    std::cout << "------------------------------------------------------------" << endl;
    for (int i = 0; i < students.size(); i++) {
        std::cout << left << setw(20) << students[i].getName() << setw(20) << students[i].getSurname();
        if (displayChoice == 'A' || displayChoice == 'a')
            std::cout << setw(20) << fixed << setprecision(2) << students[i].getFinalAvg();
        else if (displayChoice == 'M' || displayChoice == 'm')
            std::cout << setw(20) << fixed << setprecision(2) << students[i].getFinalMedian();
        std::cout << endl;
    }
    break;
}

//////////////////////////////////////////////////////////////////////////////////////////////



           /**
 * @brief Handles the case when user chooses option 3.
 *
 * This function prompts the user to input the number of students in the group and the number of homework assignments.
 * It then generates random data for the students and displays either their average grades or medians, based on user input.
 *
 * @param students A vector containing Student objects.
 */
case '3': {
    int studentukiekis; ///< Number of students in the group.
    double hw; ///< Number of homework assignments.

    // Prompt user to input the number of students in the group.
    std::cout << "Kiek studentu grupeje?";
    while (!(cin >> studentukiekis)) {
        std::cout << "Klaida. Iveskite tinkama skaiciu." << endl;
        cin.clear();
        cin.ignore();
    }
    students.resize(studentukiekis);

    // Prompt user to input the number of homework assignments.
    std::cout << "Kiek namu darbu? ";
    while (!(cin >> hw)) {
        std::cout << "Klaida. Iveskite tinkama skaiciu." << endl;
        cin.clear();
        cin.ignore();
    }

    // Generate random data for the students.
    generateRandomData(students, hw);
    std::cout << "Atsitikiniai duomenys sugeneruoti sekmingai." << endl;

    char displayChoice; ///< User's choice to display average (A) or median (M).
    std::cout << " Norite matyt vidurki (A) ar mediana (M)? ";
    cin >> displayChoice;

    // Display table headers.
    std::cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    if (displayChoice == 'A' || displayChoice == 'a')
        std::cout << setw(20) << "Vidurkis";
    else if (displayChoice == 'M' || displayChoice == 'm')
        std::cout << setw(20) << "Mediana";
    std::cout << endl;

    std::cout << "------------------------------------------------------------" << endl;
    // Display student data.
    for (int i = 0; i < students.size(); i++) {
        std::cout << left << setw(20) << students[i].getName() << setw(20) << students[i].getSurname();
        if (displayChoice == 'A' || displayChoice == 'a') {
            std::cout << setw(20) << fixed << setprecision(2) << students[i].getFinalAvg();
        } else {
            std::cout << setw(20) << fixed << setprecision(2) << students[i].getFinalMedian();
        }
        std::cout << endl;
    }
    break;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            /**
 * @brief Handles case '4' of the main program menu.
 * 
 * This function prompts the user to input the number of students' data to read,
 * then reads the data from a file, prompts the user to choose between displaying
 * average or median grades, and then sorts and displays the student data accordingly.
 * 
 * @param students Vector of Student objects to store student data.
 * @param hw Vector of vectors to store homework grades.
 */
case '4': {
    int N;
    // Prompt user to input the number of students' data to read
    std::cout << "Iveskite kieki studentu duomenu, kuri norite nuskaityti: ";
    while (!(cin >> N) || N <= 0){
        std::cout << "Klaida. Iveskite skaiciu didesni uz 0"<< endl;
        cin.clear();
        cin.ignore();
    }

    // Read data from file
    readDataFromFile(students, hw, N);

    char displayChoice;
    // Prompt user to choose between average or median grades
    std::cout << " Norite matyt vidurki (A) ar mediana (M)? ";
    cin >> displayChoice;
    while (displayChoice != 'A' && displayChoice != 'a' && displayChoice != 'M' && displayChoice != 'm') {
        std::cout << "Klaida. Iveskite 'A' arba 'M': ";
        cin.clear();
        cin.ignore();
        cin >> displayChoice;
    }

    char sortChoice;
    // Prompt user to choose sorting criteria
    std::cout << "Rusiuoti pagal (V) Varda, (P) Pavarde, (M) Mediana arba (A) Vidurki: ";
    cin >> sortChoice;
    while (sortChoice != 'V' && sortChoice != 'v' && sortChoice != 'P' && sortChoice != 'p' && sortChoice != 'M' && sortChoice != 'm' && sortChoice != 'A' && sortChoice != 'a'){
        std::cout << "Klaida. Prasome ivesti V jei norite rusiuoti pagal varda, P, jei pagal pavarde, M,  jei pagal mediana arba A, jei pagal vidurki " << endl;
        cin.clear();
        cin.ignore();
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
            std::cout << "Klaida. Duomenys bus rodomi neisrusiuoti." << endl;
            break;
    }

    // Display header
    std::cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    if (displayChoice == 'A' || displayChoice == 'a')
        std::cout << setw(20) << "Vidurkis";
    else if (displayChoice == 'M' || displayChoice == 'm')
        std::cout << setw(20) << "Mediana";
    std::cout << endl;

    // Display student data
    std::cout << "------------------------------------------------------------" << endl;
    for (int i = 0; i < students.size(); i++) {
        std::cout << left << setw(20) << students[i].getName() << setw(20) << students[i].getSurname();
        if (displayChoice == 'A' || displayChoice == 'a')
            std::cout << setw(20) << fixed << setprecision(2) << students[i].getFinalAvg();
        else if (displayChoice == 'M' || displayChoice == 'm')
            std::cout << setw(20) << fixed << setprecision(2) << students[i].getFinalMedian();
        std::cout << endl;
    }
    break;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

           /**
 * @brief Perform operations for case '5'.
 * 
 * This function handles operations for case '5' which includes reading data from a file,
 * sorting and displaying student information based on user input, and writing the results
 * to a file.
 * 
 * @param students Vector of Student objects to store student data.
 * @param hw Vector of vectors to store homework grades.
 */
case '5': {
    // Open output file
    ofstream out_file("rezultatai.txt");
    if (!out_file) {
        std::cout << "Klaida. Nepavyko atidaryti failo." << endl;
    }

    // Read number of students
    int N;
    std::cout << "Iveskite kieki studentu duomenu, kuri norite nuskaityti: ";
    while (!(cin >> N) || N <= 0) {
        std::cout << "Klaida. Iveskite skaiciu didesni uz 0" << endl;
        cin.clear();
        cin.ignore();
    }

    // Read data from file
    readDataFromFile(students, hw, N);

    // Choose display type (average or median)
    char displayChoice;
    std::cout << "Norite matyt vidurki (A) ar mediana (M)? ";
    while (!(cin >> displayChoice || displayChoice != 'A' && displayChoice != 'a' && displayChoice != 'M' && displayChoice != 'm')) {
        std::cout << "Klaida. Prasome ivesti A jei norite, kad rodytu vidurki arba M, jei norite, kad rodytu mediana" << endl;
        cin.clear();
        cin.ignore();
    }

    // Choose sorting criteria
    char sortChoice;
    std::cout << "Rusiuoti pagal (V) Varda, (P) Pavarde, (M) Mediana arba (A) Vidurki: ";
    cin >> sortChoice;
    while (sortChoice != 'V' && sortChoice != 'v' && sortChoice != 'P' && sortChoice != 'p' && sortChoice != 'M' && sortChoice != 'm' && sortChoice != 'A' && sortChoice != 'a') {
        std::cout << "Klaida. Prasome ivesti V jei norite rusiuoti pagal varda, P, jei pagal pavarde, M,  jei pagal mediana arba A, jei pagal vidurki " << endl;
        cin.clear();
        cin.ignore();
        cin >> sortChoice;
    }

    // Sort students based on user choice
    switch (sortChoice) {
        case 'V':
        case 'v':
            sort(students.begin(), students.end(), compareByName);
            break;
        case 'P':
        case 'p':
            sort(students.begin(), students.end(), compareBySurname);
            break;
        case 'M':
        case 'm':
            sort(students.begin(), students.end(), compareByMedian);
            break;
        case 'A':
        case 'a':
            sort(students.begin(), students.end(), compareByAvg);
            break;
        default:
            std::cout << "Klaida. Duomenys bus rodomi neisrusiuoti." << endl;
            break;
    }

    // Write headers to output file
    out_file << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    if (displayChoice == 'A' || displayChoice == 'a')
        out_file << setw(20) << "Vidurkis";
    else if (displayChoice == 'M' || displayChoice == 'm')
        out_file << setw(20) << "Mediana";
    out_file << endl;

    // Write separator to output file
    out_file << "------------------------------------------------------------" << endl;

    // Write student data to output file
    for (int i = 0; i < students.size(); i++) {
        out_file << left << setw(20) << students[i].getName() << setw(20) << students[i].getSurname();
        if (displayChoice == 'A' || displayChoice == 'a')
            out_file << setw(20) << fixed << setprecision(2) << students[i].getFinalAvg();
        else if (displayChoice == 'M' || displayChoice == 'm')
            out_file << setw(20) << fixed << setprecision(2) << students[i].getFinalMedian();
        out_file << endl;
    }
    break;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

                 /**
 * @brief Case '6' logic for generating and processing student data.
 * 
 * This case handles the generation, processing, and sorting of student data.
 * It prompts the user to input the number of students to generate, generates
 * student data, reads the data from file, calculates results, sorts the
 * students based on their results, and writes the sorted data to files.
 * 
 * @return 1 if an invalid input is provided, otherwise 0.
 */
case '6': {
    std::cout << "Iveskite kieki studentu, kuri norite sugeneruoti: ";
    std::cin >> studentukiekis;

    if (studentukiekis <= 0) {
        std::cerr << "neteisinga ivestis. iveskite teigiama skaiciu." << std::endl;
        return 1;
    }

    auto pradziaGeneravimas = DabartinisLaikas(); // Pradinis laiko taškas generavimui
    failuGeneravimas(studentukiekis, "studentai.txt");
    auto pabaigaGeneravimas = DabartinisLaikas(); // Baigtinis laiko taškas generavimui

    auto pradziaNuskaitymas = DabartinisLaikas(); // Pradinis laiko taškas nuskaitymui
    Nuskaitymas("studentai.txt", students, studentukiekis);
    auto pabaigaNuskaitymas = DabartinisLaikas(); // Baigtinis laiko taškas nuskaitymui

    // Spausdiname laiko skirtumus
    std::cout << "Failu generavimas užtruko: " << LaikoSkirtumas(pradziaGeneravimas, pabaigaGeneravimas) << " sekundžių." << std::endl;
    std::cout << "Failu nuskaitymas užtruko: " << LaikoSkirtumas(pradziaNuskaitymas, pabaigaNuskaitymas) << " sekundžių." << std::endl;

    char pasirinkimas;

    std::cout << "Pasirinkite, kaip norite matyti galutinį rezultatą:\n";
    std::cout << "V - pagal vidurkį\n";
    std::cout << "M - pagal medianą\n";
    std::cout << "Jūsų pasirinkimas (V/M): ";
    cin >> pasirinkimas;

    std::vector<Student> students;

    if (Nuskaitymas("studentai.txt", students, studentukiekis)) {
        auto pradziaLyginimas = DabartinisLaikas(); // Pradinis laiko taškas rūšiavimui
        calculateResults(students);
        auto pabaigaLyginimas = DabartinisLaikas(); // Baigtinis laiko taškas rūšiavimui

        auto pradziaIrasyti = DabartinisLaikas(); // Pradinis laiko taškas įrašymui
        rusiuoja_ir_raso_failus(students);
        auto pabaigaIrasyti = DabartinisLaikas(); // Baigtinis laiko taškas įrašymui

        // Spausdiname laiko skirtumus
        std::cout << "Studentų pažymių rūšiavimas užtruko: " << LaikoSkirtumas(pradziaLyginimas, pabaigaLyginimas) << " sekundžių." << endl;
        std::cout << "Duomenų įrašymas į failus užtruko: " << LaikoSkirtumas(pradziaIrasyti, pabaigaIrasyti) << " sekundžių." << endl;
        std::cout << "Duomenys sėkmingai išrūšiuoti ir išsaugoti į failus geruciai.txt ir bloguciai.txt." << std::endl;
    } else {
        std::cerr << "Nepavyko nuskaityti duomenų iš failo." << std::endl;
    }
    break;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /**
 * @brief Perform actions for case '7'.
 * 
 * This function executes the actions specific to case '7', which includes invoking the `testas()` function.
 * 
 * @return 0 upon successful completion.
 */                
case '7':{
    testas();
    break;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Case '8' of the program.
 *
 * This case compares the performance of std::vector and a custom Vector implementation
 * with different sizes of elements.
 * 
 * It measures the time taken to create vectors of Student objects using both std::vector 
 * and custom Vector.
 * 
 * @details
 * - The sizes of the vectors tested are: 10000, 100000, 1000000, and 10000000.
 * - For each size, it measures the time taken to create vectors using both std::vector 
 *   and custom Vector.
 * - The time measurements are printed in seconds.
 */
case '8': {
    unsigned int sizes[] = {10000, 100000, 1000000, 10000000};

    cout << "Vector<klase> v (std::vector):" << endl;
    for (unsigned int size : sizes) {
        auto pradziaV = DabartinisLaikas();
        vector<Student> v(size);
        auto pabaigaV = DabartinisLaikas();
        cout << "Laikas, skirtas std::vector su " << size << " dydziu: " << LaikoSkirtumas(pradziaV, pabaigaV) << " sekundziu." << endl;
    }

   
    cout << "Vector<klase> v2 (custom Vector):" << endl;
    for (unsigned int size : sizes) {
        auto pradziaV2 = DabartinisLaikas();
        Vector<Student> v2(size);
        auto pabaigaV2 = DabartinisLaikas();
        cout << "Laikas, skirtas custom Vector su " << size << " dydziu: " << LaikoSkirtumas(pradziaV2, pabaigaV2) << " sekundziu." << endl;
    }

        /*unsigned int sz = 100000000;  // 10000, 100000, 1000000, 10000000, 100000000
        std::vector<int> v1;
        int std_vector_perskirstymas = 0;
        for (int i = 1; i <= sz; ++i) {
            v1.push_back(i);
            if (v1.capacity() == v1.size()) {
                ++std_vector_perskirstymas;
            }
        }
        cout << "Atmintis buvo perskirstyta " << std_vector_perskirstymas << " kartu su std::vector" << endl;

        Vector<int> v2;
        int vector_perskirstymas = 0;
        for (int i = 1; i <= sz; ++i) {
            v2.push_back(i);
            if (v2.capacity() == v2.size()) {
                ++vector_perskirstymas;
            }
        } 
        cout << "Atmintis buvo perskirstyta " << vector_perskirstymas << " kartu su Vector" << endl;*/
    break;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief A switch statement handling user choices.
 * 
 * This switch statement handles user input choices within a loop until the user chooses to exit.
 * It provides messages for specific choices.
 * 
 * @param choice The user's input choice.
 */

        case '9':{
            std::cout << "Programa baigta." << endl;
            break;
        }
        default:{
            std::cout << "Klaidingas pasirinkimas. Prasome irasyti tinkama skaiciu." << endl;
            break;
        }
    }


    }
/**
 * @brief A loop continuing until the user chooses to exit.
 * 
 * This loop continues until the user inputs '9' to exit the program.
 * It measures the execution time of the program and displays it when the program ends.
 */
    while (choice != '9');
      auto pabaigaPrograma = DabartinisLaikas(); // Baigtinis laiko taškas programai
      std::cout << "Programos vykdymas uztruko: " << LaikoSkirtumas(pradziaPrograma, pabaigaPrograma) << " sekundziu." << endl;
/**
 * @brief Main function of the program.
 * 
 * This function executes the main logic of the program, including user interaction and execution time measurement.
 * It returns 0 upon successful execution.
 * 
 * @return 0 upon successful execution.
 */
    return 0;

  }