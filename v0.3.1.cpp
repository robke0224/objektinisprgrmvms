
#include "student.h"

int main() {
    int s;
    double hw;

    char choice;
    vector<Student> students;

    do {
        cout << "Meniu:" << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Ivesti vardus ir pavardes ranka, o pazymius generuoti atsitiktinai" << endl;
        cout << "3. Atsitiktinai generuoti viska" << endl;
        cout << "4. Nuskaityti duomenis is failo ir duomenis isvesti terminale" << endl;
        cout << "5. Nuskaityti duomenis is failo ir duomenis isvesti atskirame faile" << endl;
        cout << "6. Uzbaigti programa" << endl;
        cout << "Jusu pasirinkimas: ";
        while (!(cin >> choice)){
            cout<< "Klaida. Prasome ivesti skaiciu, atitinkanti meniu opcijas"<< endl;
            cin.clear();
            cin.ignore();
        }
        

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
                cin >> displayChoice;
    }
                char sortChoice;
                cout << "Rusiuoti pagal (V) Varda, (P) Pavarde, (M) Mediana arba (A) Vidurki: ";
                cin >> sortChoice;
                while (sortChoice != 'V' && sortChoice != 'v' && sortChoice != 'P' && sortChoice != 'p' && sortChoice != 'M' && sortChoice != 'm' && sortChoice != 'A' && sortChoice != 'a'){
                cout << "Klaida. Prasome ivesti V jei norite rusiuoti pagal varda, P, jei pagal pavarde, M,  jei pagal mediana arba A, jei pagal vidurki " << endl;
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
                break;
            }
            case '5':{
                ofstream out_file ("results.txt");
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
                break;

            }
            case '6': {
                cout << "Programa baigta." << endl;
                break;
            }
            default:{
                cout << "Klaidingas pasirinkimas. Prasome irasyti tinkama skaiciu." << endl;
                break;
            }
        }
     

    

    }while (choice != '6');
return 0;
}
