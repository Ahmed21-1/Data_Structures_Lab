#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const int STUDENTS = 6;
    const int SUBJECTS = 4;

    string subjectNames[SUBJECTS] = {"English", "Mathematics", "Programming", "AI"};
    double marks[STUDENTS][SUBJECTS];

    // 1. Take Marks Input from User
    cout << "==================================================\n";
    cout << "          ENTER MARKS FOR ALL STUDENTS            \n";
    cout << "==================================================\n\n";

    for (int i = 0; i < STUDENTS; i++) {
        cout << "--- Entering Marks for Student " << (i + 1) << " ---\n";
        for (int j = 0; j < SUBJECTS; j++) {
            cout << "Enter " << subjectNames[j] << " marks: ";
            cin >> marks[i][j];
        }
        cout << "\n";
    }

    // 2. Display Complete Marks Table
    cout << "\n=================================================================\n";
    cout << "                      STUDENT MARKS TABLE                        \n";
    cout << "=================================================================\n";
    cout << left << setw(12) << "Student"
         << setw(14) << subjectNames[0]
         << setw(14) << subjectNames[1]
         << setw(14) << subjectNames[2]
         << setw(10) << subjectNames[3] << "\n";
    cout << "-----------------------------------------------------------------\n";

    for (int i = 0; i < STUDENTS; i++) {
        cout << left << "Student " << setw(4) << (i + 1);
        for (int j = 0; j < SUBJECTS; j++) {
            cout << setw(14) << marks[i][j];
        }
        cout << "\n";
    }
    cout << "=================================================================\n\n";

    // 3 & 4. Calculate and Display Total and Average Marks
    double highestTotal = -1;
    int topStudentIndex = 0;

    cout << "-----------------------------------------------------------------\n";
    cout << "                  STUDENT TOTALS & AVERAGES                      \n";
    cout << "-----------------------------------------------------------------\n";
    for (int i = 0; i < STUDENTS; i++) {
        double total = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            total += marks[i][j];
        }
        double average = total / SUBJECTS;

        cout << "Student " << (i + 1) << " -> Total Marks: " << setw(6) << total 
             << " | Average Marks: " << fixed << setprecision(2) << average << "\n";

        // Track highest overall total
        if (total > highestTotal) {
            highestTotal = total;
            topStudentIndex = i;
        }
    }
    cout << "\n";

    // 5. Find and Display Highest Marks in Each Subject
    cout << "-----------------------------------------------------------------\n";
    cout << "                  HIGHEST MARKS PER SUBJECT                      \n";
    cout << "-----------------------------------------------------------------\n";
    for (int j = 0; j < SUBJECTS; j++) {
        double maxMark = marks[0][j];
        for (int i = 1; i < STUDENTS; i++) {
            if (marks[i][j] > maxMark) {
                maxMark = marks[i][j];
            }
        }
        cout << left << setw(15) << subjectNames[j] << ": " << maxMark << "\n";
    }
    cout << "\n";

    // 6. Find and Display Student with Highest Total Marks
    cout << "-----------------------------------------------------------------\n";
    cout << "                     TOP PERFORMING STUDENT                      \n";
    cout << "-----------------------------------------------------------------\n";
    cout << "Student " << (topStudentIndex + 1) 
         << " achieved the highest total marks of " << highestTotal << "!\n";

    return 0;
}
