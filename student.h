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
    string name; //Numele studentului
    int group; //Grupa studentului
    char subgroup; //Semigrupa studentului
    vector<int>grades; //Vector care contine notele studentului

public:
    //Constructor - initializeaza atributele clasei student 
    Student(string name = " ", int group = 0, char subgroup = 'A', vector<int>grades = {});

    //Functii
    void addGrade(int grade); //Adauga o nota la vectorul de note al studentului

    float average() const; //Calculeaza si returneaza media notelor studentului, daca nu are note returneaza 0

    bool isFailing() const; //Verifica daca studentul are vreo nota mai mica decat 5
    bool isScholar() const; //Verifica daca studentul are media >= 8,50 si daca nu are restante

    //Getteri - returneaza valoarea unui atribut privat dintr-o clasa 
    int getId() const; //Returneaza ID-ul unic al studentului
    string getName() const; //Returneaza numele studentului
    int getGroup() const; //Returneaza grupa studentului
    char getSubgroup() const; //Returneaza semigrupa studentului
    const vector<int>& getGrades() const; //Returneaza vectorul de note al studentului 

};

#endif
