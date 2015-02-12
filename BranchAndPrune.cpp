#include "BranchAndPrune.hpp"

#include <set>
#include "Proof.hpp"

BranchAndPrune::BranchAndPrune(unsigned short int x, std::vector<Constraint*> contraintes):problem(x,contraintes) {
}

int BranchAndPrune::solve() {

    return solveRec(problem.initialNode());
}

int BranchAndPrune::solveRec(Noeud noeud) {

    Proof p = problem.testSat(noeud);
    if (p == succes) {

        std::cout << "Solution :" << std::endl;
        noeud.toString();

        return 1;
    }
    else if (p == echec) {

        return 0;

    }

    std::vector<Noeud> subNode(branch(noeud));
    int nbSol = 0;
#pragma omp parallel for
    for(auto it = subNode.begin(); it < subNode.end(); it++) {
//    for (auto n: subNode) {
        nbSol += solveRec(*it);
    }

    return nbSol;

}

std::vector<Noeud> BranchAndPrune::branch(Noeud noeud) {

    std::vector<Noeud> newNoeuds;

    int i = 0;
    bool trouve = false;


    while(i < noeud.getDomains().size() && !trouve){
        if(noeud.getDomains().at(i).size() > 1){
            std::set<unsigned short int> domain = noeud.getDomains().at(i);

            for (std::set<unsigned short int>::iterator it = domain.begin(); it != domain.end(); it++){
                Noeud n;
                n = noeud.copie();
                prune(*it, &n);
                n.clear_and_add(i, *it);
                newNoeuds.push_back(n);
                trouve = true;
            }
        }
        i++;
    }

    return newNoeuds;
}

void BranchAndPrune::prune(unsigned short int val, Noeud *n) {
    for (int i = 0; i < n->getDomains().size(); ++i) {
        n->supprimer(i, val);
    }
}

