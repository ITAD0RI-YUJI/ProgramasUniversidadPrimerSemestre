#include <iostream>
#include <ctime>
using namespace std;

int descuento(int precioFinal, int cantDescuento){
    int resultado;

    return resultado = precioFinal - ((precioFinal * cantDescuento) / 100); 
}

int main(){
    srand(time(NULL));

    int numAleatorio = rand() % 100 + 1;
    int compraTotal = 0;

    cout<< "Precio de compra total: $";
    cin>> compraTotal;

    cout<< "\nEl número aleatorio es: "<< numAleatorio<< endl;

    (numAleatorio >= 74) ? cout<< "\nEl precio total de la comprar es: $" <<descuento(compraTotal , 20)<< " Con un descuento del 20%"<< endl : 
    cout<< "\nEl precio total de la comprar es: $" <<descuento(compraTotal , 15)<< " Con un descuento del 20%"<< endl;


    return 0;
}