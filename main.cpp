#include<iostream>
#include<vector>

using namespace std;

class Studenti {
private:
    string Nume;
    int Grupa;
    char Semigrupa;
    vector<int> Note;

public:
    // Constructor pentru a inițializa studentul cu nume, grupă și semigrupa
    Studenti(string nume, int grupa, char semigrupa)
        : Nume(nume), Grupa(grupa), Semigrupa(semigrupa) {}

    // Funcție pentru a adăuga o notă
    void adaugaNota(int nota) {
        Note.push_back(nota);
    }

    // Funcție pentru a calcula media notelor
    float calculeazaMedia() const {
        if (Note.empty()) {
            return 0.0f;
        }
        int suma = 0;
        for (int nota : Note) {
            suma = suma + nota;
        }
        return static_cast<float>(suma) / Note.size(); // Asigură că media va fi în format float
    }

    // Funcție pentru a afișa detaliile studentului
    void afiseazaDetalii() const {
        cout << "Nume: " << Nume << " Grupa: " << Grupa << " Semigrupa: " << Semigrupa << endl;
        cout << "Media: " << calculeazaMedia() << endl;
        cout << "Note: ";
        for (int nota : Note) {
            cout << nota << " ";
        }
        cout << endl;
    }

    // Getter pentru numele studentului
    string getName() const {
        return Nume;
    }
};

class Catalog {
private:
    vector<Studenti> listaStudenti; // Stocăm studenții în acest vector

public:
    void adaugaStudent(const Studenti& student) {
        listaStudenti.push_back(student);
    }

    // Funcția pentru afișarea catalogului complet
    void afiseazaCatalog() const {
        if (listaStudenti.empty()) {
            cout << "Catalogul este gol!" << endl;
            return;
        }
        for (const Studenti& student : listaStudenti) {
            student.afiseazaDetalii();
            cout << "---------------------------------" << endl;
        }
    }

    // Căutăm un student după nume
    void cautaStudentDupaNume(const string& nume) const {
        bool gasit = false;
        for (const Studenti& student : listaStudenti) {
            if (student.getName() == nume) {
                student.afiseazaDetalii();
                gasit = true;
                break; // Oprim căutarea odată ce l-am găsit
            }
        }
        if (!gasit) {
            cout << "Studentul " << nume << " nu a fost gasit!" << endl;
        }
    }

    // Funcția pentru adăugarea notelor unui student
    void adaugaNotaStudent() {
        string nume;
        int nota;
        cout << "Introduceti numele studentului: ";
        cin.ignore();  // Pentru a ignora caracterul newline rămas în buffer
        getline(cin, nume);  // Citim numele complet (în caz că are mai multe cuvinte)

        bool gasit = false;
        for (Studenti& student : listaStudenti) {
            if (student.getName() == nume) {
                cout << "Introduceti nota: ";
                cin >> nota;
                student.adaugaNota(nota);  // Adăugăm nota studentului
                cout << "Nota a fost adaugata cu succes!" << endl;
                gasit = true;
                break;
            }
        }
        if (!gasit) {
            cout << "Studentul nu a fost gasit!" << endl;
        }
    }
};

// Funcție pentru a afișa meniul
void afiseazaMeniu() {
    cout << "Meniu:" << endl;
    cout << "1. Afisare catalog complet" << endl;
    cout << "2. Cautare student dupa nume" << endl;
    cout << "3. Adaugare student" << endl;
    cout << "4. Adauga nota" << endl;
    cout << "5. Iesire" << endl;
}

int main() {
    Catalog catalog;
    int optiune;
    bool programIncheiat = false;

    // Adăugăm câțiva studenți la început
    catalog.adaugaStudent(Studenti("Popescu Ion", 4321, 'A'));
    catalog.adaugaStudent(Studenti("Badea Cristina", 4217, 'B'));
    catalog.adaugaStudent(Studenti("Nicolae Valentin", 3216, 'C'));
    catalog.adaugaStudent(Studenti("Cirstea Mario", 5642, 'B'));
    catalog.adaugaStudent(Studenti("Dobre Valentin", 9866, 'C'));
    catalog.adaugaStudent(Studenti("Florea Ioana", 1124, 'B'));
    catalog.adaugaStudent(Studenti("Candoi Denisa", 6744, 'A'));

    while (!programIncheiat) {
        afiseazaMeniu();
        cout << "Alege o optiune: ";
        cin >> optiune;

        switch (optiune) {
            case 1:
                catalog.afiseazaCatalog(); // Afișăm catalogul complet
                break;
            case 2: {
                string numeCautat;
                cout << "Introduceti numele studentului: ";
                cin.ignore();  // Pentru a ignora caracterul newline rămas în buffer
                getline(cin, numeCautat);  // Citim numele complet
                catalog.cautaStudentDupaNume(numeCautat); // Căutăm studentul
                break;
            }
            case 3: {
                string nume;
                int grupa;
                char semigrupa;
                cout << "Introduceti numele studentului: ";
                cin.ignore();  // Ignorăm newline-ul
                getline(cin, nume);
                cout << "Introduceti grupa: ";
                cin >> grupa;
                cout << "Introduceti semigrupa (A/B/C): ";
                cin >> semigrupa;
                catalog.adaugaStudent(Studenti(nume, grupa, semigrupa)); // Adăugăm studentul în catalog
                break;
            }
            case 4:
                catalog.adaugaNotaStudent(); // Adăugăm nota pentru un student
                break;
            case 5:
                programIncheiat = true; // Iesim din program
                cout << "La revedere!" << endl;
                break;
            default:
                cout << "Optiune invalida! Te rog alege o optiune valida." << endl;
        }
    }

    return 0;
}
