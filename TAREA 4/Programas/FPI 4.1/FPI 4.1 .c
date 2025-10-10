#include <stdio.h>
/* Cube-1.
El programa calcula el cubo de los 10 primeros numeros naturales con la ayuda de una funcion. En la 
solucion del problema se utiliza una variable global,  aunque esto, como veremos mas adelante,
no es muy recomendable.  */

int cubo (void);     /* Prototipo de funcion.  */
int I;              /*  Variable goblal.  */


void main (void)
{
    int CUB;
    for (I = 1; I <= 10; I++)
    {
        CUB = cubo ();                 /* Llamada a la funcion cubo.  */
        printf("\nEl cubo de %d es: %d", I, CUB);
    }
}


int cubo (void)            
/* Declaracion de la funcion.  */
{
    return (I*I*I);
}

