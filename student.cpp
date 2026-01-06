#include "student.h"

//Initializam ID-ul static pentru studenti

int Student::nextId = 1;

//constructorul clasei Student

Student::Student(std::string nume, int grupa, char semigrupa, vector<int>note) : nume(nume), grupa(grupa), semigrupa(semigrupa), note(note) {
    id = nextId++; // Atribuim un ID unic fiecărui student
}

void Student::adaugaNota(int nota) {
    note.push_back(nota);
}

float Student::medie() const {
    if (note.empty()) {
        return 0;
    }
    float suma = 0;

    for (int n : note) {
        suma = suma + n;
    }
    return suma / note.size();
}

bool Student::esteRestantier() const {
    for (int n : note) {
        if (n < 5) {
            return true;
        }
    }
    return false;
}

bool Student::esteBursier() const {
    if (medie() >= 8.50 && !esteRestantier()) {
        return true;
    }
    else {
        return false;
    }
}

//Getteri 

int Student::getId() const {
    return id;
}

std::string Student::getNume() const {
    return nume;
}

int Student::getGrupa() const {
    return grupa;
}

char Student::getSemigrupa() const {
    return semigrupa;
}

const std::vector<int>& Student::getNote() const {
    return note;
}
