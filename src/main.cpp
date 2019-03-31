#include "Set_Parking.hpp"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
	Parking p ;
	p.Afficher();
	/*p.situation_de_jeu();
	Parking r;
	r.Afficher();
	cout<<" "<<endl<<"avant l'apllication des changement "<<endl<<endl;
	r.deplacer(p.positions[0],p.situations[0].d);
	cout<<" "<<endl<<" apllication des changement "<<endl<<endl;
	r.Afficher();	
	r.deplacer(p.positions[0],p.situations[0].d);
	r.Afficher();	
	cout<<"les differentes situaton qu'on peut faire a partire du nouveau tableau "<<endl<<endl;
	r.situation_de_jeu();
	r.deplacer(p.positions[0],p.situations[0].d);
	r.Afficher();
	cout<<"les deplacement que je peux faire "<<endl<<endl;
	r.situation_de_jeu();
	r.deplacer(r.positions[1],r.situations[1].d);
	r.Afficher();
	cout<<"j'essaye de faire encore reculer le 4"<<endl;
	r.situation_de_jeu();
	r.deplacer(r.positions[1],r.situations[1].d);
	r.Afficher();	
	cout<<"j'essaye de faire deplacer la voiture 11 "<<endl<<endl;
	r.situation_de_jeu();
	r.deplacer(r.positions[3],r.situations[3].d);
	r.Afficher();	
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
