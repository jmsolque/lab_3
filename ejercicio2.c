// Este script contiene el codigo del ejercicio 2 del laboratorio 3

#include <stdio.h>

#define SIZE 3

int sumafila(int matriz [SIZE][SIZE], int fila){
    int suma = 0;
    for (int j = 0; j < SIZE; j++ ){    // Recorre la fila de la matriz 
        suma += matriz[fila][j];        // Suma cada elemnto de la fila
    }
    return suma;
}

int sumacolumna(int matriz [SIZE][SIZE], int columna){
    int suma = 0;
    for (int i = 0; i < SIZE; i++ ){     // Recorre la columna de la matriz
        suma += matriz[columna][i];      // Suma cada elemento de la columna 
    }
    return suma;     
}

int sumadiagonal1(int matriz [SIZE][SIZE]){
    int suma = 0;
    for (int i = 0; i < SIZE; i++ ){     // Va recorriendo la matriz sumando un elemento a cada posicion de fila y columna, por lo que se mueve sobre la diagonal
        suma += matriz[i][i];    // Va sumando cada elemento
    }
    return suma;
}

int sumadiagonal2(int matriz [SIZE][SIZE]){
    int suma = 0;
    for (int i = 0; i < SIZE; i++ ){        // Recorre la matriz sumando una posicion a la fila y restando una a la columna
        suma += matriz[i][SIZE - 1 - i];   // Suma cada elemento
    }
    return suma;
}

int magicsquare(int matriz[SIZE][SIZE]){
    int sumaobj = sumafila(matriz, 0);        // Calcula la suma iniciando en la primera fila
    for (int i = 1; i < SIZE; i++ ){
        if (sumafila(matriz, i) != sumaobj){   // Revisa todas las filas
            return 0;   // Si no es cuadrado magico se termina el programa 
        }
    }

    for (int j = 0; j < SIZE; j++){
        if (sumacolumna(matriz, j) != sumaobj){   // Revisa todas las columnas
            return 0;   // Si no es cuadrado magico se termina 
        }
    }

    if (sumadiagonal1(matriz) != sumaobj || 
         sumadiagonal2(matriz) != sumaobj){
        return 0;     // Si la suma de las diagonales es diferente a lade las filas y columnas no es cuadrado magico
    }

    return 1;  // Si llega a este punto la suma de las filas, comunas y diagonales es igual, por lo que si es un cuadrado magico
}


void printMatriz(int matriz[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){        //Suma un elemento a la fila cada vez que la posicion es menor al tamaño
        for (int j = 0; j < SIZE; j++){     //Suma un elemento a la columna cada vez que la posicion es menor al tamaño
            printf("%d ", matriz[i][j]);   // Imprime la matriz con filas i y columnas j
        }
        printf("\n");  //Salto de linea 
    }
}

int main (){
    int matriz [SIZE][SIZE] = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };

    printf("La matriz utilizada es:\n");
    printMatriz(matriz);

    if (magicsquare(matriz)){
        printf("La matriz es cuadrado magico \n");
    }
    else{
        printf("La matriz no es cuadrado magico \n");
    }
    return 0;

}




