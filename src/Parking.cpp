#include "Parking.hpp"

#include <iostream>
using namespace std;
#include <stdlib.h>

Parking::Parking(){
	string s;
	ifstream fichier("/home/chaoui/Bureau/L3/Lifap6/RushHour/Sujet/puzzle.txt", ios::in);
	getline(fichier,fstline);
	int i = 0;
	while(getline(fichier,s)){
		voiture v ;
		v.ligne=s[0];
		v.colonne=s[2];
		v.longueur=s[4];
		v.position=s[6];
		voitures.push_back(v);
		i++;
	}

}
 	

Parking::void Afficher(){
	string res;
	int grille [][] = new  int [6][6];
	for(int i = 0 ; i < voitures.size() ; i++){
		if(voitures[i].position == 0){//vertical
			for(int j = 0 ; j < voitures[i].longueur ; j++){
				grille[voitures[i].ligne][voitures[i].colonne+j] = i;
			}
		}
		else if(voitures[i].position == 1){//horizental			
			for(int j = 0 ; j < voitures[i].longueur ; j++){
				grille[voitures[i].ligne+j][voitures[i].colonne] = i;
			}
		}
	}
	res += "********";
	for(int i=0;i < 6;i++){
		for(int j=0;j < 6;j++){
		res+="*";
		if(grille[i][j] != null)
			res += grille[i][j];
		else
			res += " ";
		res+="*\n";
		}
	}
	res += "********\0";
}
