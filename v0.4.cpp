
#include "student.h"

int main() {
    chrono::time_point<chrono::high_resolution_clock> start_file = chrono::high_resolution_clock::now(); // pradzia laikko matavimo 
    int s;
    double hw;

    char choice;
    vector<Student> students;
   
    do {
        chrono::time_point<chrono::high_resolution_clock> start_menu = chrono::high_resolution_clock::now();
        cout << "Meniu:" << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Ivesti vardus ir pavardes ranka, o pazymius generuoti atsitiktinai" << endl;
        cout << "3. Atsitiktinai generuoti viska" << endl;
        cout << "4. Nuskaityti duomenis is failo ir duomenis isvesti terminale" << endl;
        cout << "5. Nuskaityti duomenis is failo ir duomenis isvesti atskirame faile" << endl;
        cout << "6. Pasirinkite kiek duomenu norite sugeneruoti i faila" << endl;
        cout << "7. Uzbaigti programa" << endl;
        cout << "Jusu pasirinkimas: ";
        while (!(cin >> choice)){
            cout<< "Klaida. Prasome ivesti skaiciu, atitinkanti meniu opcijas"<< endl;
            cin.clear();
            cin.ignore();
        }
        chrono::time_point<chrono::high_resolution_clock> end_menu = chrono::high_resolution_clock::now(); // Time after menu selection
        chrono::duration<double, std::milli> duration_menu = end_menu - start_menu;
        cout << "uztruko laiko: " << duration_menu.count() << " ms" << endl;

             switch (choice) {
         case '1': {
                 cout << "Kiek studentu grupeje? ";
                 while (!(cin >> s)|| s< 0) {
                cout << "Klaida. Iveskite tinkama skaiciu." << endl;
                cin.clear();
                cin.ignore();
    }
                students.resize(s);

                 cout << "Kiek namu darbu? ";
                 while (!(cin >> hw)|| hw < 0) {
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

            // cia kad tilptu kazkiek studentu
            students.resize(s);

    
            for (int i = 0; i < s; ++i) {
                cout << "Iveskite " << i + 1 << " mokinio varda ir pavarde: ";
                cin >> students[i].name >> students[i].sur;
        
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
                cout << "Kiek studentu grupeje?";
                 while (!(cin >> s)) {
                 cout << "Klaida. Iveskite tinkama skaiciu." << endl;
                 cin.clear();
                cin.ignore();
        
                }
              students.resize(s);

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
                else if(displayChoice == 'M' || displayChoice == 'm')
                    cout << setw(20) << "Mediana";
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
               chrono::high_resolution_clock::time_point start_files = chrono::high_resolution_clock::now(); //laikas
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
                    cout << left << setw(20) << students[i].name << setw(20) << students[i].sur;
                    if (displayChoice == 'A' || displayChoice == 'a')
                        cout << setw(20) << fixed << setprecision(2) << students[i].final_avg;
                    else if (displayChoice == 'M' || displayChoice == 'm')
                        cout << setw(20) << fixed << setprecision(2) << students[i].median;
                    cout << endl;
                }
                chrono::high_resolution_clock::time_point end_files = chrono::high_resolution_clock::now(); // Time after file operation
                chrono::duration<double, milli> duration_files = end_files - start_files;
                cout << "darbas su failais uztruko: " << duration_files.count() << " ms" << endl;
                break;
            }
            case '5':{
                chrono::time_point<chrono::high_resolution_clock> start_filees = chrono::high_resolution_clock::now();//pradzia
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
                    out_file << left << setw(20) << students[i].name << setw(20) << students[i].sur;
                    if (displayChoice == 'A' || displayChoice == 'a')
                        out_file << setw(20) << fixed << setprecision(2) << students[i].final_avg;
                    else if (displayChoice == 'M' || displayChoice == 'm')
                        out_file << setw(20) << fixed << setprecision(2) << students[i].median;
                    out_file << endl;
                }
                chrono::time_point<chrono::high_resolution_clock> end_filees = chrono::high_resolution_clock::now(); // Time after file operation
                chrono::duration<double, milli> duration_filees = end_filees - start_filees;
                cout << "darbas su failais uztruko: " << duration_filees.count() << " ms" << endl;
                break;

            }
         case '6': {
    chrono::time_point<chrono::high_resolution_clock> start_failas = chrono::high_resolution_clock::now(); //pradeda

    srand(time(0));
    // pasirinkimo meniu
    cout << "Pasirinkite, kurį failą norite sugeneruoti:" << endl;
    cout << "1. kietiakai" << endl;
    cout << "2. slabakai" << endl;

    int fileChoice;
    cout << "Jūsų pasirinkimas (1 arba 2): ";
    cin >> fileChoice;
    // tikrinam
    if (fileChoice != 1 && fileChoice != 2) {
        cout << "Klaidingas pasirinkimas. Pasirinkite 1 arba 2." << endl;
        return 1;
    }

    vector<string> choices;
    choices.push_back("1 000");
    choices.push_back("10 000");
    choices.push_back("100 000");
    choices.push_back("1 000 000");
    choices.push_back("10 000 000");

    cout << "Pasirinkite kiek duomenų norite sugeneruoti:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << i + 1 << ". " << choices[i] << endl;
    }

    int choice;
    cout << "Jūsų pasirinkimas (1-5): ";
    cin >> choice;

    if (choice < 1 || choice > 5) {
        cout << "Klaidingas pasirinkimas. Iveskite skaiciu nuo 1 iki 5." << endl;
        return 1;
    }

    int kiekis;
    switch (choice) {
        case 1: kiekis = 1000; 
        break;
        case 2: kiekis = 10000; 
        break;
        case 3: kiekis = 100000; 
        break;
        case 4: kiekis = 1000000; 
        break;
        case 5: kiekis = 10000000; 
        break;
    }

    string fileName;
    if (fileChoice == 1){
        fileName = "kietiakai.txt";
    } else {
        fileName = "slabakai.txt";
    }
    // atsidaro faila pagal vartotojo pasirinkima
    ofstream outFile(fileName);

    if (!outFile.is_open()) {
        cout << "Klaida atidarant failą irasymui." << endl;
        return 1;
    }
    //generuoja ir raso duom i faila
    for (int i = 1; i <= kiekis; ++i) {
        vector<int> grades;
        for (int j = 0; j < 10; ++j) {
            grades.push_back(generateRandomNumber(1, 10));
        }
        double average = calculateAverage(grades);
        // raso duomenis i faila pagal vidurki
        if ((fileChoice == 1 && average >= 5.0) || (fileChoice == 2 && average < 5.0)) {
            outFile << "vardas " << i << " pavarde " << i << " Vidurkis: " << average;
            for (int j = 0; j < 10; ++j) {
                outFile << " " << grades[j];
            }
            outFile << endl;
        }
    }
    //uzdaro faila
    outFile.close();

    cout << "Duomenys išsaugoti sekmingai į failą \"" << fileName << "\"." << endl;



    chrono::time_point<chrono::high_resolution_clock> end_failas = chrono::high_resolution_clock::now(); // Time after file operation
    chrono::duration<double, milli> duration_failas = end_failas - start_failas;
    cout << "irasymas uztruko: " << duration_failas.count() << " ms" << endl;

        break;
         }
             
            case '7': {
                cout << "Programa baigta." << endl;
                break;
            }
            default:{
                cout << "Klaidingas pasirinkimas. Prasome irasyti tinkama skaiciu." << endl;
                break;
            }
        }
     

    
    }
    
    while (choice != '7');
    ;
    
       chrono::time_point<chrono::high_resolution_clock> end_file = chrono::high_resolution_clock::now(); // End measuring time
    chrono::duration<double, milli> duration = end_file - start_file;
    cout << "visas programos vykdymo laikas: " << duration.count() << " milliseconds" << endl;

    return 0;
    }
