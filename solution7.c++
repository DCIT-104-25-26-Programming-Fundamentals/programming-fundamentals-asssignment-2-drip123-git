#include <iostream>
#include <vector>
#include <string>
using namespace std;

void showMenu() {
    cout << "============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
}

void addTask(vector<string>& tasks) {
    cin.ignore(); // discard leftover newline from previous cin >>
    string description;
    cout << "Enter task: ";
    getline(cin, description);
    tasks.push_back(description);
    cout << "Task added: \"" << description << "\"" << endl;
}

void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your task list is empty!" << endl;
        return;
    }
    cout << "Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}

void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your task list is empty! Nothing to delete." << endl;
        return;
    }

    viewTasks(tasks);
    int choice;
    cout << "Enter task number to delete: ";
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(tasks.size())) {
        cout << "Error: That task number doesn't exist." << endl;
        return;
    }

    string removed = tasks[choice - 1];
    tasks.erase(tasks.begin() + (choice - 1));
    cout << "Task \"" << removed << "\" has been removed." << endl;
}

int main() {
    vector<string> tasks;

    while (true) {
        showMenu();
        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            addTask(tasks);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            deleteTask(tasks);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Error: Please enter a number between 1 and 4." << endl;
        }

        cout << endl; // blank line for readability between menu cycles
    }

    return 0;
}