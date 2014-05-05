#include "implemgraphviz.h"

ImplemGraphviz::ImplemGraphviz(QWidget *parent, Graphe *graph) : QSvgWidget(parent)
{
    graphe=graph;
    lienSVG=QString("imageGraph.svg");

    G=agopen("G",Agundirected,0);

    drawGraph();
}

ImplemGraphviz::ImplemGraphviz(QWidget *parent, GrapheOriente *graph) : QSvgWidget(parent)
{
    graphe=graph;
    lienSVG=QString("imageGraph.svg");

    G=agopen("G",Agdirected,0);

    drawGraph();
}

void ImplemGraphviz::creerListeNodes(Graphe* graphe)
{
    tableNodes.clear();
    vector<Sommet*> liste=graphe->getListeSommets();
    for(int i=0; i<liste.size(); i++){
        Sommet* som=liste[i];
        char* nom=(char*)som->getId().c_str();

        Agnode_t* agnod=agnode(G,nom, 1);

        char* shape=(char*)"shape";
        string forme;
        QStringList listeChoix;
        listeChoix<<"box"<<"ellipse"<<"circle"<<"square"<<"star"<<"diamond"<<"pentagon"<<"septagon";
        if(listeChoix.contains(QString(som->getForme().c_str())))
            forme=som->getForme();

        char* shapeAttr=(char*)forme.c_str();
        agset(agnod,shape,shapeAttr);

        tableNodes.insert(som, agnod);
    }
}

void ImplemGraphviz::creerListeNodes(GrapheColore* graphe)
{
    tableNodes.clear();
    vector<Sommet*> liste=graphe->getListeSommets();
    for(int i=0; i<liste.size(); i++){
        SommetColore* som=(SommetColore*)liste[i];
        char* nom=(char*)som->getId().c_str();

        Agnode_t* agnod=agnode(G,nom, 1);

        char* shape=(char*)"shape";
        string forme;
        QStringList listeChoix;
        listeChoix<<"box"<<"ellipse"<<"circle"<<"square"<<"star"<<"diamond"<<"pentagon"<<"septagon";
        if(listeChoix.contains(QString(som->getForme().c_str())))
            forme=som->getForme();
        else
            forme="ellipse";

        char* shapeAttr=(char*)forme.c_str();
        agset(agnod,shape,shapeAttr);

        char* color=(char*)"color";
        string couleur;
        if(som->getCouleur()!="")
            couleur=som->getCouleur();
        else
            couleur="lightgrey";
        char* colorAttr=(char*)couleur.c_str();
        agset(agnod,color,colorAttr);


        tableNodes.insert(som, agnod);
    }
}


void ImplemGraphviz::creerListeEdges()
{
    tableEdges.clear();
    vector<Arete*> liste=graphe->getListeArcs();
    for(int i=0;i<liste.size();i++){
        Arete* areteCour=liste[i];
        Sommet* depart=areteCour->getDepart();
        Sommet* arrivee=areteCour->getArrivee();

        string txt=depart->getId()+"->"+arrivee->getId();
        char* nom=(char*)txt.c_str();
        Agedge_t* agedg=agedge(G,tableNodes[depart],tableNodes[arrivee],nom,1);
        tableEdges.insert(areteCour,agedg);
    }
}


void ImplemGraphviz::drawGraph()
{
    creerListeNodes(graphe);
    creerListeEdges();

    GVC_t *gvc;
    gvLayout(gvc,G,"dot");
    gvRenderFilename(gvc,G,"svg",lienSVG.toStdString().c_str());

    load(lienSVG);
}
