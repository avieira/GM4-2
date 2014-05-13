#include "importexport.h"

ImportExport::ImportExport(InterfaceGraph* graph, XMLTree* tree)
{
    graphe=graph;
    arbre=tree;
}

bool ImportExport::ouvrir(QIODevice *device, QDomDocument* domDocument)
{
    //On remplace le graphe, on oublie tout !
    *graphe=InterfaceGraph();

    //Et on commence :
    QString errorStr;
    int errorLine;
    int errorColumn;

    if (!(domDocument->setContent(device, false, &errorStr, &errorLine,
                                 &errorColumn))) {
        QMessageBox::information(arbre->window(), QObject::tr("GraphCalculus"),
                                 QObject::tr("Erreur ligne %1, colonne %2:\n%3")
                                 .arg(errorLine)
                                 .arg(errorColumn)
                                 .arg(errorStr));
        return false;
    }

    QDomElement root = domDocument->documentElement();

    arbre->clear();

    QTreeWidgetItem *rootTree;

    QDomElement listeDomSommets;
    QTreeWidgetItem *listeSommets;

    QDomElement listeDomArcs ;
    QTreeWidgetItem *listeArcs;

    if (!root.isNull()) {
        rootTree=new QTreeWidgetItem(arbre);
        arbre->insertTopLevelItem(0,rootTree);
        rootTree->setExpanded(true);
        rootTree->setText(0,QObject::tr("Graphe"));

        listeDomSommets = root.firstChildElement("Sommets");
        listeSommets = new QTreeWidgetItem(rootTree);
        listeSommets->setExpanded(true);
        listeSommets->setText(0,listeDomSommets.tagName());

        listeDomArcs = root.firstChildElement("Arcs");
        listeArcs = new QTreeWidgetItem(rootTree);
        //listeArcs->setExpanded(true);
        listeArcs->setText(0,listeDomArcs.tagName());


        if(graphe->isColore())
        {
            GrapheColore* graph=(GrapheColore*) graphe->getGraph();
            parseGraphe(graph,listeDomSommets.firstChildElement(), listeSommets);
            parseGraphe(graph,listeDomArcs.firstChildElement(), listeArcs);
        }
        else
        {
            Graphe* graph=(Graphe*) graphe->getGraph();
            parseGraphe(graph,listeDomSommets.firstChildElement(), listeSommets);
            parseGraphe(graph,listeDomArcs.firstChildElement(), listeArcs);
        }

        root = root.nextSiblingElement("Graphe");
    }

    return true;
}

bool ImportExport::enregistrer(QIODevice *device, QDomDocument* domDocument)
{
    const int IndentSize = 4;

    QTextStream out(device);
    domDocument->save(out, IndentSize);
    return true;
}


void ImportExport::parseGraphe(Graphe* graph,
                               //const QDomElement &element,
                               const QDomElement &child,
                               QTreeWidgetItem *parentItem)
{
    //QDomElement child = element.firstChildElement();
    if (!child.isNull()) {
        if (child.tagName() == "Sommet") {
            //Ajout au graphe
            Sommet *nvSom=new Sommet();
            graph->ajouterSommet(nvSom);


            QTreeWidgetItem *childItem = arbre->createItem(nvSom, parentItem);

            QString title = child.attribute(QObject::tr("id"));

            childItem->setFlags(parentItem->flags() | Qt::ItemIsSelectable);//Refus du noeud à être modifié
            childItem->setText(0, title);

            //Correspondance id<->Sommet
            graphe->insertSommet(nvSom,title);

            //On s'occupe des attributs du sommet
            arbre->parseElement(child, childItem, nvSom);
        } else if (child.tagName() == "Arc") {
            //Ajout au graphe
            Sommet* sommet1=graphe->obtenirSommet(child.attribute("Depart"));
            Sommet* sommet2=graphe->obtenirSommet(child.attribute("Arrivee"));
            Arete *nvleArete=new Arete(sommet1, sommet2);
            graph->ajouterArc(nvleArete);

            //A SUPPRIMER
            for(int incr=0;incr<graph->getListeArcs().size();incr++)
                std::cout<<*(graph->getListeArcs().at(incr));

            //Ajout à l'arbre
            QTreeWidgetItem *childItem = arbre->createItem(nvleArete, parentItem);

            QString title = child.tagName();

            childItem->setFlags(parentItem->flags() | Qt::ItemIsSelectable);
            childItem->setText(0, title);

            QTreeWidgetItem *arcChildItemD = new QTreeWidgetItem(childItem);
            arcChildItemD->setText(0, QObject::tr("Départ : "));
            arcChildItemD->setText(1, child.attribute("Depart"));

            QTreeWidgetItem *arcChildItemG = new QTreeWidgetItem(childItem);
            arcChildItemG->setText(0,QObject::tr("Arrivée : "));
            arcChildItemG->setText(1,child.attribute("Arrivee"));

            //On s'occupe du reste
            arbre->parseElement(child, childItem, nvleArete);
        }
        //child = child.nextSiblingElement();
        //On continue la marche voir s'il reste des éléments à ajouter derrière
        if(graphe->isColore()){
            GrapheColore* grapheEnCours=(GrapheColore*) graphe->getGraph();
            this->parseGraphe(grapheEnCours,child.nextSiblingElement(),parentItem);
        }
        else{
            Graphe* grapheEnCours=(Graphe*) graphe->getGraph();
            this->parseGraphe(grapheEnCours,child.nextSiblingElement(),parentItem);
        }

    }
}

void ImportExport::parseGraphe(GrapheColore* graph,
                               //const QDomElement &element,
                               const QDomElement &child,
                               QTreeWidgetItem *parentItem)
{
    //QDomElement child = element.firstChildElement();
    if (!child.isNull()) {
        if (child.tagName() == "Sommet") {
            //Ajout au graphe
            SommetColore *nvSom=new SommetColore();
            graph->ajouterSommet(nvSom);
            QTreeWidgetItem *childItem = arbre->createItem(nvSom, parentItem);

            QString title = child.attribute(QObject::tr("id"));

            childItem->setFlags(parentItem->flags() | Qt::ItemIsSelectable);//Refus du noeud à être modifié
            childItem->setText(0, title);

            //Correspondance id<->Sommet
            graphe->insertSommet(nvSom,title);

            //On s'occupe des attributs du sommet
            arbre->parseElement(child, childItem, nvSom);
        } else if (child.tagName() == "Arc") {
            //Ajout au graphe
            SommetColore* sommet1=(SommetColore*) graphe->obtenirSommet(child.attribute("Depart"));
            SommetColore* sommet2=(SommetColore*) graphe->obtenirSommet(child.attribute("Arrivee"));
            Arete *nvleArete=new Arete(sommet1, sommet2);
            graph->ajouterArc(nvleArete);

            //A SUPPRIMER
            for(int incr=0;incr<graph->getListeArcs().size();incr++)
                qDebug()<<graph->getListeArcs().at(incr);

            //Ajout à l'arbre
            QTreeWidgetItem *childItem = arbre->createItem(nvleArete, parentItem);

            QString title = child.tagName();

            childItem->setFlags(parentItem->flags() | Qt::ItemIsSelectable);
            childItem->setText(0, title);

            QTreeWidgetItem *arcChildItemD = new QTreeWidgetItem(childItem);
            arcChildItemD->setText(0, QObject::tr("Départ : "));
            arcChildItemD->setText(1, child.attribute("Depart"));

            QTreeWidgetItem *arcChildItemG = new QTreeWidgetItem(childItem);
            arcChildItemG->setText(0,QObject::tr("Arrivée : "));
            arcChildItemG->setText(1,child.attribute("Arrivee"));

            //On s'occupe du reste
            arbre->parseElement(child, childItem, nvleArete);
        }
        //child = child.nextSiblingElement();

        //On continue la marche voir s'il reste des éléments à ajouter derrière
        if(graphe->isColore()){
            GrapheColore* grapheEnCours=(GrapheColore*) graphe->getGraph();
            parseGraphe(grapheEnCours,child.nextSiblingElement(),parentItem);
        }
        else{
            Graphe* grapheEnCours=(Graphe*) graphe->getGraph();
            parseGraphe(grapheEnCours,child.nextSiblingElement(),parentItem);
        }
    }
}
