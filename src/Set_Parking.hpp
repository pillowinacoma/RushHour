#ifndef SETPARKING_HPP
#define SETPARKING_HPP

#include <iostream>
#include <set>
#include <queue>
#include "Parking.hpp"


class SetParking{
	public:
	SetParking();
	queue<Parking> Q;
	set<Parking> noeud;
	void CrerFils(Parking& p);
	void RemplirSet();
};


#endif
