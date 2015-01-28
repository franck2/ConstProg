#include <iostream>
#include "Noeud.hpp"
#include <list>
#include "backtrackingNonRec.hpp"
#include "Constraint.hpp"
#include "Nqueen_colonne.hpp"
#include "Nqueen_diago.hpp"
#include "BranchAndPrune.hpp"
#include "Solv.hpp"

using namespace std;

int main(int argc, char *argv[]){

	bool arreter = false;

	while(!arreter){
		int choix = 0;

		cout<<"Quel algo voulez vous utiliser ?"<<endl;
		cout<<"0- Arreter"<<endl;
		cout<<"1- backtrackin non recursif"<<endl;
		cout<<"2- branch and prune non recursif"<<endl;

		cin>>choix;
		if(choix > 0 && choix < 3){
			int nb_dame = 0;
			
			cout<<"Combien de dames utiliser ?"<<endl;
			cin>>nb_dame;

			if(nb_dame>=0){
				std::vector<Constraint*> contraintes;
				Solveur *solv;
				if(choix == 1){
					Nqueen_colonne contrainte_colonne;
					Nqueen_diago contrainte_diago;
					contraintes.push_back(&contrainte_colonne);
					contraintes.push_back(&contrainte_diago);
					solv = new BacktrackingNonRec(nb_dame, contraintes);
				}
				else if(choix == 2){
					Nqueen_diago contrainte_diago;
					contraintes.push_back(&contrainte_diago);
					solv = new BranchAndPrune(nb_dame, contraintes);
				}

				int nb_sol = solv->solve();
				cout<<"il y a "<<nb_sol<<" solutions"<<endl;
			}	
			else{
				cout<<"Ca ne va pas être possible, recommencer !"<<endl;
			}
		}
		else if(choix == 0){
			arreter = true;
		}
		else{
			cout<<"Ce choix n'existe pas !"<<endl;
		}
	}
	return 0;
}
