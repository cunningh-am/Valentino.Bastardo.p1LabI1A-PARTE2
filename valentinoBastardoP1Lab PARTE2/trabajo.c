#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"

int initTrabajos(eTrabajo* lista, int tam)
{
    int ret=0;
    if(lista!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty=1;
        }
        ret=1;
    }
    return ret;
}
int buscarJobLibre(eTrabajo* lista, int tam)
{
    int libre=-1;
    if(lista!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==1)
            {
                libre=i;
                break;
            }
        }
    }
    return libre;
}
int altaTrabajo(eTrabajo* lista, int tam, int* jobId, eBici* listaB, int tamB, eServicio* listaServ, int tamS)
{
    int ret=0;
    if(lista!=NULL&&tam>0&&jobId!=NULL&&listaB!=NULL&&tamB>0&&listaServ!=NULL&&tamS>0)
    {
        int actualIndex;
        int idBici=0;
        int bandera=0;

        system("cls");
        actualIndex=buscarJobLibre(lista,tam);
        printf("\nEl ID del nuevo trabajo es %d.\n",*jobId);
        lista[actualIndex].idTrabajo=(*jobId);

        system("pause");
        system("cls");

        printf("Ingrese ID de la bici: \n");
        fflush(stdin);
        scanf("%d",&idBici);

        for(int i=0; i<tam; i++)
        {
            if(listaB[i].isEmpty==1)
            {
                continue;
            }
            else if(listaB[i].idBici==idBici)
            {
                bandera=1;
                break;
            }
        }


        if(bandera)
        {
            lista[actualIndex].idBicicleta=idBici;
        }
        else
        {
            printf("\nNo se puede realizar el alta con ID de bicicleta erroneo.\n\n");
            system("pause");
            return -1;
        }
        listarServicios(listaServ,tamS);

        ingresarIntPos("servicio",&lista[actualIndex].idServicio,20000,20003);

        cargarFecha(&lista[actualIndex]);

        lista[actualIndex].isEmpty=0;
        (*jobId)++;
        printf("\nTrabajo cargado con exito.\n");

        system("pause");
        ret=1;
    }
    return ret;
}
int checkTrabajoCargado(eTrabajo* lista,int tam)
{
    int check=0;
    if(lista!= NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0)
            {
                check=1;
                return check;
                break;
            }

        }
    }
    return check;
}
int mostrarTrabajo(eTrabajo trabajo,eServicio* listaS, int tamS)
{
    if(listaS!=NULL&&tamS>0)
    {


        char descServ[20];
        cargarServicio(trabajo.idServicio,listaS,tamS,descServ);





        printf("\n------------------------------------\n");
        printf("[ID]:            %d \nID BICICLETA:    %d \nSERVICIO:        %s \nFECHA:            %d/%d/%d \n",
               trabajo.idTrabajo, trabajo.idBicicleta, descServ, trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);

        return 1;

    }
    return 0;
}
int mostrarTrabajos(eTrabajo* lista,int tam,eServicio* listaS, int tamS)
{
    int ret=0;
    if(lista!=NULL&&tam>0&&listaS!=NULL&&tamS>0)
    {
        ret=1;
        system("cls");
        printf("---------LISTA DE TRABAJOS---------\n");
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0)
            {
                mostrarTrabajo(lista[i],listaS,tamS);
                printf("------------------------------------\n");
            }
        }
    }
    return ret;
}
/*int removeTrabajo(eTrabajo* list,int tam, int index,eServicio* servicios,int tamS)
{
    int ret=0;
    if(list!=NULL && tam>0 && index>(-1)&&servicios!=NULL&&tamS>0)
    {
        char rta;
        ret=1;
        printf("------------------------------------\n");
        mostrarTrabajo(list[index],servicios,tamS);
        printf("------------------------------------\n");
        printf("\n Desea eliminar permanentemente este trabajo? s/n \n");
        fflush(stdin);
        scanf("%c",&rta);
        if(rta=='s')
        {
            list[index].isEmpty=1;

            printf("Trabajo eliminada exitosamente.\n");
            system("pause");
        }
        else
        {
            printf("No se eliminara este trabajo.\n");
            system("pause");
        }

    }
    return ret;
}*/
int findJobByID(eTrabajo* lista, int tam)
{
    int posicion=-1;

    if(lista!=NULL&&tam>0)
    {
        int userInput;
        printf("Ingrese ID que desea modificar: ");
        fflush(stdin);
        scanf("%d",&userInput);

        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==1)
            {
                continue;
            }
            else if(lista[i].idTrabajo==userInput)
            {
                posicion=i;
                break;
            }
        }
        if(posicion==(-1))
        {
            printf("No se encontro dicho ID.\t");
            system("pause");
        }
    }
    return posicion;
}
int cargarFecha(eTrabajo* x)
{
    if(x!=NULL)
    {
        fflush(stdin);
        ingresarIntPos("dia",&x->fecha.dia,1,31);
        ingresarIntPos("mes",&x->fecha.mes,1,12);
        ingresarIntPos("anio",&x->fecha.anio,1817,2023);
        return 1;
    }

    return 0;
}
int mostrarTrabajosEnTalBici(eTrabajo* lista,int tam,eServicio* listaS, int tamS,int idElegido)
{
    int ret=0;
    if(lista!=NULL&&tam>0&&listaS!=NULL&&tamS>0)
    {
        ret=1;
        system("cls");
        printf("---------LISTA DE TRABAJOS EN BICI %d---------\n",idElegido);
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0&&lista[i].idBicicleta==idElegido)
            {
                mostrarTrabajo(lista[i],listaS,tamS);
                printf("------------------------------------\n");
            }
        }
    }
    return ret;
}
int mostrarServiciosEnBicis(eTrabajo* lista,int tam,eServicio* listaS, int tamS,int idElegido)
{
    int ret=0;
    if(lista!=NULL&&tam>0&&listaS!=NULL&&tamS>0)
    {
        char nombreServicio[30];
        cargarServicio(idElegido,listaS,tamS,nombreServicio);

        ret=1;
        system("cls");
        printf("---------LISTA DE BICIS CON SERVICIO %s---------\n",nombreServicio);
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0&&lista[i].idServicio==idElegido)
            {
                printf("El dia %d/%d/%d se le realizo %s a la bici cuyo ID es: %d \n----------------------------------------------\n",lista[i].fecha.dia,lista[i].fecha.mes,lista[i].fecha.anio,nombreServicio,lista[i].idBicicleta);
            }
        }
    }
    return ret;
}
int mostrarServiciosEnFecha(eTrabajo* lista,int tam,eServicio* listaS, int tamS,int idElegido, int idElegidoDos, int idElegidoTres)
{
    int ret=0;
    if(lista!=NULL&&tam>0&&listaS!=NULL&&tamS>0)
    {
        char nombreServicio[30];


        ret=1;
        system("cls");
        printf("---------LISTA DE SERVICIOS EN FECHA %s---------\n",nombreServicio);
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0&&lista[i].fecha.dia==idElegido&&lista[i].fecha.mes==idElegidoDos&&lista[i].fecha.anio==idElegidoTres);
            {
                cargarServicio(lista[i].idServicio,listaS,tamS,nombreServicio);
                printf("El dia %d/%d/%d se realizo: %s \n----------------------------------------------\n",lista[i].fecha.dia,lista[i].fecha.mes,lista[i].fecha.anio,nombreServicio);
            }
        }
    }
    return ret;
}
