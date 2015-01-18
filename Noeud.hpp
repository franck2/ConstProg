#ifndef DEF_NOEUD
#define DEF_NOEUD

#include <iostream>
#include <set>
#include <vector>


class Noeud{

public:
	Noeud();
	Noeud(int val);
	void toString();

private:
	std::vector<std::set<int> > domains;
};

#endif
