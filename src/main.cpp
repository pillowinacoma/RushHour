#include "Set_Parking.hpp"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
	Parking p ;
	p.Afficher();
	SetParking s=SetParking();
	Parking res = s.CrerFils(p);
	cout<<" les mouvements effectuer pour arriver au dernier parking : "<<endl;
	for(unsigned int k = 0 ; k < res.m.size() ; k++){
		cout<<" la voiture : "<<res.m[k].indice<<" se deplace "<<res.m[k].nbr<<" vers la direction : "<<res.m[k].d<<endl;
	}
	res.Afficher();
	p.Afficher();
	cout<<"c'est fini "<<endl;
	cout<<"la taille de la set "<<s.noeud.size()<<endl;
	cout<<"la taille de la file "<<s.Q.size()<<endl;
	return 0;
}
