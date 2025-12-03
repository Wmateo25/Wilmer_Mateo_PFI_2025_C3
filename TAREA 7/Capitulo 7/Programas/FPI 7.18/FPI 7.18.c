#include <stdio.h>


void inversor (char *);

void main(void)
{
    char fra[50];
    printf("\nIngrese la linea de texto: ");
    gets(fra);
    printf("\nEscribe la linea de texto en forma inversa: ");
    inversor (fra);
}

void inversor (char *cadena)
{
    if(cadena[0] != '0')
    {
        inversor(&cadena[1]);
        putchar(cadena[0]);
    }
}