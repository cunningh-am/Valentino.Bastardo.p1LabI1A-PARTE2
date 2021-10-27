#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "miBiblioteca.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "biciWarehouse.h"
#include "jobWarehouse.h"

#define TAMTIP 4
#define TAMCOL 5
#define TAMSERV 4
#define TAMBICI 100
#define TAMJOB 100

int main()
{
    eTipo tipos[TAMTIP] =
    {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"}
    };
    eColor colores[TAMCOL] =
    {
        {5000, "Gris"},
        {5001, "Blanco"},
        {5002, "Azul"},
        {5003, "Negro"},
        {5004, "Rojo"}
    };
    eServicio servicios[TAMSERV] =
    {
        {20000, "Limpieza",30},
        {20001, "Parche",400},
        {20002, "Centrado",500},
        {20003, "Cadena",450}
    };

    int iterador=1;
    int bandera=0;

    eBici listaBicis[TAMBICI];
    initBicis(listaBicis,TAMBICI);

    eTrabajo listaTrabajos[TAMJOB];
    initTrabajos(listaTrabajos,TAMJOB);

    int nextID=1;
    int jobID=100;
    int idElegido;
    int idElegidoDos;
    int idElegidoTres;
    int idElegidoBici;
    hardcodearBicis(listaBicis,TAMBICI,5,&nextID);
    hardcodearTrabajos(listaTrabajos,TAMJOB,5,&jobID);
    do
    {
        switch(menu())
        {
        case 1:
            altaBici(listaBicis,TAMBICI,&nextID,tipos,TAMTIP,colores,TAMCOL);
            break;
        case 2:
            if(checkBiciCargada(listaBicis,TAMBICI))
            {
                editBici(listaBicis,TAMBICI,findBiciByID(listaBicis,TAMBICI),tipos,TAMTIP,colores,TAMCOL);
            }
            else
            {
                printf("Cargue primero una bici.\n");
                system("pause");
            }
            break;
        case 3:
            if(checkBiciCargada(listaBicis,TAMBICI))
            {
                removeBici(listaBicis,TAMBICI,findBiciByID(listaBicis,TAMBICI),tipos,TAMTIP,colores,TAMCOL);
            }
            else
            {
                printf("Cargue primero una bici.\n");
                system("pause");
            }
            break;
        case 4:
            if(checkBiciCargada(listaBicis,TAMBICI))
            {
                mostrarBicis(listaBicis,TAMBICI,tipos,TAMTIP,colores,TAMCOL);
                system("pause");
            }
            else
            {
                printf("Cargue primero una bici.\n");
                system("pause");
            }
            break;
        case 5:
            listarTipos(tipos,TAMTIP);
            system("pause");
            break;
        case 6:
            listarColores(colores,TAMCOL);
            system("pause");
            break;
        case 7:
            listarServicios(servicios,TAMSERV);
            system("pause");
            break;
        case 8:
            if(checkBiciCargada(listaBicis,TAMBICI))
            {
                altaTrabajo(listaTrabajos,TAMJOB,&jobID,listaBicis,TAMBICI,servicios,TAMSERV);
            }
            else
            {
                printf("Cargue primero una bici.\n");
                system("pause");
            }
            break;
        case 9:
            if(checkTrabajoCargado(listaTrabajos,TAMJOB))
            {
                mostrarTrabajos(listaTrabajos,TAMJOB,servicios,TAMSERV);
                system("pause");
            }
            else
            {
                printf("Cargue primero un trabajo.\n");
                system("pause");
            }
            break;
        case 10:
            if(checkBiciCargada(listaBicis,TAMBICI))
            {
                switch(submenu())
                {

                case 1:
                    listarColores(colores,TAMCOL);
                    ingresarIntPos("ID del color",&idElegido,5000,5004);
                    mostrarBiciColor(listaBicis,TAMBICI,tipos,TAMTIP,colores,TAMCOL,idElegido);
                    system("pause");
                    break;

                case 2:
                    listarTipos(tipos,TAMTIP);
                    ingresarIntPos("ID del tipo",&idElegido,1000,1003);
                    mostrarBiciTipo(listaBicis,TAMBICI,tipos,TAMTIP,colores,TAMCOL,idElegido);
                    system("pause");
                    break;

                case 3:
                    cantidadMaterial(listaBicis,TAMBICI);
                    break;
                case 4:
                    mostrarBicisSeparadasTipo(listaBicis,TAMBICI,tipos,TAMTIP,colores,TAMCOL);
                    system("pause");
                    break;
                case 5:
                    listarTipos(tipos,TAMTIP);
                    ingresarIntPos("ID del tipo",&idElegido,1000,1003);
                    listarColores(colores,TAMCOL);
                    ingresarIntPos("ID del color",&idElegidoDos,5000,5004);
                    mostrarBiciTipoYColor(listaBicis,TAMBICI,tipos,TAMTIP,colores,TAMCOL,idElegido,idElegidoDos);
                    system("pause");
                    break;
                case 6:
                    colorMasElegido(listaBicis,TAMBICI);
                    break;
                case 7:
                    if(checkTrabajoCargado(listaTrabajos,TAMJOB))
                    {
                        printf("Ingrese ID de la bici: \n");
                        fflush(stdin);
                        scanf("%d",&idElegidoBici);

                        for(int i=0; i<TAMBICI; i++)
                        {
                            if(listaBicis[i].isEmpty==1)
                            {
                                continue;
                            }
                            else if(listaBicis[i].idBici==idElegidoBici)
                            {
                                bandera=1;
                                break;
                            }
                        }


                        if(bandera)
                        {
                            mostrarTrabajosEnTalBici(listaTrabajos,TAMJOB,servicios,TAMSERV,idElegidoBici);
                            system("pause");
                        }
                        else
                        {
                            printf("\nNo se puede realizar el alta con ID de bicicleta erroneo.\n\n");
                            system("pause");
                        }
                    }
                    else
                    {
                        printf("Cargue primero un trabajo.\n");
                        system("pause");
                    }
                    break;
                case 9:
                    if(checkTrabajoCargado(listaTrabajos,TAMJOB))
                    {
                        listarServicios(servicios,TAMSERV);
                        ingresarIntPos("ID del servicio",&idElegido,20000,20003);
                        mostrarServiciosEnBicis(listaTrabajos,TAMJOB,servicios,TAMSERV,idElegido);
                        system("pause");
                    }
                    else
                    {
                        printf("Cargue primero un trabajo.\n");
                        system("pause");
                    }
                    break;
                case 10:
                    if(checkTrabajoCargado(listaTrabajos,TAMJOB))
                    {

                        ingresarIntPos("dia",&idElegido,1,31);
                        ingresarIntPos("mes",&idElegidoDos,1,12);
                        ingresarIntPos("anio",&idElegidoTres,1817,2023);
                        mostrarServiciosEnFecha(listaTrabajos,TAMJOB,servicios,TAMSERV,idElegido,idElegidoDos,idElegidoTres);
                        system("pause");
                    }
                    else
                    {
                        printf("Cargue primero un trabajo.\n");
                        system("pause");
                    }
                    break;
                case 11:
                    break;
                default:
                    printf("Invalido. Ingrese otra opcion.\n");
                    system("pause");
                    break;
                }
            }
            else
            {
                printf("Cargue primero una bici.\n");
                system("pause");
            }
            break;
        case 11:
            if(salirABM())
            {
                printf("Decidiste salir.\n");
                iterador=0;
            }
            else
            {
                printf("Salida cancelada.\n");
                system("pause");
            }
            break;

        default:
            printf("Invalido. Ingrese otra opcion.\n");
            system("pause");
            break;
        }
    }
    while(iterador==1);








    return 0;
}
int hardcodearTrabajos(eTrabajo* list, int tam, int cant, int* ID)
{
    int idservicios[5]= {20000,20001,20002,20003,20002};
    int idbicis[5]= {1,2,3,4,5};
    eFecha fechas[5]= {{10,12,2025},{4,8,2004},{27,11,2022},{28,11,2022},{14,4,2021}};
    int contador=-1;
    if(list!=NULL && tam>0 && cant >= 0 && ID != NULL && cant <= tam)
    {
        contador=0;
        for(int i=0; i<cant; i++)
        {
            list[i].idTrabajo=(*ID);
            (*ID)++;
            list[i].idServicio=idservicios[i];
            list[i].idBicicleta=idbicis[i];
            list[i].fecha=fechas[i];

            list[i].isEmpty=0;
            contador++;
        }
    }
    return contador;
}
