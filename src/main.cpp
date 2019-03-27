#include "Set_Parking.hpp"

#include <iostream>
#include <cassert>

using namespace std;

int main() {
	Parking p ;
	p.Afficher();
	voiture a = {0,0,0,0};
	voiture b = {1,1,1,1};
	if(a>b){cout<<"le comparateur plus ptite marche pour la voiture "<<endl;}
	else{cout<<"bon bah faudra revoire le comparateur "<<endl;}
	if(b>a){cout<<"le comparateur plus grand marche pour la voiture "<<endl;}
	else{cout<<"bon bah faudra revoire le comparateur "<<endl;}
	SetParking s=SetParking();
	//cout<<s.noeud.size()<<endl;
	s.CrerFils(p);
	cout<<"c'est fini "<<endl;
	cout<<"la taille de la set"<<s.noeud.size()<<endl;
	cout<<"la taille de la file "<<s.Q.size()<<endl;
	return 0;
}
