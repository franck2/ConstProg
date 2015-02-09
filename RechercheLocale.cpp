#include "RechercheLocale.hpp"

using namespace std;

RechercheLocale::RechercheLocale(int x, std::vector<Constraint*> contraintes):problem(x,contraintes){
	initial_domains(x);
}
		

void RechercheLocale::initial_domains(int x){

	std::set<int> valeure_ok;
	std::vector<std::set<int> > domains;
	
	//initialisation
	std::set<int> temp1;
	temp1.insert(1);
	domains.push_back(temp1);
	//position du tableau ou l'on veut ajouter une valeur (cette position n'existe pas encore)
	int j=0;
	valeure_ok.insert(1);
	bool fini = false;

	while(!fini){
		if(domains.size() == x){
			fini = true;
		}
		else{
			bool trouve = false;
			int i = 1;
			while(!trouve && i <= x){

				if(valeure_ok.find(i) == valeure_ok.end()){
					if(i != *domains.at(j).begin()+1 && i != *domains.at(j).begin()-1){
						valeure_ok.insert(i);
						std::set<int> temp;
						temp.insert(i);
						domains.push_back(temp);
						j++;
						trouve = true;
					}
				}
				i++;				
			}
			 
			if(!trouve){
				int val = *domains.at(j).begin() + 1; 
				j--;
				valeure_ok.erase(val-1);
				domains.pop_back();
				bool continuer = true;

				while(continuer){
					while(val > x && j>-1){
						val = *domains.at(j).begin() + 1;
						j--;
						valeure_ok.erase(val-1);
						domains.pop_back();
					}
					if(j<0 && val>x){
						continuer = false;
						fini = true;
					}
					else if(valeure_ok.find(val) == valeure_ok.end()){
						if(j==-1 || (val != (*domains.at(j).begin()+1) && val != (*domains.at(j).begin() - 1))){
						std::set<int> temp;
						temp.insert(val);
						valeure_ok.insert(val);
							domains.push_back(temp);
							continuer = false;
						j++;
						}
						else{
							val++;
						}
					}
					else{
						val++;
					}
				}
			}
		}
	}
	noeuds.setDomains(domains);

}


int RechercheLocale::solve(){

	int i = 0;
	int cpt=0;
	if(noeuds.taille()>0){
		bool fini = false;
		while(!fini){
			bool machin = true;
			int j = i; 

			while(machin){

				Proof p = constr(noeuds, i);
				if(p==echec){
					noeuds.move(i);
					cpt++;
					cout<<cpt<<endl;
				}
			
				i = (i+1)%noeuds.taille();
				if(i == j){
					machin = false;
					i = (i+1)%noeuds.taille();
				}
			}

			Proof p = problem.testSat(noeuds);
			if(p == succes){
				fini=true;
			}
		}
		cout<<"\n\nSolution trouvée: \n\n";
		noeuds.toString();
	}
	else{
		cout<<"\n\nIl n'y a pas de solution"<<endl;
	}
	return cpt;
}

Proof RechercheLocale::constr(Noeud n, int pos){
	std::vector<std::set<int> > domains = n.getDomains();
	Proof resultat = succes;
	for(int i = 0; i<pos; i++){
		if(*domains.at(i).begin()+(pos-i) == *domains.at(pos).begin() || *domains.at(i).begin()-(pos-i) == *domains.at(pos).begin()){
			resultat = echec;
		}
	}
	for(int i = pos+1; i<n.taille(); i++){
		if(*domains.at(pos).begin()+(i-pos) == *domains.at(i).begin() || *domains.at(pos).begin()-(i-pos) == *domains.at(i).begin()){
			resultat = echec;
		}
	}

	return resultat;

}
