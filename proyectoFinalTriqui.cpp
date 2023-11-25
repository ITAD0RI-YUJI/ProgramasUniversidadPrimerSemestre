#include <iostream>
#include <ctime>
#include <cstdlib> // Agregamos esta librería para la función rand()
#include <string>
using namespace std; 

string nombresComputador[] = {"Asta" , "Itadori" , "Luffy" , "Goku" , "Naruto"}; //Nombres para el computador a la hora de jugar
int nombreSize = sizeof(nombresComputador)/sizeof(nombresComputador[0]);

char tablero[3][3] = {'1','2','3','4','5','6','7','8','9'};

string nombresSelector(){ // Elegir el nombre del PC al azar
    string nombreComputador;
    
    int indiciAleatorio = rand() % nombreSize;
    
    nombreComputador = nombresComputador[indiciAleatorio];
    
    return nombreComputador;
}

int lanzarDado(){
    int numeroDado = 0;

    numeroDado = rand() % 5 + 1;
    
    return numeroDado;
}

// bool bloquear(){
    
// }

void movimientoComputador(){
    int filaAleatoria;
    int columnaAleatoria;

    do{
        filaAleatoria = rand() % 3;
        columnaAleatoria = rand() % 3;
    }
    while((tablero[filaAleatoria][columnaAleatoria] == 'X') || (tablero[filaAleatoria][columnaAleatoria] == 'O'));

    tablero[filaAleatoria][columnaAleatoria] = 'X';
}

void validarEspacio(char tableroFunc[3][3]){
    char posicionPersona = 0;

    int fila;
    int columna;

    bool espacioVacio = true;

    do{
        espacioVacio = true;
        
        cout<< "\n♧ Ingresa la posición para jugar: ";
        cin>> posicionPersona;

        switch (posicionPersona)
        {
            case '1':
                fila = 0;
                columna = 0;

                if(tableroFunc[fila][columna] == 'X' || tableroFunc[fila][columna] == 'O'){
                    cout<< "♧ Esta posición está ocupada, ingresa otra "<< endl;

                    espacioVacio = false;
                }

            break;
            
            case '2':
                fila = 0;
                columna = 1;

                if(tableroFunc[fila][columna] == 'X' || tableroFunc[fila][columna] == 'O'){
                    cout<< "♧ Esta posición está ocupada, ingresa otra "<< endl;;

                    espacioVacio = false;
                }

            break;
            
            case '3':
                fila = 0;
                columna = 2;

                if(tableroFunc[fila][columna] == 'X' || tableroFunc[fila][columna] == 'O'){
                    cout<< "♧ Esta posición está ocupada, ingresa otra "<< endl;

                    espacioVacio = false;
                }

            break;
            
            case '4':
                fila = 1;
                columna = 0;

                if(tableroFunc[fila][columna] == 'X' || tableroFunc[fila][columna] == 'O'){
                    cout<< "♧ Esta posición está ocupada, ingresa otra "<< endl;

                    espacioVacio = false;
                }

            break;
            
            case '5':
                fila = 1;
                columna = 1;

                if(tableroFunc[fila][columna] == 'X' || tableroFunc[fila][columna] == 'O'){
                    cout<< "♧ Esta posición está ocupada, ingresa otra "<< endl;

                    espacioVacio = false;
                }

            break;
            
            case '6':
                fila = 1;
                columna = 2;

                if(tableroFunc[fila][columna] == 'X' || tableroFunc[fila][columna] == 'O'){
                    cout<< "♧ Esta posición está ocupada, ingresa otra "<< endl;

                    espacioVacio = false;
                }

            break;
            
            case '7':
                fila = 2;
                columna = 0;

                if(tableroFunc[fila][columna] == 'X' || tableroFunc[fila][columna] == 'O'){
                    cout<< "♧ Esta posición está ocupada, ingresa otra "<< endl;

                    espacioVacio = false;
                }

            break;
            
            case '8':
                fila = 2;
                columna = 1;

                if(tableroFunc[fila][columna] == 'X' || tableroFunc[fila][columna] == 'O'){
                    cout<< "♧ Esta posición está ocupada, ingresa otra "<< endl;

                    espacioVacio = false;
                }

            break;
            
            case '9':
                fila = 2;
                columna = 2;

                if(tableroFunc[fila][columna] == 'X' || tableroFunc[fila][columna] == 'O'){
                    cout<< "♧ Esta posición está ocupada, ingresa otra "<< endl;

                    espacioVacio = false;
                }

            break;
        }
    }
    while(!espacioVacio);

    tableroFunc[fila][columna] = 'O';
}

int main(){
    srand(time(NULL));

    string nombrePersona;
    string nombreComputador = nombresSelector();

    int dadoPersona = 0;
    int dadoCompu = 0;
    int turno = 0;

    cout<< "\n♧ Ingresar nombre para jugador 1: ";
    cin>> nombrePersona;

    cout<< "\n♧ Nombre del jugador 2: "<< nombreComputador<< endl;

    cout<< "\nLanzando Dado..." <<endl;
    do {
        dadoPersona = lanzarDado();
        dadoCompu = lanzarDado();
    } 
    while (dadoCompu == dadoPersona); // Si los dados llegan a ser iguales, repetirá el lanzamiento hasta que sean diferentes

    cout<< "\nResultado dado "<< nombrePersona<< " : "<< dadoPersona<< endl;
    cout<< "Resultado dado "<< nombreComputador<< " : "<< dadoCompu<< endl;

    cout<< "\nTablero a jugar: "<< endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<< " "<< tablero[i][j]<< " ";
        }
        cout<< endl;
    }
    
    //Definiendo quien tendrá el primer turno
    if(dadoPersona > dadoCompu){
        cout<< "\n♧ El primer turno corresponde a "<< nombrePersona<< endl;
        turno++; 
    }
    else{
        cout<< "\n♧ El primer turno corresponde a "<< nombreComputador<< endl;
        turno = 0;
    }

    for(int i = 0; i < 9; i++){
        if(turno == 0){
            cout<< "\n♧ Movimiento de "<< nombreComputador<< endl;
            movimientoComputador();
        }
        else if(turno == 1){ // Si el turno es 1, es el turno de la persona
            validarEspacio(tablero);
        }

        cout<< endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout<< " "<< tablero[i][j]<< " ";
            }
            cout<< endl;
        }

        turno = (turno + 1) % 2;
    }

    return 0;
}