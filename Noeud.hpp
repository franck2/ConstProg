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
	void setDomains(std::vector<std::set<int> > domains);
	void clear_and_add(int pos, int val);
	void supprimer(int pos, int val);

private:
	std::vector<std::set<int> > domains;
};

#endif
