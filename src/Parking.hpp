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

class Parking {
	public:
	vector<voiture> voitures;
	sortie out;
	Parking();
	void Afficher();
	void retournerligne();
	~Parking();
	int valeur;
};

#endif
