#include <iostream>
#include <string>
using namespace std;

template <class T>
class MemoryCalculate {
private:
    T id;
    string name;

public:
    MemoryCalculate(T i, string n) {
        id = i;
        name = n;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }

    T getId() const {
        return id;
    }
};

int main() {
    vector<MemoryCalculate<int>> students;
    int choice;

    do {
        cout << "\n=== Student Management System ===\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Remove Student by ID\n";
        cout << "4. Search Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, name);
            students.push_back(MemoryCalculate<int>(id, name));
            cout << "Student added successfully!\n";
        }
        else if (choice == 2) {
            cout << "\nList of Students:\n";
            for (auto &s : students)
                s.display();
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID to remove: ";
            cin >> id;
            bool found = false;
            for (auto it = students.begin(); it != students.end(); ++it) {
                if (it->getId() == id) {
                    students.erase(it);
                    cout << "Student removed successfully!\n";
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Student not found!\n";
        }
        else if (choice == 4) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            bool found = false;
            for (auto &s : students) {
                if (s.getId() == id) {
                    s.display();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Student not found!\n";
        }

    } while (choice != 5);

    cout << "Exiting program...\n";
    return 0;
}

