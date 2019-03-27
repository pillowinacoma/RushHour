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
	SetParking(Parking p1);
	queue<Parking> Q;
	set<Parking> noeud;
	void CrerFils(Parking p);
	void RemplirSet();
	void afficherSet();
};


#endif
