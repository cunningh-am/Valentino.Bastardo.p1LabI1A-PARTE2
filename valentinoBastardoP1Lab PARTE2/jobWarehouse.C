#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jobWarehouse.h"


int idservicios[5]={20000,20001,20002,20003,20002};
int idbicis[5]={1000,1003,1003,1002,1001};
eFecha fechas[5]={{10,11,2002},{10,11,2002},{10,11,2002},{10,11,2002}};


int hardcodearTrabajos(eTrabajo* list, int tam, int cant, int* ID)
{
    int contador=-1;
    if(list!=NULL && tam>0 && cant >= 0 && ID != NULL && cant <= tam)
    {
        contador=0;
        for(int i=0;i<cant;i++)
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
