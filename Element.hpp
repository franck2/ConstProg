#ifndef DEF_ELEMENT
#define DEF_ELEMENT

#include <iostream>
#include <set>
#include "Noeud.hpp"

class Element{

public:
	Element(Noeud n, Element *suiv);
	void toString();
private:
	Noeud noeud;
	Element *suivant;
};

#endif
