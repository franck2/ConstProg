#include "Noeud.hpp"

using namespace std;

Noeud::Noeud(){
}

Noeud::Noeud(int val){
	set<int> domain;
	for(int i = 1; i<=val; i++){
		domain.insert(i);
	}
	for(int i=0; i<val; i++){
		domains.push_back(domain);
	}
}

void Noeud::toString(){
	set<int>::iterator it;
	for(int j=0; j<domains.size(); j++){
		cout<<"Domain "<<j+1<<": ";
		for(it = domains.at(j).begin(); it!=domains.at(j).end(); ++it){
			cout<<*it;
		}
		cout<<endl;
	}
}

