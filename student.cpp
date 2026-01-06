#include "student.h"

int Student::nextId = 1; //Genereaza un ID unic pentru fiecare student

//constructorul clasei Student

Student::Student(std::string name, int group, char subgroup, vector<int>grades) : name(name), group(group), subgroup(subgroup), grades(grades) {
    id = nextId++; // Atribuim un ID unic - incrementare cu 1 pentru student nou
}

    void Student::addGrade(int grade) { //Adauga o nota noua in vectorul note al studentului 
    grades.push_back(grade); //Adauga valoarea la sfarsitul vectorului
}

float Student::average() const { //Calculeaza media notelor studentului
    if (grades.empty()) { //Verifica daca lista de note e goala 
        return 0; //Daca e goala, returneaza 0, studentul nu are note
    }
    float sum = 0;

    for (int g : grades) { 
        sum = sum + g;
    }
    return sum / grades.size(); //Returneaza media
}

bool Student::isFailing() const { //Verifica daca studentul este restantier 
    for (int g : grades) {
        if (g < 5) {
            return true;
        }
    }
    return false;
}

bool Student::isScholar() const { //Verifica daca studentul este bursier
    if (average() >= 8.50 && !isFailing()) { 
        return true;
    }
    else {
        return false;
    }
}

//Getteri - returneaza valoarea unui atribut privat dintr-o clasa

int Student::getId() const {
    return id; //Returneaza ID-ul studentului
}

std::string Student::getName() const { //Returneaza numele studentului
    return name;
}

int Student::getGroup() const { //Returneaza grupa studentului
    return group;
}

char Student::getSubgroup() const { //Returneaza semigrupa studentului
    return subgroup;
}

const std::vector<int>& Student::getGrades() const { //Returneaza referinta constanta la vectorul de note al studentului, permitand doar citirea, nu modificarea
    return grades;
}
