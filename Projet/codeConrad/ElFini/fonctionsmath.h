#ifndef FONCTIONSMATH_H
#define FONCTIONSMATH_H

#include <cmath>

class FonctionsMath
{
public:
    FonctionsMath();

    static float absValue(float x);
    static float norm_Mat_1(float ** M,int n);
    static float norm_Vector_inf(float * x,int n);
    static float ind_Vector_inf(float * x,int n);
    static float norm_Vector_2(float * x,int n);
    static float norm_Vector_1(float * x,int n);
    static float ** new_Mat_Sqr(int n);
    static float ** identity_Mat(int n);
    static void init_Vector_norm1(float * x,int n,float norm);
    static float * new_Vector(int n);
    static float * sign_Vector(float * x,int n);
    static float dot_Prod(float * x,float * y,int n);
    static float ** extern_Prod_Sqr(float *x,float * y,int n);
    static float ** scalProd_Mat_Sqr(float a,float ** A,int n);
    static float * scalProd_Vector(float a,float * A,int n);
    static float ** prod_Mat_Sqr(float ** A,float ** B,int n);
    static float * prod_MatVector_Sqr(float ** A,float *b, int n);
    static float ** minus_Mat_Sqr(float ** A,float ** B,int n);
    static float * minus_Vector(float * x,float * y,int n);
    static float * plus_Vector(float * x,float * y,int n);
    static float * extr_Vect_Mat(float ** M,int n,int j);
    static void modify_Vect_Mat(float ** M,float * v,int j,int n);
    static float * affectValues_Vector(float * b,int n);
    static float ** affectValues_Mat_Sqr(float ** A,int n);
    static float * resol_Up(float ** A,float *b,int n);
    static float * resol_ConjGrad_SymPosDef(float ** A,float * b,int n);
    static float ** transp_Mat_Sqr(float ** A,int n);
    static float * base_Vector(int i,int n);
    static float * resol_ConjGrad(float ** A,float * b,int n);
    static int integer_part(float x);
};

#endif // FONCTIONSMATH_H
