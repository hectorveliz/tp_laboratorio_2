#include<conio.h>
#include<stdio.h>
#include<string.h>
#include "funciones.h"
#define CANT 3
int menu(){


    int op=0;



        printf("BIENVENIDO A LA APLICACION.\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&op);

        while(op<1 || op>5){
            printf("Opcion incorrecta, vuelva a ingresar una opcion entre 1 y 5\n");
            fflush(stdin);
            scanf("%d",&op);
        }


return op;


}

int obtenerEspacioLibre(EPersona lista[]){

int i=0;

for(i=0;i<MAX;i++){
    if(lista[i].estado == 0)
        return i;
         }//fin de for
return -1;
}// fin obtenerEspacioLibre

void agregarPersona(EPersona lista[]){

int lugar;
char aux[80];

lugar = obtenerEspacioLibre(lista);

if(lugar >=0){
    printf("Ingrese el nombre de la persona\n");
    fflush(stdin);
    gets(aux);
    while(strlen(aux)>50){
        printf("Ingrese un nombre mas corto");
        fflush(stdin);
        gets(aux);

    }//fin de while
    strcpy(lista[lugar].nombre,aux);
    printf("Ingrese la edad de la persona: \n");
    fflush(stdin);
    scanf("%d",&lista[lugar].edad);
    fflush(stdin);
    printf("Ingrese el dni de la persona:\n");
    fflush(stdin);
    scanf("%d",&lista[lugar].dni);
    lista[lugar].estado = 1;
}

}


void inicializar(EPersona lista[]){
int i=0;
for(i=0;i<MAX;i++){
    lista[i].estado = 0;
    }//fin de for

}// fin de inicializar




int buscarPorDni(EPersona lista[], int dni){
int i=0;
char seguir;

do{
    for(i=0;i<MAX;i++){

        if(lista[i].dni == dni)
            return i;
        }

printf("No se encuentra DNI Ingresado, desea ingresar nuevamente dni?: \n");
fflush(stdin);
scanf("%c",&seguir);

}while (seguir=='s');

return -1;
}







void borrarPersona(EPersona lista[]){

int aux, lugar;

printf("Ingrese el dni de la persona a borrar:\n");
fflush(stdin);
scanf("%d",&aux);

lugar = buscarPorDni(lista,aux);

if(lugar!=-1)
    lista[lugar].estado = 1;
else
    printf("Opcion de Borrar anulada: \n");


}

void ordenarPorNombre(EPersona lista[]){
EPersona cmb;
int i=0,j=0;
char aux[80];

printf("Ingresar Nombre para ordenar: \n");
fflush(stdin);
gets(aux);

while(strlen(aux)>50){
    printf("El nombre es más largo de lo permitido, reingrese el nombre");
    gets(aux);
    }
for(i=0;i<MAX;i++){
    for(j=i+1;j<MAX;j++){
        if(strcmp(lista[j].nombre,aux)==0){
            cmb =lista[j];
            lista[j]=lista[i];
            lista[i]=cmb;
            }// fin de if


    }//fin de J


}// Fin de for I

for(i=0;i<MAX;i++){
    printf("Nombre: %s\n",lista[i].nombre);
    printf("Edad: %d\n",lista[i].edad);
    printf("DNI: %d\n",lista[i].dni);
    getch();
    }
}


void graficar(EPersona lista[]){

int i, hasta18=0, de19a35=0, mayorDe35=0, flag=0, mayor;

  for(i=0;i<CANT;i++)
  {
      if(lista[i].edad>0 && lista[i].edad <= 18)
          hasta18=hasta18+1;
      else{

        if(lista[i].edad >18 && lista[i].edad <= 35){
            de19a35 = de19a35 +1;
        }else{
               if(lista[i].edad > 35)
                mayorDe35=mayorDe35+1;
            }
        }
  }



      if(hasta18 >= de19a35 && hasta18 >= mayorDe35){
        mayor = hasta18;
    }else{
            if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
            {
                mayor = de19a35;
            }
            else{
                mayor = mayorDe35;
                }
         }

  for(i=mayor; i>0; i--){
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= hasta18){
            printf("*");
        }
        if(i<= de19a35){
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d", hasta18, de19a35, mayorDe35);
    getch();

}
