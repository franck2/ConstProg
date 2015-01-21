#ifndef DEF_NQUEENDIAGO
#define DEF_NQUEENDIAGO

#include <iostream>
#include "Constraint.hpp"
#include "Proof.hpp"
#include <set>

class Nqueen_diago: public Constraint{

public:
	//teste la contrainte
	Nqueen_diago();
	Proof test(Noeud noeud);
};

#endif
