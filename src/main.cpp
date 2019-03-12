#include "Parking.hpp"

#include <iostream>
#include <cassert>

using namespace std;

int main() {
	Parking p = Parking();
	p.deplacement(4,avant);
	p.deplacement(4,arriere);
	p.deplacement(7,avant);
	p.deplacement(7,avant);
	p.deplacement(7,arriere);
	if(p.peut_avancer(0)){cout<<"cest faux"<<endl;}
	else{cout<<"ca marche "<<p.peut_avancer(0)<<endl;}
	if(p.peut_reculer(7)){cout<<"cest faux"<<p.peut_reculer(7)<<endl;}
	else{cout<<"ca marche "<<p.peut_reculer(7)<<endl;}
	return 0;
}
