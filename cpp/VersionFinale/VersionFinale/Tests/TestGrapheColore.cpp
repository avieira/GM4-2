#include<string>
#include<iostream>
#include<vector>

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "Model/graphecolore.h"
#include"Model/arete.h"
#include "Model/sommetcolore.h"


using namespace CppUnit;
using namespace std;

class TestGrapheColore : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestGrapheColore);
    CPPUNIT_TEST(testContains);
    CPPUNIT_TEST(testObtenirSommet);
    CPPUNIT_TEST(testColorerDirect);
    CPPUNIT_TEST_SUITE_END();
 
public:
    void setUp();
    void tearDown();
 
protected:
    void testColorerDirect();
    void testObtenirSommet();
    void testContains();

private:
 
    GrapheColore *grapheColoreTest;
};

void TestGrapheColore::testContains()
{
    // Test CAS NORMAL : en connaissant le nom du premier sommet dans la liste de sommets on teste si ce sommet appartient au graphe
    bool resultat = true;
    QString id = grapheColoreTest->getListeSommets().at(0)->getNom();
    bool result=(resultat == grapheColoreTest->contains(id));
    CPPUNIT_ASSERT(result==true);
}

void TestGrapheColore::testObtenirSommet()
{
	// Test CAS NORMAL : on veut recuperer le premier sommet de la liste de sommets en connaissant son nom
    vector<SommetColore*> l=grapheColoreTest->getListeSommets();
    QString nomS = l.at(0)->getNom();
    bool result=(l.at(0) == grapheColoreTest->obtenirSommet(nomS));
    CPPUNIT_ASSERT(result == true);
}

void TestGrapheColore::testColorerDirect()
{
	// Definition des variables auxiliaires
	int i = 0;
	bool estColoration = true;
	int taille = grapheColoreTest->getListeArcs().size();

	// Test de la coloration
	while (estColoration && i<(taille))
	{
        SommetColore* depart=(SommetColore*) grapheColoreTest->getListeArcs().at(i)->getDepart();
        SommetColore* arrivee=(SommetColore*) grapheColoreTest->getListeArcs().at(i)->getArrivee();
        if (depart->getCouleur() == arrivee->getCouleur())
		estColoration = false;
		
		i++;
	}
	
	CPPUNIT_ASSERT(estColoration == true);

}

void TestGrapheColore::setUp()
{
	
	grapheColoreTest = new GrapheColore(); 

    bool m=false;

    SommetColore sommet1 = SommetColore(m);
    SommetColore sommet2 = SommetColore(m);

    SommetColore *pSommet1 = &sommet1;
    SommetColore *pSommet2 = &sommet2;

    grapheColoreTest->ajouterSommet(pSommet1);
    grapheColoreTest->ajouterSommet(pSommet2);


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

    grapheColoreTest->ajouterArc(arete);
}

void TestGrapheColore::tearDown()
{
    delete grapheColoreTest;
}


CPPUNIT_TEST_SUITE_REGISTRATION(TestGrapheColore);

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
