#include "Noeud.hpp"

using namespace std;

Noeud::Noeud(){

}


Noeud::Noeud(int val){
	std::set<int> domain;
	for(int i = 1; i <= val; i++){
		domain.insert(i);
	}
	for(int i=0; i<val; i++){
		domains.push_back(domain);
	}
}

void Noeud::toString(){
	std::set<int>::iterator it;
	for(int j = 0; j < domains.size(); j++){
		cout<<"Domain "<<j+1<<": ";
		for(it = domains.at(j).begin(); it != domains.at(j).end(); ++it){
			cout<<*it;
		}
		cout<<endl;
	}
	cout<<endl;
}

void Noeud::toString2(){
	std::set<int>::iterator it;
	for(int j = 0; j < domains.size(); j++){
		for(it = domains.at(j).begin(); it != domains.at(j).end(); ++it){
			cout<<*it<<", ";
		}
	}
	cout<<endl;
}

std::vector<std::set<int> > Noeud::getDomains(){
	return domains;
}


int Noeud::taille(){
	return domains.size();
}


void Noeud::setDomains(std::vector<std::set<int> > new_domains){
	domains = new_domains;
}

Noeud Noeud::copie(){
	Noeud n;
	n.setDomains(domains);
	return n;
}

void Noeud::clear_and_add(int pos, int val){
	domains.at(pos).clear();
	domains.at(pos).insert(val);
}

void Noeud::supprimer(int pos, int val){
	domains.at(pos).erase(val);
}



void Noeud::move(int i){
	std::set<int> temp = domains.at((i+ 1)%domains.size() );
	domains.at((i+ 1)%domains.size() ) = domains.at(i%domains.size());
	domains.at(i%domains.size()) = temp;
} 
