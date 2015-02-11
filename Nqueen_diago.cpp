#include "Nqueen_diago.hpp"

using namespace std;

Nqueen_diago::Nqueen_diago(){

}

/**
*On ne regarde que les diagonale "basses" celle qui partent vers le bas de l'echequier, car on parcour le tableau de haut en bas.
*/
Proof Nqueen_diago::test(Noeud noeud){

	std::vector<std::set<int> > domains = noeud.getDomains();
	Proof resultat = succes;
	for(int i = 0; i<domains.size(); i++){
		if(domains.at(i).size() == 1){
			for(int j = i+1; j<domains.size(); j++){
				if(domains.at(j).size() == 1){

					if(*domains.at(i).begin()+(j-i) == *domains.at(j).begin() || *domains.at(i).begin()-(j-i) == *domains.at(j).begin()){
						resultat = echec;
					}
				}
			}
		}
		else if(resultat != echec){
			resultat = indefini;
		}
	}

	return resultat;
}


