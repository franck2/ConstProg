#ifndef DEF_BRANCHANDPRUNE
#define DEF_BRANCHANDPRUNE

#include <iostream>
#include <vector>
#include "Noeud.hpp"
#include "Solv.hpp"
#include "Constraint.hpp"

class BranchAndPrune : public Solveur {

public:
	BranchAndPrune(int x, std::vector<Constraint*> contraintes);
	int solve();
    std::vector<Noeud> branch(Noeud noeud);

private:

    int solveRec(Noeud noeud);
    void prune(int val, Noeud *n);

    Problem problem;

};

#endif

