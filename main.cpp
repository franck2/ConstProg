#include <iostream>
#include "Noeud.hpp"
#include <list>
#include "backtrackingNonRec.hpp"
#include "Constraint.hpp"
#include "Nqueen_colonne.hpp"
#include "Nqueen_diago.hpp"
#include "BranchAndPrune.hpp"

using namespace std;

int main(int argc, char *argv[]){

	Nqueen_colonne q;
	Nqueen_diago q2;
	std::vector<Constraint*> tab;
	//tab.push_back(&q);
	tab.push_back(&q2);
	//BacktrackingNonRec b(0, tab);*/
	
	BranchAndPrune bb(10,tab);
	int nb_sol = bb.solve();
	cout<<"il y a "<<nb_sol<<" solutions"<<endl;
	return 0;
}
