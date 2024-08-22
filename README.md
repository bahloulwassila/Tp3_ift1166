# Tp3_ift1166
Numéro A (10 points) : Surcharge d’opérateurs, fonction template, etc.

Vous pouvez démarrer ce numéro A à partir du 4 mars, exemple utile pour ce numéro A : Opera.cpp sur StudiUM.

Vous disposez du fichier TP3_NumA_H24.cpp sur StudiUM. Réalisez les tâches décrites dans les premiers commentaires du programme.

Numéro B (15 points) : Liste FIFO

Vous pouvez démarrer le numéro B, après avoir étudié les éléments ci-dessous :
-	Notion de structure, pointeur vers le type structure ;
-	Notion de liste chaînée dans l’ordre FIFO programmée en utilisant des pointeurs ;
-	Les exemples : Tab_Bis_Pers.cpp + met_h24.txt
                       Liste_Pers.cpp + imp_h24.txt
-	Les vidéos et les exemples sur la liste chaînée.
  
On dispose du fichier texte nommé : met_h24.txt qui contient au maximum 30 lignes.
Chaque ligne contient les informations d’une seule personne dans le système métrique :
Nom et prénom, sexe, taille en mètre, poids en kg et son numéro.

ROY CHANTAL                           F      1.75           57.9        2754
MOLAISON CLAUDINE             F      1.57           62.2        1848
ROBITAILLE CHANTALE         F      1.79           72.3         2007
BEDARD MARC-ANDRE          M      1.43          55.5         2636
MONAST STEPHANE                M      1.65          61.7         1750
Etc.

Le programme Tab_Bis_Pers.cpp permet de lire le fichier met_h24.txt, de mémoriser les informations lues dans un tableau des personnes, etc.

Écrivez un programme permettant de réaliser les tâches dans l’ordre ci-dessous :

a)	Lire le fichier met_h24.txt, créer une liste chaînée programmée, des personnes en utilisant des pointeurs dans l’ordre FIFO. (5 points)
b)	Compter et afficher le nombre de personnes présentes dans la liste. (2 points)
c)	Afficher les 9 premières personnes de la liste. (2 points)
d)	Afficher toutes les personnes nommées, Robitaille Suzanne, de la liste. (3 points)
e)	Supprimer la personne, Michaud Normand, puis réafficher les 7 premières personnes de la liste. (3 points)


Numéro C (15 points) : list<T>

Étudiez d’abord les vidéos et les exemples sur le conteneur list. Fixez-vous comme objectif de finaliser le numéro C vers le 12 avril, pour préparer la remise.

Refaites le numéro B en utilisant un conteneur list<Personne>.

Bonne fin de session et bonnes vacances d’été !
Équipe du IFT 1166, Hiver 2024


/* Fichier TP3_NumA_H24.cpp
    
    À compléter pour le numéro A du TP #3, Hiver 2024 (10 points)

    Tâches à faire :
	  1. Afficher le tableau des cercles en utilisant, entre
	     autres, la surcharge de l'opérateur d'affichage <<

	  2. Permuter ces éléments : c[0] et c[4] , c[1] et c[3]
	     Réafficher le tableau après ces deux permutations.

	  3. Déterminer et afficher :
	       a) Le cercle ayant le plus petit rayon ;
		   b) Le cercle ayant le plus grand rayon.
		En utilisant, entre autres :
		  - Une seule fonction template ;
		  - La surcharge des opérateurs > et <

      4. Trier le tableau des cercles par le tri rapide, puis
	     réafficher ce tableau après le tri.

	Critères de correction :
	   Tâche 1. 2 points          
	   Tâche 2. 2 points          
	   Tâche 3. 3 points          
	   Tâche 4. 3 points
*/   

#include <iostream>
#include <iomanip>

using namespace std;

const float PI = 3.14159;
class Cercle
{   private :
		float rayon ; // l'accès au champ rayon est privé
		
     public :
// un constructeur : conflit entre nom de paramètre et nom de                                // champ => on utilise le pointeur this où *this est l'objet courant	 
	    Cercle(float rayon = 5.7)	
	    {
	    	this->rayon = rayon ;// c'est même chose que                                                                                     
                                                      // (*this).rayon;
		}		
		
		// fonction membre
		float perimetre()
		{
			return 2 * PI * rayon;
		}
		
		// fonction membre : définition reportée
		float surface();
		



		// afficher un cercle avec un message pertinent
		void afficher(string message = "")
		{
		  if(message.length() > 0)
		  {		  
			cout << message << " : " << endl;
			cout << " - rayon                 : " << rayon << endl;
			cout << " - perimetre             : " << perimetre() 
                                   << endl;

			cout << " - surface               : " << surface() 
                                  << endl << endl;
		   }
		   else 
		     cout << setw(8) << setprecision(1) << rayon
		          << setw(10) << setprecision(2) << perimetre()
		          << setw(9) << setprecision(2) << surface() << endl;		    
		}
		
		float getRayon(); // définition reportée
		void setRayon(float nouvRayon);
};

float Cercle::surface()
{
	return PI * rayon * rayon;
}
  
float Cercle::getRayon()
{
	return rayon;
}


void Cercle::setRayon(float nouvRayon)
{
    rayon = nouvRayon;	
}
 
int main()
{
  
  Cercle c[] = { Cercle(6.2), Cercle(), Cercle(9.3), Cercle (6.9),
                 Cercle(4.1), Cercle(12.6), Cercle(8.4) };
  int nbCercle = sizeof(c) / sizeof(Cercle); 
    
  return 0;
}
/* Exécution :
*/
