#include <iostream>
#include <string>
using namespace std;

void porcentajes(int dineroTotal , int arrayDeLaFuncion[] , int porcentajeFunction[]){ //Función para calcular a qué porcentaje pertenece cada capital repecto al total
    for(int i = 0; i < 3; i++){
        porcentajeFunction[i] = (arrayDeLaFuncion[i] * 100)/dineroTotal;
    }
    
}

int main(){
    string nombrePersona[3];
    int dineroInvertido[3];
    int porcentajesFinal[3];
    int dineroTotal;
    
    dineroTotal = 0;

    for(int i = 0; i < 3; i++){  //usar el 3 en vez del .size() ya que es un arreglo fijo
        cout<< "\nNombre del inversor "<< i+1<< ": ";
        cin>> nombrePersona[i];

        cout<< "Monto invertido por "<< nombrePersona[i]<< ": ";
        cin>> dineroInvertido[i];

        dineroTotal += dineroInvertido[i];
    }

    cout<< "\nEl dinero total invertido es: $"<< dineroTotal<< endl;

    porcentajes(dineroTotal , dineroInvertido , porcentajesFinal);

    for(int i = 0; i < 3; i++){
        cout<< "\nEl porcentaje de dinero invertido por " << nombrePersona[i] << " es: " <<porcentajesFinal[i]<<"%";
    }

    return 0;
}

//Tres personas deciden invertir su dinero para fundar una empresa. Cada una de ellas invierte una cantidad distinta
//Obtener el porcentaje que cada bien invierte con respecto a la cantidad total invertida.