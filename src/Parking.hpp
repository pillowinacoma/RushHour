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
	friend bool operator< (const Parking& a,const Parking& b){
	return ( (a.voitures[0].ligne <= b.voitures[0].ligne) && (a.voitures[0].colonne <= b.voitures[0].colonne) ) ;
	}
	//bool EstPlusPtitQue(Parking const& b);
	~Parking();
};

//bool operator< (Parking const& a,Parking const& b);

#endif
