#include"Compte.h"

using namespace std;

#ifndef __LIVRET_h__
#define __LIVRET_h__
class Livret:public Compte{
	public:
		Livret(const double);
		virtual void retirer(const double);
};

#endif
