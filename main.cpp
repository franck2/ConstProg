#include <iostream>
#include "Noeud.hpp"
#include <list>
#include "Backtracking.hpp"
#include "BacktrackingNonRec.hpp"
#include "Constraint.hpp"
#include "Nqueen_colonne.hpp"
#include "Nqueen_diago.hpp"
#include "BranchAndPrune.hpp"
#include "BranchAndPruneNonRec.hpp"
#include "RechercheLocale.hpp"
#include "Solv.hpp"

#include <chrono>

using namespace std;

int main(int argc, char *argv[]){

    bool arreter = false;

    while(!arreter){
        unsigned short int choix = 0;

        cout<<"Quel algo voulez vous utiliser ?"<<endl;
        cout<<"0- Arreter"<<endl;
        cout<<"1- Backtracking recursif"<<endl;
        cout<<"2- Backtracking non recursif"<<endl;
        cout<<"3- Branch and prune"<<endl;
        cout<<"4- Branch and prune non recursif"<<endl;
        cout<<"5- Recherche locale avec un assignement reflechie"<<endl;
        cout<<"6- Recherche locale avec un assignement non reflechie"<<endl;

        cin>>choix;
        if(choix > 0 && choix <= 6){
            unsigned short int nb_dame = 0;

            cout<<"Combien de dames utiliser ?"<<endl;
            cin>>nb_dame;

            if(nb_dame>=0){
                std::vector<Constraint*> contraintes;
                Solveur *solv;
                if(choix == 1){
                    contraintes.push_back(new Nqueen_colonne);
                    contraintes.push_back(new Nqueen_diago);
                    solv = new Backtracking(nb_dame, contraintes);
                }
                else if(choix == 2){
                    contraintes.push_back(new Nqueen_colonne);
                    contraintes.push_back(new Nqueen_diago);
                    solv = new BacktrackingNonRec(nb_dame, contraintes);
                }
                else if(choix == 3){
                    contraintes.push_back(new Nqueen_diago);
                    solv = new BranchAndPrune(nb_dame, contraintes);
                }
                else if(choix == 4){
                    contraintes.push_back(new Nqueen_diago);
                    solv = new BranchAndPruneNonRec(nb_dame, contraintes);
                }
                else if(choix == 5){
                    contraintes.push_back(new Nqueen_diago);
                    solv = new RechercheLocale(true, nb_dame, contraintes);
                }
                else if(choix == 6){
                    contraintes.push_back(new Nqueen_diago);
                    solv = new RechercheLocale(false, nb_dame, contraintes);
                }


                cout << "Start chrono" << endl;
                auto startTime = chrono::system_clock::now();

                int nb_sol = solv->solve();

                auto duration = chrono::duration_cast<chrono::milliseconds>(
                                                                            chrono::system_clock::now() - startTime);
                cout << "Stop chrono" << endl;

                delete solv;


                if(choix!=5 && choix!=6){
                    cout << "Il y a " << nb_sol << " solutions" << endl << endl << endl;
                }
                else{
                    cout << "La solution a été trouvée en " << nb_sol << " mouvements" << endl << endl << endl;
                }
                cout << "Temps de traitement : " << duration.count() << "ms" << endl;
            }
            else{
                cout<<"Ca ne va pas être possible, recommencer !\n\n"<<endl;
            }
        }
        else if(choix == 0){
            arreter = true;
        }
        else{
            cout<<"Ce choix n'existe pas !\n\n"<<endl;
        }
    }
    return 0;
}

