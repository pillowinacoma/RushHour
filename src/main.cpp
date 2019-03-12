#include "Parking.hpp"

#include <iostream>
#include <cassert>

using namespace std;

int main() {
	Parking p = Parking();
	/*p.deplacement(4,avant);
	p.deplacement(4,arriere);
	p.deplacement(7,avant);
	p.deplacement(7,avant);
	p.deplacement(7,arriere);*/
	//cout<<typeid(p.voitures[4]).name()<<endl;
	p.situation_de_jeu();
	//cout<<p.situations[0].v.ligne<<endl;
	for(int unsigned i=0;i<p.situations.size();i++){
		cout<<p.situations[i].nb_avance<<p.situations[i].nb_recule<<endl;
	}
	return 0;
}
