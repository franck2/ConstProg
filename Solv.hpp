#ifndef DEF_SOLVEUR
#define DEF_SOLVEUR

#include <iostream>
#include <list>
#include "Noeud.hpp"
#include "Problem.hpp"

class Solveur{

public:
	//resoud le probleme et retourne le nombre de solutions
	virtual int solve();
	//cre le sous-noeud d'un noeud
	virtual void branch(Noeud noeud);

private:
	std::list<Noeud> noeuds;
	Problem p;

};

#endif
