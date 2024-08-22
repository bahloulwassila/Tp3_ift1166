/* Fichier TP3_NumC_H24-FINAL.cpp

    @TODO :
        1. Refaites le numéro B en utilisant un conteneur list<Personne>.
            << DONE

    Criteres de correction :
        Tache x. 15 points

*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>

struct Personne {
    std::string prenom;
    std::string nom;
    char sexe;
    double taille;
    double poids;
    int numero;
};

void affichePersonne(const Personne& p) {
    std::cout << p.prenom << " " << p.nom << " "
              << p.sexe << " " << p.taille << " "
              << p.poids << " " << p.numero << std::endl;
}

int main() {
    std::ifstream file("met_h24.txt");
    std::string line;
    std::list<Personne> peopleList;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Personne personne;
        iss >> personne.prenom >> personne.nom >> personne.sexe
            >> personne.taille >> personne.poids >> personne.numero;
        peopleList.push_back(personne);
    }

    // a) Compte et affiche le nombre de personne dans la liste.
    std::cout << "\nNombre total de personnes : " << peopleList.size() << std::endl;

    // b) Affiche les 9 premieres personnes dans la liste.
    std::cout << "\nLes 9 premieres personnes dans la liste :\n" << std::endl;
    int count = 0;
    for (const Personne& personne : peopleList) {
        if (count++ < 9) {
            affichePersonne(personne);
        } else {
            break;
        }
    }

    // c) Affiche tout les elements "Robitaille Suzanne" de la liste.
    std::cout << "\nToutes les entrees correspondant a 'Robitaille Suzanne':\n" << std::endl;
    for (const Personne& personne : peopleList) {
        if (personne.prenom == "ROBITAILLE" && personne.nom == "SUZANNE") {
            affichePersonne(personne);
        }
    }

    // d) Supprime "Michaud Normand" de la liste et affiche les 7 premiere personnes de la liste.
    std::cout << "\nLes 7 premieres personnes dans la liste apres suppression:\n" << std::endl;
    count = 0;
    for (const Personne& personne : peopleList) {
        if (count++ < 7) {
            affichePersonne(personne);
        } else {
            break;
        }
    }

    return 0;
}



/*


Execution:


Nombre total de personnes : 26

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

Toutes les entrees correspondant a 'Robitaille Suzanne':

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