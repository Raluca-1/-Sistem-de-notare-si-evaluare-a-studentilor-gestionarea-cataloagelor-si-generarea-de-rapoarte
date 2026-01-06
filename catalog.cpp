#include "catalog.h"
#include<iostream> 
#include<algorithm> //Permite utilizarea functiilor de sortare si manipulare a colectiilor

void Catalog::adaugaStudent(const Student& student) {
    studenti.push_back(student);
}

void Catalog::stergeStudent(int id) {
    auto it = std::find_if(studenti.begin(), studenti.end(), [id](const Student& s) {
        return s.getId() == id;
        });

    if (it != studenti.end()) {
        studenti.erase(it);  // Sterge studentul
        std::cout << "Studentul cu ID-ul " << id << " a fost sters.\n";
    }
    else {
        std::cout << "Studentul cu ID-ul " << id << " nu a fost gasit.\n";
    }
}


Student* Catalog::cautaStudentDupaNume(const std::string& nume) {
    for (auto& student : studenti) {
        if (student.getNume() == nume) {
            return &student; // Returnează pointerul către studentul găsit
        }
    }
    return nullptr; //Daca nu gaseste studentul
}

void Catalog::afiseazaCatalog() const {
    for (const auto& student : studenti) {
        std::cout << "ID: " << student.getId() << "  | "
            << "Nume: " << student.getNume()
            << ", Grupa: " << student.getGrupa()
            << ", Semigrupa: " << student.getSemigrupa()
            << ", Medie: " << student.medie()
            << ", Restantier: " << (student.esteRestantier() ? "DA" : "NU")
            << ", Bursier: " << (student.esteBursier() ? "DA" : "NU")
            << ", Note: ";
        // Afisează notele studentului
        const auto& note = student.getNote();  // Obtine notele studentului
        for (int nota : note) {
            cout << nota << " ";  // Afisează fiecare notă
        }
        cout << endl;  // După ce afisam toate notele, trecem la o linie nouă
    }
    }

void Catalog::afiseazaRestantieri() const {
    bool existaRestantieri = false;
    for (const auto& student : studenti) {
        if (student.esteRestantier()) {
            std::cout << student.getNume() << "\n";
            existaRestantieri = true;
        }
    }
    if (!existaRestantieri) {
        std::cout << "Nu există restantieri.\n";
    }
}

void Catalog::afiseazaBursieri() const {
    bool existaBursieri = false;
    for (const auto& student : studenti) {
        if (student.esteBursier()) {
            std::cout << student.getNume() << "\n";
            existaBursieri = true;
        }
    }
    if (!existaBursieri) {
        std::cout << "Nu există bursieri.\n";
    }
}


void Catalog::sorteazaDupaMedie()
{
    // Folosim std::sort pentru a sorta studen?ii
    std::sort(
        studenti.begin(),              // Începutul vectorului
        studenti.end(),                // Sfârsitul vectorului
        [](const Student& a, const Student& b) // Lambda pentru comparare
        {
            // Comparăm mediile studen?ilor
            return a.medie() > b.medie();
        }
    );
}



void Catalog::initStudenti() {
    // Creezi studenti cu note predefinite
    studenti.push_back(Student("Ion Popescu", 1, 'A', { 7, 8, 9 }));
    studenti.push_back(Student("Maria Ionescu", 2, 'B', { 5, 6, 7 }));
    studenti.push_back(Student("George Georgescu", 3, 'A', { 10, 9, 8 }));
    studenti.push_back(Student("Ana Andrei", 1, 'C', { 6, 7, 5 }));
    studenti.push_back(Student("Mihai Vasilescu", 3, 'D', { 9, 9, 10 }));
    studenti.push_back(Student("Elena Marinescu", 2, 'A', { 8, 8, 8 }));
    studenti.push_back(Student("Radu Stanescu", 1, 'B', { 4, 5, 6 }));
    studenti.push_back(Student("Ioana Popa", 3, 'C', { 7, 7, 6 }));
    studenti.push_back(Student("Florin Neagu", 2, 'D', { 6, 5, 7 }));
    studenti.push_back(Student("Gabriela Radu", 1, 'A', { 10, 10, 10 }));

}
