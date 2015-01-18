#include "Element.hpp"

using namespace std;

Element::Element(Noeud n, Element *suiv){
	noeud = n;
	suivant = suiv;
}

void Element::toString(){
	noeud.toString();
}
