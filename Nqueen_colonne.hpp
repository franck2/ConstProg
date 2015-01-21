#ifndef DEF_NQUEEN
#define DEF_NQUEEN

#include <iostream>
#include "Constraint.hpp"
#include "Proof.hpp"
#include <set>

class Nqueen_colonne: public Constraint{

public:
	//teste la contrainte
	Nqueen_colonne();
	Proof test(Noeud noeud);
	Proof memeColonne(Noeud noeud);
};

#endif
