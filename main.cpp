#include <iostream>
#include "Noeud.hpp"
#include "Element.hpp"
using namespace std;

int main(int argc, char *argv[]){

	Noeud n(10);
	n.toString();
	cout<<"\n\n\n";
	Element e(n, NULL);
	e.toString();

	return 0;
}
