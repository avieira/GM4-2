#ifndef GRAPHECOLORE_H
#define GRAPHECOLORE_H

#include"graphe.h"
#include"sommetcolore.h"
#include"Solution.h"
#include<set>
#include<map>
#include<vector>
#include<stdlib.h>
#include<time.h>

class GrapheColore : public Graphe
{
public:
    GrapheColore();
    ~GrapheColore();
    void setListeSommets(vector<SommetColore*>);
    void ajouterSommet(SommetColore*);
    vector<SommetColore*> getListeSommets();

    vector<SommetColore*> obtenirListeAdj(SommetColore*);

    void colorerDirect();
    void colorerH(int k);

    friend ostream& operator<<( ostream &flux, GrapheColore& graph );

protected:
    vector<SommetColore*> listeSommets;

    int comparerEtiquettes(set<int> L1, set<int> L2);
    vector<int> lexBFS();
    vector<int> inverser(vector<int> ordre);
    void colorerSommets(vector<int>);
};

#endif // GRAPHECOLORE_H
