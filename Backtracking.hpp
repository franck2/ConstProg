#ifndef DEF_BACKTRACKING
#define DEF_BACKTRACKING

#include <iostream>
#include <set>
#include <vector>
#include "Noeud.hpp"
#include "Solv.hpp"
#include "Constraint.hpp"

class Backtracking : public Solveur {

public:
	Backtracking(unsigned short int x, std::vector<Constraint*> contraintes);
	int solve();
    std::vector<Noeud> branch(Noeud noeud);

private:

    int solveRec(Noeud noeud);

    Problem problem;

};

#endif

