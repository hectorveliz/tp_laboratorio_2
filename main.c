#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
char seguir;
int opcion =0;

EPersona lista[MAX];
inicializar(lista);

do{
system("cls");
opcion = menu();


        switch(opcion)
        {
            case 1:
                    agregarPersona(lista);
                    printf("Desea continuar S/N: \n");
                    fflush(stdin);
                    scanf("%c",&seguir);
                break;
            case 2:
                    borrarPersona(lista);
                    printf("Desea continuar S/N: \n");
                    fflush(stdin);
                    scanf("%c",&seguir);
                break;
            case 3:
                    ordenarPorNombre(lista);
                    printf("Desea continuar S/N: \n");
                    fflush(stdin);
                    scanf("%c",&seguir);
                break;
            case 4:
                    graficar(lista);

                break;
            case 5:
                seguir = 'n';
                break;
        }
    }while(seguir=='s');

    return 0;
}
