#include<vector>
#include<cmath>
#include<iostream>
#include"MatriceSymDefPos.h"

MatriceSymDefPos::MatriceSymDefPos(){Matrice();};

MatriceTriangInf* MatriceSymDefPos::decompoCholesk(){
	int i,j,k;
	int taille=this->getMatrice().size();
	MatriceTriangInf *result=new MatriceTriangInf();

	vector< vector<double> > matRes(taille, vector<double>(taille));

	matRes[0][0]=sqrt(this->getMatrice()[0][0]);
	for(int compt=2;compt<taille+1;compt++)
		matRes[compt-1][0]=(this->getMatrice()[0][compt-1])/(matRes[0][0]);

	for(i=2;i<taille+1;i++){
		float sum=0;
		for(k=1;k<i;k++)
			sum+=(matRes[i-1][k-1])*(matRes[i-1][k-1]);
		matRes[i-1][i-1]=sqrt(this->getMatrice()[i-1][i-1]-sum);

		for(j=i+1;j<taille+1;j++){
			float sum2=0;
			for(k=1;k<i;k++)
				sum2+=matRes[i-1][k-1]*matRes[j-1][k-1];
			matRes[j-1][i-1]=(this->getMatrice()[i-1][j-1]-sum2)/(matRes[i-1][i-1]);
		}
	}

	result->setMatrice(matRes);

	return result;
}

MatriceSymDefPos* MatriceSymDefPos::transpose(){
	return this;
}
