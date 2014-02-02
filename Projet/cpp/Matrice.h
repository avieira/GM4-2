#include<vector>
using namespace std;

class Matrice{
	private:vector< vector<double> > matrice;

	public:Matrice();
	public:void setMatrice(vector<vector<double> > matrice);
	public:vector<vector<double> > getMatrice();
	public:Matrice* transpose();
};
