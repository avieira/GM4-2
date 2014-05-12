#include "graphecolore.h"

GrapheColore::GrapheColore():Graphe()
{
}

GrapheColore::~GrapheColore()
{
    int i;
    for(i=0;i<listeSommets.size();i++)
        delete listeSommets[i];

    /*for(i=0;i<listeArcs.size();i++)
        delete listeArcs[i];*/
}

void GrapheColore::setListeSommets(vector<SommetColore*> liste)
{
	listeSommets=liste;
}

vector<SommetColore*> GrapheColore::getListeSommets()
{
	return listeSommets;
}

void GrapheColore::ajouterSommet(SommetColore* sommet)
{
    listeSommets.push_back(sommet);
}

vector<SommetColore*> GrapheColore::obtenirListeAdj(SommetColore* sommet)
{

}

// On a défini une relation d'ordre sur les "étiquettes" des sommets. Cette fonction sert à calculer laquelle des deux étiquettes L1, L2 est max.
int GrapheColore::comparerEtiquettes(set<int> L1, set<int> L2)
{
	int i, l, l1, l2, resultat;
	bool trouve;

	set<int>::iterator iter1 = L1.end();
	set<int>::iterator iter2 = L2.end();

	l1 = L1.size();
	l2 = L2.size();

// Pour éviter le dépassement de capacité, on a besoin de connaître la longueur minimale des deux étiquettes.
	if (l2>l1)
	{
		l = l1;
	}
	else
	{
		l = l2;
	}
	
// On compare deux à deux les deux éléments maximaux de chaque étiquette.
	i = 0;
	trouve = false;
	while((i<l) && (!trouve))
	{
		if (*iter1 > *iter2)
		{
			trouve = true;
			resultat = 1;
		}
		else if (*iter2 > *iter1)
		{
			trouve = true;
			resultat = 2;
		}
		else
		{
			iter1--;
			iter2--;
		}
		i++;
	}
	return resultat;
}

vector<int> GrapheColore::lexBFS()
{
	int n = listeSommets.size();
	set<int> L[n];
	vector<int> theta = vector<int>(n);
	vector<SommetColore*> voisins;
	int i, j, sup, nbVoisins;
	SommetColore* s;

	s = listeSommets[0];
	for(i=0; i<n; i++)
	{
		voisins = obtenirListeAdj(s);
		nbVoisins = voisins.size();
		theta[s->getId()] = i;
		// Mise à jour des étiquettes des sommets voisins
		for (j=0; j<nbVoisins; j++)
			L[voisins[j]->getId()].insert(i);

		// Recherche du sommet d'étiquette maximale. Le maximum est forcément parmi les voisins !
		s = voisins[0];
		for (j=1; j<nbVoisins; j++)
		{
			sup = comparerEtiquettes(L[s->getId()], L[voisins[j]->getId()]);
			if(sup==2)
				s = voisins[j];
		}
	}
	return inverser(theta);
}

// Nécessaire car COLOR s'applique sur l'ordre inverse calculé
vector<int> GrapheColore::inverser(vector<int> ordre)
{
	int i, n, temp;

	n = listeSommets.size();
	for(i=0; i<(n/2); i++)
	{
		temp = ordre[i];
		ordre[i] = ordre[(n-1)-i];
		ordre[(n-1)-i] = temp;
	}
	return ordre;
}

void GrapheColore::colorerSommets(vector<int> couleurs)
{
	SommetColore* sommet;
	int couleur;
	for(int i=0;i<couleurs.size();i++){
		sommet=getListeSommets()[i];
		couleur=couleurs[i];
		sommet->setCouleur(couleur);
	}
}

void GrapheColore::colorerDirect()
{
        vector<int> ordre, couleur;
        int i, j, k, n, laCouleur, nbVoisins;
        vector<SommetColore*> voisins;
        bool mauvaiseCouleur = false;

        n = listeSommets.size();
        couleur = vector<int>(n);
        ordre = lexBFS();

        // Initialisation
        for(i=0; i<n; i++)
                couleur[i] = 0;
        j=0;
        while (ordre[j] != 0)
                j++;
        couleur[j] = 1;

        // Boucle Principale
        for(i=1; i<n; i++)
        {
                // On trouve le sommet de priorité maximale
                j=0;
                while (ordre[j] != i)
                        j++;
                
                // On colore avec la plus basse couleur telle qu'il n'y ait aucune contradiction.
                voisins = obtenirListeAdj(listeSommets[j]);
                nbVoisins = voisins.size();
                laCouleur = 1;
                do
                {
			k=0;
                        mauvaiseCouleur = false;
                        while((k<nbVoisins) && (!mauvaiseCouleur))
			{
                                if (couleur[voisins[k]->getId()] == laCouleur)
                                {
                                        mauvaiseCouleur = true;
                                        laCouleur++;
                                }
				k++;
			}
                }
                while(mauvaiseCouleur);
                couleur[j] = laCouleur;
        }

	colorerSommets(couleur);
}

void GrapheColore::colorerH(int k)
{/*
	// Initialisation des constantes "arbitraires"
	int i, n, nbVoisins, nbIter;
	int longT = 20;
	int rep = 10;
	int maxIter = 60;
	vector<int> couleur;
	Solution sol;

    n = listeSommets.size();
	couleur = vector<int>(n);

	// Génération (aléatoire) de la solution initiale
	srand (time(NULL));
	for(i=0; i<n; i++)
		couleur[i] = rand() % k + 1;
	sol = Solution(k, couleur);
	sol.setCout(solIni.calculerCout());

	// Boucle Principale de la méthode itérative
	nbIter = 0;
	while((sol.cout > 0) && (nbIter < maxIter))
	{
		nbVoisins = 0;
		do
		{
			sol.genererSolVoisine();
			nbVoisins++;
		}
		while((nbVoisins < rep) && (tabSol[tabIter].cout >= sol.cout));
		nbIter++;
	}
   */
}

ostream& operator<<( ostream &flux, GrapheColore& graph ){
    flux<<"Sommets existant : "<<"\n";
    for(int i=0;i<graph.getListeSommets().size();i++)
        flux<<*(graph.getListeSommets().at(i));
}
