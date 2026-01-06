#include "catalog.h"
#include<iostream>
#include<string>

using namespace std;

void afiseazaMeniuAdministrator() {
    cout << "\n\nMeniu Administrator:\n\n";
    cout << "1. Afiseaza catalog\n";
    cout << "2. Adauga student\n";
    cout << "3. Sterge student\n";
    cout << "4. Afiseaza restantieri\n";
    cout << "5. Afiseaza bursieri\n";
    cout << "6. Iesire\n";
}

void afiseazaMeniuProfesor() {
    cout << "\n\nMeniu Profesor:\n\n";
    cout << "1. Afiseaza catalog\n";
    cout << "2. Cauta student\n";
    cout << "3. Adauga nota\n";
    cout << "4. Afisare restantieri\n";
    cout << "5. Iesire\n";
}

void meniuStudent() {
    cout << "\n\nMeniu Student:\n\n";
    cout << "1. Afisare note\n";
    cout << "2. Afisare medie generala\n";
    cout << "3. Verificare restante\n";
    cout << "4. Verificare bursier\n";
    cout << "5. Iesire\n";
}

int main() {
    Catalog catalog;
    catalog.initStudenti(); // catalogul cu 10 studenti

    string rol;
    cout << "Cum va intitulati? (administrator/profesor/student): ";
    cin >> rol;

    if (rol == "administrator") {
        int optiune;
        do {
            afiseazaMeniuAdministrator();
            cout << "Alege o optiune: ";
            cin >> optiune;

            switch (optiune) {
            case 1:
                catalog.afiseazaCatalog();
                break;
            case 2: {
                string nume;
                int grupa;
                char semigrupa;

                cout << "Introduceti numele studentului: ";
                cin.ignore();  // Curata orice caracter ramas în buffer-ul de input (daca exista)
                getline(cin, nume);  // Citire intreaga linie (inclusiv spatiile)


                cout << "Introduceti grupa studentului: ";
                cin >> grupa;

                cout << "Introduceti semigrupa studentului: ";
                cin >> semigrupa;

                Student student(nume, grupa, semigrupa);
                catalog.adaugaStudent(student);
                break;
            }
            case 3: {
                int id;
                cout << "Introduceti ID-ul studentului pe care doriti sa il stergeti: ";
                cin >> id;
                catalog.stergeStudent(id);
                break;
            }
            case 4:
                catalog.afiseazaRestantieri();
                break;
            case 5:
                catalog.afiseazaBursieri();
                break;
            case 6:
                cout << "Iesire...\n";
                break;
            default:
                cout << "Optiune invalida!\n";
            }
        } while (optiune != 7);
    }
    else if (rol == "profesor") {
        int optiune;
        do {
            afiseazaMeniuProfesor();
            cout << "Alege o optiune: ";
            cin >> optiune;

            switch (optiune) {
            case 1:
                catalog.afiseazaCatalog();
                break;
            case 2: {
                string nume;

                cout << "Introduceti numele studentului pe care doriti sa il cautati: ";
                cin.ignore();  // Curata orice caracter ramas în buffer-ul de input (daca exista)
                getline(cin, nume);  // Citire intreaga linie (inclusiv spatiile)


                Student* student = catalog.cautaStudentDupaNume(nume);
                if (student != nullptr) {
                    cout << "Student gasit: " << student->getNume() << endl;
                }
                else {
                    cout << "Studentul nu a fost gasit.\n";
                }
                break;
            }
            case 3: {
                string nume;
                int nota;

                cout << "Introduceti numele studentului: ";
                cin.ignore();  // Curata orice caracter ramas în buffer-ul de input (daca exista)
                getline(cin, nume);  // Citire întreaga linie (inclusiv spatiile)


                Student* student = catalog.cautaStudentDupaNume(nume);
                if (student != nullptr) {
                    cout << "Introduceti nota: ";
                    cin >> nota;
                    student->adaugaNota(nota);
                    cout << "Nota adaugata.\n";
                }
                else {
                    cout << "Studentul nu a fost gasit.\n";
                }
                break;
            }
            case 4:
                catalog.afiseazaRestantieri();
                break;
            case 5:
                cout << "Iesire...\n";
                break;
            default:
                cout << "Optiune invalida!\n";
            }
        } while (optiune != 6);
    }
    else if (rol == "student") {
        int optiune;
        do {
            meniuStudent();
            cout << "Alege o optiune: ";
            cin >> optiune;

            switch (optiune) {
            case 1: {
                string nume;

                cout << "Introduceti numele pentru a vizualiza notele: ";
                cin.ignore();  // Curata orice caracter ramas în buffer-ul de input (daca exista)
                getline(cin, nume);  // Citire intreaga linie (inclusiv spatiile)


                Student* student = catalog.cautaStudentDupaNume(nume);
                if (student != nullptr) {
                    const auto& note = student->getNote();
                    cout << "Notele studentului " << nume << ": ";
                    for (int nota : note) {
                        cout << nota << " ";
                    }
                    cout << endl;
                }
                else {
                    cout << "Studentul nu a fost gasit.\n";
                }
                break;
            }
            case 2: {
                string nume;

                cout << "Introduceti numele pentru a vizualiza media generala: ";
                cin.ignore();  // Curata orice caracter ramas în buffer-ul de input (daca exista)
                getline(cin, nume);  // Citire întreaga linie (inclusiv spatiile)


                Student* student = catalog.cautaStudentDupaNume(nume);
                if (student != nullptr) {
                    cout << "Media studentului " << nume << ": " << student->medie() << endl;
                }
                else {
                    cout << "Studentul nu a fost gasit.\n";
                }
                break;
            }
            case 3: {
                string nume;

                cout << "Introduceti numele pentru verificare: ";
                cin.ignore();  // Curata orice caracter ramas în buffer-ul de input (dacă există)
                getline(cin, nume);  // Citere intreaga linie (inclusiv spatiile)


                Student* student = catalog.cautaStudentDupaNume(nume);
                if (student != nullptr) {
                    cout << "Studentul " << nume << (student->esteRestantier() ? " este restantier.\n" : " nu este restantier.\n");
                }
                else {
                    cout << "Studentul nu a fost gasit.\n";
                }
                break;
            }
            case 4: {
                string nume;

                cout << "Introduceti numele pentru verificare: ";
                cin.ignore();  // Curata orice caracter ramas în buffer-ul de input (daca exista)
                getline(cin, nume);  // Citire intreaga linie (inclusiv spatiile)


                Student* student = catalog.cautaStudentDupaNume(nume);
                if (student != nullptr) {
                    cout << "Studentul " << nume << (student->esteBursier() ? " este bursier.\n" : " nu este bursier.\n");
                }
                else {
                    cout << "Studentul nu a fost gasit.\n";
                }
                break;
            }
            case 5:
                cout << "Iesire...\n";
                break;
            default:
                cout << "Optiune invalida!\n";
            }
        } while (optiune != 5);
    }
    else {
        cout << "Rol invalid! Iesire...\n";
    }

    return 0;
}
