#include<vector>
#include<cmath>
#include<iostream>
#include"MatriceTriang.h"

MatriceTriangInf::MatriceTriangInf(){Matrice();};

vector<double> MatriceTriangInf::remontGauss(vector<double> vect){
	int n=vect.size()-1;
	vector< vector<double> > mat=this->getMatrice();
	vector<double> result(n+1,0);

	result[0]=vect[0]/mat[0][0];
	for(int k=1;k<=n;k++){
		double sum=0;
		for(int i=0;i<k;i++)
			sum+=result[i]*mat[k][i];
		result[k]=(vect[k]-sum)/mat[k][k];
	}

	return result;
};

MatriceTriangSup* MatriceTriangInf::transpose(){
	MatriceTriangSup* result=new MatriceTriangSup();
	
	vector< vector<double> > matDep=this->getMatrice();
	int taille=this->getMatrice().size();
	vector< vector<double> > matFin(taille,vector<double>(taille));
	
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++)
			matFin[j][i]=matDep[i][j];
	}

	result->setMatrice(matFin);

	return result;
}

MatriceTriangSup::MatriceTriangSup(){Matrice();};

vector<double> MatriceTriangSup::remontGauss(vector<double> vect){
	int n=vect.size()-1;
	vector< vector<double> > mat=this->getMatrice();
	vector<double> result(n+1,0);

	result[n]=vect[n]/mat[n][n];
	for(int k=n-1;k>=0;k--){
		double sum=0;
		for(int i=k+1;i<=n;i++)
			sum+=result[i]*mat[k][i];
		result[k]=(vect[k]-sum)/mat[k][k];
	}

	return result;
};

MatriceTriangInf* MatriceTriangSup::transpose(){
	MatriceTriangInf* result=new MatriceTriangInf();
	
	vector< vector<double> > matDep=this->getMatrice();
	int taille=this->getMatrice().size();
	vector< vector<double> > matFin(taille,vector<double>(taille));
	
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++)
			matFin[j][i]=matDep[i][j];
	}

	result->setMatrice(matFin);

	return result;
}

