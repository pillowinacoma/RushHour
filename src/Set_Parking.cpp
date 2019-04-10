#include "Set_Parking.hpp"
//constructeur 
SetParking::SetParking(){
	p=Parking();
}


//la fct qui resolve le jeu a 14 coup
Parking SetParking::Solve1(Parking p){
	Parking r;
	//j'insere le p dans ma set 
	noeud.insert(p);
	//je l'insere dans ma file
	Q.push(p);
	//tant que la file n'est pas vide et que j'ai tjr pas gagne le jeu je reboucle
	while( (!Q.empty()) && ( Q.front().gagner() == false)  ){
		//je reprend le premier element de la file et je le met dans un parking temporaire
		Parking q = Q.front();	
		//je pop le premier element de ma file
		Q.pop();
		//je cree ici tout les deplacment possible dans mon parking et je remplie mon tableau de movement  
		q.displacement();
		//je parcours mon tableau de mouvement possible
		for(unsigned int i = 0;i<q.moves.size();i++){
			//je cree un nouveau parking qui prend 
			Parking p1=q;
			//je vide mes deux tableau de mouvement possible pour qu'il herite pas le meme
			p1.positions.clear();
			p1.moves.clear();
			//pour chaque deplacment on effectuer k fois le deplacement sur la map
			for(int k=0;k<q.moves[i].nbr;k++){
				p1.deplacer(q.positions[i],q.moves[i].d);
			}
			//j'ajoute ce deplacement a la liste de deplamcent deja effectuer pour pouvoir garder une trace
			deplacement_effectuer l={q.positions[i]+1,q.moves[i].nbr,q.moves[i].d};
			p1.tab_deplacments.push_back(l);			
			//j'insere le nouveau parking dans ma set
			auto ret=noeud.insert(p1);
			//d'apres la valeur de retour de l'insertion dans la set sois si 
			//il existe deja dans ma set je l'insere pas dans ma file
			//si il n'y est pas je le push dans ma file
			if(ret.second==true){ 
				p1.valeur++;
				Q.push(p1);
			}
		}
	}
	if(Q.front().gagner() == true){
		r=Q.front();
	}
	return r;
}

//fait exactement le meme travail que la fct creefils mais avec plus de pas 32
//elle utilise un tableau qui contient tout les deplacement possible a 1 coup
Parking SetParking::Solve2(Parking p){
	noeud.insert(p);
	Parking res;
	Q.push(p);
	while( (!Q.empty()) && ( Q.front().gagner() == false) ){
		Parking q = Q.front();
		Q.pop();
		q.situation_de_jeu();
		for(unsigned int i = 0;i<q.situations.size();i++){
			Parking p1=q;
			p1.positions.clear();
			p1.situations.clear();
			p1.deplacer(q.positions[i],q.situations[i].d);
			auto ret=noeud.insert(p1);
			if(ret.second==true){
				p1.valeur++;
				Q.push(p1);
			}
		}
	}
	if(Q.front().gagner() == true){
		res=Q.front();
	}
	return res;
}


//je prend mon etat finale et j'essaye d'arriver au parking le plus compliqué que je peux crée
Parking SetParking::level_generator(Parking p){
	diff.insert(p);
	Parking res;
	int test = 0;
	Qu.push(p);
	while( (!Qu.empty()) /*&& (test<2)*/ ) {
		Parking q = Qu.front();
		//q.Afficher();
		if(Qu.size()==1){res=Qu.front();}
		Qu.pop();
		q.displacement();
		/*for(unsigned int zz=0;zz<q.moves.size();zz++){
			cout<<"le vehicule numero "<<q.positions[zz]+1<<"peut ce deplacer : "<<q.moves[zz].nbr<<" fois vers : "<<q.moves[zz].d<<endl;
		}*/
		for(unsigned int i = 0;i<q.moves.size();i++){
			Parking p1=q;
			p1.positions.clear();
			p1.moves.clear();
			for(int k=0;k<q.moves[i].nbr;k++){
				p1.deplacer(q.positions[i],q.moves[i].d);
			}
			//j'ajoute ce deplacement a la liste de deplamcent deja effectuer pour pouvoir garder une trace
			deplacement_effectuer l={q.positions[i]+1,q.moves[i].nbr,q.moves[i].d};
			p1.tab_deplacments.push_back(l);
			auto ret=diff.insert(p1);
			if(ret.second==true){
				p1.valeur++;
				Qu.push(p1);
			}
		}
		test++;
	}
	return res;
}