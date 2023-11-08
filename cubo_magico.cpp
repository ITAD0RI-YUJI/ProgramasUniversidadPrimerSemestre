#include <iostream>
#include <ctime>
#include <cstdlib> // Agregamos esta librería para la función rand()
using namespace std;

int par[] = {2, 4, 6, 8};
int parSize = sizeof(par) / sizeof(par[0]);
int arrayAux[4];
int arrayDesorden[4];

int numeroRandom(){
    int numeroAleatorio;

    for(int i = 0; i < parSize; i++){
        arrayAux[i] = 0; // Inicializar el auxiliar con ceros, todos los valores serán ceros
    }

    for(int i = 0; i < parSize; i++){
        int indiceAleatorio;

        do{
            indiceAleatorio = rand() % parSize;
        }
        while(arrayAux[indiceAleatorio] != 0);
    
        arrayAux[indiceAleatorio] = 1; //Si el bucle busca en el auxiliar, y encuentra este "1" quiere decir que este ind. ya lo ha seleccionado
        numeroAleatorio = par[indiceAleatorio];
        arrayDesorden[i] = numeroAleatorio;
    }

    return numeroAleatorio;
}

int main() {
    srand(time(0));

    int matriz[3][3] = {0};

    // Rellenando el arreglo con números pares aletorios
    for(int i = 0; i < parSize; i++){
        arrayDesorden[i] = numeroRandom();
    }

    // Generar números aleatorios pares y llenar la matriz
    for (int i = 0; i <= parSize; i++){
        for (int k = 0; k <= parSize; k++) {
            if(matriz[0][0] == 0){ // Validando los pares
                matriz[0][0] = arrayDesorden[i];
            }
            else{
                if(matriz[0][2] == 0){
                    matriz[0][2] = arrayDesorden[i+1];
                }
                else{
                    if(matriz[2][2] == 0){
                        matriz[2][2] = arrayDesorden[i+2];
                    }
                    else{
                        if(matriz[2][0] == 0){
                            matriz[2][0] = arrayDesorden[i+3];
                        }
                    }
                }
            }
        }
    }
    matriz[1][1] = 5; // El centro de la matriz siempre será 5

    for (int i = 0; i <= parSize; i++){
        for (int k = 0; k <= parSize; k++) {
            if(matriz[0][1] == 0){
                matriz[0][1] = 15 - (matriz[0][0] + matriz[0][2]);
            }
            else{
                if(matriz[1][2] == 0){
                    matriz[1][2] = 15 - (matriz[0][2] + matriz[2][2]);
                }
                else{
                    if(matriz[2][1] == 0){
                        matriz[2][1] = 15 - (matriz[2][0] + matriz[2][2]);
                    }
                    else{
                        if(matriz[1][0] == 0){
                            matriz[1][0] = 15 - (matriz[0][0] + matriz[2][0]);
                        }
                    }
                }
            }
        }
    }

    // Imprimir la matriz
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}