Acesta este un program în C++ care gestionează un catalog al studenților. Programul permite adăugarea, ștergerea și vizualizarea studenților, precum și gestionarea notelor și verificarea bursierilor și a restantierilor.
Descrierea programului

Programul implementează un catalog în care sunt stocați studenți. Aceștia sunt reprezentanți de clasa Student și sunt manipulați de clasa Catalog. Aplicația permite roluri diferite (administrator, profesor și student) cu funcționalități personalizate pentru fiecare.

Funcționalități:

Administrator:

1.Vizualizează catalogul complet al studenților.

2.Adaugă și șterge studenți.

3.Vizualizează lista restantierilor și bursierilor.

Profesor:

1.Vizualizează catalogul.

2.Căutare student după nume.

3.Adaugă note pentru studenți.

4.Vizualizează restantierii.

Student:

1.Vizualizează notele proprii.

2.Calculează media generală.

3.Verifică dacă este restantier.

4.Verifică dacă este bursier.

Structura Proiectului
Fișiere:

student.h: Definirea clasei Student, care reprezintă un student cu datele sale (nume, grupă, semigrupă, note).

catalog.h: Definirea clasei Catalog, care conține o listă de studenți și metodele de manipulare a acestora (adăugare, ștergere, căutare).

main.cpp: Programul principal care implementează meniul pentru fiecare tip de utilizator (administrator, profesor, student).

student.cpp: Implementarea metodelor pentru clasa Student.

catalog.cpp: Implementarea metodelor pentru clasa Catalog.

Comenzi disponibile:

Administrator:

1.Afișează catalogul studenților.

2.Adaugă un student.

3.Șterge un student.

4.Afișează restantierii.

5.Afișează bursierii.

6.Iesire.

Profesor:

1.Afișează catalogul studenților.

2.Căutare student după nume.

3.Adaugă note studentului.

4.Afișează restantierii.

5.Iesire.

Student:

1.Afișează notele studentului.

2.Afișează media generală.

3.Verifică dacă este restantier.

4.Verifică dacă este bursier.

5.Iesire.

Structura datelor
Clasa Student

Un obiect de tip Student conține următoarele atribute:

id: Un ID unic pentru fiecare student (generat automat).

nume: Numele studentului.

grupa: Grupa studentului (1, 2, 3).

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
