#ifndef DEF_BRANCHANDPRUNE
#define DEF_BRANCHANDPRUNE

#include <iostream>
#include <list>
#include "Noeud.hpp"
#include "Solv.hpp"
#include "Problem.hpp"
#include "Constraint.hpp"

class BranchAndPrune : public Solveur{

public:
	BranchAndPrune(int x, std::vector<Constraint*> contraintes);
	//resoud le probleme et retourne le nombre de solutions
	int solve();
	//cre le sous-noeud d'un noeud
	void branch(Noeud noeud);
	void supprimer(int val,Noeud *n);

private:
	std::list<Noeud> noeuds;
	Problem problem;

};

#endif
