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

class TestSommetColore : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestSommetColore);
    CPPUNIT_TEST(testSetCouleur);
    CPPUNIT_TEST(testSommetToColore);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

protected:
    void testSetCouleur();
    void testSommetToColore();

private:

    SommetColore *sommetColoreTest;
};

void TestSommetColore::testSetCouleur()
{
    // On applique la methode setCouleur à SommetColoreTest
    (*sommetColoreTest).setCouleur("#4EA9A0");

    // Test CAS NORMAL : on verifie qu'on a bien la couleur "#4EA9A0" pour le sommet sommetColoreTest
    CPPUNIT_ASSERT("#4EA9A0" == (*sommetColoreTest).getCouleur());

    // Test CAS ERREUR : Si la couleur n'est pas sous forme codeRGB on devrait avoir une erreur ; introduire une EXCEMTION ExceptionCouleurCodeRGB
    // CPPUNIT_ASSERT_THROW("blabla" == (*sommetColoreTest).getCouleur(), ExceptionCouleurCodeRGB)
}

void TestSommetColore::testSommetToColore()
{
    // Test CAS NORMAL : on vérfie qu'on a bien un sommet colore quand on applique la methode sommetToColore
    CPPUNIT_ASSERT(sommetColoreTest ==(*sommetColoreTest).sommetToColore());
}

void TestSommetColore::setUp()
{
    bool m=false;
    sommetColoreTest = new SommetColore(m,"#B9121B");
}

void TestSommetColore::tearDown()
{
    delete sommetColoreTest;
}


CPPUNIT_TEST_SUITE_REGISTRATION(TestSommetColore);

int main(int argc, char* argv[])
{
  // A COMENTER!
  CPPUNIT_NS::TestResult controller;

  CPPUNIT_NS::TestResultCollector result;
  controller.addListener( &result );

  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener( &progress );

  runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );
  runner.run( controller );

  return result.wasSuccessful() ? 0 : 1;
}
