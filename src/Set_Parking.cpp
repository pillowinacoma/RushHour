#include "Set_Parking.hpp"

SetParking::SetParking(){
	Parking p;
	noeud.insert(p);
	p.Afficher();
	CrerFils(p);
}

void SetParking::CrerFils(Parking& p){	
	p.situation_de_jeu();
	for(unsigned int i = 0;i<p.situations.size();i++){
		Parking p1;
		p1.valeur=i;
		p1.deplacer(p.positions[i],p.situations[i].d);
		noeud.insert(p1);
	}
}

void SetParking::RemplirSet(){
	Parking p;
	Q.push(p);
	if(noeud.find(p) == noeud.end()){noeud.insert(p);}
	Q.pop();
}
