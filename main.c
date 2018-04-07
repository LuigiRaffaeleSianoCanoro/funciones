#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
UTN | Mar del Plata
-
Programaci�n 1
-
Laboratorio 1
Pr�ctico
3
-
Funciones
NOTA: todas las funciones pedidas deben recibir por par�metro la/s pila/s cargadas con los datos.
No se debe usar la funci�n leer() dentro de la funci�n, excepto en la funci�n 1
.
1. Hacer una funci�n que permita ingresar varios elementos a una Pila, tantos como quiera el
usuario.*/

void llenarPila(Pila * nombrePila)
{
    char control='s';
    while(control=='s')
    {
        leer(nombrePila);
        printf("desea continuar? S/N \n");
        fflush(stdin);
        scanf("%c",&control);
    }
}
/**2. Hacer una funci�n que pase todos los elementos de una pila a otra.*/

void pasarPila(Pila * p1, Pila * p2)
{
    while(!pilavacia(p1))
    {
        apilar(p2, desapilar(p1));
    }
}

/**3.  Hacer  una  funci�n  que  pase  todos  los  elementos  de  una  pila  a  otra,  pero  cons
ervando  el
orden.*/

void pasaPilaConservador(Pila *a,Pila *c)
{
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(a))
    {
        apilar(&aux, desapilar(a));
    }
    while(!pilavacia(&aux))
    {
        apilar(c,desapilar(&aux));
    }
}

/**4. Hacer una funci�n que encuentre el menor elemento de una pila y lo retorne.*/
int menorElemento(Pila * p)
{
    int menorElmt;
    Pila menor, aux;
    inicpila(&menor);
    inicpila(&aux);

    apilar(&menor, desapilar(p));
    while(!pilavacia(p) )
    {
        if(tope(p) < tope(&menor))
        {
            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(p));
        }
        else
        {
            apilar(&aux, desapilar(p));
        }
    }

    pasarPila(&aux, p);
    menorElmt = tope(&menor);
    return menorElmt;
}
/**5. Hacer una funci�n que pase los elementos de una pila a otra, de manera que se genere una
nueva pila ordenada. Usar la funci�n del ejercicio 4.*/

void pasarOrdenando(Pila *p, Pila *q)
{
    while(!pilavacia(p))
    {
        apilar(q,menorElemento(p));
    }
}



int main()
{
    Pila pilerson, pilaPache;

    inicpila(&pilerson);
    inicpila(&pilaPache);

    llenarPila(&pilerson);
    mostrar(&pilerson);

    pasaPilaConservador(&pilerson, &pilaPache);
    mostrar(&pilaPache);

    printf("%i",menorElemento(&pilaPache));
    mostrar(&pilaPache);

    pasarOrdenando(&pilaPache,&pilerson);
    mostrar(&pilerson);

    return 0;
}

