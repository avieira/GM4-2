#include"Livret.h"

using namespace std;

Livret::Livret(const double sol) : Compte(sol){}

void Livret::retirer(const double x){
	Compte::retirer(x+1);
}
