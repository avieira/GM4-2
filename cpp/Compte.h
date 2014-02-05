#include<iostream>
#include <vector>
#include <string>

using namespace std;

#ifndef __COMPTE_h__
#define __COMPTE_h__
class Compte{
	private: 
		double solde;
		static int nombreComptes;
		int numeroCompte;
		vector<string> titulaires;

		void setSolde(const double);

	public:
		Compte(const double);
		Compte(const Compte &);
		virtual ~Compte();

		template <typename U>
		virtual void deposer(const U);

		template<typename U>
		virtual void retirer(const U);

		virtual double getSolde();
		static int nbComptes();
		virtual int getNumeroCompte();
		virtual vector<string> getTitulaires();
		virtual void ajouterTitulaires(const string);
		virtual bool retirerTitulaires(const int);
		virtual string operator [] (const int);
		virtual friend ostream& operator <<(ostream &out, Compte &c);
};

#endif
