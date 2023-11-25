#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

double calcularRec(int years, double interes, int capital) {
    if (years == 0) {
        return capital;
    } 
    else {
        double suma = pow((1 + interes), years);
        double final = capital * suma;
        return calcularRec(years - 1, interes, final);
    }
}

int main() {
    srand(time(NULL));

    double interes = (rand() % 100) / 100.0; // Generar un número aleatorio entre 0 y 1

    int capital = 0;

    cout << "\nIngresa la cantidad de capital que deseas invertir: ";
    cin >> capital;

    cout << "El interés que tiene el banco en este momento es de: " << interes * 100 << "%\n";
    cout << "Ingresa la cantidad de años que vas a invertir: ";
    
    int years;
    cin >> years;

    double resultado = calcularRec(years, interes, capital);

    cout << "El monto final después de " << years << " años es: " << resultado << endl;

    return 0;
}
