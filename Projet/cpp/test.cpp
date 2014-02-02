#include <iostream>
#include<vector>
#include"MatriceSymDefPos.h"
using namespace std;

int main(){
	MatriceSymDefPos *test=new MatriceSymDefPos();

	vector< vector<double> > mat(4,vector<double>(4));
	mat[0][0]=1;
	mat[0][1]=1;
	mat[0][2]=1;
	mat[0][3]=1;
	mat[1][0]=1;
	mat[1][1]=5;
	mat[1][2]=5;
	mat[1][3]=5;
	mat[2][0]=1;
	mat[2][1]=5;
	mat[2][2]=14;
	mat[2][3]=14;
	mat[3][0]=1;
	mat[3][1]=5;
	mat[3][2]=14;
	mat[3][3]=15;

	test->setMatrice(mat);

//--------------------------------------------------------------------------
//              Décomposition de Cholesky
//--------------------------------------------------------------------------

	MatriceTriangInf *result=test->decompoCholesk();

	for(int i=0;i<result->getMatrice().size();i++){
		for(int j=0;j<result->getMatrice().size();j++)
			cout<<result->getMatrice()[i][j]<<" ";
		cout<<endl;
	}

//--------------------------------------------------------------------------
//		Essai de transposée
//--------------------------------------------------------------------------

	MatriceTriangSup* transpo=result->transpose();

	for(int i=0;i<transpo->getMatrice().size();i++){
		for(int j=0;j<transpo->getMatrice().size();j++)
			cout<<transpo->getMatrice()[i][j]<<" ";
		cout<<endl;
	}

//--------------------------------------------------------------------------
//              Remontée de Gauss
//--------------------------------------------------------------------------
	vector<double> vectResult;
	vector<double> vectTest(transpo->getMatrice().size(),8);

	vectTest[1]=12;
	vectTest[2]=12;
	vectTest[3]=2;

	vectResult=transpo->remontGauss(vectTest);

	for(int i=0;i<vectResult.size();i++)
		cout<<vectResult[i]<<endl;

	return 0;
}
