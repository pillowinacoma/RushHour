#ifndef PARKING_HPP
#define PARKING_HPP
#include <list>
#include <vector>
#include <fstream>
#include <iostream>

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

enum deplace { avant , arriere};

class Parking {
	public:
	vector<voiture> voitures;
	sortie out;	
	int grille[6][6] = {{0}};
	Parking();
	void Afficher();
	void deplacement(int numvehicule,deplace d);
	void deplacer(int numvehicule,deplace);
	void retournerligne();
	~Parking();
};

#endif
