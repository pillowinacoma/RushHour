#include "Parking.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

Parking::Parking(){
	string s;
	valeur=0;
	string fstline;
	ifstream fichier("../Sujet/puzzle.txt",ios::in);
	getline(fichier,fstline);
	//creation de ma sortie	
	out={fstline[0]-'0',fstline[1]-'0'};
	//creation de mon tableau de voitures	
	while(getline(fichier,s)){
		voiture v={s[0]-'0',s[1]-'0',s[2]-'0',s[3]-'0'};
		voitures.push_back(v);
	}
	//initialisation de ma grille
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
}

	
bool Parking::gagner(){
	if(voitures[0].colonne+voitures[0].longueur-1 == out.y){
		return true;
	}
	return false;
}

void Parking::met_a_jour_la_grille(){
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
}

void Parking::Afficher(){
	met_a_jour_la_grille();
	unsigned int digiSize = voitures.size()/10;
	for(int i = 0 ; i < 6 ; i++){
		for(int j = 0 ; j < 6 ; j++){
				cout<<"  "<<grille[i][j]<<string(digiSize - to_string(grille[i][j]).length()+1,' ');
		}std::cout << endl;
	}
	std::cout << endl;
}

void Parking::deplacer(int numvehicule,deplace d){
	if(voitures[numvehicule].position == 0){//vertical
		if(d == avant && peut_avancer(numvehicule)){
			grille[voitures[numvehicule].ligne][voitures[numvehicule].colonne]=0;
			voitures[numvehicule].ligne++;
		}
		if(d == arriere && peut_reculer(numvehicule)){
		grille[voitures[numvehicule].ligne+voitures[numvehicule].longueur-1][voitures[numvehicule].colonne]=0;
			voitures[numvehicule].ligne--;
		}
	}
	else if(voitures[numvehicule].position == 1){//horizentale
		if(d == avant && peut_avancer(numvehicule)){
			grille[voitures[numvehicule].ligne][voitures[numvehicule].colonne]=0;
			voitures[numvehicule].colonne++;
		}
		if(d == arriere && peut_reculer(numvehicule)){
			grille[voitures[numvehicule].ligne][voitures[numvehicule].colonne+voitures[numvehicule].longueur-1]=0;
			voitures[numvehicule].colonne--;
		}
	}
}

bool Parking::peut_avancer(int numvehicule){
	bool flag;
	if(voitures[numvehicule].position == 0){//vertical
		if(( voitures[numvehicule].ligne+voitures[numvehicule].longueur+1 <= 6 ) 
			&& grille[voitures[numvehicule].ligne+voitures[numvehicule].longueur][voitures[numvehicule].colonne] == 0 ){
			flag=true;
		}
		else flag=false;
	}
	if(voitures[numvehicule].position == 1){//horizentale
		if((voitures[numvehicule].colonne+voitures[numvehicule].longueur+1 <= 6 )&&
			grille[voitures[numvehicule].ligne][voitures[numvehicule].colonne+voitures[numvehicule].longueur] == 0){
			flag=true;
		}
		else flag=false;
	}
	return flag;
}

bool Parking::peut_reculer(int numvehicule){
	bool flag;
	if(voitures[numvehicule].position == 0){//vertical
		if(( voitures[numvehicule].ligne -1 >= 0  )
			&& grille[voitures[numvehicule].ligne-1][voitures[numvehicule].colonne] == 0){
			flag=true;
		}
		else flag=false;
	}
	if(voitures[numvehicule].position == 1){//horizentale
		if(( voitures[numvehicule].colonne -1 >= 0  ) && 
			grille[voitures[numvehicule].ligne][voitures[numvehicule].colonne-1] == 0 ){
			flag=true;
		}
		else flag=false;
	}
	return flag;
}

void Parking::situation_de_jeu(){
	for(unsigned int i=0;i<voitures.size()-1;i++){
		if(peut_avancer(i)){
			cout<<"la voiture "<<i+1<<" peut avancer "<<endl; 
			situation s = {voitures[i],avant};
			situations.push_back(s);
			positions.push_back(i);
		}
		if(peut_reculer(i)){
			cout<<"la voiture "<<i+1<<" peut reculer "<<endl;
			situation s = {voitures[i],arriere};
			situations.push_back(s);
			positions.push_back(i);
		}
	}
	cout<<endl;
}

void Parking::moving_forward(int numvehicule){
	int advance = 0;
	vector<voiture> r=voitures;
	while(peut_avancer(numvehicule)){
		advance++;
		mouvements m = {advance,voitures[numvehicule],avant};
		moves.push_back(m);
		positions.push_back(numvehicule);
		deplacer(numvehicule,avant);
	}
	voitures.clear();
	voitures=r;
	for(int i = 0 ; i<6;i++){
		for(int j = 0 ;j<6;j++){
			grille[i][j]=0;
		}
	}
	met_a_jour_la_grille();
}

void Parking::moving_backward(int numvehicule){
	int retreat = 0;
	vector<voiture> r=voitures;
	while(peut_reculer(numvehicule)){
		retreat++;
		mouvements m = {retreat,voitures[numvehicule],arriere};
		moves.push_back(m);
		positions.push_back(numvehicule);
		deplacer(numvehicule,arriere);
	}
	voitures.clear();
	voitures=r;
	for(int i = 0 ; i<6;i++){
		for(int j = 0 ;j<6;j++){
			grille[i][j]=0;
		}
	}
	met_a_jour_la_grille();
}

void Parking::displacement(){
	vector<voiture> r=voitures;
	for(unsigned int k = 0;k<voitures.size()-1;k++){		
		moving_forward(k);
		moving_backward(k);
	}
	/*for(unsigned int j = 0;j < moves.size() ; j++){
		cout<<"le vehicule numero : "<<positions[j]+1<<" peut : "<<moves[j].d<<" de "<<moves[j].nbr<<" coup "<<endl;
	}*/
}

void Parking::chemin_effectuer(){
	cout<<" les mouvements effectuer pour arriver au dernier parking : "<<endl;
	Parking p;
	for(unsigned int k = 0 ; k < tab_deplacments.size() ; k++){
		cout<<" la voiture : "<<tab_deplacments[k].indice<<" se deplace "<<tab_deplacments[k].nbr<<" vers la direction : "<<((tab_deplacments[k].d == 0)?"avance":"recule")<<endl;
	}
}

Parking::~Parking(){}
