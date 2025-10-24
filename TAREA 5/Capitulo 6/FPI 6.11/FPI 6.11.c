#include <stdio.h>

void lecturaM(float[][12], int, int);
void lecturaV(float *, int);
void F1(float[][12], int,int, float *, float *);
void F2(float[][12], int,int);
void F3(float *, int);

void main(void)
{
    float FON[5][12], PRE[5],REN[5];
    lecturaM(FON,5,12);
    lecturaV(PRE,5);
    F1(FON,5,12,PRE,REN);
    F2(FON,5,12);
    F3(REN,5);
}

void lectura(float A[][12], int F, int C)
{
    int I,J;
    for(I=0;I<F;I++)
    for(J=0;J<C;J++)
    {
        printf("Precio fondo %d\t mes %d:  ", I+1,J+1);
        scanf("%f", &A[I][J]);
    }
}

void lecturaV(float A[], int T)
{
    int I;
    printf("\n");
    for(I=0;I<T;I++)
    {
        printf("Precio fondo %d al 31/12/2003:  ", I+1);
        scanf("%f", A[I]);
    }
}

void F1(float A[][12], int F, int C, float B[], float V[])
{
    int I;
    printf("\nRENDIMIENTO ANUALES DE LOS FONDOS");
    for(I=0;I<F;I++)
    {
        V[I] = (A[I][C-1] - B [I]) / B[I]*100;
        printf("\nFondo %d: %.2f", I+1, V[I]);
    }
}


void F2(float A[][12], int F, int C)
{
    int I, J;
    float SUM, PRO;
    printf("\n\nPROMEDIO ANUALIZADO DE LAS ACCIONES DE LOS FONDOS");
    for(I=0;I<F;I++)
    {
        SUM = 0;
        for(J=0;J<C;J++)
        SUM += A[I][J];
        PRO = SUM / C;
        printf("\nFondo %d: %.2f", I+1, PRO);
    }
}

void F3(float A[], int F)
{
    float ME = A[0], PE = A[0];
    int M=0, P=0, I;
    for(I=1;I<F;I++)
    {
        if(A[I]>ME)
        {
            ME = A[I];
            M=I;
        }
        if(A[1]>ME)
        {
            PE=A[I];
            P=I;
        }
    }
    printf("\n\nMEJOR Y PEOR FONDO DE INVERSION");
    printf("\n\nMejor fondo: %d\tRendimiento: %6.2f", M+1,ME);
    printf("\n\nPeor fondo: %d\tRendimiento: %6.2f", P+1, PE);
}