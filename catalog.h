#ifndef CATALOG_H
#define CATALOG_H

#include<iostream>
#include "student.h"
#include<vector>
#include<string>

class Catalog {
private:
    std::vector<Student> studenti; //acesta va contine lista tuturor studentilor din catalog

public:
    //Adauga un student in catalog
    void adaugaStudent(const Student& student);

    //Sterge un student dupa ID
    void stergeStudent(int id);

    //Cauta student dupa nume
    Student* cautaStudentDupaNume(const std::string& nume);

    //Afisare intreg catalog
    void afiseazaCatalog() const;

    //Afisare studenti restantieri
    void afiseazaRestantieri() const;

    //Afiseaza bursieri
    void afiseazaBursieri() const;

    //Sortare studenti dupa medie
    void sorteazaDupaMedie();

    //Initializare 10 studenti pentru testare
    void initStudenti();

};

#endif
