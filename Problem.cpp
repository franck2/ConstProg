#include "Problem.hpp"
#include "Nqueen_colonne.hpp"
using namespace std;

Problem::Problem(){
}
 
Problem::Problem(int x, vector<Constraint*> cst){
	n = x;
	constraints = cst;
}

Noeud Problem::initialNode(){
	return Noeud(n);
}

Proof Problem::testSat(Noeud node){
	Proof resultat = succes;
	int i = 0;
	while(i < constraints.size() && resultat == succes){

		if(resultat == succes){
			resultat = constraints[i]->test(node);
		}
		i++;
	}
	return resultat;
}
