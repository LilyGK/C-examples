#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define DIM_FIL 50
#define DIM_COL 50

/* Función que intercambia dos valores en una matriz, dadas las posiciones de estos */
void Intercambia_valores_Matriz (int m[][DIM_COL], int fil1, int col1, int fil2, int col2){

    int aux;

    m[fil1][col1]=aux;
    m[fil1][col1]=m[fil2][col2];
    m[fil2][col2]=aux;

}


/* Primero vamos a diseñar una función que calcule la matriz traspuesta de una matriz cuadrada */
/* no aplicable a una matriz con distinto numero de columnas que de filas */
void MatrizCuadrada_traspuesta (int m[][DIM_COL], int util_fil, int util_col){

    int i,j;

    for (i=0; i<util_fil; i++)
        for (j=i; j<util_col; j++)                      /* Empieza en j=i ya que los anteriores ya se han intercambiado */
            Intercambia_valores_Matriz(m,i,j,j,i);

}

/*Funcion que copia una matriz en otra */
void CopiaMatriz(int moriginal[][DIM_COL], int mcopia[][DIM_COL], int utilfil, int utilcol){

    int i,j;

    for(i=0; i<utilfil; i++);
        for (j=0; j<utilcol; j++)
            mcopia[i][j] = moriginal[i][j];
}

/* Funcion que comprueba si dos vectores int son iguales */
int Iguales_VectoresINT (int vector1[], int vector2[], int longitud1, int longitud2){

    int iguales,i,aux;
    aux=0;

    if (longitud1 != longitud2)         /* Si la longitud de los vectores no es la misma para los dos*/
            iguales = 0;                    /* no son iguales */
    else{
        for (i=0; i<longitud1; i++){
            if (vector1[i]==vector2[i])
                aux++;
        }
        if (aux==longitud1)
            iguales = 1;
        else
            iguales = 0;
    }


    return (iguales);
}

/* Funcion que compara si dos matrices son iguales */

int Matrices_iguales (int m1[][DIM_COL], int m2[][DIM_COL], int util_fil1, int util_col1, int util_fil2, int util_col2){

    int i1,i2,j1,j2,k1,k2,iguales;
    int v1[2500],v2[2500];                      /* Ya que la matriz mas grande es 50x50 */

    k1=0;
    k2=0;
    for (i1=0; i1<util_fil1; i1++){
        for (j1=0; j1<util_col1; j1++){
            m1[i1][j1]=v1[k1];
            k1++;
        }
    }
    for (i2=0; i2<util_fil2; i2++){
        for(j2=0; j2<util_col2; j2++){
            m2[i2][j2]=v2[k2];
            k2++;
        }
    }
    iguales=Iguales_VectoresINT(v1,v2,util_fil1*util_col1,util_fil2*util_col2);

    return (iguales);

}

/* Función que comprueba si una matriz es simetrica */
int Matriz_simetrica (int matriz[][DIM_COL],int utilfil, int utilcol){

    int simetrica,iguales;
    int maux[DIM_FIL][DIM_COL];

    CopiaMatriz(matriz,maux,utilfil,utilcol);

    if (utilfil != utilcol)
        simetrica=0;                                        /* Ya que la matriz no es cuadrada, condicion para
                                                            /* que sea simetrica */
    else{
        MatrizCuadrada_traspuesta(matriz,utilfil,utilcol);
        iguales=Matrices_iguales(matriz,maux,utilfil,utilcol,utilfil,utilcol);
        if (iguales)
            simetrica=1;
        else
            simetrica=0;
    }

    return (simetrica);
}

int main(){

    int matriz[DIM_FIL][DIM_COL]={{1,2,3},{2,1,4},{3,4,1}};
    int simetrica;

    simetrica=Matriz_simetrica(matriz,3,3);

    if (simetrica)
        printf("La matriz es simetrica");
    else
        printf("La matriz no es simetrica");

    return 0;

}
