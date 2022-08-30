/*
    Desafío EY Para TTT Campus - Marsh Technical Exam

    - Juanito quiere cruzar el río, para cruzarlo debe saltar por las piedras.
    - El río es una serie de piedras, cada piedra tiene un número que indica la posición
    - Al saltar puede saltar una o dos piedras, no más
    - Debe evitar los lugares sin piedras
    - Los huecos en el agua están determinados por los 1 en un array de longitud 7, es decir
    su índice va de 0 a 6. Ej: C=[0,1,0,0,0,1,0] 


    IMPORTANTE: Para correr el programa en windows, se debe ejecutar el archivo con el comando:
        gcc ey-challenge.c -o ey-challenge
        ./ey-challenge
    
    - Parámetros de la función:
        La función recibe un parámetro C[i] que contiene "n" enetros binarios describiendo las rocas y huecos en el agua.
        Donde 0<=i<n
    - Formato de salida: imprime la cantidad MÍNIMA de saltos necesarios para ganar el juego
*/

#include <stdlib.h>
#include <stdio.h>
#include<Windows.h>

// Declaración de funciones
void llenarArray(int C[], int N);
void mostrarArray(int C[], int N);
void predictorDeSaltos(int C[], int N);

int main(){
    // Declaro las variables
    int N=1;
    int C[N];
    int i;
    
    // Seteo para que me tome el ASCII extendido y poder usar tildes
    SetConsoleOutputCP(CP_UTF8);

    // Solicito longitud
    while(N<2||N>100){
        printf("Indique longitud de camino N donde 2<=N<=100: ");
        scanf("%i",&N);
    }

    llenarArray(C,N);
    
    mostrarArray(C,N);
    
    predictorDeSaltos(C,N);

    return 0;
}

void llenarArray(int C[], int N){
    int i;
    
    for(i=1;i<N;i++){
        printf("Indique si hay una roca en la posición %i: ",i);
        scanf("%d",&C[i]);
    }
}

void mostrarArray(int C[], int N){
    int i;

    C[0]=0;

    for(i=0;i<N;i++){
        printf("%i ",C[i]);
    }

    printf("\n");
}

void predictorDeSaltos(int C[], int N){
    int i=0;
    int saltos = 0;

    while(i<N-1){

        if(C[i+2]==0){
            saltos++;
            i+=2;
        }
        else if(C[i+1]==0){
            saltos++;
            i++;
        }else{
            saltos=0;
            break;
        }
    }

    if(saltos!=0){
        printf("Se podrá cruzar con un mínimo de %i saltos\n",saltos);
    }else{
        printf("No se puede saltar ya que tiene dos hoyos seguidos en el agua");
    }


}