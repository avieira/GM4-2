#include "interfacegraph.h"

InterfaceGraph::InterfaceGraph()
{
    grapheNormal=Graphe();
    grapheColore=GrapheColore();
    colore=false;

    //Liste des formes actuellement supportées
    listeFormes<<"box"<<"ellipse"<<"circle"<<"square"<<"star"<<"diamond"<<"pentagon"<<"septagon";
}

void* InterfaceGraph::getGraph()
{
    if(colore)
        return &grapheColore;
    else
        return &grapheNormal;
}

QStringList InterfaceGraph::getListeForme()
{
    return listeFormes;
}

void InterfaceGraph::setColore(bool coloration)
{
    colore=coloration;
}

bool InterfaceGraph::isColore()
{
    return colore;
}

void InterfaceGraph::grapheToColore()
{
    int i;
    //Pour commencer : le graph deviendra coloré, donc on y pense de suite !
    colore=true;

    //Un nouveau graphe coloré, un !
    grapheColore=GrapheColore();

    //On construit la liste des sommets.
    map<Sommet*,SommetColore*> tableSommets;
    Sommet* ancSom;
    SommetColore* nvSom;
    vector<Sommet*> listeG;

    listeG=grapheNormal.getListeSommets();

    for(i=0;i<listeG.size();i++){
        //Ancien et nouveau sommet
        ancSom=listeG[i];
        nvSom=(SommetColore*)ancSom->sommetToColore();

        nvSom->setNom(ancSom->getNom());

        //Ajout au graphe
        grapheColore.ajouterSommet(nvSom);

        //Table de correspondance entre les sommets
        tableSommets[listeG[i]]=nvSom;

        //Ajout des observeurs au nouveau sommet. Si on le fait avant, tout bug...
        for(std::vector<Observer*>::iterator it=ancSom->listeObserver.begin();it!=ancSom->listeObserver.end();it++){
            nvSom->addObserver(*it);
            (*it)->setSommet(nvSom);
        }

    }

    //On fait la liste d'arêtes
    vector<Arete*> listeA=grapheNormal.getListeArcs();
    SommetColore* nvDepart;
    SommetColore* nvArrivee;
    Arete* nvleArete;
    for(i=0;i<listeA.size();i++){
        //Sommets reliés par l'arc en question
        nvDepart=tableSommets[listeA[i]->getDepart()];
        nvArrivee=tableSommets[listeA[i]->getArrivee()];

        //Ajout au graph
        nvleArete=new Arete(nvDepart,nvArrivee);
        grapheColore.ajouterArc(nvleArete);

        //Ajout des observeurs à la nouvelle arête
        for(std::vector<Observer*>::iterator it=listeA[i]->listeObserver.begin();it!=listeA[i]->listeObserver.end();it++){
            nvleArete->addObserver(*it);
            (*it)->setArete(nvSom);
        }
    }

    //Pour l'id : on supprime les sommets normaux, histoire de remettre le nombre de sommets comme il faut
    for(i=0;i<listeG.size();i++)
        delete listeG[i];
}

void InterfaceGraph::colorerGraphD(){
    if(colore){
        if(grapheColore.getListeSommets().size()>0)
            grapheColore.colorerDirect();
    }else{
            if(grapheNormal.getListeSommets().size()>0){
                grapheToColore();
                grapheColore.colorerDirect();
            }
        }
}

bool InterfaceGraph::colorerGraphH(){
    bool reussi=true;

    if(colore){
        if(grapheColore.getListeSommets().size()>0){
            reussi=grapheColore.colorerH();
        }
    }
    else{
        if(grapheNormal.getListeSommets().size()>0){
            grapheToColore();
            reussi=grapheColore.colorerH();
        }
    }
    return reussi;
}

bool InterfaceGraph::contains(QString id)
{
    Graphe* graphe=(Graphe*) getGraph();
    return graphe->contains(id);
}
