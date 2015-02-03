#include "Backtracking.hpp"

#include "Proof.hpp"

Backtracking::Backtracking(int x, std::vector<Constraint*> contraintes):problem(x,contraintes) {
}

int Backtracking::solve() {

    return solveRec(problem.initialNode());
}

int Backtracking::solveRec(Noeud noeud, int nbSol) {

    Proof p = problem.testSat(noeud);
    if (p == succes) {

        nbSol++;

        std::cout << "Solution numero " << nbSol << " :" << std::endl;
        noeud.toString();

        return nbSol;
    }
    else if (p == echec) {

        return nbSol;

    }

    std::vector<Noeud> subNode(branch(noeud));

    for (auto n: subNode) {
        nbSol = solveRec(n, nbSol);
    }

    return nbSol;

}

std::vector<Noeud> Backtracking::branch(Noeud noeud) {

    std::vector<Noeud> newNoeuds;

    int i=0;
    bool trouve = false;


    while(i < noeud.getDomains().size() && !trouve){
        if(noeud.getDomains().at(i).size() > 1){
            std::set<int> domain = noeud.getDomains().at(i);
            for (std::set<int>::iterator it = domain.begin(); it != domain.end(); it++){
                Noeud n;
                n = noeud.copie();
                n.clear_and_add(i, *it);

                newNoeuds.push_back(n);
                trouve = true;
            }
        }
        i++;
    }

    return newNoeuds;
}

