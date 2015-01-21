#ifndef DEF_NQUEEN
#define DEF_NQUEEN

#include <iostream>
#include "Constraint.hpp"
#include "Proof.hpp"
#include <set>

class Nqueen: public Constraint{

public:
	//teste la contrainte
	Nqueen();
	Proof test(Noeud noeud);
	Proof memeColonne(Noeud noeud);
};

#endif
