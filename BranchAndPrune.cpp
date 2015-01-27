#include "BranchAndPrune.hpp"

using namespace std;

BranchAndPrune::BranchAndPrune(int x, std::vector<Constraint*> contraintes):problem(x,contraintes){
	noeuds.push_front(problem.initialNode());
}

int BranchAndPrune::solve(){
	int nb_so = 0;
	int cpt = 0;
	while(!noeuds.empty()){
		cout<<noeuds.size()<<endl;
		std::list<Noeud>::iterator list_iter = noeuds.begin();

		while(list_iter != noeuds.end()){

			std::list<Noeud>::iterator temp = list_iter;

			list_iter++;
			Proof p = problem.testSat(*temp);
			if(p == succes){
				nb_so++;
				cout<<"Solution numero "<<nb_so<<": "<<endl;
				(*temp).toString();
				noeuds.erase(temp);
			}
			else if(p == echec){
				noeuds.erase(temp);
			}
			else{
				branch(*temp);
				noeuds.erase(temp);
			}
		}
		cpt++;
	}
	return nb_so;
}

void BranchAndPrune::branch(Noeud noeud){
	int i=0;
	int a_supprimer = 0;
	bool trouve = false;
	while(i < noeud.getDomains().size() && !trouve){
		if(noeud.getDomains().at(i).size() > 1){
			set<int> domain = noeud.getDomains().at(i);
			for (std::set<int>::iterator it = domain.begin(); it != domain.end(); it++){
				Noeud n;
				n = noeud.copie();
				supprimer(*it, &n);
				n.clear_and_add(i, *it);
				noeuds.push_front(n);
				trouve = true;
			}
		}
		i++;	
	}
}

void BranchAndPrune::supprimer(int val,Noeud *n){			
	for (int i = 0; i < n->getDomains().size(); i++){
		n->supprimer(i, val);
	}
}
