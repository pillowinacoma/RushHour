#include "Set_Parking.hpp"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
	Parking p ;

	//affichage du parking
	cout<<"<------------ afichage de mon parking initiale ------------->"<<endl<<endl;
	p.Afficher();
	cout<<endl;
	//affiche les different deplacment a 1 coup possible
	cout<<"  les different situations de jeu possible a 1 coup : "<<endl<<endl; 
	p.situation_de_jeu();

	//essayer de deplacer le vehicule d'apres les coups possible
	cout<<"<----------- affichage apres avoire effectuer un deplacement--------->"<<endl<<endl;
	p.deplacer(p.positions[0],p.situations[0].d);

	//j'affiche le terain apres deplacment
	p.Afficher();
	cout<<endl<<"<-----------je test si des voiture peuvent avancer ou reculer----------->"<<endl<<endl;
	//je test si des voitures peuvent avancer ou reculer 
	//ici dans la fct peut avancer je lui passe 3 en parametre car mon tableau de voiture commence a 0
	cout<<endl<<" on test si la voiture 4 peut avancer , ca renvoie : "<<((p.peut_avancer(3)== 0)?" non il peut pas":" oui il peut ")<<endl<<endl;
	cout<<endl<<" on test si la voiture 4 peut reculer , ca renvoie : "<<((p.peut_reculer(3)== 0)?" non il peut pas":" oui il peut ")<<endl<<endl;

	cout<<"<----------------je test si j'ai gagner---------------->"<<endl<<endl;
	cout<<" est ce que j'ai gagner ? "<<((p.gagner()== 0)?"non pas encore":"u won")<<endl<<endl;

	//j'affiche tout les deplamcent possible a plusieurs coup
	cout<<"<----------------------les differentes situations de jeu a plusieurs coups ---------------->"<<endl<<endl;
	Parking p1;
	p1.Afficher();
	cout<<endl;
	p1.displacement();
	cout<<endl<<endl;
	cout<<"<-----------------creation de ma set------------------>"<<endl<<endl;
	SetParking s=SetParking();
	//je resoue mon jeu et je renvoie le parking finale 
	Parking res = s.Solve1(p1);
	cout<<"<-------------j'affiche mon parking final--------------->"<<endl<<endl;
	res.Afficher();
	cout<<"ce parking a éte résolue en : "<<res.valeur<<" coups "<<endl<<endl;
	cout<<"<-------------j'affiche les coups effectuer pour arriver au dernier etat--------------->"<<endl<<endl;
	res.chemin_effectuer();

	cout<<endl<<"<------------------generateur de niveau------------------->"<<endl<<endl;
	res.valeur=0;	
	p1=s.level_generator(res);
	cout<<"le shema le plus difficile a été trouver avec : "<<p1.valeur<<" coups "<<endl<<endl;
	//affichage du parking le plus compliqué 
	cout<<" le shema le plus compliqué que je peux obtenir a partir de ma solution"<<endl<<endl;
	p1.Afficher();
	return 0;
}