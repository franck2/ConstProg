#ifndef DEF_RECHERCHELOCALE
#define DEF_RECHERCHELOCALE

#include <iostream>
#include <list>
#include <set>
#include "Noeud.hpp"
#include "Solv.hpp"
#include "Problem.hpp"
#include "Constraint.hpp"

class RechercheLocale : public Solveur{

public:
	RechercheLocale(int x, std::vector<Constraint*> contraintes);
	//resoud le probleme et retourne le nombre de solutions
	int solve();
	Proof constr(Noeud n, int pos);
	void initial_domains(int taille);

private:
	Noeud noeuds;
	Problem problem;

};

#endif
