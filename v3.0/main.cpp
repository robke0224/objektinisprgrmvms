
#include "student.h"
#include "vektorius.h"

using namespace std;

  int main() {
    int studentukiekis;
    double hw;
      auto pradziaPrograma = DabartinisLaikas(); // Pradinis laiko taškas generavimui
    char choice;
    vector<Student> students;

    //Zmogus z ;


    do {
        std::cout << "Meniu:" << endl;
        std::cout << "1. Ivesti duomenis ranka" << endl;
        std::cout << "2. Ivesti vardus ir pavardes ranka, o pazymius generuoti atsitiktinai" << endl;
        std::cout << "3. Atsitiktinai generuoti viska" << endl;
        std::cout << "4. Nuskaityti duomenis is failo ir duomenis isvesti terminale" << endl;
        std::cout << "5. Nuskaityti duomenis is failo ir duomenis isvesti atskirame faile" << endl;
        std::cout << "6. Iveskite kieki studentu, kuri norite sugeneruoti " << endl;
        std::cout << "7. Vector konteinerio testavimas" << endl;
        std::cout << "8. Klases testavimas" << endl;
        std::cout << "9. Baigti programa" << endl;
        std::cout << "Jusu pasirinkimas: ";
        while (!(cin >> choice)){
            std::cout<< "Klaida. Prasome ivesti skaiciu, atitinkanti meniu opcijas"<< endl;
            cin.clear();
            cin.ignore();
        }


             switch (choice) {
         case '1': {
    std::cout << "Kiek studentu grupeje? ";
    while (!(cin >> studentukiekis) || studentukiekis < 0) {
        std::cout << "Klaida. Iveskite tinkama skaiciu." << endl;
        cin.clear();
        cin.ignore();
    }
    students.resize(studentukiekis);

    std::cout << "Kiek namu darbu? ";
    while (!(cin >> hw) || hw < 0) {
        std::cout << "Klaida. Iveskite tinkama skaiciu." << endl;
        cin.clear();
        cin.ignore();
    }

    enterDataManually(students, hw);
    std::cout << "Duomenys ranka ivesti sekmingai." << endl;

    char displayChoice;
    std::cout << "Norite matyt vidurki (A) ar mediana (M)? ";
    cin >> displayChoice;
    if (!(displayChoice == 'A' || displayChoice == 'a' || displayChoice == 'M' || displayChoice == 'm')) {
        std::cout << "Klaida. Neteisingas pasirinkimas. Iveskite'A' arba 'M'." << endl;
        break;
    }

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
//output tikrinimas
/*for (int i = 0; i< studentukiekis; i++){
        cout << students[i];
    }*/
    break;

}


           case '2': {
    int s;
    double hw;

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



           case '3': {
    int studentukiekis;
    double hw;

    std::cout << "Kiek studentu grupeje?";
    while (!(cin >> studentukiekis)) {
        std::cout << "Klaida. Iveskite tinkama skaiciu." << endl;
        cin.clear();
        cin.ignore();
    }
    students.resize(studentukiekis);

    std::cout << "Kiek namu darbu? ";
    while (!(cin >> hw)) {
        std::cout << "Klaida. Iveskite tinkama skaiciu." << endl;
        cin.clear();
        cin.ignore();
    }

    generateRandomData(students, hw);
    std::cout << "Atsitikiniai duomenys sugeneruoti sekmingai." << endl;

    char displayChoice;
    std::cout << " Norite matyt vidurki (A) ar mediana (M)? ";
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
        if (displayChoice == 'A' || displayChoice == 'a') {
            std::cout << setw(20) << fixed << setprecision(2) << students[i].getFinalAvg();
        } else {
            std::cout << setw(20) << fixed << setprecision(2) << students[i].getFinalMedian();
        }
        std::cout << endl;
    }
    break;
}

            case '4': {
    int N;
    std::cout << "Iveskite kieki studentu duomenu, kuri norite nuskaityti: ";
    while (!(cin >> N) || N <= 0){
        std::cout << "Klaida. Iveskite skaiciu didesni uz 0"<< endl;
        cin.clear();
        cin.ignore();
    }

    readDataFromFile(students, hw, N);

    char displayChoice;
    std::cout << " Norite matyt vidurki (A) ar mediana (M)? ";
    cin >> displayChoice;
    while (displayChoice != 'A' && displayChoice != 'a' && displayChoice != 'M' && displayChoice != 'm') {
        std::cout << "Klaida. Iveskite 'A' arba 'M': ";
        cin.clear();
        cin.ignore();
        cin >> displayChoice;
    }

    char sortChoice;
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

           case '5':{
    ofstream out_file ("rezultatai.txt");
    if (!out_file){
        std::cout << "Klaida. Nepavyko atidaryti failo." << endl;
    }
    int N;
    std::cout << "Iveskite kieki studentu duomenu, kuri norite nuskaityti: ";
    while (!(cin >> N) || N <= 0){
        std::cout << "Klaida. Iveskite skaiciu didesni uz 0"<< endl;
        cin.clear();
        cin.ignore();
    }

    readDataFromFile(students, hw, N);

    char displayChoice;
    std::cout << "Norite matyt vidurki (A) ar mediana (M)? ";
    while (!(cin  >> displayChoice || displayChoice != 'A' && displayChoice != 'a' && displayChoice != 'M' && displayChoice != 'm')){
        std::cout << "Klaida. Prasome ivesti A jei norite, kad rodytu vidurki arba M, jei norite, kad rodytu mediana"<< endl;
        cin.clear();
        cin.ignore();
    }

    char sortChoice;
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

    out_file << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    if (displayChoice == 'A' || displayChoice == 'a')
        out_file << setw(20) << "Vidurkis";
    else if (displayChoice == 'M' || displayChoice == 'm')
        out_file << setw(20) << "Mediana";
    out_file << endl;

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
    std::cout << "Failu generavimas užtruko: " << LaikoSkirtumas(pradziaGeneravimas, pabaigaGeneravimas) << " sekundžių." << endl;
    std::cout << "Failu nuskaitymas užtruko: " << LaikoSkirtumas(pradziaNuskaitymas, pabaigaNuskaitymas) << " sekundžių." << endl;

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
                 
case '7':{
    testas();
    return 0;
}

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
                break;
            }


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

    while (choice != '9');
      auto pabaigaPrograma = DabartinisLaikas(); // Baigtinis laiko taškas programai
      std::cout << "Programos vykdymas uztruko: " << LaikoSkirtumas(pradziaPrograma, pabaigaPrograma) << " sekundziu." << endl;

    return 0;

  }