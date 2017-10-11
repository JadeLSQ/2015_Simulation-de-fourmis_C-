#include <iostream>
#include "simulation.hpp"


using namespace std;

int nbIteration=300;

    int main(){
    ensFourmis lesFourmis;
    ensCoord leSucre, leNid;
    grille g;


initialiserEmplacements(lesFourmis,leSucre,leNid);

initialiserGrille(leNid,leSucre,lesFourmis,g);

dessinerGrille(g);

for (int i=0; i<nbIteration; i++){

     mettreAJourEnsFourmis(g,lesFourmis);
    diminuerPheroSucreGrille(g);
    dessinerGrille(g);
}
return 0;
}



