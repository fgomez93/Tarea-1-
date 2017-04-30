#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int cantidades_hora[24];
long int cantidades_semana[7];


void depurar_solo_fechas(FILE *posicion, int opcion)
{
    char caracter[1];
    char fecha[26];
    //FILE *ptr_fechas;

    while(!feof(posicion))
    {

        fread(caracter,sizeof(char),1,posicion);
        if(*caracter=='[')
        {
            fread(fecha,sizeof(char)*26,1,posicion);

            /*ptr_fechas= fopen("solo_fechas.txt","a");

            fwrite(fecha,sizeof(char)*26,1,ptr_fechas);*/

            if (opcion==0)
            {
                separar_hora(fecha);
            }
            else if (opcion==1)
            {
                separar_dma(fecha);
            }

        }
    }
    //fclose(ptr_fechas);
}
//---------------------- Procesar horas -----------------------------------------

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

void funcion_hora(int hora)
{
    cantidades_hora[hora]++;
}

//-------------------------Procesar semanas-------------------------------------------------------


void separar_dma(char registro[26]){
    char *otro_registro= registro;
    char vacio[]="";
    char dia[2],mes[3],anho[4];
    char *primero,*segundo,*tercero,*cuarto;
    int rial_dia,rial_mes,rial_anho;
    //--------DIA
    strcpy(dia,vacio);
    primero=otro_registro[0];
    segundo=otro_registro[1];
    strcat(dia,&primero);
    strcat(dia,&segundo);
    //printf("%s",dia);
    rial_dia=atoi(dia);
    //--------MES
    strcpy(mes,vacio);
    primero=otro_registro[3];
    segundo=otro_registro[4];
    tercero=otro_registro[5];
    strcat(mes,&primero);
    strcat(mes,&segundo);
    strcat(mes,&tercero);
    //printf("%s",mes);
    //rial_mes=12;
    rial_mes=num_mes(mes);
    //--------ANHO
    strcpy(anho,vacio);
    primero=otro_registro[7];
    segundo=otro_registro[8];
    tercero=otro_registro[9];
    cuarto=otro_registro[10];
    strcat(anho,&primero);
    strcat(anho,&segundo);
    strcat(anho,&tercero);
    strcat(anho,&cuarto);
    //printf("%s\n",anho);
    rial_anho=atoi(anho);
    //rial_dia= atoi(dia);
    //rial_mes= num_mes(mes);
    //rial_anho=atoi(anho);

    //printf("%d-%d-%d\n",rial_dia,rial_mes,rial_anho);

    calendario(rial_dia,rial_mes,rial_anho);

}


int num_mes(char mes[3]){
    char *Aux[]={"Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul","Aug","Sep","Oct","Nov","Dic"};
    int i;

    for(i=0; i<12; i++)
    {
        if (strcmp(Aux[i],mes)==0)
        {
            return i+1;
        }
    }

}



//-------------------------------SUPER FUNCION DE CALENDARIO-------------------------------------------

void calendario(int d, int m, int a)
{
    int regular[]={0,3,3,6,1,4,6,2,5,0,3,5};
    int bisiesto[]={0,3,4,0,2,5,0,3,6,1,4,6};

    int result1,result2,result3,result4,result5;


    if((a%4==0) && !(a%100==0))
    {
        m=bisiesto[m-1];
    }
    else if (a%400==0)
    {
        m=bisiesto[m-1];
    }
    else
    {
        m=regular[m-1];
    }

    result1=(a-1)%7;
    result2=(a-1)/4;
    result3=(3*(((a-1)/100)+1))/4;
    result4=(result2-result3)%7;
    result5=d%7;
    d=(result1+result4+m+result5)%7;

    switch(d)
    {
        case 0:
            funcion_dia(6);//Domingo
            break;
        case 1:
            funcion_dia(0);//Lunes
            break;
        case 2:
            funcion_dia(1);//Martes
            break;
        case 3:
            funcion_dia(2);//Miercoles
            break;
        case 4:
            funcion_dia(3);//Jueves
            break;
        case 5:
            funcion_dia(4);//Viernes
            break;
        case 6:
            funcion_dia(5);//Sabado
            break;
    }
}

void funcion_dia(int dia)
{
    cantidades_semana[dia]++;
}




//---------------------------------------------------------------------------------------------------//

int main()
{

    char texto[1];
    char fecha[26];
    char ruta[40];
    char opcion[6];
    int numero_opcion;

    FILE *ptr_clientes;

//------------------------------MENU---------------------------------------------------

    while ((strcmp(opcion,"hora")!=0) && (strcmp(opcion,"semana")!=0) )
    {
        printf("Ingrese opcion (hora) o (semana)\n");
        gets(opcion);

        if (strcmp(opcion, "hora")==0)
        {
            numero_opcion=0;
        }
        else if (strcmp(opcion,"semana")==0)
        {
            numero_opcion=1;
        }
        else
        {
            printf("Ingrese una opcion valida!!!!!\n");
        }
    }

    printf("Ingrese la ruta del archivo\n");
    gets(ruta);

//-----------------------------------------------------------------------------------------

    char archivo[]="/access.log";

    strcat(ruta,archivo);

    if ((ptr_clientes =fopen(ruta,"r"))==NULL )
    {
        printf("El archivo no se pudo abrir!!");
    }

    else
    {
        depurar_solo_fechas(ptr_clientes, numero_opcion);

        fclose(ptr_clientes);
    }



    printf("termine :)");
    return 0;

}




