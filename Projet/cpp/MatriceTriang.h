#include<vector>
#include"Matrice.h"

class MatriceTriangSup;

class MatriceTriangInf : public Matrice{
	public:MatriceTriangInf();
	public:vector<double> remontGauss(vector<double> vect);
	public:MatriceTriangSup* transpose();
};

class MatriceTriangSup : public Matrice{
	public:MatriceTriangSup();
	public:vector<double> remontGauss(vector<double> vect);
	public:MatriceTriangInf* transpose();
};
