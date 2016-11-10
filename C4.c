#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Definimos la estructura de un rectangulo */
struct Rectangulo{

    float base;
    float altura;

};

/* Funcion que calcula el area de un rectangulo */
float AreaRectangulo (struct Rectangulo rectangulo1){

    int area;

    area = rectangulo1.altura * rectangulo1.base;

    return area;
}

/* Funcion que calcula el perimetro de un rectangulo */
float PerimetroRectangulo (struct Rectangulo rectangulo1){

    int perimetro;

    perimetro = (2*rectangulo1.altura)+(2*rectangulo1.base);

    return(perimetro);

}

/* Funcion que dados dos rectangulos devuelve cual de ellos es mayor */
int Rectangulo_mas_grande (struct Rectangulo rectangulo1, struct Rectangulo rectangulo2){

    float area1,area2;
    int grande;

    area1=AreaRectangulo(rectangulo1);
    area2=AreaRectangulo(rectangulo2);

    if (area1>area2)
        grande = 1;                             /*La función devolverá 1 si el primer rectangulo */
    else if (area2>area1)                       /* introucido en la funcion es mas grande, 2 si es */
        grande = 2;                             /* el segundo introducido y  si son iguales */
    else
        grande = 0;


    return (grande);
}

/* Funcion que detrmina si dos rectangulos son identicos */

int IdenticosRectangulo (struct Rectangulo rectangulo1, struct Rectangulo rectangulo2){

    float area1,area2,perimetro1,perimetro2;
    int identicos;

    area1 = AreaRectangulo(rectangulo1);
    area2 = AreaRectangulo(rectangulo2);
    perimetro1 = PerimetroRectangulo(rectangulo1);
    perimetro2 = PerimetroRectangulo(rectangulo2);

    if (area1=area2 && perimetro1==perimetro2)
        identicos=1;
    else
        identicos=0;

    return identicos;

}

/* Funcion que intercambia los datos de dos variables tipo rectangulo */
void IntercambiaRectangulos (struct Rectangulo *rectangulo1, struct Rectangulo *rectangulo2){

    struct Rectangulo aux;

    aux = *rectangulo1;
    *rectangulo1 = *rectangulo2;
    *rectangulo2 = aux;
}

/* Funcion que devuelve la funcion posicion del minimo de un vector */
int PosMinimo (const float v[], int izda, int dcha){

    int posicion_minimo;
    float minimo;
    int i;

    minimo = v[izda];
    posicion_minimo = izda;
    for (i=izda+1 ; i <= dcha ; i++){
        if (v[i] < minimo){
            minimo = v[i];
            posicion_minimo = i;
        }
    }
    return posicion_minimo;
}
/* Funcion que intercambia dos posiciones de un vector */
void IntercambiaFloat(float *a, float *b){
    float aux;
    aux = (*a);
    (*a) = (*b);
    (*b) = aux;
}

/* Funcion que ordena un vector intercambiando valores y realza los mismos cambios en otro vector struct */
void Ordena_areasyrectangulos(float v[], struct Rectangulo rectangulos[], int util_v){

    int pos_min,izda;

        for (izda=0 ; izda<util_v-1 ; izda++){
            pos_min = PosMinimo(v, izda, util_v-1);
            IntercambiaFloat(&v[izda], &v[pos_min]);
            IntercambiaRectangulos(&rectangulos[izda], &rectangulos[pos_min]);
        }
}
/* Funcion que dado un vector de rectangulos los ordene de mayor a menor */
void OrdenaRectangulos (struct Rectangulo rectangulos[], int utilv){

    int i;
    float areas[100];

    for (i=0; i<utilv; i++)
        areas[i]=AreaRectangulo(rectangulos[i]);

    Ordena_areasyrectangulos(areas,rectangulos,utilv);

}

int main(){

    struct Rectangulo rectangulos[100];
    float area0,perimetro0;
    int mayor, identicos;

    rectangulos[0].altura=5;
    rectangulos[0].base=4;
    rectangulos[1].altura=3;
    rectangulos[1].base=2;
    rectangulos[2].altura=4;
    rectangulos[2].base=3;

    /* APARTADO A */
    area0=AreaRectangulo(rectangulos[0]);
    printf("\na) El area del rectangulo del vector rectangulos[0] es: %f\n ",area0);

    /* APARTADO B */
    perimetro0=PerimetroRectangulo(rectangulos[0]);
    printf("\nb) El perimetro del rectangulo del vector rectangulos[0] es: %f\n ", perimetro0);

    /* APARTADO C */
    mayor = Rectangulo_mas_grande(rectangulos[0], rectangulos[1]);
    if (mayor==1)
        printf("\nc) rectangulos[0] es mayor que rectangulos[1]\n");
    else if (mayor==2)
        printf("\nc) rectangulos[1] es mayor que rectangulos[0]\n");
    else if (mayor == 0)
        printf("\nc) rectangulos[0] y rectangulos[1] tienen el mismo area\n");

    /* APARTADO D */
    identicos=IdenticosRectangulo(rectangulos[1], rectangulos[2]);
    if (identicos)
        printf("\nd) rectangulos[1] y rectangulos[2] son identicos");
    else
        printf("\nd) rectangulos[1] y rectangulos[2] no son identicos");

    /* APARTADO E y F, se ordenan los triangulos de mayor a menor del vector rectangulos */
    printf("\nAntes de ordenar:\n");
    printf("\nArea de rectangulos[0]=%f",AreaRectangulo(rectangulos[0]));
    printf("\nArea de rectangulos[1]=%f",AreaRectangulo(rectangulos[1]));
    printf("\nArea de rectangulos[2]=%f",AreaRectangulo(rectangulos[2]));
    OrdenaRectangulos(rectangulos, 3);
    printf("\nDespues de ordenar:\n");
    printf("\nArea de rectangulos[0]=%f",AreaRectangulo(rectangulos[0]));
    printf("\nArea de rectangulos[1]=%f",AreaRectangulo(rectangulos[1]));
    printf("\nArea de rectangulos[2]=%f",AreaRectangulo(rectangulos[2]));

    return 0;
}


