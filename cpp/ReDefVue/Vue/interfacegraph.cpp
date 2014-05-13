#include "interfacegraph.h"

InterfaceGraph::InterfaceGraph()
{
    /*grapheNormal=Graphe();
    grapheColore=GrapheColore();
    colore=false;

    //Liste des formes actuellement supportées
    listeFormes<<"box"<<"ellipse"<<"circle"<<"square"<<"star"<<"diamond"<<"pentagon"<<"septagon";*/

    colore=true;

    Arete *a;
    SommetColore *s;
    vector<SommetColore*> lSommet;
    vector<Arete*> lArete;
    QString nom;

    for(int i=0;i<22;i++)
    {
        s=new SommetColore(true);
        lSommet.push_back(s);

        nom=QString("id")+QString::number(i);
        stringForSommet.insert(s,nom);
        sommetForString.insert(nom,s);
    }

    a=new Arete(lSommet[0],lSommet[2]);
    lArete.push_back(a);
    a=new Arete(lSommet[0],lSommet[3]);
    lArete.push_back(a);
    a=new Arete(lSommet[0],lSommet[4]);
    lArete.push_back(a);
    a=new Arete(lSommet[0],lSommet[5]);
    lArete.push_back(a);
    a=new Arete(lSommet[0],lSommet[6]);
    lArete.push_back(a);
    a=new Arete(lSommet[0],lSommet[7]);
    lArete.push_back(a);
    a=new Arete(lSommet[0],lSommet[8]);
    lArete.push_back(a);
    a=new Arete(lSommet[0],lSommet[9]);
    lArete.push_back(a);

    a=new Arete(lSommet[1],lSommet[3]);
    lArete.push_back(a);
    a=new Arete(lSommet[1],lSommet[4]);
    lArete.push_back(a);
    a=new Arete(lSommet[1],lSommet[5]);
    lArete.push_back(a);
    a=new Arete(lSommet[1],lSommet[6]);
    lArete.push_back(a);
    a=new Arete(lSommet[1],lSommet[7]);
    lArete.push_back(a);
    a=new Arete(lSommet[1],lSommet[8]);
    lArete.push_back(a);
    a=new Arete(lSommet[1],lSommet[9]);
    lArete.push_back(a);
    a=new Arete(lSommet[1],lSommet[10]);
    lArete.push_back(a);

    a=new Arete(lSommet[2],lSommet[4]);
    lArete.push_back(a);
    a=new Arete(lSommet[2],lSommet[5]);
    lArete.push_back(a);
    a=new Arete(lSommet[2],lSommet[6]);
    lArete.push_back(a);
    a=new Arete(lSommet[2],lSommet[7]);
    lArete.push_back(a);
    a=new Arete(lSommet[2],lSommet[8]);
    lArete.push_back(a);
    a=new Arete(lSommet[2],lSommet[9]);
    lArete.push_back(a);
    a=new Arete(lSommet[2],lSommet[10]);
    lArete.push_back(a);

    a=new Arete(lSommet[3],lSommet[5]);
    lArete.push_back(a);
    a=new Arete(lSommet[3],lSommet[6]);
    lArete.push_back(a);
    a=new Arete(lSommet[3],lSommet[7]);
    lArete.push_back(a);
    a=new Arete(lSommet[3],lSommet[8]);
    lArete.push_back(a);
    a=new Arete(lSommet[3],lSommet[9]);
    lArete.push_back(a);
    a=new Arete(lSommet[3],lSommet[10]);
    lArete.push_back(a);

    a=new Arete(lSommet[4],lSommet[6]);
    lArete.push_back(a);
    a=new Arete(lSommet[4],lSommet[7]);
    lArete.push_back(a);
    a=new Arete(lSommet[4],lSommet[8]);
    lArete.push_back(a);
    a=new Arete(lSommet[4],lSommet[9]);
    lArete.push_back(a);
    a=new Arete(lSommet[4],lSommet[10]);
    lArete.push_back(a);

    a=new Arete(lSommet[5],lSommet[7]);
    lArete.push_back(a);
    a=new Arete(lSommet[5],lSommet[8]);
    lArete.push_back(a);
    a=new Arete(lSommet[5],lSommet[9]);
    lArete.push_back(a);
    a=new Arete(lSommet[5],lSommet[10]);
    lArete.push_back(a);

    a=new Arete(lSommet[6],lSommet[8]);
    lArete.push_back(a);
    a=new Arete(lSommet[6],lSommet[9]);
    lArete.push_back(a);
    a=new Arete(lSommet[6],lSommet[10]);
    lArete.push_back(a);

    a=new Arete(lSommet[7],lSommet[9]);
    lArete.push_back(a);
    a=new Arete(lSommet[7],lSommet[10]);
    lArete.push_back(a);

    a=new Arete(lSommet[8],lSommet[10]);
    lArete.push_back(a);

    a=new Arete(lSommet[0],lSommet[21]);
    lArete.push_back(a);
    a=new Arete(lSommet[1],lSommet[20]);
    lArete.push_back(a);
    a=new Arete(lSommet[2],lSommet[19]);
    lArete.push_back(a);
    a=new Arete(lSommet[3],lSommet[18]);
    lArete.push_back(a);
    a=new Arete(lSommet[4],lSommet[17]);
    lArete.push_back(a);
    a=new Arete(lSommet[5],lSommet[16]);
    lArete.push_back(a);
    a=new Arete(lSommet[6],lSommet[15]);
    lArete.push_back(a);
    a=new Arete(lSommet[7],lSommet[14]);
    lArete.push_back(a);
    a=new Arete(lSommet[8],lSommet[13]);
    lArete.push_back(a);
    a=new Arete(lSommet[9],lSommet[12]);
    lArete.push_back(a);
    a=new Arete(lSommet[10],lSommet[11]);
    lArete.push_back(a);

    a=new Arete(lSommet[21],lSommet[20]);
    lArete.push_back(a);
    a=new Arete(lSommet[20],lSommet[19]);
    lArete.push_back(a);
    a=new Arete(lSommet[18],lSommet[19]);
    lArete.push_back(a);
    a=new Arete(lSommet[17],lSommet[18]);
    lArete.push_back(a);
    a=new Arete(lSommet[16],lSommet[17]);
    lArete.push_back(a);
    a=new Arete(lSommet[15],lSommet[16]);
    lArete.push_back(a);
    a=new Arete(lSommet[14],lSommet[15]);
    lArete.push_back(a);
    a=new Arete(lSommet[13],lSommet[14]);
    lArete.push_back(a);
    a=new Arete(lSommet[12],lSommet[13]);
    lArete.push_back(a);
    a=new Arete(lSommet[11],lSommet[12]);
    lArete.push_back(a);
    a=new Arete(lSommet[21],lSommet[11]);
    lArete.push_back(a);

    grapheColore=GrapheColore();
    grapheColore.setListeSommets(lSommet);
    grapheColore.setListeArcs(lArete);
    cout<<grapheColore;
    grapheColore.colorerDirect();
    cout<<grapheColore;
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
