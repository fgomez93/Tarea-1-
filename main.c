#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int cantidades[24];
int numero_opcion;


void depurar_solo_fechas(FILE *posicion)
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

            //separar_hora(fecha);
            separar_dma(fecha);
        }
    }
    //fclose(ptr_fechas);
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

void funcion_hora(int hora)
{
    cantidades[hora]++;
}

int num_mes(char mes[3]){
    char *Aux[]={"Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul","Aug","Sep","Oct","Nov","Dic"};
    int i;
    for (i=0;i<12;i++){
        //printf("%s-%s",Aux[i],mes);
        if ( strcmp(Aux[i],mes)==0){
            return i+1;
        }
    }



}
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

    printf("%d-%d-%d\n",rial_dia,rial_mes,rial_anho);

}
//---------------------------------------------------------------------------------------------------//

int main()
{

    char texto[1];
    char fecha[26];
    char ruta[40];
    char opcion[6];
    int j;

    FILE *ptr_clientes;
//------------------------------MENU---------------------------------------------------
    while ((strcmp(opcion,"hora")!=0) && (strcmp(opcion,"semana")!=0) )
    {
        printf("\nIngrese opcion (hora) o (semana)\n");
        gets(opcion);

        if (strcmp(opcion, "hora"))
        {
            numero_opcion=0;
        }
        else if (strcmp(opcion,"semana"))
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

    char ruta_default[]="C:/Users/EquipoCasa/Downloads/tarea1";
    char archivo[]="/access.log";

    strcat(ruta_default,archivo);

    if ((ptr_clientes =fopen(ruta_default,"r"))==NULL )
    {
        printf("El archivo no se pudo abrir!!");
    }

    else
    {
        depurar_solo_fechas(ptr_clientes);



        fclose(ptr_clientes);
    }


    //for(j=0;j<24;j++)
    //{
    //    printf("Hora %d Cantidad %d\n",j,cantidades[j]);
    //}


    //fclose(ptr_clientes);

    printf("termine");
    return 0;

}



