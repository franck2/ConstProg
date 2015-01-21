#include "Nqueen.hpp"

using namespace std;

Nqueen::Nqueen(){

}

Proof Nqueen::test(Noeud noeud){
	return memeColonne(noeud);
}

Proof Nqueen::memeColonne(Noeud noeud){
	set<int> temp;
	Proof p=succes;
	for(int i = 0; i<noeud.getDomains().size(); i++){
		std::set<int>::iterator it;
		if((noeud.getDomains())[i].size()==1){
			it=temp.find(*((noeud.getDomains())[i].begin()));
			if(it == (noeud.getDomains())[i].end()){
				cout<<"pas trouve"<<endl;
			}
		}
		else{
			p=indefini;
		}

	}
	return p;
}
