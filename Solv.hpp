#ifndef DEF_SOLVEUR
#define DEF_SOLVEUR

#include <iostream>
#include <list>
#include "Noeud.hpp"
#include "Problem.hpp"

/*
*Interface pour tous les algorithmes
*/
class Solveur{

public:
	//resoud le probleme et retourne le nombre de solutions
	virtual int solve() = 0;

};

#endif

