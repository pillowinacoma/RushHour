#include "Set_Parking.hpp"

SetParking::SetParking(){
	p=Parking();
}

void SetParking::CrerFils(Parking p){
	noeud.insert(p);
	Q.push(p);
	int res=0;
	//cout<<"la valeur de la sortie x: "<<p.out.x<<" la valeur de y : "<<p.out.y<<endl;
	while( (!Q.empty()) && ( Q.front().gagner() == false) /*&& (res<2)*/ ){
		cout<<" verifier la valeur du premier test "<<
		(Q.front().voitures[0].colonne+p.voitures[0].longueur-1 == p.out.y)<<endl;
		cout<<"c'est rentrer dans la boucle "<<endl;
		Parking q = Q.front();
		cout<<"je recupere mon parking "<<endl;	
		Q.pop();
		q.Afficher();
		cout<<" les differentes situations de jeu que j'ai "<<endl;
		q.situation_de_jeu();
		for(unsigned int i = 0;i<q.situations.size();i++){
			//cout<<"c'est rentrer dans la boucle for "<<endl;
			Parking p1=q;
			//cout<<"creation de mon parking "<<endl;
			p1.Afficher();
			p1.deplacer(q.positions[i],q.situations[i].d);
			p1.Afficher();
			//if(<)
			//cout<<"j'applique les deplacement sur le noueau parking crée "<<endl;
			//noeud.insert(p1));			
			auto ret=noeud.insert(p1);
			//cout<<"j'insere mon parking dans la set et je retourne un iterateur"<<endl;
			if(ret.second==true){ 
				cout<<"ca push "<<endl;
				Q.push(p1);
			}else{cout<<"ca ne la pas push dans ma queue "<<endl;}
			//cout<<"j'ai résussi a push dans ma queue "<<endl;
	}
	res+=1;
	//cout<<"c'est sortie de ma for "<<endl;
	cout<<" le res est de "<<res<<endl;	
	}
}



