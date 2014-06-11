#include "importexport.h"

ImportExport::ImportExport(InterfaceGraph* graph, XMLTree* tree, ImplemGraphviz* affichage)
{
    graphe=graph;
    arbre=tree;
    affich=affichage;
}

bool ImportExport::ouvrir(QIODevice *device, QDomDocument* domDocument)
{
    //On remplace le graphe, on oublie tout !
    *graphe=InterfaceGraph();

    //Et on commence : on parse le document
    QString errorStr;
    int errorLine;
    int errorColumn;

    if (!(domDocument->setContent(device, true, &errorStr, &errorLine,
                                 &errorColumn))) {
        QMessageBox::information(arbre->window(), QObject::tr("GraphCalculus"),
                                 QObject::tr("Erreur ligne %1, colonne %2:\n%3")
                                 .arg(errorLine)
                                 .arg(errorColumn)
                                 .arg(errorStr));
        return false;
    }

    //On en trouve la racine
    QDomElement root = domDocument->documentElement();

    //On nettoye l'arbre s'il avait déjà des éléments
    arbre->clear();

    //On construit à nouveau l'arbre : la racine
    QTreeWidgetItem *rootTree;

    //Liste des sommets : dans l'arbre et dans le document
    QTreeWidgetItem *listeSommets;
    QDomElement listeDomSommets;

    //Liste des arcs : dans l'arbre et dans le document
    QTreeWidgetItem *listeArcs;
    QDomElement listeDomArcs ;

    if (!root.isNull()) {
        //D'abord la racine
        rootTree=new QTreeWidgetItem(arbre);
        arbre->insertTopLevelItem(0,rootTree);
        rootTree->setExpanded(true);
        rootTree->setText(0,QObject::tr("Graphe"));

        //Liste des sommets
        listeDomSommets = root.firstChildElement("Sommets");
        listeSommets = new QTreeWidgetItem(rootTree);
        listeSommets->setExpanded(true);
        listeSommets->setText(0,listeDomSommets.tagName());

        //Liste des arcs
        listeDomArcs = root.firstChildElement("Arcs");
        listeArcs = new QTreeWidgetItem(rootTree);
        //listeArcs->setExpanded(true);
        listeArcs->setText(0,listeDomArcs.tagName());

        //On remplit chacune des listes : d'abord les sommets
        if(graphe->isColore())
        {
            QDomElement firstElmt=listeDomSommets.firstChildElement();
            GrapheColore* graph=(GrapheColore*) graphe->getGraph();
            parseGraphe(graph, &firstElmt, listeSommets);
        }
        else
        {
            QDomElement firstElmt=listeDomSommets.firstChildElement();
            Graphe* graph=(Graphe*) graphe->getGraph();
            parseGraphe(graph, &firstElmt, listeSommets);
        }

        //Puis les arcs
        QDomElement firstElmt=listeDomArcs.firstChildElement();
        if(graphe->isColore())
        {
            GrapheColore* graph=(GrapheColore*) graphe->getGraph();
            parseGraphe(graph, &firstElmt, listeArcs);
        }
        else
        {
            Graphe* graph=(Graphe*) graphe->getGraph();
            parseGraphe(graph, &firstElmt, listeArcs);
        }

        //root = root.nextSiblingElement("Graphe");
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
                               QDomElement* child,
                               QTreeWidgetItem *parentItem)
{
    //QDomElement child = element.firstChildElement();
    if (!child->isNull()) {
        if (child->tagName() == "Sommet") {
            //Ajout au graphe
            Sommet *nvSom=new Sommet();
            graph->ajouterSommet(nvSom);

            //Ajout à l'arbre
            QTreeWidgetItem *childItem = arbre->createItem(nvSom, parentItem);

            QString title = child->attribute(QObject::tr("id"));

            childItem->setFlags(parentItem->flags() | Qt::ItemIsSelectable);//Refus du noeud à être modifié
            childItem->setText(0, title);

            //On affecte au sommet son nom
            nvSom->setNom(title);

            //On pense à ajouter l'élément comme étant Observeur du sommet créé
            XMLElementSommet *obsXML=new XMLElementSommet(nvSom,*child, graphe);
            nvSom->addObserver(obsXML);

            //Et aussi l'affichage
            //nvSom->addObserver(affich);
            //GraphViz non thread-safe : affichage mal géré. Mieux vaut donc redemander l'affichage à chaque fois.


            //On s'occupe des attributs du sommet
            parseElement(*child, childItem, nvSom);


        } else if (child->tagName() == "Arc") {
            //Ajout au graphe
            Sommet* sommet1=graph->obtenirSommet(child->attribute("Depart"));
            Sommet* sommet2=graph->obtenirSommet(child->attribute("Arrivee"));
            Arete *nvleArete=new Arete(sommet1, sommet2);
            graph->ajouterArc(nvleArete);

            //Ajout à l'arbre
            QTreeWidgetItem *childItem = arbre->createItem(nvleArete, parentItem);

            QString title = child->tagName();

            childItem->setFlags(parentItem->flags() | Qt::ItemIsSelectable);
            childItem->setText(0, title);

            QTreeWidgetItem *arcChildItemD = new QTreeWidgetItem(childItem);
            arcChildItemD->setText(0, QObject::tr("Départ : "));
            arcChildItemD->setText(1, child->attribute("Depart"));

            QTreeWidgetItem *arcChildItemA = new QTreeWidgetItem(childItem);
            arcChildItemA->setText(0,QObject::tr("Arrivée : "));
            arcChildItemA->setText(1,child->attribute("Arrivee"));

            //On n'oublie pas d'ajouter l'élément comme observeur de l'arête
            XMLElementArete *obsXML=new XMLElementArete(nvleArete,*child);
            nvleArete->addObserver(obsXML);

            //Et aussi l'affichage
            //nvleArete->addObserver(affich);
            //GraphViz non thread-safe : affichage mal géré. Mieux vaut donc redemander l'affichage à chaque fois.

            //On s'occupe du reste
            parseElement(*child, childItem, nvleArete);
        }

        //On continue la marche voir s'il reste des éléments à ajouter derrière
        QDomElement nextSibling=child->nextSiblingElement();
        if(graphe->isColore()){
            GrapheColore* grapheEnCours=(GrapheColore*) graphe->getGraph();
            this->parseGraphe(grapheEnCours,&nextSibling,parentItem);
        }
        else{
            Graphe* grapheEnCours=(Graphe*) graphe->getGraph();
            this->parseGraphe(grapheEnCours,&nextSibling,parentItem);
        }

    }
}

void ImportExport::parseGraphe(GrapheColore* graph,
                               QDomElement* child,
                               QTreeWidgetItem *parentItem)
{
    //QDomElement child = element.firstChildElement();
    if (!child->isNull()) {
        if (child->tagName() == "Sommet") {
            //Ajout au graphe
            SommetColore *nvSom=new SommetColore();
            graph->ajouterSommet(nvSom);
            QTreeWidgetItem *childItem = arbre->createItem(nvSom, parentItem);

            QString title = child->attribute(QObject::tr("id"));

            //On donne son nom au sommet
            nvSom->setNom(title);

            //Ajout à l'arbre
            childItem->setFlags(parentItem->flags() | Qt::ItemIsSelectable);//Refus du noeud à être modifié
            childItem->setText(0, title);

            //Ajout du sommet à la liste des observeurs
            XMLElementSommet *obsXML=new XMLElementSommet(nvSom,*child,graphe);
            nvSom->addObserver(obsXML);

            //Et aussi l'affichage
            //nvSom->addObserver(affich);
            //GraphViz non thread-safe : affichage mal géré. Mieux vaut donc redemander l'affichage à chaque fois.


            //On s'occupe des attributs du sommet
            parseElement(*child, childItem, nvSom);
        } else if (child->tagName() == "Arc") {
            //Ajout au graphe
            SommetColore* sommet1=graph->obtenirSommet(child->attribute("Depart"));
            SommetColore* sommet2=graph->obtenirSommet(child->attribute("Arrivee"));
            Arete *nvleArete=new Arete(sommet1, sommet2);
            graph->ajouterArc(nvleArete);

            //Ajout à l'arbre
            QTreeWidgetItem *childItem = arbre->createItem(nvleArete, parentItem);

            QString title = child->tagName();

            childItem->setFlags(parentItem->flags() | Qt::ItemIsSelectable);
            childItem->setText(0, title);

            QTreeWidgetItem *arcChildItemD = new QTreeWidgetItem(childItem);
            arcChildItemD->setText(0, QObject::tr("Départ : "));
            arcChildItemD->setText(1, child->attribute("Depart"));

            QTreeWidgetItem *arcChildItemG = new QTreeWidgetItem(childItem);
            arcChildItemG->setText(0,QObject::tr("Arrivée : "));
            arcChildItemG->setText(1,child->attribute("Arrivee"));

            //Ajout de l'observeur à l'arête
            XMLElementArete *obsXML=new XMLElementArete(nvleArete,*child);
            nvleArete->addObserver(obsXML);

            //Et aussi l'affichage
            //nvleArete->addObserver(affich);
            //GraphViz non thread-safe : affichage mal géré. Mieux vaut donc redemander l'affichage à chaque fois.

            //On s'occupe du reste
            parseElement(*child, childItem, nvleArete);
        }

        //On continue la marche voir s'il reste des éléments à ajouter derrière
        QDomElement nextSibling=child->nextSiblingElement();
        if(graphe->isColore()){
            GrapheColore* grapheEnCours=(GrapheColore*) graphe->getGraph();
            parseGraphe(grapheEnCours,&nextSibling,parentItem);
        }
        else{
            Graphe* grapheEnCours=(Graphe*) graphe->getGraph();
            parseGraphe(grapheEnCours,&nextSibling,parentItem);
        }
    }
}

void ImportExport::parseElement(const QDomElement &element,
                           QTreeWidgetItem *parentItem,
                           Sommet *sommet)
{
    QDomElement child = element.firstChildElement();

    while (!child.isNull()) {
        //On ajoute ça au sommet
        if (child.tagName()=="Valeur"){
            /*
            QTreeWidgetItem *childItem = createItem(*sommet, parentItem);

            QString title = child.text();

            childItem->setFlags(parentItem->flags() | Qt::ItemIsSelectable);
            childItem->setText(0, child.tagName()+tr(" : "));
            childItem->setText(1, title);

            SommetValue* sommetValue=(SommetValue*)sommet->sommetToValue();
            sommet=sommetValue;
            sommetColore->setValeur(element.tagName("Valeur"));*/
        } else if (child.tagName()=="Forme"){
            sommet->setForme(element.text());
        } else if ((child.tagName()=="Couleur")){
            //GROSSE ASTUCE : je veux récupérer le sommet coloré qui correspond à mon sommet précédent. Normalement, en construisant mon graphe coloré,
            //mes sommets gardent le même ID ! Donc, j'utilise ça pour récupérer le bon sommet à colorer :

            //Je récupère l'ID
            QString idSom=sommet->getNom();

            //Je colore le graphe si besoin
            if(!(graphe->isColore()))
                graphe->grapheToColore();

            //Je récupère mon sommet coloré
            GrapheColore* graph=(GrapheColore*) graphe->getGraph();
            SommetColore* sommetColore=graph->obtenirSommet(idSom);

            //Je lui fixe sa couleur !
            QString nvCouleur = QString("#")+child.text();
            sommetColore->setCouleur(nvCouleur.toStdString());
        }

        child = child.nextSiblingElement();
    }
}


void ImportExport::parseElement(const QDomElement &element,
                           QTreeWidgetItem *parentItem,
                           Arete *arc)
{
    QDomElement child = element.firstChildElement();

    while (!child.isNull()) {
        QTreeWidgetItem *childItem = new QTreeWidgetItem(parentItem);

        QString title = child.text();

        childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
        childItem->setText(0, child.tagName()+QObject::tr(" : "));
        childItem->setText(1, title);

        //On ajoute ça à l'arc
        if (element.tagName()=="Valeur"){
            //arc->setValeur(element.tagName().toInt())
        } else if (element.tagName()=="Couleur"){
            //arc->setCouleur(element.tagName().toStdString())
        }

        child = child.nextSiblingElement();
    }
}
