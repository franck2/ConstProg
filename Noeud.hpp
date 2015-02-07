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
	void toString2();
	std::vector<std::set<int> > getDomains();
	void setDomains(std::vector<std::set<int> > domains);
	void clear_and_add(int pos, int val);
	void supprimer(int pos, int val);
	int get(int pos);
	void set(int val);
	int taille(); 
	void move(int i); 


private:
	std::vector<std::set<int> > domains;
};

#endif
