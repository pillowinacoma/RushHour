#include "Parking.hpp"

#include <iostream>
using namespace std;
#include <stdlib.h>

Parking::Parking(){
	string s;
	string fstline;
	ifstream fichier("/home/chaoui/Bureau/L3/Lifap6/RushHour/Sujet/puzzle.txt",ios::in);
	getline(fichier,fstline);
	cout<<"la valuer de la premiere ligne"<<fstline<<endl;
	int i = 0;
	while(getline(fichier,s)){
		cout<<"la valeur de la ligne en cour :"<<s<<endl;
		/*voiture v={s[0],s[1],s[2],s[3]};
		cout<<v.ligne<<" "<<s[0]<<endl;
		cout<<v.colonne<<" "<<s[1]<<endl;
		cout<<v.longueur<<" "<<s[2]<<endl;
		cout<<v.position<<" "<<s[3]<<endl;
		//voitures[i].ligne=s[0];
		//voitures[i].colonne=s[1];
		//voitures[i].longueur=s[2];
		//voitures[i].position=s[3];
		voitures.push_back({s[0],s[1],s[2],s[3]});*/
		i++;
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
	/*string res;
	int ** grille = new int[6][6];
	for(unsigned int i = 0 ; i < voitures.size() ; i++){
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
	res += "********\0";*/
}

Parking::~Parking(){}