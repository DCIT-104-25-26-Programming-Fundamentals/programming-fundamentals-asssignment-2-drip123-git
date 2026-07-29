#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

void showMenu() {
    cout << "================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
}

double calculateAverage(const vector<double>& scores) {
    double total = 0;
    for (double s : scores) {
        total += s;
    }
    return total / scores.size();
}

void addStudent(vector<Student>& students) {
    Student s;
    cin.ignore(); // discard leftover newline before getline
    cout << "Student name: ";
    getline(cin, s.name);
    cout << "Student ID: ";
    cin >> s.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << string(50, '-') << endl;
    cout << left << setw(15) << "Name" << setw(12) << "ID"
         << setw(15) << "Scores" << setw(10) << "Average" << endl;
    cout << string(50, '-') << endl;

    for (const Student& s : students) {
        string scoresStr;
        for (size_t i = 0; i < s.scores.size(); i++) {
            scoresStr += to_string(static_cast<int>(s.scores[i]));
            if (i != s.scores.size() - 1) {
                scoresStr += ", ";
            }
        }

        cout << left << setw(15) << s.name << setw(12) << s.id
             << setw(15) << scoresStr
             << fixed << setprecision(2) << calculateAverage(s.scores) << endl;
    }
    cout << string(50, '-') << endl;
}

void findStudentAverage(const vector<Student>& students) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    for (const Student& s : students) {
        if (s.id == id) {
            cout << fixed << setprecision(2);
            cout << s.name << "'s average score: " << calculateAverage(s.scores) << endl;
            return;
        }
    }

    cout << "Error: No student found with that ID." << endl;
}

int main() {
    vector<Student> students;

    while (true) {
        showMenu();
        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayStudents(students);
        } else if (choice == 3) {
            findStudentAverage(students);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Error: Please enter a number between 1 and 4." << endl;
        }

        cout << endl;
    }

    return 0;
}