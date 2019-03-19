#include "Set_Parking.hpp"

SetParking::SetParking(){
	std::cout<<"c'est dans le constructeur "<<std::endl;
	Parking p;
	noeud.insert(p);
	p.Afficher();
	p.situation_de_jeu();
	for(unsigned int i = 0;i<p.situations.size();i++){
		Parking p1=p;
		p1.deplacer(p.positions[i],p.situations[i].d);
		noeud.insert(p1);
	}
	std::cout<<"c'est sortie du constructeur "<<std::endl;
}
