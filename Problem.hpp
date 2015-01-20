#ifndef DEF_PROBLEM
#define DEF_PROBLEM

#include <iostream>
#include <vector>
enum Proof {echec, succes, indefini};
class Problem{

public:
	Problem();
	Problem(int x, std::vector<Constraint> cst);
	Noeud initialNode();
	Proof testSat(Noeud node);

private:
	int n;
	std::vector<Constraint> constraints;
};

#endif
