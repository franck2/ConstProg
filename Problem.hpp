#ifndef DEF_PROBLEM
#define DEF_PROBLEM

#include <iostream>
#include <vector>
#include "Noeud.hpp"
#include "Constraint.hpp"
#include "Proof.hpp"

/*
*Classe qui s'occupe de verifier si les contraintes d'un algo sont respectees
*/
class Problem{

public:
	~Problem();
	Problem(unsigned short int x, std::vector<Constraint*> cst);
	Noeud initialNode();
	//verifie si le socntraintes sont respectes
	Proof testSat(Noeud node);

private:
	//le nombre de dammes
	unsigned short int n;
	//les contraintes d'un probleme
	std::vector<Constraint*> constraints;
};

#endif

