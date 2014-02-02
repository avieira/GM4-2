#include<string>
#include"MatriceTriang.h"

class MatriceSymDefPos : public Matrice{
	public:MatriceSymDefPos();
	public:MatriceTriangInf* decompoCholesk();
	public:MatriceSymDefPos* transpose();
};
