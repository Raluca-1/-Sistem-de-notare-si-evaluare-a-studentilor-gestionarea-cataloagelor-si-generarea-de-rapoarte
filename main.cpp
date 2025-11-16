#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
 string nume;
 string prenume;
 int grupa;
 char semigrupa;
 vector<float>note;
};

vector<Student>catalog;
void afiseazaNote(const vector<float>& note);

void adaugaStudent(){
 Student s;
 cout << "\n--- Adaugare Student ---\n";
 cout << "Introduceti numele: ";
 cin >> s.nume;
 cout << "Introduceti prenumele: ";
 cin >> s.prenume;
 cout << "Introduceti grupa: ";
 cin >> s.grupa;
 cout << "Introduceti semigrupa: ";
 cin >> s.semigrupa;

 /*Așa că, atunci când completăm informațiile pentru un student (nume, prenume, grupă etc.), apelăm push_back() pentru a salva acel student în vectorul catalog*/
 catalog.push_back(s);
 cout << "\nStudent adaugat cu succes! \n" << endl;
}

void adaugaNote(){
 string nume_cautat;
 cout << "\n--- Adauga Note pentru Student ---\n";
 cout << "\nIntroduceti numele studentului pentru note: ";
 cin >> nume_cautat;
// Parcurgem fiecare student din vectorul 'catalog'
// 'auto' va deduce tipul 'Student', iar '&' face ca 'student' să fie o referință
// la obiectul actual din vector, fără a-l copia
 for (auto &student : catalog){
    if (student.nume == nume_cautat){
      int nr_note;
      cout << "\nCate note doriti sa adaugati? ";
      cin >> nr_note;
      for (int i = 0; i<nr_note; i++){
        float nota;
        cout << "Nota " << i+1 << ": ";
        cin >> nota;
        student.note.push_back(nota);
      }
      cout << "\nNotele au fost adaugate!\n" << endl;
      return;
    }

 }

 cout << "\nStudentul nu a fost gasit." << endl;
}

void afiseazaCatalog(){
cout << "\n--- Catalogul Studentilor ---\n";
 for(auto student : catalog){
    cout << "\nNume: " << student.nume << " " << student.prenume
         << "\nGrupa: " <<student.grupa << student.semigrupa
         << "\nNote: ";
   // Verificăm dacă studentul are note
    if(student.note.size() > 0){
        afiseazaNote(student.note);
    }else {
        cout << "\nNu exista note pentru acest student.\n";
    }
    cout << "\n----------------------------\n";
 }
}
void afiseazaNote(const vector<float>& note){
  for(float n : note){
    cout << n << " ";// Afiseaza fiecare nota
  }
 }

 int main(){
     int opt;
     while (true){
        cout << "\n---Meniu---\n";
        cout << "1. Adauga student\n";
        cout << "2. Adauga note\n";
        cout << "3. Afiseaza catalog\n";
        cout << "4. Iesire\n";
        cout << "Va rog sa alegeti!\n";
        cin >> opt;
        switch(opt){
           case 1: adaugaStudent();
              break;
           case 2: adaugaNote();
              break;
           case 3: afiseazaCatalog();
              break;
           case 4: return 0;
           default: cout << "Optiune invalida!" << endl;
        }

     }

 getchar();
 }
