#include<vector>
#include"Matrice.h"

Matrice::Matrice(){
}

void Matrice::setMatrice(vector<vector<double> > matrice){
	this->matrice=matrice;
}

vector<vector<double> > Matrice::getMatrice(){
	return this->matrice;
}

Matrice* Matrice::transpose(){
	Matrice* result=new Matrice();
	
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
