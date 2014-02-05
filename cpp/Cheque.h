#include"Compte.h"

using namespace std;

#ifndef __CHEQUE_h__
#define __CHEQUE_h__
class Cheque:public Compte{
	private: 
		double decouvert;

	public:
		Cheque(const double, const double);
};

#endif
