#include "Set_Parking.hpp"

SetParking::SetParking(){
	p=Parking();
	noeud.insert(p);
	Q.push(p);
}

SetParking::SetParking(Parking p1): p(p1){
}

void SetParking::CrerFils(){
	int res=0;
	while((Q.front().voitures[0].colonne+p.voitures[0].longueur-1 == p.out.y)==false && (res<200) ){
		res+=1;
		//cout<<" verifier la valeur du premier test "<<
		//(Q.front().voitures[0].colonne+p.voitures[0].longueur-1 == p.out.y)<<endl;
		//cout<<"c'est rentrer dans la boucle "<<endl;
		Parking q = Q.front();
		//cout<<"je recupere mon parking "<<endl;	
		Q.pop();
		//cout<<"je pop le premier element de mon parking "<<endl;
		q.situation_de_jeu();
		for(unsigned int i = 0;i<q.situations.size();i++){
			//cout<<"c'est rentrer dans la boucle for "<<endl;
			Parking p1;
			//cout<<"creation de mon parking "<<endl;
			p1.deplacer(q.positions[i],q.situations[i].d);
			//cout<<"j'applique les deplacement sur le noueau parking crée "<<endl;
			auto ret=noeud.insert(p1);
			//cout<<"j'insere mon parking dans la set et je retourne un iterateur"<<endl;
			if(ret.second){ Q.push(p1); }
			//cout<<"j'ai résussi a push dans ma queue "<<endl;
		}
		//cout<<"c'est sortie de ma for "<<endl;
	}
	/*if(p.voitures[0].colonne+p.voitures[0].longueur-1 != p.out.y){
		p.situation_de_jeu();
		for(unsigned int i = 0;i<p.situations.size();i++){
			Parking p1;
			p1.valeur=i;
			p1.deplacer(p.positions[i],p.situations[i].d);
			Q.push(p1);
		}
		while(!Q.empty()){
			if( noeud.find(Q.front()) == noeud.end() ){
				noeud.insert(Q.front());
				Parking q = Q.front();
				Q.pop();
				CrerFils(q);
			}
			else {Q.pop();}
		}
	}*/
}

void SetParking::RemplirSet(){
	Parking p;
	Q.push(p);
	if(noeud.find(p) == noeud.end()){noeud.insert(p);}
	Q.pop();
	CrerFils();
}

void SetParking::afficherSet(){
	
}

