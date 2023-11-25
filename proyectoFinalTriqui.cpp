#include <iostream>
#include <ctime>
#include <cstdlib> // Agregamos esta librería para la función rand()
#include <string>
using namespace std; 

string nombresComputador[] = {"Asta" , "Itadori" , "Luffy" , "Goku" , "Naruto"}; //Nombres para el computador a la hora de jugar
int nombreSize = sizeof(nombresComputador)/sizeof(nombresComputador[0]);

string tablero[3][3] = {"1","2","3","4","5","6","7","8","9"};


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


// void movimientoComputador(){
//     int filaAleatoria;
//     int columnaAleatoria;

//     do{
//         filaAleatoria = rand() % 3;
//         columnaAleatoria = rand() % 3;
//     }
//     while((tablero[filaAleatoria][columnaAleatoria] == "X") || (tablero[filaAleatoria][columnaAleatoria] == "O"));

//     tablero[filaAleatoria][columnaAleatoria] = "X";
// }

void bloquear(int filaAleatoria , int columnaAleatoria){

    
}


void movimientoComputador(){
    int filaAleatoria;
    int columnaAleatoria;

    filaAleatoria = rand() % 3;
    columnaAleatoria = rand() % 3;

    if((tablero[filaAleatoria][columnaAleatoria] == "X") || (tablero[filaAleatoria][columnaAleatoria] == "O")){
        bloquear(filaAleatoria , columnaAleatoria);
    }
    else{
        tablero[filaAleatoria][columnaAleatoria] = "X";
    }
}


int main(){
    srand(time(NULL));

    string nombrePersona;
    string nombreComputador = nombresSelector();

    int dadoPersona = 0;
    int dadoCompu = 0;
    int turno = 0;

    int filaPosicionUsuario;
    int columnaPosicionUsuario;

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
            bool espacioVacio = true;

            do{
                espacioVacio = true;

                cout<< "\n♧ Ingresa la fila de la posición para jugar: ";
                cin>> filaPosicionUsuario;

                cout<< "\n♧ Ingresa la columna de la posición para jugar: ";
                cin>> columnaPosicionUsuario;

                if((tablero[filaPosicionUsuario][columnaPosicionUsuario] == "X") || (tablero[filaPosicionUsuario][columnaPosicionUsuario] == "O")){
                    cout<< "♧ Ocupado, igresa otra posición "<< endl;

                    espacioVacio = false;
                }
                else{
                    tablero[filaPosicionUsuario][columnaPosicionUsuario] = "O";
                }

            }
            while(!espacioVacio); // Mientras el espacio no esté vacío, no se terminará de ejeutar
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