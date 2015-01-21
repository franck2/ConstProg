#ifndef DEF_BACKTRACKINGNONREC
#define DEF_BACKTRACKINGNONREC

#include <iostream>
#include <list>
#include "Noeud.hpp"
#include "Solv.hpp"
#include "Problem.hpp"
#include "Constraint.hpp"

class BacktrackingNonRec : public Solveur{

public:
	BacktrackingNonRec(int x, std::vector<Constraint*> c);
	//resoud le probleme et retourne le nombre de solutions
	int solve();
	//cre le sous-noeud d'un noeud
	void branch(Noeud noeud);

private:
	std::list<Noeud> noeuds;
	Problem problem;

};

#endif
