#ifndef DEF_SOLVEUR
#define DEF_SOLVEUR

#include <iostream>


class Solveur{

public:
	//resoud le probleme et retourne le nombre de solutions
	virtual int solve();
	//cre le sous-noeud d'un noeud
	virtual void branch(Noeud noeud);

private:
	Element *premier;	

};

#endif
