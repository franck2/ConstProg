#ifndef DEF_SOLVEUR
#define DEF_SOLVEUR

#include <iostream>
#include <list>
#include "Noeud.hpp"
#include "Problem.hpp"

class Solveur{

public:
	//resoud le probleme et retourne le nombre de solutions
	virtual int solve() = 0;
	//cre le sous-noeud d'un noeud
	//virtual void branch(Noeud noeud) = 0;
};

#endif

