#include <iostream>
#include "Noeud.hpp"
#include <list>
#include "backtrackingNonRec.hpp"
#include "Constraint.hpp"
#include "Nqueen.hpp"


using namespace std;

int main(int argc, char *argv[]){

	Nqueen q;
	Noeud n(2);
	std::vector<Constraint*> tab;
	tab.push_back(&q);
	BacktrackingNonRec b(3, tab);
	b.solve();

	return 0;
}
