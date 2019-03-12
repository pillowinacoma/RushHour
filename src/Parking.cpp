#include "Parking.hpp"

#include <iostream>
using namespace std;
#include <stdlib.h>

Parking::Parking(){
	string s;
	string fstline;
	ifstream fichier("/home/chaoui/Bureau/L3/Lifap6/RushHour/Sujet/puzzle.txt",ios::in);
	getline(fichier,fstline);
	out={fstline[0]-'0',fstline[1]-'0'};
	while(getline(fichier,s)){
		voiture v={s[0]-'0',s[1]-'0',s[2]-'0',s[3]-'0'};
		voitures.push_back(v);
	}


}


void Parking::retournerligne(){
	string fstline;
	string s,s1;
	ifstream fichier("/home/chaoui/Bureau/L3/Lifap6/RushHour/src/ff.txt");
	if(fichier){cout<<"le fichier a été lu avec succes"<<endl;}
	else{cout<<"ca a merder"<<endl;}
	getline(fichier,fstline);
	getline(fichier,s);
	getline(fichier,s1);
	voiture v(fstline[0],fstline[1],fstline[2],fstline[3]);
	v.ligne=fstline[0];
	v.colonne=fstline[1];
	v.longueur=fstline[2];
	v.position=fstline[3];
	cout<<fstline[0]<<fstline[1]<<fstline[2]<<fstline[3];
	cout<<" "<<v.ligne<<" "<<v.colonne<<" "<<v.longueur<<" "<<v.position<<endl;
	voitures.push_back(v);
}


void Parking::Afficher(){
	for(unsigned int i = 0 ; i < voitures.size()-1 ; i++){
		if(voitures[i].position == 0){//vertical
			for(int j = 0 ; j < voitures[i].longueur ; j++){
				grille[voitures[i].ligne+j][voitures[i].colonne] = i+1;
			}
		}
		else if(voitures[i].position == 1){//horizental
			for(int j = 0 ; j < voitures[i].longueur ; j++){
				grille[voitures[i].ligne][voitures[i].colonne+j] = i+1;
			}
		}
	}

	for(int i = 0 ; i < 6 ; i++){
		for(int j = 0 ; j < 6 ; j++){
			cout<<grille[i][j]<<' ';
		}std::cout << endl;
	}
}

void Parking::deplacer(int numvehicule,deplace d){
	if(voitures[numvehicule].position == 0){//vertical
		if(d == avant && 
		grille[voitures[numvehicule].ligne+voitures[numvehicule].longueur][voitures[numvehicule].colonne] == 0){
			grille[voitures[numvehicule].ligne][voitures[numvehicule].colonne]=0;
			voitures[numvehicule].ligne++;
		}
		if(d == arriere && 
		grille[voitures[numvehicule].ligne-1][voitures[numvehicule].colonne] == 0){
		grille[voitures[numvehicule].ligne+voitures[numvehicule].longueur-1][voitures[numvehicule].colonne]=0;			
			voitures[numvehicule].ligne--;
		}
	}	
	else if(voitures[numvehicule].position == 1){//horizentale
		if(d == avant && 
		grille[voitures[numvehicule].ligne][voitures[numvehicule].colonne+voitures[numvehicule].longueur+1] == 0){
			grille[voitures[numvehicule].ligne][voitures[numvehicule].colonne]=0;
			voitures[numvehicule].colonne++;
		}
		if(d == arriere && 
		grille[voitures[numvehicule].ligne][voitures[numvehicule].colonne-1] == 0){
			voitures[numvehicule].colonne--;			
			grille[voitures[numvehicule].ligne][voitures[numvehicule].colonne+voitures[numvehicule].longueur]=0;
		}
	}
}

bool Parking::peut_avancer(int numvehicule){
	bool flag;	
	if(voitures[numvehicule].position == 0){//vertical
		if(grille[voitures[numvehicule].ligne+voitures[numvehicule].longueur][voitures[numvehicule].colonne] == 0){
			flag=true;
		}
		else flag=false; 
	}
	if(voitures[numvehicule].position == 1){//horizentale
		if(grille[voitures[numvehicule].ligne][voitures[numvehicule].colonne+voitures[numvehicule].longueur+1] == 0){
			flag=true;
		}
		else flag=false;
	}
	return flag;
}

bool Parking::peut_reculer(int numvehicule){
	bool flag;
	if(voitures[numvehicule].position == 0){//vertical
		if(grille[voitures[numvehicule].ligne-1][voitures[numvehicule].colonne] == 0){
			flag=true;
		}
		else flag=false;
	}
	if(voitures[numvehicule].position == 1){//horizentale
		if(grille[voitures[numvehicule].ligne][voitures[numvehicule].colonne-1] == 0){
			flag=true;
		}
		else flag=false;
	}
	return flag;
}


void Parking::situation_de_jeu(){
	for(unsigned int i=0;i<voitures.size()-1;i++){
		int nb_avance=0;
		int nb_recule=0;
		//cout<<"cest avant le premier while"<<endl;
		while(peut_avancer(i)){
			//cout<<"cest dans le premier while"<<endl;
			deplacer(i,avant);
			nb_avance++;
		}
		while(peut_reculer(i)){
			//cout<<"cest dans le deusieme while"<<endl;
			deplacer(i,arriere);
			nb_recule++;
		}
		situation s = {voitures[i],nb_avance,nb_recule};
		situations.push_back(s);
	}
}


void Parking::deplacement(int numvehicule,deplace d){
	Afficher();
	deplacer(numvehicule,d);
	Afficher();
}

Parking::~Parking(){}
