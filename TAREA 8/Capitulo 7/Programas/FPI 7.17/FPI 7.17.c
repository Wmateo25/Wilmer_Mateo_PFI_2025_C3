#include <stdio.h>
#include <string.h>

char * inversor(char *);


void main(void)
{
    char fra[50], aux[50];
    printf("\nIngrese la linea de texto: ");
    gets(fra);
    strcpy(aux, inversor(fra));
    printf("\nEscribe la linea de texto de forma inversa: ");
    puts(aux);
}

char * inversor(char *cadena)
{
    int i=0,j,lon;
    char cad;
    lon=strlen(cadena);
    j = lon-1;
    while(i < ((lon - 1) / 2))
    {
        cad = cadena[1];
        cadena [i]= cadena[j];
        cadena [j]= cad;
        i++;
        j--;
    }
    return(cadena);
}