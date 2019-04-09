#include "Set_Parking.hpp"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
	Parking p ;
	p.Afficher();
	/*p.displacement();
	p.Afficher();
	Parking r = p;
	cout<<endl<<endl;
	cout<<"creation de r "<<endl<<endl;
	r.Afficher();
	//cout<<" le num du vehicule deplacer "<<p.positions[0]<<endl;
	//cout<<" la direction dans laquelle je deplace "<<p.moves[0].d<<endl;
	//cout<<" le nbr de fois que je dois effectuer ce deplacement "<<p.moves[0].nbr<<endl;
	for(int j=0;j<p.moves[0].nbr;j++){
		r.deplacer(p.positions[0],p.moves[0].d);
	}
	cout<<" deplacement appliquer sur r "<<endl<<endl;	
	r.Afficher();
	r.moves.clear();
	r.positions.clear();
	r.displacement();
	//cout<<endl;
	r.Afficher();
	for(unsigned int i = 0;i<p.voitures.size()-1;i++){
		p.moving_forward(i);
	}
	for(unsigned int j = 0;j < p.moves.size() ; j++){
		cout<<"le vehicule numero : "<<p.positions[j]<<" peut : "<<p.moves[j].d<<" de "<<p.moves[j].nbr<<" coup "<<endl;
	}*/
	//p.movements();
	//p.displacement();
	//p.Afficher();	
	/*p.deplacer(p.positions[0],p.situations[0].d);
	p.Afficher();
	p.reset_table();
	p.Afficher();*/	
	/*Parking r;
	r.Afficher();
	cout<<" "<<endl<<"avant l'apllication des changement "<<endl<<endl;
	m.situation_de_jeu();*/
	SetParking s=SetParking();
	//cout<<s.noeud.size()<<endl;
	s.CrerFils(p);
	cout<<"c'est fini "<<endl;
	cout<<"la taille de la set "<<s.noeud.size()<<endl;
	cout<<"la taille de la file "<<s.Q.size()<<endl;
	return 0;
}
