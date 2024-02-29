
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
        cin >> choice;

             switch (choice) {
         case '1': {
                 cout << "Kiek studentu grupeje? ";
                 while (!(cin >> s)) {
                cout << "Klaida. Iveskite tinkama skaiciu." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
                students.resize(s);

                 cout << "Kiek namu darbu? ";
                 while (!(cin >> hw)) {
                cout << "Klaida. Iveskite tinkama skaiciu." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
                 }

                    enterDataManually(students, hw);
                    cout << "Duomys ranka ivesti sekmingai." << endl;

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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

    
            cout << "Kiek namu darbu? ";
            while (!(cin >> hw) || hw <= 0) {
            cout << "Klaida. Iveskite skaiciu didesni uz 0." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
                }
              students.resize(s);

            cout << "Kiek namu darbu? ";
            while (!(cin >> hw)) {
            cout << "Klaida. Iveskite tinkama skaiciu." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
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
                cin >> N;

                readDataFromFile(students, hw, N);

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
                cin >> N;

                readDataFromFile(students, hw, N);

                char displayChoice;
                cout << "Norite matyt vidurki (A) ar mediana (M)? ";
                cin >> displayChoice;

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
            }
        }
     

    return 0;

}while (choice != '6');
}
