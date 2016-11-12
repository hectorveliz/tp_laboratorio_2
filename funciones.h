#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAX 3
typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);
void agregarPersona(EPersona lista[]);
int menu(void);
void inicializar(EPersona lista[]);
void borrarPersona(EPersona lista[]);
void ordenarPorNombre(EPersona lista[]);
void graficar(EPersona lista[]);

#endif // FUNCIONES_H_INCLUDED
