#include <iostream>
using namespace std;

int descuento(int precioFinal, int cantDescuento){
    int resultado;

    return resultado = ((precioFinal * cantDescuento) / 100); 
}

int main(){
    int monto = 0;
    int LIMITE = 50000;

    cout<< "\nHola, recuerda que si el monto escogido es menor a 50k, el monto será del 3%, de lo contrario será del 2%"<< endl;

    cout<< "\n¿De cuánto será el monto? ";
    cin>> monto;

    (monto < LIMITE) ? cout<< "\nLa cuota a pagar es de: $" <<descuento(monto , 3)<< " Con una tarifa del 3%"<< endl : 
    cout<< "\nLa cuota a pagar es de: $" <<descuento(monto , 2)<< " Con una tarifa del 2%"<< endl;

    return 0;
}