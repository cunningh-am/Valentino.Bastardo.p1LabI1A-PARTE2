#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "bicicleta.h"
#include "servicio.h"


typedef struct
    {
     int idTrabajo;
     int idBicicleta;
     int idServicio;
     eFecha fecha;
     int isEmpty;
    }eTrabajo;

/** \brief inicializa      .isEmpty en todas las posiciones de un array eTrabajo en 1 para determinar que estan vacias
 *
 * \param lista eTrabajo*   array eTrabajo
 * \param tam int           tama�o array
 * \return int              retorna 1 en caso de que la validacion de datos este correcta, 0 en caso de que no
 *
 */
int initTrabajos(eTrabajo* lista, int tam);
/** \brief                  busca una posicion vacia dentro de un array eTrabajo
 *
 * \param lista eTrabajo*   array eTrabajo
 * \param tam int           tama�o array
 * \return int              retorna el indice dentro del array
 *
 */
int buscarJobLibre(eTrabajo* lista, int tam);
/** \brief                  permite dar un alta de trabajo, autogenerando el id, pidiendo campos como el ID de la bici y validando, para luego guardarlo en una posicion de un array eTrabajo
 *
 * \param lista eTrabajo*   array eTrabajo
 * \param tam int           tama�o array eTrabajo
 * \param jobId int*        ubicacion de memoria del ID autogenerado
 * \param listaB eBici*     array de bicicletas para poder validar que dicho ID es una bicicleta existente
 * \param tamB int          tama�o array eBicicleta
 * \param listaServ eServicio*  array de servicios, utilizado para listarlos y validar que son servicios existentes
 * \param tamS                  tama�o array servicios
 * \return int              retorna 1 en caso de que la validacion de datos este correcta, 0 en caso de que no
 *
 */
int altaTrabajo(eTrabajo* lista, int tam, int* jobId, eBici* listaB, int tamB, eServicio* listaServ, int tamS);
/** \brief                  es una bandera dinamica que se adapta dependiendo si existen trabajos cargados en isEmpty=0 o no
 *
 * \param lista eTrabajo*   array eTrabajo con el que trabaja
 * \param tam int           tama�o del array eTrabajo
 * \return int              retorna 1 en caso de que haya al menos un trabajo cargado, 0 en caso de que no haya ninguno
 *
 */
int checkTrabajoCargado(eTrabajo* lista,int tam);
/** \brief                  imprime un elemento eTrabajo en pantalla
 *
 * \param trabajo eTrabajo  array eTrabajo donde se almacena dicho elemento
 * \param listaS eServicio* array eServicio para mostrar servicio por nombre y no por ID
 * \param tamS int          tama�o array eServicio
 * \return int              retorna 1 en caso de que la validacion de datos este correcta, 0 en caso de que no
 *
 */
int mostrarTrabajo(eTrabajo trabajo,eServicio* listaS, int tamS);
/** \brief                  imprime todos los eTrabajos dentro de un array eTrabajo donde isEmpty este en 0
 *
 * \param lista eTrabajo*   array eTrabajo
 * \param tam int           tama�o array eTrabajo
 * \param listaS eServicio* array eServicio para enviarle a mostrarTrabajo()
 * \param tamS int          tama�o array eServicio
 * \return int              retorna 1 en caso de que la validacion de datos este correcta, 0 en caso de que no
 *
 */
int mostrarTrabajos(eTrabajo* lista,int tam,eServicio* listaS, int tamS);
/** \brief                  remueve de forma logica un trabajo cargado en un array eTrabajo
 *
 * \param list eTrabajo*    array eTrabajo
 * \param tam int           tama�o array eTrabajo
 * \param index int         indice del trabajo dentro del array eTrabajo
 * \param servicios eServicio* array eServicio para poder mostrarlo
 * \param tamS int             tama�o array eServicio
 * \return int              retorna 1 en caso de que la validacion de datos este correcta, 0 en caso de que no
 *
 */
//int removeTrabajo(eTrabajo* list,int tam, int index,eServicio* servicios,int tamS);
/** \brief                  utilizando su ID, busca dentro de un array eTrabajo su indice
 *
 * \param lista eTrabajo*   tama�o array eTrabajo
 * \param tam int           tama�o array eTrabajo
 * \return int              retorna 1 en caso de que la validacion de datos este correcta, 0 en caso de que no
 *
 */
int findJobByID(eTrabajo* lista, int tam);

/** \brief              permite completar la fecha en un elemento de eTrabajo
 *
 * \param x eTrabajo    trabajo donde se pondra esta fecha
 *
 */
int cargarFecha(eTrabajo* x);
/** \brief                  permite ver los trabajos relacionados a una bici, ubicada por un ID previamente ingresado
 *
 * \param lista eTrabajo*
 * \param tam int
 * \param listaS eServicio*
 * \param tamS int
 * \return int               retorna 1 en caso de que la validacion de datos este correcta, 0 en caso de que no
 *
 */
int mostrarTrabajosEnTalBici(eTrabajo* lista,int tam,eServicio* listaS, int tamS, int idElegido);
/** \brief
 *
 * \param lista eTrabajo*       permite ver a que bicicletas se le hizo un determinado servicio, incluye fecha
 * \param tam int
 * \param listaS eServicio*
 * \param tamS int
 * \param idElegido int
 * \return int                   retorna 1 en caso de que la validacion de datos este correcta, 0 en caso de que no
 *
 */
int mostrarServiciosEnBicis(eTrabajo* lista,int tam,eServicio* listaS, int tamS,int idElegido);
/** \brief                      permite ver que servicios se ejercieron en una fecha determinada, la cual es antes pedida y pasada por parametro
 *
 * \param lista eTrabajo*
 * \param tam int
 * \param listaS eServicio*
 * \param tamS int
 * \param idElegido int
 * \param idElegidoDos int
 * \param idElegidoTres int
 * \return int                   retorna 1 en caso de que la validacion de datos este correcta, 0 en caso de que no
 *
 */
int mostrarServiciosEnFecha(eTrabajo* lista,int tam,eServicio* listaS, int tamS,int idElegido, int idElegidoDos, int idElegidoTres);
#endif // TRABAJO_H_INCLUDED
