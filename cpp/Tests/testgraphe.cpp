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
#include<vector>
#include"Model/arete.h"
#include "Model/sommet.h"

using namespace CppUnit;
using namespace std;

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
    void test();

private:

    Graphe *grapheTest;
};


void TestGraphe:testSupprSommet()
{
    // On recupere le premier sommet du graphe via un pointeur
    Sommet *pS = NULL;
    pS = &(*grapheTest).getListeSommets().at(0);

    // Test CAS NORMAL : on supprime un sommet qui existe dans le graphe

        // On applique la methode supprSommet au premier sommet du graphe test
        (*grapheTest).supprSommet((*grapheTest).getListeSommets().at(0));

        // On test si le sommet a ete bien supprimer ie si le pointeur pS pointe bien sur NULL apres suppression
        CPPUNIT_ASSERT(pS == NULL);

    // Test CAS ERREUR : on supprime un sommet qui n'existe pas dans le graphe ; introduire une EXCEPTION ExceptionSommetInexistant

        // On cree un sommet qui n'est pas dans le graphe
        bool b=false;
        Sommet sommetExt = new Sommet(b);

        // On verifie que la methode gere bien l'exception du sommet qui n'existe pas dans le graphe
        //CPPUNIT_ASSERT_THROW((*grapheTest).supprSommet(sommetExt), ExceptionSommetInexistant)

}

void TestGraphe::setUp()
{
    bool m=false;

    sommet1 = new Sommet(m);
    sommet2 = new Sommet(m);

    Sommet *pSommet1 = &sommet1;
    Sommet *pSommet2 = &sommet2;

    vector<Sommet*> lSommets;
    lSommets.push_back(pSommet1);
    lSommets.push_back(pSommet2);

    arete = new Arete(pSommet1, pSommet2);
    Arete *pArete = &arete;

    vector<Arete*> lAretes;
    lAretes.push_back(pArete);

    grapheTest = new Graphe(lSommets, lAretes);

}

void TestGraphe::tearDown()
{
    delete grapheTest;
}


CPPUNIT_TEST_SUITE_REGISTRATION(TestGraphe);

int main(int argc, char* argv[])
{
  //  A COMENTER!
  CPPUNIT_NS::TestResult controller;

  CPPUNIT_NS::TestResultCollector result;
  controller.addListener( &result );

  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener( &progress );

  runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );
  runner.run( controller );


  return result.wasSuccessful() ? 0 : 1;
}


