Fișa de funcționalități – Proiect POO

Tema: Sistem de notare și evaluare a studenților – gestionarea cataloagelor și generarea de rapoarte
Student: Badea Raluca-Maria
Specializare: CTI, an 2

 Descriere generală

Aplicația reprezintă un sistem de gestionare a studenților și notelor acestora. Programul permite introducerea studenților în catalog, adăugarea notelor, afișarea situației generale și generarea de rapoarte simple bazate pe informațiile introduse. Aplicația este realizată în C++ și funcționează prin intermediul unei interfețe text-based, utilizând un meniu interactiv.

Scopul sistemului este de a ușura administrarea notelor, vizualizarea performanței fiecărui student și menținerea unui catalog organizat.

   Funcționalități principale
1. Gestionarea studenților

Adăugarea unui student nou (nume, prenume, grupă, semigrupă).
 → funcția adaugaStudent()

Vizualizarea listei tuturor studenților din catalog.
 → funcția afiseazaCatalog()

Căutarea unui student după nume pentru a-i accesa datele.
 → în funcția adaugaNote() (partea de căutare)

2. Gestionarea notelor

Adăugarea de note unui student existent în catalog.
 → funcția adaugaNote()

Afișarea notelor unui student.
 → funcția afiseazaNote()

Calcularea mediilor (funcționalitate ce poate fi adăugată ulterior).
 → o funcție calculeazaMedie(student)

3. Generarea rapoartelor

Afișarea catalogului complet (toți studenții și notele lor).
 → funcția afiseazaCatalog()

Raport simplu pentru fiecare student (nume, grupă, note).


Posibilitatea extinderii pentru: bursieri, restanțieri.
Loc viitor: funcții noi în main.cpp sau fișiere separate.

4. Interacțiunea cu utilizatorul

Meniu principal interactiv cu opțiuni pentru acțiunile principale.
Cod în: main.cpp → în funcția main()

Mesaje de atenționare atunci când studentul nu este găsit.
 → adaugaNote()

5. Extensii viitoare

Statistici: medii, restanțieri.
Cod viitor: funcții suplimentare

 Roluri utilizatori

Administrator – gestionează toți studenții.

Profesor – adaugă și actualizează note.

Student – își vede notele.
.

 Tip interfață

Interfață text-based (terminal / consolă).

Utilizatorul alege opțiuni prin tastare (1, 2, 3…).

 Structura fișierelor


Include toate funcțiile: adaugaStudent(), adaugaNote(), afiseazaCatalog(), afiseazaNote().

