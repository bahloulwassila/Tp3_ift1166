/* Fichier TP3_NumB_H24-FINAL.cpp

    @TODO :
        1. Lire le fichier met_h24.txt, créer une liste chaînée programmée, 
        des personnes en utilisant des pointeurs dans l’ordre FIFO.
            << DONE

        2. Compter et afficher le nombre de personnes présentes dans la liste.
            << DONE

        3. Afficher les 9 premières personnes de la liste.
            << DONE

        4. Afficher toutes les personnes nommées, Robitaille Suzanne, de la liste.
            << DONE

        5. Supprimer la personne, Michaud Normand, puis réafficher les 7 premières personnes de la liste.
            << DONE

    Criteres de correction :
        Tache 1. 5 points
        Tache 2. 2 points
        Tache 3. 2 points
        Tache 4. 3 points
        Tache 5. 3 points

*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct Person {
    std::string firstName;
    std::string lastName;
    char gender;
    double height;
    double weight;
    int number;
};

struct Node {
    Person person;
    Node* next;
    Node(const Person& p) : person(p), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void addPerson(const Person& p) {
        Node* newNode = new Node(p);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        ++size;
    }

    void displayFirstN(int n) {
        Node* current = head;
        int count = 0;
        while (current != nullptr && count < n) {
            const Person& p = current->person;
            std::cout << p.firstName << " " << p.lastName << " "
                      << p.gender << " " << p.height << " "
                      << p.weight << " " << p.number << std::endl;
            current = current->next;
            ++count;
        }
    }

    void displaySpecificPerson(const std::string& firstName, const std::string& lastName) {
        Node* current = head;
        while (current != nullptr) {
            const Person& p = current->person;
            if (p.firstName == firstName && p.lastName == lastName) {
                std::cout << p.firstName << " " << p.lastName << " "
                          << p.gender << " " << p.height << " "
                          << p.weight << " " << p.number << std::endl;
            }
            current = current->next;
        }
    }

    void removePerson(const std::string& firstName, const std::string& lastName) {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr) {
            const Person& p = current->person;
            if (p.firstName == firstName && p.lastName == lastName) {
                if (prev == nullptr) { // Supprime head element.
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                if (current == tail) { // A ajuster en cas de besoin.
                    tail = prev;
                }
                delete current;
                --size;
                break;
            }
            prev = current;
            current = current->next;
        }
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};




int main() {
    std::ifstream file("met_h24.txt");
    std::string line;
    LinkedList peopleList;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Person person;
        iss >> person.firstName >> person.lastName >> person.gender
            >> person.height >> person.weight >> person.number;
        peopleList.addPerson(person);
    }

    std::cout << "\nNombre totalde personne : " << peopleList.size << std::endl;
    std::cout << "\nLes 9 premieres personnes dans la liste :\n" << std::endl;
    peopleList.displayFirstN(9);

    std::cout << "\nToutes les entrees correspondant a'Robitaille Suzanne':\n" << std::endl;
    peopleList.displaySpecificPerson("ROBITAILLE", "SUZANNE");

    peopleList.removePerson("MICHAUD", "NORMAND");
    std::cout << "\nLes 7 premieres personnes dans la liste apres suppression:\n" << std::endl;
    peopleList.displayFirstN(7);

    return 0;
}



/*


Execution:


Nombre totalde personne : 26

Les 9 premieres personnes dans la liste :

ROY CHANTAL F 1.75 57.9 2754
MOLAISON CLAUDINE F 1.57 62.2 1848
ROBITAILLE CHANTALE F 1.79 72.3 2007
BEDARD MARC-ANDRE M 1.43 55.5 2636
MONAST STEPHANE M 1.65 61.7 1750
JALBERT LYNE F 1.63 52.6 2168
DUBE FRANCOISE F 1.68 67.5 4612
ROBITAILLE SUZANNE F 1.72 75.4 2325
LEMELIN SOPHIE F 1.88 57.8 7777

Toutes les entrees correspondant a'Robitaille Suzanne':

ROBITAILLE SUZANNE F 1.72 75.4 2325
ROBITAILLE SUZANNE F 1.82 76.1 8007
ROBITAILLE SUZANNE F 1.63 75.1 7654
ROBITAILLE SUZANNE F 1.68 60.2 4119

Les 7 premieres personnes dans la liste apres suppression:

ROY CHANTAL F 1.75 57.9 2754
MOLAISON CLAUDINE F 1.57 62.2 1848
ROBITAILLE CHANTALE F 1.79 72.3 2007
BEDARD MARC-ANDRE M 1.43 55.5 2636
MONAST STEPHANE M 1.65 61.7 1750
JALBERT LYNE F 1.63 52.6 2168
DUBE FRANCOISE F 1.68 67.5 4612


*/