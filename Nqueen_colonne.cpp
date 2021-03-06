#include "Nqueen_colonne.hpp"

using namespace std;

Nqueen_colonne::Nqueen_colonne(){

}

Proof Nqueen_colonne::test(Noeud noeud){
	std::vector<std::set<unsigned short int> > domains = noeud.getDomains();
	//pour savoir quelles colonnes sont deja utilises dans un noeud
	set<unsigned short int> colonnes_utilises;
	Proof resultat = succes;
	for(int i = 0; i < domains.size(); i++){
		std::set<unsigned short int>::iterator it;

		if(domains.at(i).size() == 1){
			it = colonnes_utilises.find(*domains.at(i).begin());

			if(it == colonnes_utilises.end()){
				colonnes_utilises.insert(*domains.at(i).begin());
			}
			else{
				resultat = echec;
			}
		}
		else if(resultat != echec){
			resultat = indefini;
		}
	}
	return resultat;
}

