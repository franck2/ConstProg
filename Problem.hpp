#ifndef DEF_PROBLEM
#define DEF_PROBLEM

#include <iostream>
#include <vector>
#include "Noeud.hpp"
#include "Constraint.hpp"
#include "Proof.hpp"


class Problem{

public:
	Problem();
	Problem(int x, std::vector<Constraint*> cst);
	Noeud initialNode();
	Proof testSat(Noeud node);

private:
	int n;
	//en c++ les class abstraites (interfaces en java) ne peuvent pas etre mis
	//en template dans un vector, sauf si c'est en pointeur 
	std::vector<Constraint*> constraints;
};

#endif
