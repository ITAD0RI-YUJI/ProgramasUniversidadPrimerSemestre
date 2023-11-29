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


void movimientoComputador(){
    int filaAleatoria;
    int columnaAleatoria;

    // Búsqueda de bloqueo en filas
    for (int i = 0; i < 3; ++i){
        if (tablero[i][0] == "O" && tablero[i][1] == "O" && tablero[i][2] == to_string(3 * i + 1)){
            tablero[i][2] = "X"; // Bloqueo
            return;
        }
        else if (tablero[i][0] == "O" && tablero[i][2] == "O" && tablero[i][1] == to_string(3 * i + 2)){
            tablero[i][1] = "X"; // Bloqueo
            return;
        }
        else if (tablero[i][1] == "O" && tablero[i][2] == "O" && tablero[i][0] == to_string(3 * i + 1)){
            tablero[i][0] = "X"; // Bloqueo
            return;
        }
    }

    // Búsqueda de bloqueo en columnas
    for (int j = 0; j < 3; ++j){
        if (tablero[0][j] == "O" && tablero[1][j] == "O" && tablero[2][j] == to_string(j + 7)){
            tablero[2][j] = "X"; // Bloqueo
            return;
        }
        else if (tablero[0][j] == "O" && tablero[2][j] == "O" && tablero[1][j] == to_string(j + 4)){
            tablero[1][j] = "X"; // Bloqueo
            return;
        }
        else if (tablero[1][j] == "O" && tablero[2][j] == "O" && tablero[0][j] == to_string(j + 1)){
            tablero[0][j] = "X"; // Bloqueo
            return;
        }
    }

    // Búsqueda de bloqueo en diagonales
    if (tablero[0][0] == "O" && tablero[1][1] == "O" && tablero[2][2] == "9"){
        tablero[2][2] = "X"; // Bloqueo
        return;
    }
    else if (tablero[0][0] == "O" && tablero[2][2] == "O" && tablero[1][1] == "5"){
        tablero[1][1] = "X"; // Bloqueo
        return;
    }
    else if (tablero[1][1] == "O" && tablero[2][2] == "O" && tablero[0][0] == "1"){
        tablero[0][0] = "X"; // Bloqueo
        return;
    }
     
    if (tablero[2][0] == "O" && tablero[1][1] == "O" && tablero[0][2] == "7"){
        tablero[0][2] = "X"; // Bloqueo
        return;
    }
    else if (tablero[0][2] == "O" && tablero[2][0] == "O" && tablero[1][1] == "5"){
        tablero[1][1] = "X"; // Bloqueo
        return;
    }
    else if (tablero[1][1] == "O" && tablero[0][2] == "O" && tablero[2][0] == "1"){
        tablero[2][0] = "X"; // Bloqueo
        return;
    }

      // Colocación aleatoria si no hay bloqueo
    do{
        filaAleatoria = rand() % 3;
        columnaAleatoria = rand() % 3;
    } 
    while ((tablero[filaAleatoria][columnaAleatoria] == "X") || (tablero[filaAleatoria][columnaAleatoria] == "O"));

    tablero[filaAleatoria][columnaAleatoria] = "X";
}


bool ganador(string nombreComputador, string nombrePersona) 
{
  bool hayGanador = false;

  for(int i = 0; i < 3; ++i){

    // Analizo si hay un ganador en filas o columna
    if((tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) || (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i])){
      hayGanador = true;

      // Aquí verifico si es ganador X u O para filas
      if(tablero[i][0] == "X" && tablero[i][1] == "X" && tablero[i][2] == "X"){
        cout << "\n♧ El ganador es " << nombreComputador << endl;
        break;
      } 
      else if(tablero[i][0] == "O" && tablero[i][1] == "O" && tablero[i][2] == "O"){
        cout << "\n♧ El ganador es " << nombrePersona << endl;
        break;
      }

      //Aquí verifico si es ganador X u O para columnas
      if(tablero[0][i] == "X" && tablero[1][i] == "X" && tablero[2][i] == "X"){
        cout<< "\n♧ El ganador es " << nombreComputador << endl;
        break;
      }
      else if(tablero[0][i] == "O" && tablero[1][i] == "O" && tablero[2][i] == "O"){
        cout<<"\n♧ El ganador es " << nombrePersona << endl;
        break;
      }
    }
  }

  // Analizo si hay un ganador en las diagonales
  if((tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) || (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])){
    hayGanador = true;

    // Aquí verifico si es ganador X u O
    if((tablero[0][0] == "X" && tablero[2][2] == "X") || (tablero[0][2] == "X" && tablero[2][0] == "X")){
      cout << "\n♧ El ganador es " << nombreComputador << endl;
      
    }
    else if((tablero[0][0] == "O" && tablero[2][2] == "O") || (tablero[0][2] == "O" && tablero[2][0] == "O")){
      cout << "\n♧ El ganador es " << nombrePersona << endl;
    }
  }
  
  if(!hayGanador){
    bool empate = true;

    // Revisa que las filas y las columnas no estén vacías
    for(int i = 0; i < 3; ++i) {
      for(int j = 0; j < 3; ++j){

        if (tablero[i][j] != "X" && tablero[i][j] != "O") {
          empate = false;
          break;
        }
      }// Aquí termina el ciclo de columnas para una fila particular

      if (!empate) 
      {
        break;
      }
    }

    if (empate)
    {
      hayGanador = true;
      cout << "\n♧ Hay un empate" << endl;
    }
    
  }
  
  return hayGanador;
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
        ganador(nombreComputador, nombrePersona);

        if(ganador(nombreComputador, nombrePersona) == true) break;

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