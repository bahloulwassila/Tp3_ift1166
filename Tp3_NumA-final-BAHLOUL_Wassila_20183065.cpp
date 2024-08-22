/* Fichier TP3_NumA_H24.cpp

    Completer pour le numero A du TP #3, Hiver 2024 (10 points)

    @TODO :
        1. Afficher le tableau des cercles en utilisant, entre
        autres, la surcharge de l'op�rateur d'affichage 
            << DONE

        2. Permuter ces elements : c[0] et c[4] , c[1] et c[3]
        Reafficher le tableau apres ces deux permutations.
            << DONE

        3. Determiner et afficher :
            a) Le cercle ayant le plus petit rayon ;
            b) Le cercle ayant le plus grand rayon.
            En utilisant, entre autres :
                - Une seule fonction template ;
                - La surcharge des op�rateurs > et <
            << DONE


        4. Trier le tableau des cercles par le tri rapide, puis
        reafficher ce tableau apres le tri.
            << DONE

    Criteres de correction :
        Tache 1. 2 points
        Tache 2. 2 points
        Tache 3. 3 points
        Tache 4. 3 points
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

const float PI = 3.14159;

// Definition de la classe Cercle
class Cercle
{
private:
    float rayon; // l'acces prive au champ rayon

public:
    // un constructeur : conflit entre nom de parametre et nom de champ
    // => on utilise le pointeur this o� *this est l'objet courant
    Cercle(float rayon = 5.7) {
        this->rayon = rayon; // c'est meme chose que (*this).rayon;
    }

    // Methode d'acces + methode de calcul
    float getRayon() const { return rayon; }
    float perimetre() const { return 2 * PI * rayon; }
    float surface() const { return PI * rayon * rayon; }

    // Surcharge d'operateurs pour les comparaisons sur l'attribut 'rayon'
    bool operator<(const Cercle &autre) const { 
        return rayon < autre.rayon; 
        }

    bool operator>(const Cercle &autre) const { 
        return rayon > autre.rayon; 
    }

    bool operator<=(const Cercle &autre) const { 
        return rayon <= autre.rayon;
        }

    friend ostream &operator<<(ostream &sortie, const Cercle &c) {
        sortie << fixed << showpoint;
        sortie << "Rayon: " << setw(6) << setprecision(2) << c.getRayon()
               << ", Perimetre: " << setw(8) << setprecision(2) << c.perimetre()
               << ", Surface: " << setw(8) << setprecision(2) << c.surface() << endl;
        return sortie;
    }
};

// Declaration d'une fonction patron permuter.
template <class T>
void permuter(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Declaration d'une fonction patron pour trouver les MIN et MAX.
template <class T>
void trouverEtAfficherExtremums(const T c[], int nbCercle) {
    if (nbCercle == 0) return;  // Cas pour empty array.

    const T* min = &c[0];
    const T* max = &c[0];
    for (int i = 1; i < nbCercle; ++i) {
        if (c[i] < *min)
            min = &c[i];
        if (c[i] > *max)
            max = &c[i];
    }
    cout << "Cercle avec le plus petit rayon: \n" << *min
         << "Cercle avec le plus grand rayon: \n" << *max;
}

// Declaration d'une fonction patron partitionner
template <class T>
int partitionner(T c[], int debut, int fin) {
    int g = debut, d = fin;
    T valPivot = c[debut];

    do {
        while (g <= d && c[g] <= valPivot)
            g++;
        while (c[d] > valPivot)
            d--;
        if (g < d)
            permuter(c[g], c[d]);
    } while (g < d);
    permuter(c[d], c[debut]);
    return d;
}

// Definition d'une fonction triRapide.
template <class T>
void triRapide(T c[], int gauche, int droite) {
    if (droite > gauche) {
        int indPivot = partitionner(c, gauche, droite);
        triRapide(c, gauche, indPivot - 1);
        triRapide(c, indPivot + 1, droite);
    }
}

void afficherCercles(Cercle c[], int taille) {
    for (int i = 0; i < taille; i++)
    {
        cout << c[i];
    }
}



// Main function.
int main() {
    Cercle c[] = { Cercle(6.2), Cercle(), Cercle(9.3), Cercle(6.9), Cercle(4.1), Cercle(12.6), Cercle(8.4) };
    int nbCercle = sizeof(c) / sizeof(Cercle);

    cout << "Array initiale :\n";
    afficherCercles(c, nbCercle);

    // 2. Permutation des elements.
    permuter(c[0], c[4]);
    permuter(c[1], c[3]);

    cout << "\nArray apres permutation :\n";
    afficherCercles(c, nbCercle);

    // 4. Tri rapide de l'array.
    triRapide(c, 0, nbCercle - 1);

    cout << "\nArray apres tri :\n";
    afficherCercles(c, nbCercle);

    // 3. Trouver et afficher les extremums.
    cout << "\nExtremums :\n";
    trouverEtAfficherExtremums(c, nbCercle);

    return 0;
}




/*


Execution:

Array initiale :
Rayon:   6.20, Perimetre:    38.96, Surface:   120.76
Rayon:   5.70, Perimetre:    35.81, Surface:   102.07
Rayon:   9.30, Perimetre:    58.43, Surface:   271.72
Rayon:   6.90, Perimetre:    43.35, Surface:   149.57
Rayon:   4.10, Perimetre:    25.76, Surface:    52.81
Rayon:  12.60, Perimetre:    79.17, Surface:   498.76
Rayon:   8.40, Perimetre:    52.78, Surface:   221.67

Array apres permutation :
Rayon:   4.10, Perimetre:    25.76, Surface:    52.81
Rayon:   6.90, Perimetre:    43.35, Surface:   149.57
Rayon:   9.30, Perimetre:    58.43, Surface:   271.72
Rayon:   5.70, Perimetre:    35.81, Surface:   102.07
Rayon:   6.20, Perimetre:    38.96, Surface:   120.76
Rayon:  12.60, Perimetre:    79.17, Surface:   498.76
Rayon:   8.40, Perimetre:    52.78, Surface:   221.67

Array apres tri :
Rayon:   4.10, Perimetre:    25.76, Surface:    52.81
Rayon:   5.70, Perimetre:    35.81, Surface:   102.07
Rayon:   6.20, Perimetre:    38.96, Surface:   120.76
Rayon:   6.90, Perimetre:    43.35, Surface:   149.57
Rayon:   8.40, Perimetre:    52.78, Surface:   221.67
Rayon:   9.30, Perimetre:    58.43, Surface:   271.72
Rayon:  12.60, Perimetre:    79.17, Surface:   498.76

Extremums :
Cercle avec le plus petit rayon: 
Rayon:   4.10, Perimetre:    25.76, Surface:    52.81
Cercle avec le plus grand rayon: 
Rayon:  12.60, Perimetre:    79.17, Surface:   498.76


*/
