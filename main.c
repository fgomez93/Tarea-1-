#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datos
{
    char ip[20];
    int dia;
    char mes[10];
    int anio;
};

int main()
{

    char texto[1];
    char fecha[29];

    FILE *puntero;
    FILE *nuevo;

    int i;

    struct datos los_datos;

    if ((puntero =fopen("clientes.txt","r"))==NULL )
    {
        printf("El archivo no se pudo abrir!!");
    }
    else
    {


       while(!feof(puntero))
       {
            fread(texto,sizeof(char),1,puntero);
            if (*texto=='[')
            {
                fread(fecha,sizeof(char)*26,1,puntero);
                printf("\n\n%s\n",&fecha);

                if ((nuevo =fopen("fechas.txt","a"))==NULL )
                {
                    printf("El archivo no se pudo abrir!!");
                }
                else
                {
                    fwrite(fecha,sizeof(char)*27,1,nuevo);
                }
            }
       }
       fclose(puntero);
    }
    return 0;

}

