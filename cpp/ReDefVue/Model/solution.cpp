#include"Solution.h"

/*Solution::Solution(int k, vector<int> tab)
{
    nbCouleurs = k;
    leTableau = tab;
}

int Solution::calculerCout()
{
    int i, j, l, leCout, coutPartiel;
    vector<SommetColore> voisins;
    SommetColore s;

    l = leTableau.size();
    leCout = 0;
    for(i=0; i<l; i++)
    {
        coutPartiel = 0;
        s = listeSommets[i];
        voisins = s.obtenirListeAdj();
        for(j=0; j<voisins.size(); j++)
            if(leTableau[i] == leTableau[voisins[j].getNumero()])
                coutPartiel++;
        leCout += coutPartiel;
    }
    return leCout;
}

// Pour generer aléatoirement des Solutions "proches", on ne modifie que les Sommets dont la coloration n'est pas admissible. Cette fonction doit les reperer et les retourner dans un Vector
vector<Sommet> Solution::calculerSommetsModifiables()
{

}

// Cette fonction generera aleatoirement des Solutions "proches" de s
Solution Solution::genererSolVoisine(vector<Sommet> sommetsModifiables)
{

}

// Pour verifier qu'une Solution soit presente ou non dans une file (queue) de Solutions T
bool Solution::appartientA(queue<Solution> T)
{

}*/
