// Este script contiene el codigo del ejercicio 2 del laboratorio 3
// En esta modificacion se hace que se genere una matriz aleatoria
// En esta modfica para que el tamaño de la matriz "SIZE" cambie 


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3  // Cambio el tamaño de la matriz 
 

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
            printf("%d ", matriz[i][j]);   
        }
        printf("\n");  //Salto de linea 
    }
}

void randomMatriz(int matriz[SIZE][SIZE]){    // Esta funcion genera una matriz cuadrada aleatoria
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            matriz[i][j] = rand() % 10 + 0;  // Escoge numeros aleatorios ente 0 y 10 para tener mas posibilidad de tener un cuadrado magico en el ejemplo 
        }
    }
}

int main (){
    srand(time(NULL));   // Hace que los numeros no se repitan en la misma linea 
    printf("\nLas siguientes matrices son del tamaño %d x %d \n", SIZE, SIZE);
    
    for (int prueba = 1; prueba <= 3; prueba++){   // Genera la contidad de pruebas dentro del rango de 1 a 3
        int matrizAleatoria[SIZE][SIZE];
        randomMatriz(matrizAleatoria);     // Aplica la funcion que genera una matriz aleatroia 

        printf("\n La matriz generada aleatoriamente #%d: \n", prueba);   //Imprime las matrices generadas aleatoriamente
        printMatriz(matrizAleatoria);

        if (magicsquare(matrizAleatoria)){
            printf("La matriz  #%d es cuadrado magico \n", prueba);    // Revisa si la matriz es cuadrada magica y da el mesnaje
        }
        else{
            printf("La matriz #%d NO es cuadrado magico \n", prueba);   //Si la matriz no es cuadrada magica da el mensaje
        }

    }
    return 0;

}








