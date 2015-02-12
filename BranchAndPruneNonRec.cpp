#include "BranchAndPruneNonRec.hpp"

using namespace std;

BranchAndPruneNonRec::BranchAndPruneNonRec(unsigned short int nombre_dames, std::vector<Constraint*> contraintes):problem(nombre_dames,contraintes){
	noeuds.push_front(problem.initialNode());
}

int BranchAndPruneNonRec::solve(){

	//le nombre de solutions au probleme
	int nb_so = 0;

	/*
	*si la liste chainee ne contient plus de noeud, alors il n'y a plus de solution possible
	*/
	while(!noeuds.empty()){
		std::list<Noeud>::iterator list_iter = noeuds.begin();

		/*
		* On verifie pour toute la liste chainee si on a trouve une solution, une non solution ou alors si on doit generer les sous-noeuds.
		*/
		while(list_iter != noeuds.end()){

			std::list<Noeud>::iterator temp = list_iter;

			list_iter++;

			/*
			*On regarde si les contraintes sont respectees:
			*succes pour oui, on incremente le compteur et on supprime le noeud.
			*indefini, si on ne peut rien dire, on genere les sous noeuds et on supprime le noeud.
			*echec sinon, dans ce cas on supprime juste le noeud.
			*/
			Proof p = problem.testSat(*temp);
			if(p == succes){
				nb_so++;
				cout<<"Solution numero: "<<endl;
				temp->toString();
			}
			else if(p == indefini){
				branch(*temp);
			}
			noeuds.erase(temp);
		}
	}
	return nb_so;
}

void BranchAndPruneNonRec::branch(Noeud noeud){

	//sert a acceder aux element du vector dans un noeud
	int i=0;

	//ce booleen sert a savoir quand on a trouve un domaine pour generer les sous noeuds
	bool trouve = false;
	/*
	* On est sur de trouver une position une position pour generer les sous noeuds
	*/
	while(!trouve){
		//si le domaine a la position i a une taille superieure a 1 alors on peut generer les sous noeuds
		if(noeud.getDomains().at(i).size() > 1){
			set<unsigned short int> domain = noeud.getDomains().at(i);
			for (std::set<unsigned short int>::iterator it = domain.begin(); it != domain.end(); it++){
				Noeud n;
				n = noeud.copie();
				//on supprime la valeur choisie dans tous les ensembles
				supprimer(*it, &n);
				n.clear_and_add(i, *it);
				noeuds.push_front(n);
				trouve = true;
			}
		}
		i++;
	}
}

void BranchAndPruneNonRec::supprimer(unsigned short int val,Noeud *n){
	for (int i = 0; i < n->getDomains().size(); i++){
		n->supprimer(i, val);
	}
}

