#include "Set_Parking.hpp"

#include <iostream>
#include <cassert>

using namespace std;

int main() {
	Parking p ;
	p.Afficher();
	SetParking s;
	//cout<<s.noeud.size()<<endl;
	s.CrerFils(s.p);
	//int res = s.noeud.size() + 1;
	//int res=s.noeud.size();
	cout<<s.noeud.size()<<endl;
	return 0;
}
