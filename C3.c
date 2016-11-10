#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*Definimos la estructura de un numero complejo */
struct TipoComplejo{

    float real;
    float imaginaria;

};

/* Funcion que calcula la suma de dos numeros complejos */
struct TipoComplejo Suma(struct TipoComplejo complejo1, struct TipoComplejo complejo2){

    struct TipoComplejo aux;

    aux.real = complejo1.real + complejo2.real;
    aux.imaginaria = complejo1.imaginaria +complejo2.imaginaria;

    return aux;
}

/* Funcion que calcula el producto de dos numeros complejos */
struct TipoComplejo Multiplicacion (struct TipoComplejo complejo1, struct TipoComplejo complejo2){

    struct TipoComplejo aux;

    aux.real = (complejo1.real*complejo2.real)-(complejo1.imaginaria*complejo2.imaginaria);
    aux.imaginaria = (complejo1.real*complejo2.imaginaria)+(complejo1.imaginaria*complejo2.real);

    return aux;

}

/* Funcion que calcula el conjugado de un numero complejo */
struct TipoComplejo Conjugado (struct TipoComplejo complejo1){

    struct TipoComplejo aux;

    aux.real=complejo1.real;
    aux.imaginaria=-complejo1.imaginaria;

    return aux;
}

/* Funcion que imprime un numero complejo de la forma (r,i) */
void ImprimeNumeroComplejo (struct TipoComplejo complejo1){

    printf("\n(%.2f,%.2f)\n",complejo1.real,complejo1.imaginaria);

}

int main(){

    struct TipoComplejo num_comp;
    struct TipoComplejo num_comp2;

    num_comp.real=2;
    num_comp.imaginaria=5;
    num_comp2.real=3;
    num_comp2.imaginaria=6;

    printf("\n Suma:\n");
    ImprimeNumeroComplejo(Suma(num_comp,num_comp2));
    printf("\nConjugado:\n");
    ImprimeNumeroComplejo(Conjugado(num_comp));
    printf("\nProducto:\n");
    ImprimeNumeroComplejo(Multiplicacion(num_comp, num_comp2));

    return 0;
}
