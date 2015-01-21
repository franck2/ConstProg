#include "backtrackingNonRec.hpp"

using namespace std;

BacktrackingNonRec::BacktrackingNonRec(int x, std::vector<Constraint*> c):problem(x,c){
	noeuds.push_front(problem.initialNode());
	

}

int BacktrackingNonRec::solve(){
	int nb_so=0;
	//while(!noeuds.empty()){

		std::list<Noeud>::iterator list_iter2 = noeuds.begin();
		//while(list_iter2 != noeuds.end()){
			int cpt =1;
			cout<<"noeud : "<<cpt<<endl;
			(*list_iter2).toString();
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
					cout<<"echec"<<endl;
					noeuds.erase(temp);
				}
				else{
					cout<<"indef"<<endl;
					branch(*temp);
					noeuds.erase(temp);
				}
			cpt++;

		//}
	//}
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
				n.getDomains().at(i).clear();
				(n.getDomains())[i].insert(*it);
				cout<<"new  "<<i<<endl;
				n.toString();
				cout<<"\nnew2"<<endl;
				(n.getDomains())[i].insert(*it);

				noeuds.push_front(n);
				trouve = true;
			}
		}
		i++;
		
	}

}
