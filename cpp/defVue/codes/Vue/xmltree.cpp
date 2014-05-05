#include "xmltree.h"
#include <QtWidgets>
#include<QUrl>


XMLTree::XMLTree(QWidget *parent, Graphe *graph) : QTreeWidget(parent)
{
    QStringList labels;
    labels << tr("Liste de sommets") << tr("Valeur de l'arguement");

    header()->setSectionResizeMode(QHeaderView::Stretch);
    setHeaderLabels(labels);

    graphe=graph;
}

bool XMLTree::ouvrir(QIODevice *device)
{
    QString errorStr;
    int errorLine;
    int errorColumn;

    if (!domDocument.setContent(device, false, &errorStr, &errorLine,
                                &errorColumn)) {
        QMessageBox::information(window(), tr("GraphCalculus"),
                                 tr("Erreur ligne %1, colonne %2:\n%3")
                                 .arg(errorLine)
                                 .arg(errorColumn)
                                 .arg(errorStr));
        return false;
    }

    QDomElement root = domDocument.documentElement();

    clear();

    disconnect(this, SIGNAL(itemChanged(QTreeWidgetItem*,int)),
               this, SLOT(updateDomElement(QTreeWidgetItem*,int)));

    QTreeWidgetItem *rootTree;

    QDomElement listeDomSommets;
    QTreeWidgetItem *listeSommets;

    QDomElement listeDomArcs ;
    QTreeWidgetItem *listeArcs;

    while (!root.isNull()) {
        rootTree=createItem(root);
        insertTopLevelItem(0,rootTree);
        rootTree->setExpanded(true);
        rootTree->setText(0,tr("Graphe"));

        listeDomSommets = root.firstChildElement("Sommets");
        listeSommets = createItem(listeDomSommets, rootTree);
        listeSommets->setExpanded(true);
        listeSommets->setText(0,listeDomSommets.tagName());

        listeDomArcs = root.firstChildElement("Arcs");
        listeArcs = createItem(listeDomArcs, rootTree);
        //listeArcs->setExpanded(true);
        listeArcs->setText(0,listeDomArcs.tagName());


        parseGraphe(listeDomSommets, listeSommets);
        parseGraphe(listeDomArcs, listeArcs);
        root = root.nextSiblingElement("Graphe");
    }

    connect(this, SIGNAL(itemChanged(QTreeWidgetItem*,int)),
            this, SLOT(updateDomElement(QTreeWidgetItem*,int)));

    return true;
}

bool XMLTree::enregistrer(QIODevice *device)
{
    const int IndentSize = 4;

    QTextStream out(device);
    domDocument.save(out, IndentSize);
    return true;
}


//Si appelé deuxième fois : ne change pas le DomDoc :(
void XMLTree::updateDomElement(QTreeWidgetItem *item, int column)
{
    QDomElement element = domElementForItem.value(item);
    if (!element.isNull()) {
        if (column == 0) {
            QString text=item->text(0);
            if(text.isEmpty()){
                QDomNode parentDom =element.parentNode();
                parentDom.removeChild(element);

                QTreeWidgetItem *parentTree=item->parent();
                parentTree->removeChild(item);
            } else{
                if (element.tagName()!="Sommet")
                    item->setText(0,element.tagName()+tr(" :"));
                else
                    item->setText(0,element.attribute(QObject::tr("id")));
            }

        } else {
            QDomNode parentDom = element.parentNode();
            QDomElement newElement;
            QDomText newText=domDocument.createTextNode(item->text(1));

            if (element.tagName()=="Valeur"){
                newElement = domDocument.createElement("Valeur");
            } else if (element.tagName()=="Forme"){
                newElement = domDocument.createElement("Forme");
            } else if (element.tagName()=="Couleur"){
                newElement = domDocument.createElement("Couleur");
            }

            newElement.appendChild(newText);
            parentDom.replaceChild(newElement, element);
        }

    }
}

void XMLTree::parseGraphe(const QDomElement &element,
                           QTreeWidgetItem *parentItem)
{
    QDomElement child = element.firstChildElement();
    while (!child.isNull()) {
        if (child.tagName() == "Sommet") {
            QTreeWidgetItem *childItem = createItem(child, parentItem);

            QString title = child.attribute(QObject::tr("id"));

            childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);//Autorisation du noeud à être modifié
            childItem->setText(0, title);

            //Ajout au graphe
            Sommet *nvSom=new Sommet(title.toStdString());
            graphe->ajouterSommet(nvSom);

            //On s'occupe des attributs du sommet
            parseElement(child, childItem, nvSom);
        } else if (child.tagName() == "Arc") {
            QTreeWidgetItem *childItem = createItem(child, parentItem);

            QString title = child.tagName();

            childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
            childItem->setText(0, title);

            QTreeWidgetItem *arcChildItemD = new QTreeWidgetItem(childItem);
            arcChildItemD->setText(0, QObject::tr("Départ : "));
            arcChildItemD->setText(1, child.attribute("Depart"));

            QTreeWidgetItem *arcChildItemG = new QTreeWidgetItem(childItem);
            arcChildItemG->setText(0,QObject::tr("Arrivée : "));
            arcChildItemG->setText(1,child.attribute("Arrivee"));

            //Ajout au graphe
            Sommet* sommet1=graphe->trouverSommet(child.attribute("Depart").toStdString());
            Sommet* sommet2=graphe->trouverSommet(child.attribute("Arrivee").toStdString());
            Arete *nvleArete=new Arete(sommet1, sommet2);
            parseElement(child, childItem, nvleArete);
        }
        child = child.nextSiblingElement();
    }
}

// A reprendre quand on aura sommetToValue
void XMLTree::parseElement(const QDomElement &element,
                            QTreeWidgetItem *parentItem,
                            Sommet *sommet)
{
    QDomElement child = element.firstChildElement();

    while (!child.isNull()) {
        QTreeWidgetItem *childItem = createItem(child, parentItem);

        QString title = child.text();

        childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
        childItem->setText(0, child.tagName()+tr(" : "));
        childItem->setText(1, title);

        //On ajoute ça au sommet
        if (element.tagName()=="Valeur"){
            /*SommetValue* sommetValue=(SommetValue*)sommet->sommetToValue();
            sommet=sommetValue;
            sommetColore->setValeur(element.tagName("Valeur"));*/
        } else if (element.tagName()=="Forme"){
            sommet->setForme(element.tagName().toStdString());
        } else if (element.tagName()=="Couleur"){
            SommetColore* sommetColore=(SommetColore*)sommet->sommetToColore();
            sommet=sommetColore;
            sommetColore->setCouleur(element.tagName().toStdString());
        }

        child = child.nextSiblingElement();
    }
}

//A reprendre quand on aura setValeur et setCouleur
void XMLTree::parseElement(const QDomElement &element,
                            QTreeWidgetItem *parentItem,
                            Arete *arc)
{
    QDomElement child = element.firstChildElement();

    while (!child.isNull()) {
        QTreeWidgetItem *childItem = createItem(child, parentItem);

        QString title = child.text();

        childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
        childItem->setText(0, child.tagName()+tr(" : "));
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

QTreeWidgetItem *XMLTree::createItem(const QDomElement &element,
                                      QTreeWidgetItem *parentItem)
{
    QTreeWidgetItem *item;
    if (parentItem) {
        item = new QTreeWidgetItem(parentItem);
    } else {
        item = new QTreeWidgetItem(this);
    }
    domElementForItem.insert(item, element);
    return item;
}

void XMLTree::ajouterSommet(Sommet* sommet){
    //Création de l'élément dans le document Dom
    QDomElement elmt=domDocument.createElement("Sommet");

    QDomElement listeDomSommets = domDocument.documentElement().firstChildElement("Sommets");
    listeDomSommets.appendChild(elmt);

    elmt.attribute(QString("id"),QString(sommet->getId().c_str()));

    //Ajout à l'arbre
    QTreeWidgetItem *parentItem=topLevelItem(0)->child(0);
    QTreeWidgetItem *childItem = createItem(elmt,parentItem);

    QString title = elmt.attribute("id");

    childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
    childItem->setText(0, title);

    parseElement(elmt, childItem, sommet);
}

void XMLTree::ajouterSommet(SommetColore* sommet)
{
    QDomElement elmt=domDocument.createElement("Sommet");

    QDomElement listeDomSommets = domDocument.documentElement().firstChildElement("Sommets");
    listeDomSommets.appendChild(elmt);

    elmt.attribute(QString("id"),QString(sommet->getId().c_str()));

    QDomElement couleurElmt=domDocument.createElement("Couleur");
    elmt.appendChild(couleurElmt);
    couleurElmt.appendChild(domDocument.createTextNode(QString(sommet->getCouleur().c_str())));

    //Ajout à l'arbre
    QTreeWidgetItem *parentItem=topLevelItem(0)->child(0);
    QTreeWidgetItem *childItem = createItem(elmt,parentItem);

    QString title = elmt.attribute("id");

    childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
    childItem->setText(0, title);

    parseElement(elmt, childItem, sommet);
}

void XMLTree::ajouterSommet(SommetValue* sommet)
{
    QDomElement elmt=domDocument.createElement("Sommet");

    QDomElement listeDomSommets = domDocument.documentElement().firstChildElement("Sommets");
    listeDomSommets.appendChild(elmt);

    elmt.attribute(QString("id"),QString(sommet->getId().c_str()));

    QDomElement valeurElmt=domDocument.createElement("Valeur");
    elmt.appendChild(valeurElmt);
    valeurElmt.appendChild(domDocument.createTextNode(QString(sommet->getValeur())));

    //Ajout à l'arbre
    QTreeWidgetItem *parentItem=topLevelItem(0)->child(0);
    QTreeWidgetItem *childItem = createItem(elmt,parentItem);

    QString title = elmt.attribute("id");

    childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
    childItem->setText(0, title);

    parseElement(elmt, childItem, sommet);
}

/*void XMLTree::ajouterSommet(SommetValueColore* sommet, int numId)
{
    QDomElement elmt=domDocument.createElement("Sommet");

    QDomElement listeDomSommets = domDocument.documentElement().firstChildElement("Sommets");
    listeDomSommets.appendChild(elmt);

    elmt.attribute(QString("id"),QString(sommet->getId().c_str()));

    QDomElement valeurElmt=domDocument.createElement("Valeur");
    elmt.appendChild(valeurElmt);
    valeurElmt.appendChild(domDocument.createTextNode(QString(sommet->getValeur())));

    QDomElement couleurElmt=domDocument.createElement("Couleur");
    elmt.appendChild(couleurElmt);
    couleurElmt.appendChild(domDocument.createTextNode(QString(sommet->getCouleur().c_str())));

    //Ajout à l'arbre
    QTreeWidgetItem *parentItem=topLevelItem(0)->child(0);
    QTreeWidgetItem *childItem = createItem(elmt,parentItem);

    QString title = elmt.attribute("id");

    childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
    childItem->setText(0, title);

    parseElement(elmt, childItem);
}*/

void XMLTree::ajouterArc(Arete* arc){
    //Création de l'élément dans le document Dom
    QDomElement elmt=domDocument.createElement("Arc");

    QDomElement listeDomSommets = domDocument.documentElement().firstChildElement("Arcs");
    listeDomSommets.appendChild(elmt);

    elmt.attribute(QString("Depart"),QString(arc->getDepart()->getId().c_str()));
    elmt.attribute(QString("Arrivee"),QString(arc->getArrivee()->getId().c_str()));

    //Ajout à l'arbre
    QTreeWidgetItem *parentItem=topLevelItem(0)->child(1);
    QTreeWidgetItem *childItem = createItem(elmt, parentItem);

    QString title = elmt.tagName();

    childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
    childItem->setText(0, title);

    QTreeWidgetItem *arcChildItemD = new QTreeWidgetItem(childItem);
    arcChildItemD->setText(0, QObject::tr("Départ : "));
    arcChildItemD->setText(1, elmt.attribute("Depart"));

    QTreeWidgetItem *arcChildItemG = new QTreeWidgetItem(childItem);
    arcChildItemG->setText(0,QObject::tr("Arrivée : "));
    arcChildItemG->setText(1,elmt.attribute("Arrivee"));

    parseElement(elmt, childItem, arc);
}

