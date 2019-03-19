#include "Set_Parking.hpp"

#include <iostream>
#include <cassert>

using namespace std;

int main() {
	/*Parking p ;
	p.Afficher();
	p.situation_de_jeu();
	cout<<endl;
	for(unsigned int i = 0 ;i<p.situations.size();i++){
		cout<<"ligne : "<<p.situations[i].v.ligne<<" colonne : "<<p.situations[i].v.colonne<<" direction : "<<p.situations[i].d<<endl;
		cout<<"la voiture "<<p.positions[i]<<" peut se deplacer "<<endl;
	}*/
	set<Parking>::iterator it1;
	SetParking s;
	/*for (it1 = s.noeud.begin(); it1!=s.noeud.end();  ++it1){
		*it1.p;
	}*/
	*s.noeud.begin().Afficher();
	return 0;
}
