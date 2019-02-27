#ifndef PARKING_HPP
#define PARKING_HPP
#include <list>
#include <fstream>
#include <iostream>

using namespace std;

typedef struct {
	int  ligne, colonne, longueur, position ;
}voiture;

typedef struct {
	int x , y ;
}sortie;

class Parking {
	public:
	list <voiture> voitures;
	sortie fstline;
	Parking();
	void Afficher();
	~Parking();
	int valeur;
};

#endif
