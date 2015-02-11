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
	//deux methodes d'affichage
	void toString();
	void toString2();
	std::vector<std::set<int> > getDomains();
	void setDomains(std::vector<std::set<int> > domains);
	//supprime les elements d'un ensemble a la position i pour y placer la valeur val
	void clear_and_add(int pos, int val);
	//supprime une valeur dans un ensemble a la position i
	void supprimer(int pos, int val);
	//retourne la taille de domains
	int taille(); 
	//decale l'ensemble de la position i a la position (i+1) modulo la taille de domains
	void move(int i); 


private:
	//la position dans le vetor definie une ligne dans le probleme du N-Queen, le set defini toutes colonnes possibles pour une ligne
	std::vector<std::set<int> > domains;
};

#endif
