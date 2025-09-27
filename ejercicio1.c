// Este script contiene el codigo del ejercicio 1

#include <stdio.h>

int factorial (int n){
    int i = 1;
    while (n > 1){
        i = i * n;
        n = n - 1;  // Se elimina el int que generaba el error en el codigo
    }
    return i;
}

int main (int argc, char *argv[]){

    int numero;    // Define la variable numero 
    printf("Ingrese el numero al que desea calcular el factorial: ");
    scanf("%d", &numero);  // Recibe el numero y lo guarda en la variable numero

    int resultado = factorial(numero);  // Guarda en resultado el resultado d ela funcion factorial con el numero de la variable numero
    printf("%d! = %d\n", numero, resultado);  // Impime el resultado 

    return 0;
}

