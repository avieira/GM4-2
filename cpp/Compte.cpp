#include<iostream>
#include<vector>
#include<string>
#include"Compte.h"

using namespace std;
int Compte::nombreComptes=0;

Compte::Compte(double x){
	solde=x;
	nombreComptes++;
	numeroCompte=nombreComptes;
}

Compte::Compte(const Compte &x){
	solde=x.solde;
	numeroCompte=x.numeroCompte;
	titulaires=x.titulaires;
}

void Compte::deposer(const double x){
	solde+=x;
}

void Compte::retirer(const double x){
	solde-=x;
}

void Compte::setSolde(const double x){
	solde=x;
}

double Compte::getSolde(){
	return solde;
}

int Compte::nbComptes(){
	return nombreComptes;
}

int Compte::getNumeroCompte(){
	return numeroCompte;
}

vector<string> Compte::getTitulaires(){
	return titulaires;
}

void Compte::ajouterTitulaires(const string ch){
	titulaires.push_back(ch);
}

bool Compte::retirerTitulaires(const int i){
	if(i>titulaires.size()){
		return false;
	}
	else{
		titulaires.erase(titulaires.begin()+i-1);
		return true;
	}
}

string Compte::operator [] (const int i){
	return titulaires[i];
}

ostream& operator << (ostream &out, Compte &c){
	out<<"Compte ";
	out<<c.numeroCompte<<", ";
	if(c.getTitulaires().size())
		out<<"0 titulaire : ";
	else{
		out<<c.getTitulaires().size()<<" titulaires ("<<c[0];
		for(int i=0;i<c.getTitulaires().size();i++)
			out<<", "<<c[i];
		out<<") : ";
	}
	out<<c.getSolde();
	return out;
}
