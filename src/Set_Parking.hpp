#ifndef SETPARKING_HPP
#define SETPARKING_HPP

#include <iostream>
#include <set>
#include <queue>
#include "Parking.hpp"


class SetParking{
	public:
	Parking p;

	SetParking();
	
	//la file utilisée pour empiler les nouveau fils crée
	queue<Parking> Q;

	//la structure qui contient tout les parking
	set<Parking> noeud;

	//fct qui resou le rush_hour en 14 coups et renvoie le Parking gagnant 
	Parking CrerFils(Parking p);

	//fct qui resou le rush_hour en 32 coups et renvoie le Parking gagnant 
	Parking CrerFilsGrand(Parking p);
	
};


#endif
