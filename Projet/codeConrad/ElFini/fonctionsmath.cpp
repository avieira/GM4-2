#include "fonctionsmath.h"

#define PRECISION 0.000001
#define BORN_INT 1000

FonctionsMath::FonctionsMath()
{
}

float FonctionsMath::absValue(float x)
{
    if(x<0)
        return -1*x;
    else
        return x;
}

float FonctionsMath::norm_Mat_1(float ** M,int n)
{
    int i,j;
    float temp,norm1;

    temp=0;
    norm1=0;

    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
            temp=temp+absValue(M[i][j]);
        if(norm1 < temp)
            norm1=temp;
        temp=0;
    }

    return norm1;
}

float FonctionsMath::norm_Vector_inf(float * x,int n)
{
    int i;
    float norm;

    norm=0;

    for(i=0;i<n;i++)
        if(absValue(x[i]) > norm )
            norm=absValue(x[i]);

    return norm;

}

float FonctionsMath::ind_Vector_inf(float * x,int n)
{
    int i,ind;

    ind=0;

    for(i=0;i<n;i++)
        if(absValue(x[i]) > absValue(x[ind]) )
            ind=i;

    return ind;
}


float FonctionsMath::norm_Vector_2(float * x,int n)
{
    int i;
    float norm;

    norm=0;

    for(i=0;i<n;i++)
        norm=norm+x[i]*x[i];

    return sqrt(norm);
}

float FonctionsMath::norm_Vector_1(float * x,int n)
{
    int i;
    float norm;

    norm=0;

    for(i=0;i<n;i++)
        norm=norm+absValue(x[i]);

    return norm;
}

float ** FonctionsMath::new_Mat_Sqr(int n)
{
    float ** M;
    int i;
    int j;

    M= new float*[n];;
    for(int i=0;i<n;i++)
    {
        M[i] = new float[n];
        for(int j=0;j<n;j++)
            M[i][j]=0;
    }

    return M;
}

float ** FonctionsMath::identity_Mat(int n)
{
    float ** M;
    int i;

    M=new_Mat_Sqr(n);

    for(i=0;i<n;i++)
        M[i][i]=1.;

    return M;
}

void FonctionsMath::init_Vector_norm1(float * x,int n,float norm)
{
    int i;

    for(i=0;i<n;i++)
    {
        x[i]=norm/n;
    }

}

float * FonctionsMath::new_Vector(int n)
{
    float * x;
    int i;

    x = new float[n];
    for(i=0;i<n;i++)
        x[i]=0.;
    return x;
}

float * FonctionsMath::sign_Vector(float * x,int n)
{
    int i;
    float * s;

    s=new_Vector(n);

    for(i=0;i<n;i++)
    {
        if(x[i] > 0)
            s[i]=1;
        else if(x[i]==0)
            s[i]=0;
        else
            s[i]=-1;
    }

    return s;
}


float FonctionsMath::dot_Prod(float * x,float * y,int n)
{
    float scalarProduct;
    int i;

    scalarProduct=0;

    for(i=0;i<n;i++)
        scalarProduct=scalarProduct+x[i]*y[i];

    return scalarProduct;
}

float ** FonctionsMath::extern_Prod_Sqr(float *x,float * y,int n)
{
    float ** M;
    int i,j;

    M=new_Mat_Sqr(n);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            M[i][j]=x[i]*y[j];

    return M;
}

float ** FonctionsMath::scalProd_Mat_Sqr(float a,float ** A,int n)
{
    int i,j;
    float ** C;

    C=new_Mat_Sqr(n);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            C[i][j]=a*A[i][j];

    return C;
}

float * FonctionsMath::scalProd_Vector(float a,float * A,int n)
{
    int i;
    float * C;

    C=new_Vector(n);

    for(i=0;i<n;i++)
        C[i]=a*A[i];

    return C;
}

float ** FonctionsMath::prod_Mat_Sqr(float ** A,float ** B,int n)
{
    int i,j,k;
    float ** C;

    C=new_Mat_Sqr(n);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                C[i][j]=C[i][j]+A[i][k]*B[k][j];

    return C;
}

float * FonctionsMath::prod_MatVector_Sqr(float ** A,float *b, int n)
{
    int i,j;
    float * x;

    x=new_Vector(n);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            x[i]=x[i]+A[i][j]*b[j];

    return x;
}

float ** FonctionsMath::minus_Mat_Sqr(float ** A,float ** B,int n)
{
    int i,j;
    float ** C;

    C=new_Mat_Sqr(n);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            C[i][j]=A[i][j]-B[i][j];

    return C;
}

float * FonctionsMath::minus_Vector(float * x,float * y,int n)
{
    int i;
    float * z;

    z=new_Vector(n);

    for(i=0;i<n;i++)
        z[i]=x[i]-y[i];

    return z;
}


float * FonctionsMath::plus_Vector(float * x,float * y,int n)
{
    int i;
    float * z;

    z=new_Vector(n);

    for(i=0;i<n;i++)
        z[i]=x[i]+y[i];

    return z;
}

float * FonctionsMath::extr_Vect_Mat(float ** M,int n,int j)
{
    int i;
    float * x;

    x=new_Vector(n);

    for(i=0;i<n;i++)
        x[i]=M[i][j];

    return x;
}

void FonctionsMath::modify_Vect_Mat(float ** M,float * v,int j,int n)
{
    int i;

    for(i=0;i<n;i++)
        M[i][j]=v[i];

}

float * FonctionsMath::affectValues_Vector(float * b,int n)
{
    float * c;
    int i;

    c=new_Vector(n);
    for(i=0;i<n;i++)
        c[i]=b[i];
    return c;
}

float ** FonctionsMath::affectValues_Mat_Sqr(float ** A,int n)
{
    float ** B;
    int i,j;

    B=new_Mat_Sqr(n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            B[i][j]=A[i][j];
    return B;

}

float * FonctionsMath::resol_Up(float ** A,float *b,int n)
{
    int i,j;
    float *x,s;

    x=new_Vector(n);

    x[n-1]=b[n-1]/A[n-1][n-1];

    for(i=(n-2);i >= 0;i--)
    {
        s=0;
        for(j=(i+1);j<n;j++)
            s=s+A[i][j]*x[j];
        x[i]=(b[i]-s)/A[i][i];
    }
    return x;
}

float * FonctionsMath::resol_ConjGrad_SymPosDef(float ** A,float * b,int n)
{
    float * x,* r,* p,* Ap,alpha,beta,normRSqr;

    x=new_Vector(n);
    init_Vector_norm1(x,n,norm_Vector_2(b,n));
    r=minus_Vector(b,prod_MatVector_Sqr(A,x,n),n);
    p=affectValues_Vector(r,n);

    do
    {
        normRSqr=dot_Prod(r,r,n);
        Ap=prod_MatVector_Sqr(A,p,n);
        alpha=normRSqr/dot_Prod(p,Ap,n);
        x=plus_Vector(x,scalProd_Vector(alpha,p,n),n);
        r=minus_Vector(r,scalProd_Vector(alpha,Ap,n),n);
        beta=dot_Prod(r,r,n)/normRSqr;
        p=plus_Vector(r,scalProd_Vector(beta,p,n),n);
    }
    while(norm_Vector_inf(r,n)/norm_Vector_2(b,n) > PRECISION);

    return x;
}

float ** FonctionsMath::transp_Mat_Sqr(float ** A,int n)
{
    float ** B;
    int i,j;

    B=new_Mat_Sqr(n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            B[i][j]=A[j][i];
    return B;
}

float * FonctionsMath::base_Vector(int i,int n)
{
    float *x;

    x=new_Vector(n);
    x[i]=1;
    return x;
}

float * FonctionsMath::resol_ConjGrad(float ** A,float * b,int n)
{
    float * x,* r,* s,* p,* q,** tA,alpha,beta,normRSqr;

    x=new_Vector(n);
    tA=transp_Mat_Sqr(A,n);
    init_Vector_norm1(x,n,norm_Vector_2(b,n));
    s=minus_Vector(b,prod_MatVector_Sqr(A,x,n),n);
    r=prod_MatVector_Sqr(tA,s,n);
    p=affectValues_Vector(r,n);
    q=prod_MatVector_Sqr(A,p,n);

    do
    {
        normRSqr=dot_Prod(r,r,n);
        alpha=normRSqr/dot_Prod(q,q,n);
        x=plus_Vector(x,scalProd_Vector(alpha,p,n),n);
        s=minus_Vector(s,scalProd_Vector(alpha,q,n),n);
        delete [] r;
        r=prod_MatVector_Sqr(tA,s,n);
        beta=dot_Prod(r,r,n)/normRSqr;
        p=plus_Vector(r,scalProd_Vector(beta,p,n),n);
        q=prod_MatVector_Sqr(A,p,n);
    }
    while(norm_Vector_inf(s,n)/norm_Vector_2(b,n) > PRECISION);

    return x;
}

int FonctionsMath::integer_part(float x)
{
    int i;
    i=0;
    while(i<=x)
        i+=1;

    return i-1;
}

#undef PRECISION
#undef BORN_INT
