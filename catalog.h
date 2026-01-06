#ifndef CATALOG_H //Aceste directive sunt folosite pentru a evita includerea multiplă a aceluiasi fisier de antet (header) în timpul compilării.
#define CATALOG_H

#include<iostream>
#include "student.h"
#include<vector>
#include<string>

class Catalog {
private:
    std::vector<Student> students; //Acesta va contine lista tuturor studentilor din catalog

public:
    void addStudent(const Student& student); //Adauga un student in catalog, primeste obiectul de tip Student pe care il adauga in vectorul students

    void deleteStudent(int id); //Sterge un student din catalog dupa ID

    Student* searchStudentByName(const std::string& name); //Cauta un student dupa nume si returneaza un pointer catre obiectul student gasit 

    void displayCatalog() const; //Afisare intreg catalog

    void displayFailingStudents() const; //Afisare studenti restantieri

    void displayScholarshipStudents() const; //Afiseaza bursieri

    void sortStudentsByAverage(); //Sortare studenti dupa medie

    void initStudents(); //Initializare 10 studenti pentru testare

};

#endif
