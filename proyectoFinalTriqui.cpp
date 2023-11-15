#include <iostream>
#include <ctime>
#include <cstdlib> // Agregamos esta librería para la función rand()
#include <string>
using namespace std; 

string nombresComputador[] = {"Asta" , "Itadori" , "Luffy" , "Goku" , "Naruto"}; //Nombres para el computador a la hora de jugar
int nombreSize = sizeof(nombresComputador)/sizeof(nombresComputador[0]);

char tablero[3][3];

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

bool bloquear(){
    bool lanzarBloqueo = false;

    for(int i = 0; i < 3; i++){
        if(((tablero[i][0] == 'O') && (tablero[i][1] == 'O') && (tablero[i][2] == 'O')) || 
           ((tablero[i][0] == 'O') && (tablero[i][2] == 'O') && (tablero[i][1] == 'O')) ||
           ((tablero[i][1] == 'O') && (tablero[i][2] == 'O') && (tablero[i][0] == 'O'))){
            for(int k = 0; k < 3; k++){
                if(tablero[i][k] != 'O'){
                    tablero[i][k] = 'X';
                    return !lanzarBloqueo;
                }
            }
        }

        if(((tablero[0][i] == 'O') && (tablero[1][i] == 'O') && (tablero[2][i] == 'O')) || 
           ((tablero[0][i] == 'O') && (tablero[2][i] == 'O') && (tablero[1][i] == 'O')) ||
           ((tablero[1][i] == 'O') && (tablero[2][i] == 'O') && (tablero[0][i] == 'O'))){
            for(int k = 0; k < 3; k++){
                if(tablero[k][i] != 'O'){
                    tablero[k][i] = 'X';
                    return !lanzarBloqueo;
                }
            }
        }
        
        if(((tablero[0][0] == 'O') && (tablero[1][1] == 'O') && (tablero[2][2] == 'O')) || 
           ((tablero[0][0] == 'O') && (tablero[2][2] == 'O') && (tablero[1][1] == 'O')) ||
           ((tablero[1][1] == 'O') && (tablero[2][2] == 'O') && (tablero[0][0] == 'O'))){
            for(int k = 0; k < 3; k++){
                if(tablero[k][k] != 'O'){
                    tablero[k][k] = 'X';
                    return !lanzarBloqueo;
                }
            }
        }
        
        if(((tablero[0][2] == 'O') && (tablero[1][1] == 'O') && (tablero[2][0] == 'O')) || 
           ((tablero[0][2] == 'O') && (tablero[2][0] == 'O') && (tablero[1][1] == 'O')) ||
           ((tablero[1][1] == 'O') && (tablero[2][0] == 'O') && (tablero[0][2] == 'O'))){
            for(int k = 0; k < 3; k++){
                if(tablero[k][k] != 'O'){
                    tablero[k][k] = 'X';
                    return !lanzarBloqueo;
                }
            }
        }
    }

    return lanzarBloqueo; // Lanza "false" por defecto
}

void movimientoComputador(){
    int filaAleatoria = rand() % 3;
    int columnaAleatoria = rand() % 3;
    bool vacioValidar = true;

    if((tablero[filaAleatoria][columnaAleatoria] == 'X') || (tablero[filaAleatoria][columnaAleatoria] == 'O')){
        vacioValidar = false;
    }

    while(!vacioValidar){
        filaAleatoria = rand() % 3;
        columnaAleatoria = rand() % 3;

        if((tablero[filaAleatoria][columnaAleatoria] == 'X') || (tablero[filaAleatoria][columnaAleatoria] == 'O')){
            vacioValidar = false;
        } 
        else {
            bloquear();
            vacioValidar = true;
        }
    }

    tablero[filaAleatoria][columnaAleatoria] = 'X';

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

    char aumentador = '1';
    for(int i = 0; i < 3; i++){     // Definiendo las posiciones dentro de la matriz (rellenar de 1-9)
        for(int j = 0; j < 3; j++){
           tablero[i][j] = aumentador;
           aumentador += 1;
        }
    }

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
        char posicionPersona = '0';

        if(turno == 0){
            cout<< "\nMovimiento de "<< nombreComputador<< endl;
            movimientoComputador();
        }
        else if(turno == 1){ // Si el turno el 1 es elturno de la persona
            cout<<"\n♧ Valor donde quieres poner en el tablero "<< nombrePersona<< ": ";
            cin>> posicionPersona;

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(tablero[i][j] == posicionPersona){
                        tablero[i][j] = 'O'; 
                    }
                }
            }
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