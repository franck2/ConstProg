#include "Problem.hpp"

using namespace std;

Problem::Problem(){
}

Problem::Problem(int x, vector<Constraint> cst){
	n=x;
	constraints=cst;
}

Noeud Problem::initialNode(){
	return Noeud(n);
}

Proof Problem::testSat(Noeud node){

}
