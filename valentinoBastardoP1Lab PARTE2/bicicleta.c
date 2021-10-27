#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bicicleta.h"


int initBicis(eBici* lista, int tam)
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
int buscarLibre(eBici* lista, int tam)
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
int altaBici(eBici* lista, int tam, int* nextId,eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor)
{
    int ret=0;
    if(lista!=NULL&&tam>0&&nextId!=NULL&&listaTipo!=NULL&&tamTipo>0&&listaColor!=NULL&&tamColor>0)
    {
        int actualIndex;
        system("cls");
        actualIndex=buscarLibre(lista,tam);
        printf("\nEl ID de la nueva bici es %d.\n",*nextId);
        lista[actualIndex].idBici=(*nextId);
        (*nextId)++;
        system("pause");
        system("cls");
        ingresarStr("marca",lista[actualIndex].marca,20);
        listarTipos(listaTipo,tamTipo);
        printf("\n");
        ingresarIntPos("tipo",&lista[actualIndex].idTipo,1000,1003);
        listarColores(listaColor,tamColor);
        printf("\n");
        ingresarIntPos("color",&lista[actualIndex].idColor,5000,5004);
        ingresarMaterial(&lista[actualIndex].material);

        lista[actualIndex].isEmpty=0;
        printf("\nBicicleta cargada con exito.\n");
        mostrarBici(lista[actualIndex],listaTipo,tamTipo,listaColor,tamColor);
        system("pause");
        ret=1;
    }
    return ret;
}
int ingresarMaterial(char* campo)
{
    int ret=0;
    char auxChar;

    if(campo!=NULL)
    {
        printf("Ingrese material: ('c' / 'a') \n");
        fflush(stdin);
        scanf("%c",&auxChar);
        auxChar=tolower(auxChar);
        while(auxChar!='c'&&auxChar!='a')
        {
            printf("Material invalido. Reingresar.\n");
            fflush(stdin);
            scanf("%c",&auxChar);
        }
        *campo=auxChar;
        ret=1;
    }
    return ret;
}
int mostrarBici(eBici bici,eTipo* listaT, int tamT, eColor* listaC, int tamC)
{
    if(listaT!=NULL&&tamT>0&&listaC!=NULL&&tamC>0)
    {
        char descTipo[20];
        char descColor[20];
        char material[20];


        cargarTipo(bici.idTipo,listaT,tamT,descTipo);
        cargarColor(bici.idColor,listaC,tamC,descColor);
        if(bici.material=='c')
        {
            strcpy(material, "Carbono");
        }
        else
        {
            strcpy(material, "Aluminio");
        }

        printf("\n----------------------\n");
        printf("[ID]:        %d \nMARCA:       %s \nTIPO:        %s \nCOLOR:       %s \nMATERIAL:    %s \n\n",
               bici.idBici, bici.marca, descTipo,descColor,material);

        return 1;

    }
    return 0;
}
int mostrarBicis(eBici* lista, int tam, eTipo* listaT,int tamT, eColor* listaC, int tamC)
{
    int ret=0;
    if(lista!=NULL&&tam>0&&listaT!=NULL&&tamT>0&&listaC!=NULL&&tamC>0)
    {
        ret=1;
        system("cls");
        printf("---------LISTA DE BICICLETAS---------\n");
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0)
            {
                mostrarBici(lista[i],listaT,tamT,listaC,tamC);
                printf("------------------------------------\n");
            }
        }
    }
    return ret;
}
int checkBiciCargada(eBici* lista,int tam)
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
int findBiciByID(eBici* lista, int tam)
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
            else if(lista[i].idBici==userInput)
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
int editBici(eBici* list, int tam, int index, eTipo* tipos,int tamT,eColor* colores,int tamC)
{
    int ret=0;
    if(list!=NULL&&tam>0&&index>-1)
    {
        int opcion;
        printf("------------------------------------\n");
        mostrarBici(list[index],tipos,tamT,colores,tamC);
        printf("------------------------------------\n");
        printf("Que desea modificar?\n[1]-Marca\n[2]-Tipo\n[3]-Color\n[4]-Material\n");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            ingresarStr("marca",list[index].marca,20);
            printf("\nMarca cambiada exitosamente. \n");
            system("pause");
            break;
        case 2:
            listarTipos(tipos,tamT);
            ingresarIntPos("tipo",&list[index].idTipo,1000,1003);
            printf("\nTipo cambiado exitosamente. \n");
            system("pause");
            break;
        case 3:
            listarColores(colores,tamC);
            ingresarIntPos("color",&list[index].idColor,5000,5004);
            printf("\nColor cambiado exitosamente. \n");
            system("pause");
            break;
        case 4:
            ingresarMaterial(&list[index].material);
            printf("\nMaterial cambiado exitosamente. \n");
            system("pause");
            break;
        }
        ret=1;
    }
    return ret;
}
int removeBici(eBici* list,int tam, int index,eTipo* tipos,int tamT,eColor* colores, int tamC)
{
    int ret=0;
    if(list!=NULL && tam>0 && index>(-1))
    {
        char rta;
        ret=1;
        printf("------------------------------------\n");
        mostrarBici(list[index],tipos,tamT,colores,tamC);
        printf("------------------------------------\n");
        printf("\n Desea eliminar permanentemente esta bici? s/n \n");
        fflush(stdin);
        scanf("%c",&rta);
        if(rta=='s')
        {
            list[index].isEmpty=1;

            printf("Bici eliminada exitosamente.\n");
            system("pause");
        }
        else
        {
            printf("No se eliminara esta bici.\n");
            system("pause");
        }

    }
    return ret;
}
int mostrarBiciColor(eBici* list,int tam,eTipo* tipos,int tamT,eColor* colores, int tamC,int colorElegido)
{
    int ret=0;
    int flag=1;
    char color[20];
    cargarColor(colorElegido,colores,tamC,color);
    if(list!=NULL&&tam>0&&tipos!=NULL&&tamT>0&&colores!=NULL&&tamC>0)
    {
        ret=1;
        system("cls");
        printf("---------LISTA DE BICICLETAS---------\n");
        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty==0&& list[i].idColor==colorElegido)
            {
                flag=0;
                mostrarBici(list[i],tipos,tamT,colores,tamC);
                printf("------------------------------------\n");
            }
        }
        if(flag)
        {
            printf("No se encontraron bicicletas de color %s.\n",color);
        }
    }
    return ret;
}
int mostrarBiciTipo(eBici* list,int tam,eTipo* tipos,int tamT,eColor* colores, int tamC,int tipoElegido)
{
    int ret=0;
    int flag=1;
    char tipo[20];
    cargarTipo(tipoElegido,tipos,tamT,tipo);
    if(list!=NULL&&tam>0&&tipos!=NULL&&tamT>0&&colores!=NULL&&tamC>0)
    {
        ret=1;
        system("cls");
        printf("---------LISTA DE BICICLETAS---------\n");
        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty==0&& list[i].idTipo==tipoElegido)
            {
                flag=0;
                mostrarBici(list[i],tipos,tamT,colores,tamC);
                printf("------------------------------------\n");
            }
        }
        if(flag)
        {
            printf("No se encontraron bicicletas del tipo %s.\n",tipo);
        }
    }
    return ret;
}
int cantidadMaterial(eBici* list,int tam)
{
    int ret=0;
    int cantC=0;
    int cantA=0;
    char ganador[55];
    int cantGanador;
    if(list!=NULL)
    {
        ret=1;
        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty)
            {
                continue;
            }
            else if(list[i].material=='c')
            {
                cantC++;
            }
            else
            {
                cantA++;
            }
        }
        system("cls");
        if(cantC>cantA)
        {
            strcpy(ganador,"Hay mas bicicletas de carbono, con un total de: ");
            cantGanador=cantC;
        }
        else if(cantC==cantA)
        {
            strcpy(ganador,"Hubo un empate, teniendo cada material un numero de : ");
            cantGanador=cantC;
        }
        else
        {
            strcpy(ganador,"Hay mas bicicletas de aluminio, con un total de: ");
            cantGanador=cantA;
        }
        printf("%s %d \n",ganador,cantGanador);
        system("pause");
    }
    return ret;
}
int mostrarBicisSeparadasTipo(eBici* lista, int tam, eTipo* listaT,int tamT, eColor* listaC, int tamC)
{
    int ret=0;
    char descTipo[20];

    if(lista!=NULL&&tam>0&&listaT!=NULL&&tamT>0&&listaC!=NULL&&tamC>0)
    {
        ret=1;
        system("cls");
        for(int x=1000; x<1004; x++)
        {
            cargarTipo(x,listaT,tamT,descTipo);
            printf("*--------LISTA DE BICICLETAS %s--------*\n",descTipo);
            for(int i=0; i<tam; i++)
            {
                if(lista[i].isEmpty==0&&lista[i].idTipo==x)
                {
                    mostrarBici(lista[i],listaT,tamT,listaC,tamC);
                    printf("------------------------------------\n");
                }
            }
        }

    }
    return ret;
}
int mostrarBiciTipoYColor(eBici* list,int tam,eTipo* tipos,int tamT,eColor* colores, int tamC,int tipoElegido,int colorElegido)
{
    int ret=0;
    int flag=1;
    char tipo[20];
    cargarTipo(tipoElegido,tipos,tamT,tipo);
    char color[20];
    cargarColor(colorElegido,colores,tamC,color);
    int contador=0;
    if(list!=NULL&&tam>0&&tipos!=NULL&&tamT>0&&colores!=NULL&&tamC>0)
    {
        ret=1;
        system("cls");
        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty==0&& list[i].idTipo==tipoElegido && list[i].idColor==colorElegido)
            {
                contador++;
                flag=0;
            }
        }
        if(flag)
        {
            printf("No se encontraron bicicletas con esas caracteristicas.\n");
        }
        else
        {
            printf("Hay %d bicicletas %s de color %s.\n",contador,tipo,color);
        }
    }
    return ret;
}
int colorMasElegido(eBici* list,int tam)
{
    int ret=0;
    int cantGris=0;
    int cantBlanco=0;
    int cantAzul=0;
    int cantNegro=0;
    int cantRojo=0;

    int cantMayor=0;

    if(list!=NULL)
    {
        ret=1;
        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty)
            {
                continue;
            }
            switch(list[i].idColor)
            {
            case 5000:
                cantGris++;
                break;
            case 5001:
                cantBlanco++;
                break;
            case 5002:
                cantAzul++;
                break;
            case 5003:
                cantNegro++;
                break;
            case 5004:
                cantRojo++;
                break;
            }
        }
        system("cls");
        int array[5]= {cantGris,cantBlanco,cantAzul,cantNegro,cantRojo};
        char color[20];
        for(int i=0; i<5; i++)
        {
            if(array[i]>cantMayor)
            {
                cantMayor=array[i];
            }
        }
        printf("Color/es mas elegido/s por clientes:\n\n");
        for(int i=0; i<5; i++)
        {
            if(array[i]==cantMayor)
            {
                switch(i)
                {
                case 0:
                    strcpy(color,"gris");
                    printf("-Hay %d bicicletas de color %s.\n",cantMayor,color);
                    break;
                case 1:
                    strcpy(color,"blanco");
                    printf("-Hay %d bicicletas de color %s.\n",cantMayor,color);
                    break;
                case 2:
                    strcpy(color,"azul");
                    printf("-Hay %d bicicletas de color %s.\n",cantMayor,color);
                    break;
                case 3:
                    strcpy(color,"negro");
                    printf("-Hay %d bicicletas de color %s.\n",cantMayor,color);
                    break;
                case 4:
                    strcpy(color,"rojo");
                    printf("-Hay %d bicicletas de color %s.\n",cantMayor,color);
                    break;

                }
            }
        }

        system("pause");
    }
    return ret;
}

