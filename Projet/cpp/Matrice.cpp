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
