#include<iostream>
#include<string>
#include<vector>
#include"Compte.h"
#include"Cheque.h"
#include"Livret.h"

int main(){
Compte c(1000);
Cheque cc(1200,120);
Livret li(1525);


c.ajouterTitulaires("Alex Vi");
c.ajouterTitulaires("Clément Douanier Di Rousso");
cc.ajouterTitulaires("Rémi SF");
cc.ajouterTitulaires("Toto Shakespeare");

cout<<c<<endl;
cout<<cc <<"\n";

c.retirer(90);
cc.retirer(1213);
cc.deposer(5);
cc.retirerTitulaires(1);

cout<<cc<<endl;
cout<<c<<endl;

li.ajouterTitulaires("Georges J");
cout<<li<<endl;
li.retirer(24);
cout<<li<<endl;

return(0);
}


