#include <iostream>
#include <ctime>
#include <cstdlib> // Agregamos esta librería para la función rand()
#include <string>
using namespace std;

string nombresComputador[] = {"Asta" , "Itadori" , "Luffy" , "Goku" , "Naruto"}; //Nombres para el computador a la hora de jugar
int nombreSize = sizeof(nombresComputador)/sizeof(nombresComputador[0]);

int tablero[3][3];


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

bool tableroRlleno(){ // Verifica si el tablero está vacío o totalmente lleno
    int lleno = false;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tablero[i][j] == 0){
                lleno = true;
            }
        }
    }

    return lleno;
}

void movimientoTablero(int fichaCompu){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tablero[i][j] == 0){
                tablero[i][j] = fichaCompu;
            }
        }
    }

    // return posicionColocar;
}

main(){
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


    //Definiendo las posiciones dentro de la matriz (rellenar de 1-9)
    // int aumentador = 1;

    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //        tablero[i][j] = aumentador;
    //        aumentador++;
    //     }
    // }
    cout<< "\nTablero a jugar: "<< endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<< tablero[i][j]<< " ";
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
    cout<< endl;


    //Bucle que contiene todo lo que es el "juego" colocar X u O
    while(tableroRlleno()){
        int colocarPersonaFila = 0;
        int colocarPersonaColumna = 0;
        int numPersona = 0; // Ficha del usuario

        if(turno == 0){ // Si el turno el 0 es elturno del computador
            cout <<"computador" << endl;
        }
        else if(turno == 1){ // Si el turno el 1 es elturno de la persona
            do{
                cout<<"\n♧ Posición a colocar en fila de "<< nombrePersona<< ": ";
                cin>> colocarPersonaFila;
            
                cout<<"\n♧ Posición a colocar en columna de "<< nombrePersona<< ": ";
                cin>> colocarPersonaColumna;
            
                cout<<"\n♧ Valor a poner en la posición dada "<< nombrePersona<< ": ";
                cin>> numPersona;

                if(tablero[colocarPersonaFila][colocarPersonaColumna] != 0){
                    cout<< "\nLa posición seleccionada ya está ocupada, elige otra "<< endl;
                }
                else{
                    tablero[colocarPersonaFila][colocarPersonaColumna] = numPersona;
                    break;
                }
            }
            while(tablero[colocarPersonaFila][colocarPersonaColumna] != 0);
        }

        cout<< endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout<< tablero[i][j]<< " ";
            }
            cout<< endl;
        }

        turno = (turno + 1) % 2; 
    }

    return 0;
}