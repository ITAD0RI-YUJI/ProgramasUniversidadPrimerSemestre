#include <iostream>
using namespace std;

int descuento(int precioFinal, int cantDescuento){
    int resultado;

    return resultado = precioFinal - ((precioFinal * cantDescuento) / 100); 
}

int main(){
    int camisasPrecio = 20000;
    int cantCamisas = 0;

    cout<< "\nEl precio por unidad es de $"<< camisasPrecio<< endl;

    do{
        cout<< "\nIngresa la cantidad de camisas que deseas adquirir: ";
        cin>> cantCamisas;

        for(int i = 1; i <= cantCamisas; i++){
            camisasPrecio *= i;
        }

        if(cantCamisas < 0){
            cout<< "\nLa cantidad de camisas no puede ser negativa, vuelve a intentarlo"<< endl;
        }
        else if(cantCamisas >= 3){
            cout<< "\nEl precio total de la comprar es: $" <<descuento(camisasPrecio , 20)<< " Con un descuento del 20%"<< endl;
            break;
        }
        else if(cantCamisas < 3){
            cout<< "\nEl precio total de la comprar es: $" <<descuento(camisasPrecio , 10)<< " Con un descuento del 10%"<< endl;
            break;
        }
    }
    while(cantCamisas < 0);

    return 0;
}