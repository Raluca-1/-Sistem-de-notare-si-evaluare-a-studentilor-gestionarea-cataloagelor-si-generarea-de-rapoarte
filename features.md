Fișa de funcționalități – Proiect POO

Tema: Sistem de notare și evaluare a studenților – gestionarea cataloagelor și generarea de rapoarte
Student: Badea Raluca-Maria
Specializare: CTI, an 2

📌 Descriere generală

Aplicația reprezintă un sistem de gestionare a studenților și notelor acestora. Programul permite introducerea studenților în catalog, adăugarea notelor, afișarea situației generale și generarea de rapoarte simple bazate pe informațiile introduse. Aplicația este realizată în C++ și funcționează prin intermediul unei interfețe text-based, utilizând un meniu interactiv.

Scopul sistemului este de a ușura administrarea notelor, vizualizarea performanței fiecărui student și menținerea unui catalog organizat.

   Funcționalități principale
1. Gestionarea studenților

Adăugarea unui student nou (nume, prenume, grupă, semigrupă).
Cod în: main.cpp → funcția adaugaStudent()

Vizualizarea listei tuturor studenților din catalog.
Cod în: main.cpp → funcția afiseazaCatalog()

Căutarea unui student după nume pentru a-i accesa datele.
Cod în: main.cpp → în funcția adaugaNote() (partea de căutare)

2. Gestionarea notelor

Adăugarea de note unui student existent în catalog.
Cod în: main.cpp → funcția adaugaNote()

Afișarea notelor unui student.
Cod în: main.cpp → funcția afiseazaNote()

Calcularea mediilor (funcționalitate ce poate fi adăugată ulterior).
Loc viitor: main.cpp → o funcție calculeazaMedie(student)

3. Generarea rapoartelor

Afișarea catalogului complet (toți studenții și notele lor).
Cod în: main.cpp → funcția afiseazaCatalog()

Raport simplu pentru fiecare student (nume, grupă, note).
Cod în: main.cpp

Posibilitatea extinderii pentru: top studenți, restanțieri, statistici.
Loc viitor: funcții noi în main.cpp sau fișiere separate.

4. Interacțiunea cu utilizatorul

Meniu principal interactiv cu opțiuni pentru acțiunile principale.
Cod în: main.cpp → în funcția main()

Mesaje de atenționare atunci când studentul nu este găsit.
Cod în: main.cpp → adaugaNote()

5. Extensii viitoare (opționale)

Salvarea catalogului în fișiere externe.
Fișier viitor: students.txt

Încărcarea datelor de la pornirea aplicației.
Fișier viitor: students.txt

Statistici: medii, restanțieri, ordine descrescătoare.
Cod viitor: funcții suplimentare

 Roluri utilizatori

Acum proiectul tău nu are roluri diferite, dar dacă vrei să îl extinzi, poți avea:

Administrator – gestionează toți studenții și notele.

Profesor – adaugă și actualizează note.

Student – își vede notele.

Deocamdată, toate rolurile sunt într-un singur program (un singur meniu).

 Tip interfață

Interfață text-based (terminal / consolă).

Utilizatorul alege opțiuni prin tastare (1, 2, 3…).

 Structura fișierelor

Pentru moment, proiectul folosește un singur fișier:

✔️ main.cpp

Conține structura Student.

Conține vectorul global catalog.

Include toate funcțiile: adaugaStudent(), adaugaNote(), afiseazaCatalog(), afiseazaNote().

Include meniul principal și logica programului.
