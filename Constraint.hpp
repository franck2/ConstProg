#ifndef DEF_CONSTRAINT
#define DEF_CONSTRAINT

#include <iostream>
#include "Noeud.hpp"
#include "Proof.hpp"

/*
*Interface servant a implementer des contraintes
*/
class Constraint{

public:
	//teste la contrainte
	virtual Proof test(Noeud noeud) = 0;

};

#endif
