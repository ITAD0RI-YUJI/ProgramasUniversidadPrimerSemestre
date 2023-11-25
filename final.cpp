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
    int filaAleatoria;
    int columnaAleatoria;

    do{
        filaAleatoria = rand() % 3;
        columnaAleatoria = rand() % 3;
    }
    while((tablero[filaAleatoria][columnaAleatoria] == 'X') || (tablero[filaAleatoria][columnaAleatoria] == 'O'));

    tablero[filaAleatoria][columnaAleatoria] = 'X';
    // bloquear();
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
        char posicionPersona = '0';

        if(turno == 0){
            cout<< "\n♧ Movimiento de "<< nombreComputador<< endl;
            movimientoComputador();
        }
        else if(turno == 1){ // Si el turno es 1, es el turno de la persona

            cout<< "\n♧ Ingresa la posición para colocar tu ficha: ";
            cin>> posicionPersona;

            for(int i = 0; i < 3; i++){
                int espacioVacio = true;

                for(int j = 0; j < 3; j++){
                    if((tablero[i][j] == posicionPersona)){
                        if((tablero[i][j] == 'X') || (tablero[i][j] == 'O')){
                            cout<< "♧ Ocupado, escoge otra"<< endl;
                            espacioVacio = false;
                            break;
                        }
                        else if((tablero[i][j] == posicionPersona) && ((tablero[i][j] != 'X') || (tablero[i][j] != 'O'))){
                            tablero[i][j] = 'O';
                            espacioVacio = false;
                            break;
                        }
                    }
                }
                if(!espacioVacio) break;
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