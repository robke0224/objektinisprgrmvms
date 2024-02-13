#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm> //rusiavimui

using namespace std;

struct Student {
string name, sur;
double final_avg, median;
int* grades;
int exam_results;
};

double calculateMedian(int arr[], int size) {
  sort(arr, arr + size);

if (size % 2 != 0)
    return arr[size / 2];
return (arr[(size - 1) / 2] + arr[size / 2]) / 2.0;
}

int main() {
  int s;
  double hw;

cout << "How many students in a group?";
while (!(cin >> s)) {
  cout << "Error: Please enter a number." << endl;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "How many students in a group?";
}

while (s <= 0) {
  cout << "Error: Please enter a positive number for the count of students." << endl;
  cout << "How many students in a group?";
  cin >> s;
}

cout << "How much homework?";
while (!(cin >> hw)) {
  cout << "Error: Please enter a number." << endl;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "How much homework?";
}

while (hw < 0) {
  cout << "Error: Please enter a positive number for the count of homework." << endl;
  cout << "How much homework?";
  cin >> hw;
}

Student* students = new Student[s];
  for (int i=0; i < s; i++) {
    cout << "Enter" << i + 1 << " student's name and surname: ";
    cin >> students[i].name >> students[i].sur;

    students[i].grades = new int [static_cast<int>(hw)];
    double total_grades = 0.0;

for (int j = 0; j < hw; j++) {
  do {
      cout << "Enter student's grades for" << j + 1 << "homework: ";
      cin >> students[i].grades[j];
  if (students[i].grades[j] < 1 || students[i].grades[j] > 10) {
      cout << "Error: Grade must be between 1 and 10." << endl;
  }
} while (students[i].grades[j] < 1 || students[i].grades[j] > 10);
total_grades += students[i].grades[j];
}
students[i].final_avg = total_grades / hw;

//skaiciuojam mediana
students[i].median = calculateMedian(students[i].grades, hw);

do{
    cout << "Enter" << i + 1 << " student's exam grade: ";
    cin >> students[i].exam_results;
      if (students[i].exam_results < 1 || students [i].exam_results > 10){
        cout << "Error: Grade must be between 1 and 10." << endl;
      }
  } while (students[i].exam_results < 1 || students[i].exam_results > 10);
students[i].final_avg = 0.4 * students[i].final_avg + 0.6 * students[i].exam_results;
}

char choice;
cout << "Do you want to see the final average (A) or the median (M)?";
cin >> choice;

cout << left << setw(20) << "Name" << setw(20) << "Surname";
  if(choice == 'A' || choice == 'a')
      cout << setw(20) << "Final Average";
  else if (choice == 'M' || choice == 'm')
      cout << setw(20) << "Median";
  cout << endl;

cout << "------------------------------------------------------------" << endl;
for (int i = 0; i < s; i++) {
    cout << left << setw(20) << students[i].name << setw(20) << students[i].sur;
    if (choice == 'A' || choice == 'a')
      cout << setw(20) << fixed << setprecision(2) << students[i].final_avg;
  else if (choice == 'M' || choice == 'm')
      cout << setw(20) << fixed << setprecision(2) << students[i].median;
  cout << endl;
};

for (int i = 0; i < s: i++) {
  delete[] students[i].grades;
}
delete[] students;
}
