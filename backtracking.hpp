#ifndef DEF_BACKTRACKING
#define DEF_BACKTRACKING

#include <iostream>
#include <set>
#include <vector>
#include "Noeud.hpp"

class Backtracking{

public:
	Backtracking();
	int solve();
	void branch(Noeud noeud);

};

#endif
