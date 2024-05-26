#include "student.h"

/**
 * @brief The main function of the program.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    int studentukiekis; /**< Number of students */
    double hw; /**< Number of homework assignments */
    auto pradziaPrograma = DabartinisLaikas(); /**< Initial time point for generating */

    char choice; /**< User's menu choice */
    vector<Student> students; /**< Vector to store student objects */

    do {
        cout << "Meniu:" << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Ivesti vardus ir pavardes ranka, o pazymius generuoti atsitiktinai" << endl;
        cout << "3. Atsitiktinai generuoti viska" << endl;
        cout << "4. Nuskaityti duomenis is failo ir duomenis isvesti terminale" << endl;
        cout << "5. Nuskaityti duomenis is failo ir duomenis isvesti atskirame faile" << endl;
        cout << "6. Iveskite kieki studentu, kuri norite sugeneruoti " << endl;
        cout << "7. Testavimas" << endl;
        cout << "8. Baigti programa" << endl;
        cout << "Jusu pasirinkimas: ";

        // Input validation loop
        while (!(cin >> choice)){
            cout<< "Klaida. Prasome ivesti skaiciu, atitinkanti meniu opcijas"<< endl;
            cin.clear();
            cin.ignore();
        }

        switch (choice) {
            case '1': {
                // Manual data input
                cout << "Kiek studentu grupeje? ";
                while (!(cin >> studentukiekis) || studentukiekis < 0) {
                    cout << "Klaida. Iveskite tinkama skaiciu." << endl;
                    cin.clear();
                    cin.ignore();
                }
                students.resize(studentukiekis);

                cout << "Kiek namu darbu? ";
                while (!(cin >> hw) || hw < 0) {
                    cout << "Klaida. Iveskite tinkama skaiciu." << endl;
                    cin.clear();
                    cin.ignore();
                }

                enterDataManually(students, hw);
                cout << "Duomenys ranka ivesti sekmingai." << endl;

                char displayChoice;
                cout << "Norite matyt vidurki (A) ar mediana (M)? ";
                cin >> displayChoice;
                if (!(displayChoice == 'A' || displayChoice == 'a' || displayChoice == 'M' || displayChoice == 'm')) {
                    cout << "Klaida. Neteisingas pasirinkimas. Iveskite'A' arba 'M'." << endl;
                    break;
                }

                // Displaying student data
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
            case '2': {
                // Generating random data based on user-provided names
                int s;
                double hw;

                cout << "Kiek studentu grupeje? ";
                while (!(cin >> s) || s <= 0) {
                    cout << "Klaida. Iveskite skaiciu didesni uz 0." << endl;
                    cin.clear();
                    cin.ignore();
                }

                cout << "Kiek namu darbu? ";
                while (!(cin >> hw) || hw <= 0) {
                    cout << "Klaida. Iveskite skaiciu didesni uz 0." << endl;
                    cin.clear();
                    cin.ignore();
                }

                // Resize the vector to accommodate 's' students
                students.resize(s);

                // Input student names
                for (int i = 0; i < s; ++i) {
                    cout << "Iveskite " << i + 1 << " mokinio varda ir pavarde: ";
                    string name, surname;
                    cin >> name >> surname;
                    students[i].setName(name);
                    students[i].setSurname(surname);
                }

                // Generate random grades
                generateRandomGrades(students, hw);

                char displayChoice;
                cout << "Norite matyt vidurki (A) ar mediana (M)? ";
                cin >> displayChoice;

                // Displaying student data
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
/////////////////////////////////////////////////////////////////////////////////////////////////

           /**
 * @brief Handles case '3' for displaying randomly generated student data.
 *
 * @param none
 * @return void
 */
case '3': {
    int studentukiekis;
    double hw;

    cout << "Kiek studentu grupeje?";
    while (!(cin >> studentukiekis)) {
        cout << "Klaida. Iveskite tinkama skaiciu." << endl;
        cin.clear();
        cin.ignore();
    }
    students.resize(studentukiekis);

    cout << "Kiek namu darbu? ";
    while (!(cin >> hw)) {
        cout << "Klaida. Iveskite tinkama skaiciu." << endl;
        cin.clear();
        cin.ignore();
    }

    generateRandomData(students, hw);
    cout << "Atsitikiniai duomenys sugeneruoti sekmingai." << endl;

    char displayChoice;
    cout << " Norite matyt vidurki (A) ar mediana (M)? ";
    cin >> displayChoice;

    cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    if (displayChoice == 'A' || displayChoice == 'a')
        cout << setw(20) << "Vidurkis";
    else if (displayChoice == 'M' || displayChoice == 'm')
        cout << setw(20) << "Mediana";
    cout << endl;

    cout << "------------------------------------------------------------" << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << left << setw(20) << students[i].getName() << setw(20) << students[i].getSurname();
        if (displayChoice == 'A' || displayChoice == 'a') {
            cout << setw(20) << fixed << setprecision(2) << students[i].getFinalAvg();
        } else {
            cout << setw(20) << fixed << setprecision(2) << students[i].getFinalMedian();
        }
        cout << endl;
    }
    break;
}

/**
 * @brief Handles case '4' for reading student data from a file and displaying it.
 *
 * @param none
 * @return void
 */
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
        cin.clear();
        cin.ignore();
        cin >> displayChoice;
    }

    char sortChoice;
    cout << "Rusiuoti pagal (V) Varda, (P) Pavarde, (M) Mediana arba (A) Vidurki: ";
    cin >> sortChoice;
    while (sortChoice != 'V' && sortChoice != 'v' && sortChoice != 'P' && sortChoice != 'p' && sortChoice != 'M' && sortChoice != 'm' && sortChoice != 'A' && sortChoice != 'a'){
        cout << "Klaida. Prasome ivesti V jei norite rusiuoti pagal varda, P, jei pagal pavarde, M,  jei pagal mediana arba A, jei pagal vidurki " << endl;
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
        cout << left << setw(20) << students[i].getName() << setw(20) << students[i].getSurname();
        if (displayChoice == 'A' || displayChoice == 'a')
            cout << setw(20) << fixed << setprecision(2) << students[i].getFinalAvg();
        else if (displayChoice == 'M' || displayChoice == 'm')
            cout << setw(20) << fixed << setprecision(2) << students[i].getFinalMedian();
        cout << endl;
    }
    break;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

           /**
 * @brief Case '5' of the main menu: Perform sorting and display data in a specified format.
 * 
 * This case reads data from a file, sorts it based on user preference, and outputs the sorted data to a file.
 * The user can choose to display either the average or median of student grades.
 * 
 * @param students Vector containing student objects.
 * @param hw Vector containing homework grades.
 */
case '5':{
    // Open output file
    ofstream out_file ("rezultatai.txt");
    if (!out_file){
        cout << "Klaida. Nepavyko atidaryti failo." << endl;
    }

    // Read number of students
    int N;
    cout << "Iveskite kieki studentu duomenu, kuri norite nuskaityti: ";
    while (!(cin >> N) || N <= 0){
        cout << "Klaida. Iveskite skaiciu didesni uz 0"<< endl;
        cin.clear();
        cin.ignore();
    }

    // Read data from file
    readDataFromFile(students, hw, N);

    // Choose to display average (A) or median (M)
    char displayChoice;
    cout << "Norite matyt vidurki (A) ar mediana (M)? ";
    while (!(cin  >> displayChoice || displayChoice != 'A' && displayChoice != 'a' && displayChoice != 'M' && displayChoice != 'm')){
        cout << "Klaida. Prasome ivesti A jei norite, kad rodytu vidurki arba M, jei norite, kad rodytu mediana"<< endl;
        cin.clear();
        cin.ignore();
    }

    // Choose sorting method: Name (V), Surname (P), Median (M), or Average (A)
    char sortChoice;
    cout << "Rusiuoti pagal (V) Varda, (P) Pavarde, (M) Mediana arba (A) Vidurki: ";
    cin >> sortChoice;
    while (sortChoice != 'V' && sortChoice != 'v' && sortChoice != 'P' && sortChoice != 'p' && sortChoice != 'M' && sortChoice != 'm' && sortChoice != 'A' && sortChoice != 'a'){
        cout << "Klaida. Prasome ivesti V jei norite rusiuoti pagal varda, P, jei pagal pavarde, M,  jei pagal mediana arba A, jei pagal vidurki " << endl;
        cin.clear();
        cin.ignore();
        cin >> sortChoice;
    }

    // Sort students based on user choice
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

    // Output headers to file
    out_file << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    if (displayChoice == 'A' || displayChoice == 'a')
        out_file << setw(20) << "Vidurkis";
    else if (displayChoice == 'M' || displayChoice == 'm')
        out_file << setw(20) << "Mediana";
    out_file << endl;

    // Output student data to file
    out_file << "------------------------------------------------------------" << endl;
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                 /**
 * @brief Executes the selected functionality based on user input until the user chooses to exit.
 * 
 * @return 0 upon successful execution.
 */
do {
    // Switch statement to handle different user choices
    switch (choice) {
        case '6': {
            // Prompt user to input the number of students to generate
            std::cout << "Iveskite kieki studentu, kuri norite sugeneruoti: ";
            std::cin >> studentukiekis;

            // Validate input
            if (studentukiekis <= 0) {
                std::cerr << "neteisinga ivestis. iveskite teigiama skaiciu." << std::endl;
                return 1;
            }

            // Generate students and measure time
            auto pradziaGeneravimas = DabartinisLaikas(); // Pradinis laiko taškas generavimui
            failuGeneravimas(studentukiekis, "studentai.txt");
            auto pabaigaGeneravimas = DabartinisLaikas(); // Baigtinis laiko taškas generavimui

            // Read students from file and measure time
            auto pradziaNuskaitymas = DabartinisLaikas(); // Pradinis laiko taškas nuskaitymui
            Nuskaitymas("studentai.txt", students, studentukiekis);
            auto pabaigaNuskaitymas = DabartinisLaikas(); // Baigtinis laiko taškas nuskaitymui

            // Print time differences
            cout << "Failu generavimas užtruko: " << LaikoSkirtumas(pradziaGeneravimas, pabaigaGeneravimas) << " sekundžių." << endl;
            cout << "Failu nuskaitymas užtruko: " << LaikoSkirtumas(pradziaNuskaitymas, pabaigaNuskaitymas) << " sekundžių." << endl;

            // Prompt user for choice of displaying final results
            char pasirinkimas;
            cout << "Pasirinkite, kaip norite matyti galutinį rezultatą:\n";
            cout << "V - pagal vidurkį\n";
            cout << "M - pagal medianą\n";
            cout << "Jūsų pasirinkimas (V/M): ";
            cin >> pasirinkimas;

            // Calculate results based on user's choice
            std::vector<Student> students;
            if (Nuskaitymas("studentai.txt", students, studentukiekis)) {
                auto pradziaLyginimas = DabartinisLaikas(); // Pradinis laiko taškas rūšiavimui
                calculateResults(students);
                auto pabaigaLyginimas = DabartinisLaikas(); // Baigtinis laiko taškas rūšiavimui

                auto pradziaIrasyti = DabartinisLaikas(); // Pradinis laiko taškas įrašymui
                rūšiuoja_ir_rašo_failus(students);
                auto pabaigaIrasyti = DabartinisLaikas(); // Baigtinis laiko taškas įrašymui

                // Print time differences
                cout << "Studentų pažymių rūšiavimas užtruko: " << LaikoSkirtumas(pradziaLyginimas, pabaigaLyginimas) << " sekundžių." << endl;
                cout << "Duomenų įrašymas į failus užtruko: " << LaikoSkirtumas(pradziaIrasyti, pabaigaIrasyti) << " sekundžių." << endl;
                cout << "Duomenys sėkmingai išrūšiuoti ir išsaugoti į failus geruciai.txt ir bloguciai.txt." << std::endl;
            } else {
                std::cerr << "Nepavyko nuskaityti duomenų iš failo." << std::endl;
            }
            break;
        }

        case '7':{
            // Execute the test function
            testas();
            return 0;
        }

        case '8': {
            // Display exit message
            cout << "Programa baigta." << endl;
            break;
        }

        default:{
            // Display error message for invalid choice
            cout << "Klaidingas pasirinkimas. Prasome irasyti tinkama skaiciu." << endl;
            break;
        }
    }

} while (choice != '8');

// Measure program execution time and print
auto pabaigaPrograma = DabartinisLaikas(); // Baigtinis laiko taškas programai
cout << "Programos vykdymas užtruko: " << LaikoSkirtumas(pradziaPrograma, pabaigaPrograma) << " sekundžių." << endl;

return 0;
        
        }
    }
}
