
#include "student.h"

int main() {
    int s;
    double hw;

    char choice;
    vector<Student> students;

    do {
        cout << "Menu:" << endl;
        cout << "1. Enter data manually" << endl;
        cout << "2. Enter names and surnames manually and then generate random grades" << endl;
        cout << "3. Generate random names, surnames, and grades" << endl;
        cout << "4. Read data from file and print data on screen" << endl;
        cout << "5. Read data from file and create a file for results" << endl;
        cout << "6. End the program" << endl;
        cout << "Choose an option: ";
        cin >> choice;

             switch (choice) {
         case '1': {
                 cout << "How many students in a group? ";
                 while (!(cin >> s)) {
                cout << "Error: Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
                students.resize(s);

                 cout << "How much homework? ";
                 while (!(cin >> hw)) {
                cout << "Error: Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
                 }

                    enterDataManually(students, hw);
                    cout << "Data entered manually successfully." << endl;

                    char displayChoice;
                    cout << "Do you want to see the final average (A) or the median (M)? ";
                    cin >> displayChoice;

                    if (!(displayChoice == 'A' || displayChoice == 'a' || displayChoice == 'M' || displayChoice == 'm')) {
                    cout << "Error: Invalid choice. Please enter 'A' or 'M'." << endl;
                    break;
                }

                cout << left << setw(20) << "Name" << setw(20) << "Surname";
                if (displayChoice == 'A' || displayChoice == 'a')
                    cout << setw(20) << "Final Average";
                else if (displayChoice == 'M' || displayChoice == 'm')
                    cout << setw(20) << "Median";
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


            cout << "How many students in a group? ";
            while (!(cin >> s) || s <= 0) {
            cout << "Error: Please enter a valid number greater than 0." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

    
            cout << "How much homework? ";
            while (!(cin >> hw) || hw <= 0) {
            cout << "Error: Please enter a valid number greater than 0." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // cia kad tilptu kazkiek studentu
            students.resize(s);

    
            for (int i = 0; i < s; ++i) {
                cout << "Enter " << i + 1 << " student's name and surname: ";
                cin >> students[i].name >> students[i].sur;
        
        }
        generateRandomGrades(students, hw);
  

    
            char displayChoice;
            cout << "Do you want to see the final average (A) or the median (M)? ";
            cin >> displayChoice;

    
                cout << left << setw(20) << "Name" << setw(20) << "Surname";
            if (displayChoice == 'A' || displayChoice == 'a')
                cout << setw(20) << "Final Average";
            else if (displayChoice == 'M' || displayChoice == 'm')
                cout << setw(20) << "Median";
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
                cout << "How many students in a group?";
                 while (!(cin >> s)) {
                 cout << "Error: Please enter a valid number." << endl;
                 cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
                }
              students.resize(s);

            cout << "How much homework? ";
            while (!(cin >> hw)) {
            cout << "Error: Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
               }

                generateRandomData(students, hw);
                cout << "Random data generated successfully." << endl;

                char displayChoice;
                cout << "Do you want to see the final average (A) or the median (M)? ";
                cin >> displayChoice;

                cout << left << setw(20) << "Name" << setw(20) << "Surname";
                if (displayChoice == 'A' || displayChoice == 'a')
                    cout << setw(20) << "Final Average";
                else if(displayChoice == 'M' || displayChoice == 'm')
                    cout << setw(20) << "Median";
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
                cout << "Enter how many data entries you want to read: ";
                cin >> N;

                readDataFromFile(students, hw, N);

                char displayChoice;
                cout << "Do you want to see the final average (A) or the median (M)? ";
                cin >> displayChoice;

                cout << left << setw(20) << "Name" << setw(20) << "Surname";
                if (displayChoice == 'A' || displayChoice == 'a')
                    cout << setw(20) << "Final Average";
                else if (displayChoice == 'M' || displayChoice == 'm')
                    cout << setw(20) << "Median";
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
                    cout << "Error opening the file" << endl;
                }
                int N;
                cout << "Enter how many data entries you want to read: ";
                cin >> N;

                readDataFromFile(students, hw, N);

                char displayChoice;
                cout << "Do you want to see the final average (A) or the median (M)? ";
                cin >> displayChoice;

                out_file << left << setw(20) << "Name" << setw(20) << "Surname";
                if (displayChoice == 'A' || displayChoice == 'a')
                    out_file << setw(20) << "Final Average";
                else if (displayChoice == 'M' || displayChoice == 'm')
                    out_file << setw(20) << "Median";
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
                cout << "Ending the program." << endl;
                break;
            }
            default:{
                cout << "Invalid option. Please choose again." << endl;
            }
        }
     

    return 0;

}while (choice != '6');
}
