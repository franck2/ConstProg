#ifndef DEF_RECHERCHELOCALE
#define DEF_RECHERCHELOCALE

#include <iostream>
#include <list>
#include <set>
#include "Noeud.hpp"
#include "Solv.hpp"
#include "Problem.hpp"
#include "Constraint.hpp"


/*
*Implemente un algorithme qui permet de trouver une solution a partir d'un assignement initial
*/
class RechercheLocale : public Solveur{

public: 
	RechercheLocale(bool assignement, unsigned short int x, std::vector<Constraint*> contraintes);
	//resoud le probleme et retourne le nombre de mouvement
	int solve();
	//verifie si une dame est en conflit avec au moins une autre, retourne succes ou echec
	Proof constr(Noeud n, int pos);
	//cree un assignement initial reflechi
	void initial_domains1(unsigned short int taille);
	//cree un assignement initial non reflechi
	void initial_domains2(unsigned short int taille);

private:
	Noeud noeuds;
	Problem problem;

};

#endif
