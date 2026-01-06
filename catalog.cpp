#include "catalog.h"
#include <iostream>
#include <algorithm> // Permite utilizarea functiilor de sortare, manipulare - sort,find

void Catalog::addStudent(const Student& student) {
    students.push_back(student); // Adauga un obiect Student la vectorul students
}

void Catalog::deleteStudent(int id) { //Sterge ID-ul studentului din lista de studenti 
    auto it = std::find_if(students.begin(), students.end(), [id](const Student& s) {
        return s.getId() == id;  // Verifica daca ID-ul studentului corespunde
        });

    if (it != students.end()) {
        students.erase(it);  // Sterge studentul
        std::cout << "Student with ID " << id << " has been removed.\n";
    }
    else {
        std::cout << "Student with ID " << id << " was not found.\n";
    }
}

Student* Catalog::searchStudentByName(const std::string& name) { //Cauta un student in lista de studenti si returneaza un pointer la acel student daca este gasit
    for (auto& student : students) {
        if (student.getName() == name) {
            return &student; // Returnam un pointer catre studentul gasit 
        }
    }
    return nullptr; // Returnam nullptr daca studentul nu a fost gasit
}

void Catalog::displayCatalog() const {  //Afiseaza toate detaliile despre studenti
    for (const auto& student : students) {
        std::cout << "ID: " << student.getId() << "  | "
            << "Name: " << student.getName()
            << ", Group: " << student.getGroup()
            << ", Subgroup: " << student.getSubgroup()
            << ", Average: " << student.average()
            << ", Failing: " << (student.isFailing() ? "YES" : "NO")
            << ", Scholarship: " << (student.isScholar() ? "YES" : "NO")
            << ", Grades: ";

        const auto& grades = student.getGrades();  // Obtine notele studentului
        for (int grade : grades) {
            std::cout << grade << " ";  // Afiseaza fiecare nota
        }
        std::cout << std::endl;  // Se trece la linia urmatoare dupa ce afisam notele
    }
}

void Catalog::displayFailingStudents() const { //Verifica daca exisa cel putin un student care a picat 
    bool isFailing = false; //Se presupune ca nu exista studenti care au picat
    for (const auto& student : students) {
        if (student.isFailing()) {
            std::cout << student.getName() << "\n"; //Se afiseaza numele studentului
            isFailing = true;
        }
    }
    if (!isFailing) { //Dupa ce bucla a terminat de parcurs toti studentii, verificam daca hasFailing = false 
        std::cout << "No failing students.\n";
    }
}

void Catalog::displayScholarshipStudents() const { //Verifica daca exista cel putin un student bursier
    bool isScholar = false; //Se presupune ca nu exista studenti bursieri
    for (const auto& student : students) {
        if (student.isScholar()) {
            std::cout << student.getName() << "\n"; //Se afiseaza numele studentului
            isScholar = true;
        }
    }
    if (!isScholar) { //Dupa ce bucla a terminat de parcurs toti studentii, verificam daca hasScholarship = false 
        std::cout << "No scholarship students.\n";
    }
}

void Catalog::sortStudentsByAverage() {
    //Pentru a sorta studentii din vectorul students de la inceput pana la sfarsit
    std::sort(
        students.begin(),              // Inceputul vectorului students
        students.end(),                // Sfarsitul vectorului students
        [](const Student& a, const Student& b) // Functia Lambda(definita direct in corpul unui alt apel de functie) - pentru comparatie
        {
            // Compararare medii studenti
            return a.average() > b.average(); //a si b vor fi comparati pentru a decide ordinea lor
        }
    );
}

void Catalog::initStudents() {
    // Creare studenti predefiniti cu note 
    students.push_back(Student("Ion Popescu", 1, 'A', { 7, 8, 9 }));
    students.push_back(Student("Maria Ionescu", 2, 'B', { 5, 6, 7 }));
    students.push_back(Student("George Georgescu", 3, 'A', { 10, 9, 8 }));
    students.push_back(Student("Ana Andrei", 1, 'C', { 6, 7, 5 }));
    students.push_back(Student("Mihai Vasilescu", 3, 'D', { 9, 9, 10 }));
    students.push_back(Student("Elena Marinescu", 2, 'A', { 8, 8, 8 }));
    students.push_back(Student("Radu Stanescu", 1, 'B', { 4, 5, 6 }));
    students.push_back(Student("Ioana Popa", 3, 'C', { 7, 7, 6 }));
    students.push_back(Student("Florin Neagu", 2, 'D', { 6, 5, 7 }));
    students.push_back(Student("Gabriela Radu", 1, 'A', { 10, 10, 10 }));

}
