#include<string>
#include<iostream>
#include<vector>

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "Model/sommetcolore.h"
#include "Model/sommet.h"

using namespace CppUnit;
using namespace std;

class TestSommet : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestSommet);
    CPPUNIT_TEST(testSommetToColore);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

protected:
    void testSommetToColore();

private:

    Sommet *sommetTest;
};


void TestSommet:testSommetToColore()
{
    // On applique la methode sommetToColore au sommet
    (*sommetTest).sommetToColore();

    // On cree un pointeur qui va pointer sur sommet.couleur si sommet.couleur existe
    String *pCouleur = NULL;
    if((*sommetTest).getCouleur() != NULL)
        pCouleur = &(*sommetTest).getCouleur();

    // Test CAS NORMAL : on vérfie qu'on a bien un sommet colore quand on applique la methode sommetToColore
    CPPUNIT_ASSERT(pCouleur != NULL);
}

void TestSommet::setUp()
{
    bool m=false;
    sommetTest = new Sommet(m);
}

void TestSommet::tearDown()
{
    delete sommetTest;
}


CPPUNIT_TEST_SUITE_REGISTRATION(TestSommet);

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

