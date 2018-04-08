#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
UTN | Mar del Plata
-
Programación 1
-
Laboratorio 1
Práctico
3
-
Funciones
NOTA: todas las funciones pedidas deben recibir por parámetro la/s pila/s cargadas con los datos.
No se debe usar la función leer() dentro de la función, excepto en la función 1
.
1. Hacer una función que permita ingresar varios elementos a una Pila, tantos como quiera el
usuario.*/

void llenarPila(Pila*nombrePila){
    char control='s';
    while(control=='s'){
        leer(nombrePila);
        printf("desea continuar? S/N \n");
        fflush(stdin);
        scanf("%c",&control);
    }
}

/**2. Hacer una función que pase todos los elementos de una pila a otra.*/

void pasarPila(Pila*p1, Pila*p2){
    while(!pilavacia(p1)){
        apilar(p2, desapilar(p1));
    }
}

/**3.  Hacer  una  función  que  pase  todos  los  elementos  de  una  pila  a  otra,  pero  cons
ervando  el
orden.*/

void pasarPilaCons(Pila*a,Pila*c){
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(a)){
        apilar(&aux, desapilar(a));
    }
    while(!pilavacia(&aux)){
        apilar(c,desapilar(&aux));
    }
}

/**4. Hacer una función que encuentre el menor elemento de una pila y lo retorne.*/
int menorElemento(Pila*p){
    int menorElmt;
    Pila menor, aux;
    inicpila(&menor);
    inicpila(&aux);

    apilar(&menor, desapilar(p));
    while(!pilavacia(p)){
        if(tope(p) < tope(&menor)){
            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(p));
        }else{
            apilar(&aux, desapilar(p));
        }
    }

    pasarPila(&aux, p);
    menorElmt = tope(&menor);
    return menorElmt;
}
/**5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
nueva pila ordenada. Usar la función del ejercicio 4.*/

void pasarOrdenando(Pila*p, Pila*q){
    while(!pilavacia(p)){
        apilar(q,menorElemento(p));
    }
}

/**6. Hacer una función que inserte en una pila ordenada un nuevo elemento, conservando el orden de esta. */

void ubicarEn(int x, Pila*p){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(p) && tope(p)>x){
        apilar(&aux,desapilar(p));
    }
    apilar(&aux,x);
    while(!pilavacia(p)){
        apilar(&aux,desapilar(p));
    }
    while(!pilavacia(&aux)){
        apilar(p,desapilar(&aux));
    }
}

/**7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
nueva pila ordenada. Usar la función del ejercicio 6.
*/

void ubicarPila(Pila*p, Pila*q){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(q)){
        apilar(&aux,desapilar(q));
    }
    pasarOrdenando(&aux,q);
    while(!pilavacia(p)){
        ubicarEn(desapilar(p), q);
    }
}
/**8. Hacer una función que sume y retorne los dos primeros elementos de una pila
(tope y anterior), sin alterar su contenido*/

int sumDosPrimEl(Pila p){
    int suma;
    Pila aux;
    inicpila(&aux);

    if(!pilavacia(&p)){
        apilar(&aux, desapilar(&p));
    } else {
        printf("La pila esta vacia\n");
    }

    if(!pilavacia(&p)){
        suma = tope(&p) + tope(&aux);
    } else {
        suma = 0 + tope(&aux);
    }
    return suma;
}

/**9. Hacer una función que calcule el promedio de los elementos de una pila,
para ello hacer también una función que calcule la suma, otra para la cuenta y
otra que divida. En total son cuatro funciones, y la función que calcula el
promedio invoca a las otras 3.*/

int sumarPila(Pila p){
    int suma = 0;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&p)){
        suma += tope(&p);
        apilar(&aux, desapilar(&p));
    }
    return suma;
}

int contarPila(Pila p){
    int i = 0;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&p)){
        apilar(&aux, desapilar(&p));
        i++;
    }
    return i;
}
float dividir(int a, int b){
    float cociente;
    cociente = (float)a / (float)b;
    return cociente;
}
float promedioPila(Pila p){
    float promedio;
    promedio = dividir(sumarPila(p),contarPila(p));
    return promedio;
}




int main(){
    Pila pilerson, pilaPache;

    inicpila(&pilerson);
    inicpila(&pilaPache);

    printf("Ejercicio 1\n");
    llenarPila(&pilerson);
    mostrar(&pilerson);

    /*
    printf("Ejercicio 3\n");
    pasarPilaCons(&pilerson, &pilaPache);
    mostrar(&pilaPache);
    */
    /*
    printf("Ejercicio 4\n");
    printf("%i",menorElemento(&pilaPache));
    mostrar(&pilaPache);
    */
    /*
    printf("Ejercicio 5\n");
    pasarOrdenando(&pilaPache,&pilerson);
    mostrar(&pilerson);
    */
    /*
    printf("Ejercicio 6\n");
    ubicarEn(11, &pilerson );
    mostrar(&pilerson);
    */
    /*
    printf("Ejercicio 7\n");
    llenarPila(&pilaPache);
    mostrar(&pilaPache);
    ubicarPila(&pilerson, &pilaPache);
    mostrar(&pilaPache);
    */
    /*
    printf("Ejercicio 8\n");
    int suma = sumDosPrimEl(pilerson);
    printf("Suma de los dos primeros elementos: %i",suma);
    mostrar(&pilerson);
    */
    /*
    printf("Ejercicio 9\n");
    printf("Promedio de pilerson: %f.2\n", promedioPila(pilerson));
    */


    return 0;
}
