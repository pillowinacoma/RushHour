#include "Set_Parking.hpp"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
	Parking p ;
	p.Afficher();
	SetParking s=SetParking();
	Parking res = s.CrerFils(p);
	res.Afficher();
	res.chemin_effectuer();
	p.Afficher();
	cout<<"c'est fini "<<endl;
	cout<<"la taille de la set "<<s.noeud.size()<<endl;
	cout<<"la taille de la file "<<s.Q.size()<<endl;
	return 0;
}