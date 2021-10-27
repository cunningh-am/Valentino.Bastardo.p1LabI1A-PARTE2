#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biciWarehouse.h"

char marcas[5][20]={
     "Piolisima",
     "Valentino",
     "Turfito",
     "Maradona",
     "YAMAHA"
     };

int idtipos[5]={1000,1003,1003,1002,1001};

int idcolores[5]={5004,5003,5004,5002,5004};

char materiales[5][2]={"c\0","c\0","a\0","c\0","a\0"};

int hardcodearBicis(eBici* list, int tam, int cant, int* ID)
{
    int contador=-1;
    if(list!=NULL && tam>0 && cant >= 0 && ID != NULL && cant <= tam)
    {
        contador=0;
        for(int i=0;i<cant;i++)
        {
            list[i].idBici=(*ID);
            (*ID)++;
            strcpy(list[i].marca,marcas[i]);
            list[i].idTipo=idtipos[i];
            list[i].idColor=idcolores[i];
            strcpy(&list[i].material,materiales[i]);
            list[i].isEmpty=0;
            contador++;
       }
    }
    return contador;
}
