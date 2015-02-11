#ifndef DEF_NQUEENCOLONNE
#define DEF_NQUEENCOLONNE

#include <iostream>
#include "Constraint.hpp"
#include "Proof.hpp"
#include <set>

/**
*Classe implementant la contrainte pas plus de une dame par colonne
*/
class Nqueen_colonne: public Constraint{

public:

	Nqueen_colonne();
	Proof test(Noeud noeud);
};

#endif
