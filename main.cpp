
#include "student.h"

  int main() {
    int studentukiekis;
    double hw;
      auto pradziaPrograma = DabartinisLaikas(); // Pradinis laiko taškas generavimui
    char choice;
    vector<Student> students;

    


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
        while (!(cin >> choice)){
            cout<< "Klaida. Prasome ivesti skaiciu, atitinkanti meniu opcijas"<< endl;
            cin.clear();
            cin.ignore();
        }


             switch (choice) {
         case '1': {
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
//output tikrinimas
/*for (int i = 0; i< studentukiekis; i++){
        cout << students[i];
    }*/
    break;
    
}


           case '2': {
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

    for (int i = 0; i < s; ++i) {
        cout << "Iveskite " << i + 1 << " mokinio varda ir pavarde: ";
        string name, surname;
        cin >> name >> surname;
        students[i].setName(name);
        students[i].setSurname(surname);
    }

    generateRandomGrades(students, hw);

    char displayChoice;
    cout << "Norite matyt vidurki (A) ar mediana (M)? ";
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
        if (displayChoice == 'A' || displayChoice == 'a')
            cout << setw(20) << fixed << setprecision(2) << students[i].getFinalAvg();
        else if (displayChoice == 'M' || displayChoice == 'm')
            cout << setw(20) << fixed << setprecision(2) << students[i].getFinalMedian();
        cout << endl;
    }
    break;
}



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

           case '5':{
    ofstream out_file ("rezultatai.txt");
    if (!out_file){
        cout << "Klaida. Nepavyko atidaryti failo." << endl;
    }
    int N;
    cout << "Iveskite kieki studentu duomenu, kuri norite nuskaityti: ";
    while (!(cin >> N) || N <= 0){
        cout << "Klaida. Iveskite skaiciu didesni uz 0"<< endl;
        cin.clear();
        cin.ignore();
    }

    readDataFromFile(students, hw, N);

    char displayChoice;
    cout << "Norite matyt vidurki (A) ar mediana (M)? ";
    while (!(cin  >> displayChoice || displayChoice != 'A' && displayChoice != 'a' && displayChoice != 'M' && displayChoice != 'm')){
        cout << "Klaida. Prasome ivesti A jei norite, kad rodytu vidurki arba M, jei norite, kad rodytu mediana"<< endl;
        cin.clear();
        cin.ignore();
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
    cout << "Failu generavimas užtruko: " << LaikoSkirtumas(pradziaGeneravimas, pabaigaGeneravimas) << " sekundžių." << endl;
    cout << "Failu nuskaitymas užtruko: " << LaikoSkirtumas(pradziaNuskaitymas, pabaigaNuskaitymas) << " sekundžių." << endl;

    char pasirinkimas;

    cout << "Pasirinkite, kaip norite matyti galutinį rezultatą:\n";
    cout << "V - pagal vidurkį\n";
    cout << "M - pagal medianą\n";
    cout << "Jūsų pasirinkimas (V/M): ";
    cin >> pasirinkimas;

    std::vector<Student> students;

    if (Nuskaitymas("studentai.txt", students, studentukiekis)) {
        auto pradziaLyginimas = DabartinisLaikas(); // Pradinis laiko taškas rūšiavimui
        calculateResults(students);
        auto pabaigaLyginimas = DabartinisLaikas(); // Baigtinis laiko taškas rūšiavimui

        auto pradziaIrasyti = DabartinisLaikas(); // Pradinis laiko taškas įrašymui
        rūšiuoja_ir_rašo_failus(students);
        auto pabaigaIrasyti = DabartinisLaikas(); // Baigtinis laiko taškas įrašymui

        // Spausdiname laiko skirtumus
        cout << "Studentų pažymių rūšiavimas užtruko: " << LaikoSkirtumas(pradziaLyginimas, pabaigaLyginimas) << " sekundžių." << endl;
        cout << "Duomenų įrašymas į failus užtruko: " << LaikoSkirtumas(pradziaIrasyti, pabaigaIrasyti) << " sekundžių." << endl;
        cout << "Duomenys sėkmingai išrūšiuoti ir išsaugoti į failus geruciai.txt ir bloguciai.txt." << std::endl;
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
            cout << "Programa baigta." << endl;
            break;
        }
        default:{
            cout << "Klaidingas pasirinkimas. Prasome irasyti tinkama skaiciu." << endl;
            break;
        }
    }


    }
    while (choice != '8');
      auto pabaigaPrograma = DabartinisLaikas(); // Baigtinis laiko taškas programai
      cout << "Programos vykdymas užtruko: " << LaikoSkirtumas(pradziaPrograma, pabaigaPrograma) << " sekundžių." << endl;

    return 0;

}
