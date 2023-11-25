#include <iostream>
using namespace std;

int main(){
    char tablero[3][3] = {'1','2','3','4','X','6','7','X','9'};
    int posicionPersona = 0;

    cout<< endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<< " "<< tablero[i][j]<< " ";
        }
        cout<< endl;
    }

    cout<< "\n♧ Ingresa la posición para colocar tu ficha: ";
    cin>> posicionPersona;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tablero[i][j] == posicionPersona){
                if(tablero[i][j] == '1'){
                    cout<< "Intenta otra vez, está lleno"<< endl;
                }
                else{
                    tablero[i][j] = 'O';
                }
            }
        }
        cout<< endl;
    }

    return 0;
}