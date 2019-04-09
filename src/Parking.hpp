#ifndef PARKING_HPP
#define PARKING_HPP
#include <list>
#include <vector>
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

const int int_x=6;
const int int_y=6;

//ma structure voiture
struct voiture{
	int  ligne;
	int colonne;
	int longueur;
	int position ;
	/**
	*const par copie
	*/
	voiture(int l,int c,int lg,int p):ligne(l),colonne(c),longueur(lg),position(p){}
	//utulisation de struct pour optimiser la memoire
	
	//operateur de comparaison qui compare les situations (parkings) pour ne pas avoir des doublons dans la set
	bool operator < (const voiture& b)const{
		return ( (this->ligne+int_y*this->colonne) < (b.ligne+int_y*b.colonne) );
	}
	bool operator > (const voiture& b)const{
		return ( (this->ligne+int_y*this->colonne) > (b.ligne+int_y*b.colonne) ); 
	}
	bool operator == (const voiture& b)const{
		return ( (this->ligne+int_y*this->colonne) == (b.ligne+int_y*b.colonne) );
	}
};

//une stucture qui contient les cordonne de la sortie
struct sortie{
	int x , y ;
};

//s'approcher de 0 == arriere
//s'eloigner du 0 == avant
enum deplace {avant ,arriere};

//la sturcture qui contient le deplacment que peux faire la voiture ainsi que sa direction sois vers l'avant sois vers l'arriere
//on utilisant cette structure on arrive à trouver une solution qui fait 23 coups
struct situation{
	voiture v;
	deplace d;
};

//mouvements contient le deplacment que peux faire la voiture ainsi que le nombre de fois quelle peut l'effectuer 
//on utilisant cette structure on arrive à trouver une solution qui fait 14 coups
struct mouvements{	
	int nbr;
	voiture v;
	deplace d;
};

struct mm{
	int indice;
	int nbr;
	deplace d;
};

class Parking {
	public:

	//le nombre de coup effectuer pour arriver a l'etat actuelle
	int valeur;
	
	//un tableau qui contient toutes les voitures
	vector<voiture> voitures;

	//un tableau de situation (tous les déplacements que je peux faire sur mon Parking)
	vector<situation> situations;
	vector<int> positions;

	//un tableau qui contient tout les deplacement ainsi que le nombre de fois que je peux les appliquer 
	vector<mouvements> moves;

	//table de coup deja subit
	vector<mm> m;

	//le point de sortie
	sortie out;

	//la grille d'affichage que j'initialise a zero
	int grille[6][6] = {{0}};
	
	Parking();
	
	//affichage de ma grille	
	void Afficher();
	
	//applique un changement sur le tableau de vehicule
	void deplacer(int numvehicule,deplace);

	//verifie si un vehicule peut avancer
	bool peut_avancer(int numvehicule);

	//verifie si un vehicule peut reculer
	bool peut_reculer(int numvehicule);

	//les diferent deplacment que le vehicule peut effectuer a un coup
	void situation_de_jeu();

	//mise a jour de la grille d'affichage 
	void met_a_jour_la_grille();

	//verifie que le premier vehicule a les memes cordonneé que la sortie
	bool gagner();

	//test si une voiture pour avancer a combien de coups et stocke les possibilités dans le tableau moves
	void moving_forward(int numvehicule);
	
	//test si une voiture pour reculer a combien de coups et stocke les possibilités dans le tableau moves
	void moving_backward(int numvehicule);
	
	//trouve tout les deplacement 
	void displacement();	
	
	//operateur pour comparer entre les parking
	bool operator < (const Parking& b) const{
		for(unsigned int i=0;i<this->voitures.size();i++){
			if(this->voitures[i]>b.voitures[i]){
				return false;
			}			
			if(this->voitures[i]<b.voitures[i]) {
				return true;
			}
		} 
		return false;	
	}
	~Parking();
};

#endif
