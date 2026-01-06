#include "catalog.h"
#include<iostream>
#include<string>

using namespace std;

void displayAdminMenu() {
    cout << "\n\nAdministrator Menu:\n\n";
    cout << "1. Display catalog\n";
    cout << "2. Add student\n";
    cout << "3. Remove student\n";
    cout << "4. Display failing students\n";
    cout << "5. Display scholarship students\n";
    cout << "6. Exit\n";
}

void displayProfessorMenu() {
    cout << "\n\nProfessor Menu:\n\n";
    cout << "1. Display catalog\n";
    cout << "2. Search student\n";
    cout << "3. Add nota\n";
    cout << "4. Display failing students\n";
    cout << "5. Exit\n";
}

void displayStudentMenu() {
    cout << "\n\nStudent Menu:\n\n";
    cout << "1. Display grades\n";
    cout << "2. Display average\n";
    cout << "3. Check failing status\n";
    cout << "4. Check scholarship status\n";
    cout << "5. Exit\n";
}

int main() {
    Catalog catalog;
    catalog.initStudents(); // Catalogul cu 10 studenti

    string role;
    cout << "What is your role? (administrator/professor/student): ";
    cin >> role;

    if (role == "administrator") {
        int option;
        do {
            displayAdminMenu();
            cout << "Choose an option: ";
            cin >> option;

            switch (option) {
            case 1:
                catalog.displayCatalog();
                break;
            case 2: {
                string name;
                int group;
                char subgroup;

                cout << "Enter student's name: ";
                cin.ignore();  // Curata orice caracter ramas in buffer-ul de input (daca exista)
                getline(cin, name);  // Citire intreaga linie (inclusiv spatiile)


                cout << "Enter group's student: ";
                cin >> group;

                cout << "Enter subgroup's student: ";
                cin >> subgroup;

                Student student(name, group, subgroup);
                catalog.addStudent(student);
                break;
            }
            case 3: {
                int id;
                cout << "Enter the ID of the student you want to remove: ";
                cin >> id;
                catalog.deleteStudent(id);
                break;
            }
            case 4:
                catalog.displayFailingStudents();
                break;
            case 5:
                catalog.displayScholarshipStudents();
                break;
            case 6:
                cout << "Exit...\n";
                break;
            default:
                cout << "Invalid option!\n";
            }
        } while (option != 6);
    }
    else if (role == "professor") {
        int option;
        do {
            displayProfessorMenu();
            cout << "Choose an option: ";
            cin >> option;

            switch (option) {
            case 1:
                catalog.displayCatalog();
                break;
            case 2: {
                string name;

                cout << "Enter the name of the student you want to search: ";
                cin.ignore();  // Curata orice caracter ramas in buffer-ul de input (daca exista)
                getline(cin, name);  // Citire intreaga linie (inclusiv spatiile)


                Student* student = catalog.searchStudentByName(name);
                if (student != nullptr) {
                    cout << "Student found: " << student->getName() << endl;
                }
                else {
                    cout << "Student not found.\n";
                }
                break;
            }
            case 3: {
                string name;
                int grade;

                cout << "Enter the name of the student: ";
                cin.ignore();  // Curata orice caracter ramas in buffer-ul de input (daca exista)
                getline(cin, name);  // Citire întreaga linie (inclusiv spatiile)


                Student* student = catalog.searchStudentByName(name);
                if (student != nullptr) {
                    cout << "Enter the grade: ";
                    cin >> grade;
                    student->addGrade(grade);
                    cout << "Grade added.\n";
                }
                else {
                    cout << "Student not found.\n";
                }
                break;
            }
            case 4:
                catalog.displayFailingStudents();
                break;
            case 5:
                cout << "Exit...\n";
                break;
            default:
                cout << "Invalid option!\n";
            }
        } while (option != 5);
    }
    else if (role == "student") {
        int option;
        do {
            displayStudentMenu();
            cout << "Choose an option: ";
            cin >> option;

            switch (option) {
            case 1: {
                string name;

                cout << "Enter your name for checking the grades: ";
                cin.ignore();  // Curata orice caracter ramas in buffer-ul de input (daca exista)
                getline(cin, name);  // Citire intreaga linie (inclusiv spatiile)


                Student* student = catalog.searchStudentByName(name);
                if (student != nullptr) {
                    const auto& grades = student->getGrades();
                    cout << "Grades of student " << name << ": ";
                    for (int grade : grades) {
                        cout << grade << " ";
                    }
                    cout << endl;
                }
                else {
                    cout << "Student not found.\n";
                }
                break;
            }
            case 2: {
                string name;

                cout << "Enter the name to view overall average: ";
                cin.ignore();  // Curata orice caracter ramas in buffer-ul de input (daca exista)
                getline(cin, name);  // Citire întreaga linie (inclusiv spatiile)


                Student* student = catalog.searchStudentByName(name);
                if (student != nullptr) {
                    cout << "Student " << name << "'s overall average: " << student->average() << endl;
                }
                else {
                    cout << "Student not found.\n";
                }
                break;
            }
            case 3: {
                string name;

                cout << "Enter your name to check failing status: ";
                cin.ignore();  // Curata orice caracter ramas in buffer-ul de input (dacă există)
                getline(cin, name);  // Citere intreaga linie (inclusiv spatiile)


                Student* student = catalog.searchStudentByName(name);
                if (student != nullptr) {
                    cout << "Student " << name << (student->isFailing() ? " is failing.\n" : " is not failing.\n");
                }
                else {
                    cout << "Student not found.\n";
                }
                break;
            }
            case 4: {
                string name;

                cout << "Enter your name to check scholarship status: ";
                cin.ignore();  // Curata orice caracter ramas in buffer-ul de input (daca exista)
                getline(cin, name);  // Citire intreaga linie (inclusiv spatiile)


                Student* student = catalog.searchStudentByName(name);
                if (student != nullptr) {
                    cout << "Student " << name << (student->isScholar() ? " is a scholarship student.\n" : " is not a scholarship student.\n");
                }
                else {
                    cout << "Student not found.\n";
                }
                break;
            }
            case 5:
                cout << "Exit...\n";
                break;
            default:
                cout << "Invalid option!\n";
            }
        } while (option != 5);
    }
    else {
        cout << "Invalid role! Exit...\n";
    }

    return 0;
}
