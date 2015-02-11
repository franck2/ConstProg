#ifndef DEF_BRANCHANDPRUNE_NON_REC
#define DEF_BRANCHANDPRUNE_NON_REC

#include <iostream>
#include <list>
#include "Noeud.hpp"
#include "Solv.hpp"
#include "Problem.hpp"
#include "Constraint.hpp"

class BranchAndPruneNonRec : public Solveur{

public:
	BranchAndPruneNonRec(int x, std::vector<Constraint*> contraintes);
	//resoud le probleme et retourne le nombre de solutions
	int solve();
	//cre le sous-noeud d'un noeud
	void branch(Noeud noeud);
	//supprime une valeur dans tous les ensembles du noeud
	void supprimer(int val,Noeud *n);

private:
	std::list<Noeud> noeuds;
	Problem problem;

};

#endif

