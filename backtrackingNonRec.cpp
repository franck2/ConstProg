#include "backtrackingNonRec.hpp"

using namespace std;

BacktrackingNonRec::BacktrackingNonRec(int x, std::vector<Constraint*> c):problem(x,c){
	noeuds.push_front(problem.initialNode());
	

}

int BacktrackingNonRec::solve(){
	int nb_so=0;
	while(!noeuds.empty()){
					int cpt =1;
		std::list<Noeud>::iterator list_iter2 = noeuds.begin();
		while(list_iter2 != noeuds.end()){

			cout<<"noeud : "<<cpt<<endl;

			std::list<Noeud>::iterator temp = list_iter2;

			list_iter2++;

			Proof p = problem.testSat(*temp);

				if(p==succes){
					cout<<"succes"<<endl;
					nb_so++;
					(*temp).toString();
					noeuds.erase(temp);
				}
				else if(p==echec){
					noeuds.erase(temp);
				}
				else{
					branch(*temp);
					noeuds.erase(temp);
				}
			cpt++;

		}
		cout<<"\n\n\n\n\n";
	}
}

void BacktrackingNonRec::branch(Noeud noeud){
	int i=0;
	bool trouve = false;
	while(i<noeud.getDomains().size() && !trouve){
		if(noeud.getDomains().at(i).size()>1){
			set<int> s = noeud.getDomains().at(i);
			for (std::set<int>::iterator it=s.begin(); it!=s.end(); it++){
				Noeud n;
				n= noeud.copie();
				n.clear_and_add(i, *it);
				(n.getDomains())[i].insert(*it);

				noeuds.push_front(n);
				trouve = true;
			}
		}
		i++;
		
	}

}
