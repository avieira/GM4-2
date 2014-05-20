#include "implemgraphviz.h"

ImplemGraphviz::ImplemGraphviz(InterfaceGraph *graph, QWidget *parent) : QSvgWidget(parent)
{
    graphe=graph;
    lienSVG=QString("imageGraph.svg");

    /*setMinimumWidth(parent->minimumWidth());
    setMinimumHeight(parent->minimumHeight());*/
    drawGraph();
}

void ImplemGraphviz::creerListeNodes(Graphe* graph)
{
    tableNodes.clear();
    vector<Sommet*> liste=graph->getListeSommets();
    for(int i=0; i<liste.size(); i++){
        Sommet* som=liste[i];
        char* nom=(char*)(graphe->obtenirId(som).toStdString().c_str());

        Agnode_t* agnod=agnode(G,nom);

        char* shape=(char*)"shape";
        string forme;
        QStringList listeChoix=graphe->getListeForme();
        QString form=graphe->obtenirForme(som);
        if(listeChoix.contains(form))
            forme=graphe->obtenirForme(som).toStdString();
        else
            forme="ellipse";

        char* shapeAttr=(char*)forme.c_str();
        agsafeset(agnod,shape,shapeAttr,"");

        tableNodes.insert(som, agnod);
    }
}

void ImplemGraphviz::creerListeNodes(GrapheColore* graph)
{
    tableNodes.clear();
    vector<SommetColore*> liste=graph->getListeSommets();
    for(int i=0; i<liste.size(); i++){
        SommetColore* som=liste[i];
        char* nom=(char*)(graphe->obtenirId(som).toStdString().c_str());

        Agnode_t* agnod=agnode(G,nom);

        char* shape=(char*)"shape";
        string forme;
        QStringList listeChoix=graphe->getListeForme();
        QString form=graphe->obtenirForme(som);
        if(listeChoix.contains(form))
            forme=graphe->obtenirForme(som).toStdString();
        else
            forme="ellipse";

        char* shapeAttr=(char*)forme.c_str();
        agsafeset(agnod,shape,shapeAttr,"");

        char* style=(char*)"style";
        char* filled=(char*)"filled";
        agsafeset(agnod,style,filled,"");

        char* color=(char*)"fillcolor";
        string couleur;
        if(som->getCouleur()!="#FFFFFF")
            couleur=som->getCouleur();
        else
            couleur="lightgrey";
        char* colorAttr=(char*)couleur.c_str();
        agsafeset(agnod,color,colorAttr,"");

        tableNodes.insert(som, agnod);
    }
}

void ImplemGraphviz::creerListeEdges(Graphe* graph)
{
    tableEdges.clear();
    vector<Arete*> liste=graph->getListeArcs();
    for(int i=0;i<liste.size();i++){
        Arete* areteCour=liste[i];
        Sommet* depart=areteCour->getDepart();
        Sommet* arrivee=areteCour->getArrivee();

        Agedge_t* agedg=agedge(G,tableNodes[depart],tableNodes[arrivee]);
        tableEdges.insert(areteCour,agedg);
    }
}

void ImplemGraphviz::drawGraph()
{
    GVC_t *gvc=gvContext();

    G=agopen("G",AGRAPH); //Ici pour modifier afin que le graphe soit orienté : AGRAPH -> AGDIGRAPH

    if(graphe->isColore())
    {
        GrapheColore* graph=(GrapheColore*) graphe->getGraph();
        creerListeNodes(graph);
        creerListeEdges(graph);
    }
    else
    {
        Graphe* graph=(Graphe*) graphe->getGraph();
        creerListeNodes(graph);
        creerListeEdges(graph);
    }

    gvLayout(gvc,G,"dot");

    gvRenderFilename(gvc,G,"svg",lienSVG.toStdString().c_str());

    load(lienSVG);
    adjustSize();
}
