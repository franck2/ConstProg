#ifndef DEF_NQUEENDIAGO
#define DEF_NQUEENDIAGO

#include <iostream>
#include "Constraint.hpp"
#include "Proof.hpp"
#include <set>

/*
*Implemente la contrainte: pas plus d'une dame par diagonale
*/
class Nqueen_diago: public Constraint{

public:

	Nqueen_diago();
	Proof test(Noeud noeud);
};

#endif
