#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define DIM_FIL 50
#define DIM_COL 50


/* Funcion que imprime una matriz bidimensional */
void ImprimeMatriz(int m[][DIM_COL] , int utilFil,int utilCol){
    int fil,col;

    for (fil=0 ; fil<utilFil ; fil++){
        for (col=0 ; col<utilCol ; col++)
        printf("%d ", m[fil][col]);
    printf("\n");
    }
}

/* Funcion que transforma una columna de una matriz en un vector */
void ColumnadeMatriz_vector (int m[][DIM_COL], int v[], int utilfil, int columna){

    int i,j;

    for (i=0; i<utilfil; i++){
        v[i]=m[i][columna];
        j++;
    }
}

/* Funcion que calcula el producto escalar de dos vectores de igual longitud */
int Producto_escalar_vectores(int v1[], int v2[], int utilvectores){

    int i,aux,resultado=0;

    for (i=0; i<utilvectores; i++){
        aux=v1[i]*v2[i];
        resultado=resultado+aux;
    }

    return (resultado);
}

/* Función que calcula el producto de dos matrices, una mxn y otra nxm */
/* que tiene como resultado una matriz mxm */
void MultiplicaMatrices(int m1[][DIM_COL], int m2[][DIM_COL], int mresultado[][DIM_COL], int utilfil1, int utilcol1, int utilfil2, int utilcol2){

    int i,j,k,p,utilfilresultado,utilcolresultado;      /* Se considera que m1 es la matriz que multiplica por la izquierda*/
    int valor,vaux[DIM_FIL];

    if (utilcol1 == utilfil2){                          /* Condicion para que se puedan multiplicar las matrices */

        utilfilresultado=utilfil1;
        utilcolresultado=utilcol2;                       /* Vector auxiliar que sera la columna de la segunda matriz */

        for (i=0; i<utilfilresultado; i++)
            for (j=0; j<utilcolresultado; j++){
                ColumnadeMatriz_vector(m2,vaux,utilfil2,j);                     /* Bucle for que va haciendo el producto */
                valor=Producto_escalar_vectores(m1[i],vaux,utilcol1);           /* escalra de cada fila con cada columna */
                mresultado[i][j]=valor;                                         /* y asignandolo a su posicion en la matriz */
            }                                                                   /* resultado */
    }
    else
        printf("\nLas matrices no se pueden multiplicar\n");
}

int main(){

    int m1[DIM_FIL][DIM_COL]={{5,2,3}};
    int m2[DIM_FIL][DIM_COL]={{1,2},{5,6},{2,4}};
    int m1xm2[DIM_FIL][DIM_COL];

    MultiplicaMatrices(m1,m2,m1xm2,1,3,3,2);
    printf("\nLa multiplicacion de las dos matrices es:\n");
    ImprimeMatriz(m1xm2,1,2);

    return 0;
}
