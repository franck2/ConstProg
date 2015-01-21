#ifndef DEF_NOEUD
#define DEF_NOEUD

#include <iostream>
#include <set>
#include <vector>


class Noeud{

public:
	Noeud();
	Noeud(int val);
	Noeud copie();
	void toString();
	std::vector<std::set<int> > getDomains();
	void setDomains(std::vector<std::set<int> > d);

private:
	std::vector<std::set<int> > domains;
};

#endif
