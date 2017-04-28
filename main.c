#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cantidades[24];

void funcion_hora(int);

int main()
{

    char texto[1];
    char fecha[26];

    FILE *ptr_clientes;
    FILE *ptr_fechas;

    int i;
    int j;


    if ((ptr_clientes =fopen("clientes.txt","r"))==NULL )
    {
        printf("El archivo no se pudo abrir!!");
    }

    else
    {


        crear_solo_fechas(ptr_clientes);

       /*while(!feof(ptr_clientes))
       {
            fread(texto,sizeof(char),1,ptr_clientes);
            if (*texto=='[')
            {
                fread(fecha,sizeof(char)*26,1,ptr_clientes);
                printf("\n%s\n",fecha);

                if ((ptr_fechas =fopen("solo_fechas.txt","a"))==NULL )
                {
                    printf("El archivo no se pudo abrir!!");
                }
                else
                {


                    fwrite(fecha,sizeof(char)*27,1,ptr_fechas);*/

                    /*char *otra_fecha= fecha;
                    char vacio1[]="";
                    char hora[2];
                    char *creoqeno,*creoqeno2;
                    strcpy(hora,vacio1);
                    //creoqeno=otra_fecha[12];
                    //printf("%c\n",*creoqeno);
                    creoqeno=otra_fecha[12];
                    creoqeno2=otra_fecha[13];
                    strcat(hora,&creoqeno);
                    strcat(hora,&creoqeno2);
                    //strcat(hora,&otra_fecha[13]);
                    //printf("%c\n",otra_fecha[12]);
                    //printf("%s",&hora);
                    //funcion_hora(fecha,nuevo);

                    /*int i;
                    char dias[11];
                    char hora[11];
                    char *token=strtok(fecha,":");

                    while (token!=NULL)
                    {
                        *hora=token;
                        printf("%s\n",hora);
                        token=strtok(NULL,":");
                    }*/

                    //funcion_hora(atoi(hora));
                    //fclose(ptr_fechas);

                //}
            //}

       //}

      for(j=0;j<24;j++)
        {
            printf("Hora %d Cantidad %d\n",j,cantidades[j]);
        }


        fclose(ptr_clientes);
        //remove("solo_fechas.txt"); //borrar el archivo solo_fechas!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        /*printf("%d\n",strlen(cantidades));
        printf("%d\n",cantidades[5]);
        printf("%d\n",cantidades[6]);
        printf("%d\n",cantidades[23]);*/



    }
    return 0;

}

void funcion_hora(int hora)
{
    cantidades[hora]++;
}

void crear_solo_fechas(FILE *posicion)
{
    char caracter[1];
    char fecha[26];
    FILE *ptr_fechas;


    while(!feof(posicion))
    {
        fread(caracter,sizeof(char),1,posicion);
        if(*caracter=='[')
        {
            fread(fecha,sizeof(char)*26,1,posicion);

            ptr_fechas= fopen("solo_fechas.txt","a");

            fwrite(fecha,sizeof(char)*26,1,ptr_fechas);

            separar_hora(fecha);
        }
    }
    fclose(ptr_fechas);
}

void separar_hora(char registro[26])
{
    char *otro_registro= registro;
    char vacio[]="";
    char hora[2];
    char *primero,*segundo;
    int rial_hora;

    strcpy(hora,vacio);
    primero=otro_registro[12];
    segundo=otro_registro[13];
    strcat(hora,&primero);
    strcat(hora,&segundo);

    rial_hora= atoi(hora);
    funcion_hora(rial_hora);

}
