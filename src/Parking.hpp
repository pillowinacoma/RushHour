#ifndef PARKING_HPP
#define PARKING_HPP
#include <list>
#include <vector>
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

struct voiture{
	int  ligne;
	int colonne;
	int longueur;
	int position ;
	voiture(int l,int c,int lg,int p):ligne(l),colonne(c),longueur(lg),position(p){}
	bool operator < (const voiture& b)const{
		return ( (this->ligne < b.ligne) && (this->colonne < b.colonne) ); 
	}
	bool operator > (const voiture& b)const{
		return ( (this->ligne > b.ligne) && (this->colonne > b.colonne)); 
	}
};


struct sortie{
	int x , y ;
};

enum deplace {avant ,arriere};

struct situation{
	voiture v;
	deplace d;
};

class Parking {
	public:
	int valeur;
	vector<voiture> voitures;
	vector<situation> situations;
	vector<int> positions;
	sortie out;
	int grille[6][6] = {{0}};
	Parking();
	void Afficher();
	void deplacement(int numvehicule,deplace d);
	void deplacer(int numvehicule,deplace);
	bool peut_avancer(int numvehicule);
	bool peut_reculer(int numvehicule);
	void situation_de_jeu();
	void retournerligne();
	bool operator < (const Parking& b) const{
		for(unsigned int i=0;i<this->voitures.size();i++){
			if(this->voitures[i]<b.voitures[i]){
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
