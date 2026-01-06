Acesta este un program în C++ care gestionează un catalog al studenților. Programul permite adăugarea, ștergerea și vizualizarea studenților, precum și gestionarea notelor și verificarea bursierilor și a restantierilor.
Descrierea programului

Programul implementează un catalog în care sunt stocați studenți. Aceștia sunt reprezentanți de clasa Student și sunt manipulați de clasa Catalog. Aplicația permite roluri diferite (administrator, profesor și student) cu funcționalități personalizate pentru fiecare.

Funcționalități:

Administrator:

Vizualizează catalogul complet al studenților.

Adaugă și șterge studenți.

Vizualizează lista restantierilor și bursierilor.

Profesor:

Vizualizează catalogul.

Căutare student după nume.

Adaugă note pentru studenți.

Vizualizează restantierii.

Student:

Vizualizează notele proprii.

Calculează media generală.

Verifică dacă este restantier.

Verifică dacă este bursier.

Structura Proiectului
Fișiere:

student.h: Definirea clasei Student, care reprezintă un student cu datele sale (nume, grupă, semigrupă, note).

catalog.h: Definirea clasei Catalog, care conține o listă de studenți și metodele de manipulare a acestora (adăugare, ștergere, căutare).

main.cpp: Programul principal care implementează meniul pentru fiecare tip de utilizator (administrator, profesor, student).

student.cpp: Implementarea metodelor pentru clasa Student.

catalog.cpp: Implementarea metodelor pentru clasa Catalog.

Comenzi disponibile:

Administrator:

Afișează catalogul studenților.

Adaugă un student.

Șterge un student.

Afișează restantierii.

Afișează bursierii.

Iesire.

Profesor:

Afișează catalogul studenților.

Căutare student după nume.

Adaugă note studentului.

Afișează restantierii.

Iesire.

Student:

Afișează notele studentului.

Afișează media generală.

Verifică dacă este restantier.

Verifică dacă este bursier.

Iesire.

Structura datelor
Clasa Student

Un obiect de tip Student conține următoarele atribute:

id: Un ID unic pentru fiecare student (generat automat).

nume: Numele studentului.

grupa: Grupa studentului.

semigrupa: Semigrupa studentului (A, B, C, D).

note: O listă de note ale studentului.

Clasa Catalog

Clasa Catalog conține o listă de studenți și metode pentru gestionarea acestora:

adaugaStudent: Adaugă un student în catalog.

stergeStudent: Șterge un student din catalog după ID.

cautaStudentDupaNume: Căutare student după nume.

afiseazaCatalog: Afișează întregul catalog cu detalii despre studenți.

afiseazaRestantieri: Afișează lista studenților restantieri.

afiseazaBursieri: Afișează lista studenților bursieri.
