#include "Set_Parking.hpp"

SetParking::SetParking(){
	Parking p;
	noeud.insert(p);
	p.Afficher();
	//CrerFils(p);
}

void SetParking::CrerFils(Parking& p){	
	if(p.voitures[0].colonne+p.voitures[0].longueur-1 != p.out.y){	
		p.situation_de_jeu();
		for(unsigned int i = 0;i<p.situations.size();i++){
			Parking p1;
			p1.valeur=i;
			p1.deplacer(p.positions[i],p.situations[i].d);
			Q.push(p1);
		}
		while(!Q.empty()){
			if( noeud.find(Q.front()) == noeud.end() ){
				noeud.insert(Q.front());
				Parking q = Q.front();
				Q.pop();
				CrerFils(q);
			}
			else {Q.pop();}
		}
	}
}

void SetParking::RemplirSet(){
	Parking p;
	Q.push(p);
	if(noeud.find(p) == noeud.end()){noeud.insert(p);}
	Q.pop();
	CrerFils(p);
}

//static void 
