#ifndef PROBLEME_H
#define PROBLEME_H

#include <fstream>

#include "carre.h"
#include "formlinr2p1.h"
#include "formbilinr2p1.h"
#include "fonctionsmath.h"

using namespace std;

class Probleme
{
public:
    Carre *geometrie;
    MaillageR2 *maillage;
    float 	*composantesNeum,*composantesDirHom,*secondMembreNeum,*secondMembreDirHom,**matriceRigiditeNeum,**matriceRigiditeDirHom;
    FormBilinR2P1 *a;
    FormLinR2P1 *L;
    int dimensionNeum,dimensionDirHom;

    Probleme(Carre *c,FormBilinR2P1 *fB,FormLinR2P1 *fL);
    void genererMaillage(float h);
    void calculerMatrices();
    void resoudreProbleme();
    void calculerSolutionPoints();
    void afficherSolution();
    void afficherMaillage();
    void afficherMatrices();
};

#endif // PROBLEME_H
