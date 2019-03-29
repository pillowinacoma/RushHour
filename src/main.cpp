#include "Set_Parking.hpp"

#include <iostream>
#include <cassert>

using namespace std;

int main() {
	Parking p ;
	/*p.Afficher();
	p.situation_de_jeu();
	Parking r;
	r.Afficher();
	cout<<" "<<endl<<"avant l'apllication des changement "<<endl<<endl;
	r.deplacer(p.positions[0],p.situations[0].d);
	cout<<" "<<endl<<" apllication des changement "<<endl<<endl;
	r.Afficher();	
	cout<<"les differentes situaton qu'on peut faire a partire du nouveau tableau "<<endl<<endl;
	r.situation_de_jeu();
	Parking m =r;
	cout<<endl<<"le tableau apres afectation de r "<<endl<<endl;
	m.Afficher();
	m.situation_de_jeu();*/
	SetParking s=SetParking();
	//cout<<s.noeud.size()<<endl;
	s.CrerFils(p);
	cout<<"c'est fini "<<endl;
	cout<<"la taille de la set "<<s.noeud.size()<<endl;
	cout<<"la taille de la file "<<s.Q.size()<<endl;
	return 0;
}
