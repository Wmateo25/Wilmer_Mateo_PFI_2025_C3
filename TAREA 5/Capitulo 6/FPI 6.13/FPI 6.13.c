#include <stdio.h>

const int MES = 12;
const int DEP = 3;
const int AÑO = 8;

void lectura (float [MES][DEP][AÑO], int, int, int );
void funcion1(float [MES][DEP][AÑO],int,int,int);
void funcion2(float [MES][DEP][AÑO],int,int,int);
void funcion3(float [MES][DEP][AÑO],int,int,int);


void main(void)
{
    float PRO[MES][DEP][AÑO];
    lectura(PRO,MES,DEP,AÑO);
    funcion1(PRO,MES,DEP,2);
    funcion2(PRO,MES,DEP,AÑO);
    funcion3(PRO,MES,DEP,AÑO);
}

void lectura(float A[][DEP][AÑO], int F, int C, int P)
{
    int K,I,J;
    for(K=0;K<P;K++)
    for(I=0;I<F;I++)
    for(J=0;J<C;J++)
    {
        printf("AÑO: %d\tMes: %d\tDepartamento: %d", K+1,I+1,J+1);
        scanf("%f",&A[I][J][K]);
    }
}

void funcion1(float A[][DEP][AÑO],int F, int C, int P)
{
    int I, J;
    float SUM = 0.0;
    for(I=0;I<F;I++)
    for(J=0;J<C;J++)
    SUM += A[I][J][P-1];
    printf("\n\nVentas totales de la empresa en el segundo AÑO: %.2f", SUM);
}

void funcion2(float A[][DEP][AÑO], int F,int C, int P)
{
    int I,J;
    float SUM1 = 0, SUM2 = 0, SUM3 =0;
    for(I=0;I<F;I++)
    for(J=0;J<C;J++)
    switch(J+1)
    {
        case 1: SUM1 += A[I][J][P-1];
        break;
        case 2: SUM2 +=A[I][J][P-1];
        break;
        case 3: SUM3 += A[I][J][P-1];
        break;
    }
    if(SUM1>SUM2)
    if(SUM1>SUM3)
    {
        printf("\n\nDepartamento con mayorees ventas en el ultimo AÑO: hilos");
        printf("Ventas : %.2f",SUM1);
    }
    else
    {
        printf("\n\nDepartamento con mayorees ventas en el ultimo AÑO: licra");
        printf("Ventas : %.2f",SUM3);
    }
    else
    if(SUM2>SUM3)
    {
        printf("\n\nDepartamento con mayorees ventas en el ultimo AÑO: lanas");
        printf("Ventas : %.2f",SUM2);
    }
    else
    {
        printf("\n\nDepartamento con mayorees ventas en el ultimo AÑO: licra");
        printf("Ventas : %.2f",SUM3);
    }
}

void funcion3(float A[][DEP][AÑO], int F, int C, int P)
{
    int K,I,J,DE,ME,AN;
    float VEN = -1.0;
    for(K=0;K<P;K++)
    for(I=0;I<F;I++)
    for(J=0;J<C;J++)
    if (A[I][J][K]>VEN)
    {
        VEN=A[1][J][K];
        DE=J;
        ME=I;
        AN=K;
    }
    printf("\n\nDepartamento: %d\tMes: %d\tAÑO: %d", DE+1,AN+1);
    printf("\tVentas:%.2f", VEN);
}