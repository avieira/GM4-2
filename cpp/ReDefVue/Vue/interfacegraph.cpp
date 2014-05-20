#include "interfacegraph.h"

InterfaceGraph::InterfaceGraph()
{
    grapheNormal=Graphe();
    grapheColore=GrapheColore();
    colore=false;

    //Liste des formes actuellement supportées
    listeFormes<<"box"<<"ellipse"<<"circle"<<"square"<<"star"<<"diamond"<<"pentagon"<<"septagon";
}

InterfaceGraph::InterfaceGraph(bool m)
{
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

QString InterfaceGraph::obtenirId(Sommet* som)
{
    return stringForSommet[som];
}

Sommet* InterfaceGraph::obtenirSommet(QString id)
{
    return sommetForString[id];
}

QString InterfaceGraph::obtenirForme(Sommet* som)
{
    return tableForme[som];
}

QTreeWidgetItem* InterfaceGraph::obtenirTreeItem(Sommet* som)
{
    return sommetForItem[som];
}

QDomElement* InterfaceGraph::obtenirDomElmt(Sommet* som)
{
    return sommetForElmt[som];
}

QDomElement* InterfaceGraph::obtenirDomElmt(Arete* arc)
{
    return areteForElmt[arc];
}

QDomElement* InterfaceGraph::obtenirFormDomElmt(Sommet* som)
{
    return formeSommet[som];
}


bool InterfaceGraph::contains(QString id)
{
    return sommetForString.contains(id);
}

bool InterfaceGraph::modifierId(Sommet* sommet, QString nvId)
{
    bool noErreur=false;
    QString ancienid=stringForSommet.take(sommet);
    sommetForString.remove(ancienid);

    if(!(sommetForString.contains(nvId))){
        stringForSommet.insert(sommet,nvId);
        sommetForString.insert(nvId,sommet);
        noErreur=true;
    }
    else{
        stringForSommet.insert(sommet,ancienid);
        sommetForString.insert(ancienid,sommet);
        noErreur=false;
    }

    return noErreur;
}

bool InterfaceGraph::modifierForme(Sommet* sommet, QString nvlleForme)
{
    tableForme[sommet]=nvlleForme;
    return true;
}

bool InterfaceGraph::modifierTreeItem(Sommet* sommet, QTreeWidgetItem* nvlItem)
{
    sommetForItem[sommet]=nvlItem;
    return true;
}

bool InterfaceGraph::modifierElement(Sommet* sommet, QDomElement* nvlElmt)
{
    sommetForElmt[sommet]=nvlElmt;
    return true;
}

bool InterfaceGraph::modifierElement(Arete *arc, QDomElement* nvlElmt)
{
    areteForElmt[arc]=nvlElmt;
}

void InterfaceGraph::insertSommet(Sommet* sommet, QString id, QString forme)
{
    sommetForString.insert(id,sommet);
    stringForSommet.insert(sommet,id);
    tableForme.insert(sommet,forme);
}

void InterfaceGraph::grapheToColore()
{
    int i;
    //Pour commencer : le graph deviendra coloré, donc on y pense de suite !
    colore=true;

    //Un nouveau graphe coloré, un !
    grapheColore=GrapheColore();

    //On construit la liste des sommets. On construit en même temps les nouvelles tables d'association.
    map<Sommet*,SommetColore*> tableSommets;
    QHash<Sommet*, QString> nvStringForSommet;
    QHash<QString, Sommet*> nvSommetForString;
    QHash<Sommet*,QString> nvTableForme;
    Sommet* ancSom;
    SommetColore* nvSom;
    vector<Sommet*> listeG;

    listeG=grapheNormal.getListeSommets();

    for(i=0;i<listeG.size();i++){
        //Ancien et nouveau sommet
        ancSom=listeG[i];
        nvSom=(SommetColore*)ancSom->sommetToColore();
        //Ajout au graphe
        grapheColore.ajouterSommet(nvSom);
        //Ajout aux nouvelles tables de correspondance
        tableSommets[listeG[i]]=nvSom;
        nvStringForSommet.insert(nvSom,stringForSommet[ancSom]);
        nvSommetForString.insert(stringForSommet[ancSom],nvSom);
        nvTableForme.insert(nvSom,tableForme[ancSom]);
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
    }

    //On affecte les nouvelles tables d'association
    /*delete &sommetForString;
    delete &stringForSommet;
    delete &tableForme;*/

    sommetForString=nvSommetForString;
    stringForSommet=nvStringForSommet;
    tableForme=nvTableForme;

    //Pour l'id : on supprime les sommets normaux, histoire de remettre le nombre de sommets comme il faut
    for(i=0;i<listeG.size();i++)
        delete listeG[i];
}
