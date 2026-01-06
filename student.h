#ifndef STUDENT_H //Aceste directive sunt folosite pentru a evita includerea multiplă a aceluiasi fisier de antet (header) în timpul compilării.
#define STUDENT_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Student {
private:
    static int nextId; // Variabila statică pentru ID-ul unic
    int id; //ID-ul unic al studentului
    string nume;
    int grupa;
    char semigrupa;
    vector<int>note;

public:
    Student(string nume = " ", int grupa = 0, char semigrupa = 'A', vector<int>note = {});

    //Metode
    void adaugaNota(int nota);

    float medie() const;

    bool esteRestantier() const;
    bool esteBursier() const;

    //Getteri
    int getId() const;
    string getNume() const;
    int getGrupa() const;
    char getSemigrupa() const;
    const vector<int>& getNote() const;

};

#endif
