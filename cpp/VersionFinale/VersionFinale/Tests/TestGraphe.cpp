#include<string>
#include<iostream>
#include<vector>

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "Model/graphe.h"
#include"Model/arete.h"
#include "Model/sommet.h"

using namespace std;
using namespace CppUnit;

class TestGraphe : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestGraphe);
    CPPUNIT_TEST(testSupprSommet);
    CPPUNIT_TEST(testObtenirListeAdj);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

protected:
    void testSupprSommet();
    void testObtenirListeAdj();

private:

    Graphe *grapheTest;
};


void TestGraphe::testSupprSommet()
{
    // On recupere le premier sommet du graphe via un pointeur
    vector<Sommet*> l = grapheTest->getListeSommets();
    Sommet *pS = l.at(0);
    // Test CAS NORMAL : on supprime un sommet qui existe dans le graphe

    // On applique la methode supprSommet au premier sommet du graphe test
    grapheTest->supprSommet(pS);

    // On test si le sommet a ete bien supprimé ie si le pointeur pS se trouve encore dans la liste de sommets :
    bool result=true;
    l = grapheTest->getListeSommets();
    for(int i=0;i<l.size();i++){
        if(l.at(i)==pS){
            result=false;
        }
    }
    CPPUNIT_ASSERT(result==true);

    // Test CAS ERREUR : on supprime un sommet qui n'existe pas dans le graphe ; introduire une EXCEPTION ExceptionSommetInexistant

    // On cree un sommet qui n'est pas dans le graphe
    /*bool b=false;
    Sommet sommetExt = Sommet(b);

    // On verifie que la methode gere bien l'exception du sommet qui n'existe pas dans le graphe
    //CPPUNIT_ASSERT_THROW((*grapheTest).supprSommet(sommetExt), ExceptionSommetInexistant)*/


}

void TestGraphe::testObtenirListeAdj()
{
    // Test CAS NORMAL : on veut obtenir la liste d'adj d'un sommet qui existe.
    // On applique la methode obtenirListeAdj au premier sommet du graphe
    vector<Sommet *> listeAdj1 ;
    listeAdj1 = grapheTest->obtenirListeAdj(grapheTest->getListeSommets().at(0));

    // On test si on obtient bien une liste contenant le deuxieme sommet du graphe
    vector<Sommet *> lAdj1 ;
    //lAdj1.push_back(grapheTest->getListeSommets().at(0));
    lAdj1.push_back(grapheTest->getListeSommets().at(1));

    CPPUNIT_ASSERT(listeAdj1 == lAdj1);

    // Test CAS LIMITE : on veut obtenir la liste d'adj d'un sommet qui n'est pas dans le graphe

    // On cree un sommet exterieur
    /*Sommet s = Sommet();
        Sommet *pS = &s;

        // On applique la methode obtenirListeAdj au graphe pour le sommet s exterieur et on verifie que l'on obtient bien une liste vide
        vector<Sommet *> listeAdj2 = vector<Sommet*>();
        listeAdj2 = grapheTest->obtenirListeAdj(pS);

        vector<Sommet *> lAdj2 = vector<Sommet*>();
        CPPUNIT_ASSERT(listeAdj2 == lAdj2);*/



}

void TestGraphe::setUp()
{

    grapheTest = new Graphe();

    bool m=false;

    Sommet sommet1 = Sommet(m);
    Sommet sommet2 = Sommet(m);

    Sommet *pSommet1 = &sommet1;
    Sommet *pSommet2 = &sommet2;

    grapheTest->ajouterSommet(pSommet1);
    grapheTest->ajouterSommet(pSommet2);


    /*Sommet s1 = Sommet(m);
    Sommet s2 = Sommet(m);

    Sommet *pS1 = &s1;
    Sommet *pS2 = &s2;

    Arete *arete = new Arete(pS1, pS2);

    #ifdef DELIF1
    #undef DELIF1
    #endif
    #define DELIF1( _pS1, _pS2 )  \
    if( (_pS1)&&(_pS2) )              \
        { delete _pS1; _pS1 = NULL;  \
          delete _pS2; _pS2 = NULL; }

    arete->setDepart(pSommet1);
    arete->setArrivee(pSommet2);*/

    Arete *arete = new Arete(pSommet1, pSommet2);

    grapheTest->ajouterArc(arete);


}

void TestGraphe::tearDown()
{
    delete grapheTest;
}


CPPUNIT_TEST_SUITE_REGISTRATION(TestGraphe);

int main(int argc, char* argv[])
{
    //  Creation de la serie de tests
    CPPUNIT_NS::TestResult controller;

  CPPUNIT_NS::TestResultCollector result;
  controller.addListener( &result );

  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener( &progress );
  
  
  CPPUNIT_NS::TestRunner runner;
  runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );
  runner.run( controller );

  return result.wasSuccessful() ? 0 : 1;

}
