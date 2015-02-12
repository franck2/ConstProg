#ifndef DEF_BACKTRACKINGNONREC
#define DEF_BACKTRACKINGNONREC

#include <iostream>
#include <list>
#include "Noeud.hpp"
#include "Solv.hpp"
#include "Problem.hpp"
#include "Constraint.hpp"

/*
* Cette classe implémente l'algorithme de backtracking de facon non recursive.
* Le but l'algorithme est de trouver le nombre de solution au problème du N-Queen.
*/
class BacktrackingNonRec : public Solveur{

public:
	BacktrackingNonRec(unsigned short int nombre_dames, std::vector<Constraint*> contraintes);
	//resoud le probleme et retourne le nombre de solutions
	int solve();
	//cre le sous-noeud d'un noeud
	void branch(Noeud noeud);

private:
	std::list<Noeud> noeuds;
	Problem problem;

};

#endif
