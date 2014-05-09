#ifndef SOMMET_H
#define SOMMET_H

class Sommet
{
public:
    int	numero,dimension;
    float *coordonnees; //VECTOR

    Sommet(int num);
    void setNumero(int num);
    int getNumero();
};

#endif // SOMMET_H
