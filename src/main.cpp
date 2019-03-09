#include "Parking.hpp"

#include <iostream>
#include <cassert>

using namespace std;

int main() {

	Parking p;
	//p.retournerligne();
	for(unsigned int i=0 ; i < p.voitures.size();i++){
		cout<<p.voitures[i].ligne<<p.voitures[i].colonne<<p.voitures[i].longueur<<p.voitures[i].position<<endl;
	}
	cout<<"  "<<p.voitures[0].ligne<<" "<<p.voitures[0].colonne<<" "<<p.voitures[0].longueur<<" "<<p.voitures[0].position<<endl;
	voiture v={1,2,3,4};
	cout<<v.ligne<<endl;	
	cout<<"ta un main "<<endl;	
	return 0 ;
}
