#include "Parking.hpp"

#include <iostream>
#include <cassert>

using namespace std;

int main() {
	Parking p = Parking();
	p.Afficher();	
	p.situation_de_jeu();
	p.Afficher();	
	for(unsigned int i = 0 ;i<p.situations.size();i++){
		cout<<"ligne : "<<p.situations[i].v.ligne<<" colonne : "<<p.situations[i].v.colonne<<" direction : "<<p.situations[i].d<<endl;
	}
	return 0;
}
