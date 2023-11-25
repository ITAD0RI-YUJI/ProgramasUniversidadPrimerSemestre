#include <iostream>
#include <cmath> // Utiliza cmath en lugar de math.h
#include <ctime>
using namespace std;

int inversionista = 0;
int capitalInicial = 0;
double interes; 
int cantYears = 0;
int tipoPlan;
int periodoCap = 0;

int tipoPlanArray[100];
int capitalesIni[100];
int tiempoArray[100];
int porcentajeInte[100];
int periodoArray[100];
// int tasaEfectiva[100];

void valorFinal(double interes, int tiempo, int capitalInicial) {
    cout << "\n♧ ¿Cuántos años?: ";
    cin >> cantYears;

    int p = tiempo;
    int N = cantYears * p;
    
    double i = interes / p;
    double formulaCalc = capitalInicial * pow((1 + i), N);

    cout << "El capital a retornar es: $" << formulaCalc<< endl;
}

int main() {
    srand(time(NULL));

    cout << "\n♧ Cantidad de inversionistas en total: ";
    cin >> inversionista;

    for (int i = 0; i < inversionista; i++) {
        interes = 12; 

        cout << "\n♧ Cantidad de capital a invertir del inversionista " << i + 1 << ": ";
        cin>> capitalesIni[i];

        cout << "\n♧ Escoje tu tipo de plan:\n 1. Mensual\n 2. Trimestral\n 3. Semestral\n 4. Anual" << endl;
        cin >> tipoPlan;

        cout << "\n♧ Porcentaje de intereses: " << interes << "%" << endl;
        interes /= 100;

        if (capitalInicial < 0) {
            cout << "Lo sentimos, no puedes ingresar un capital negativo, vuelve a intentarlo " << endl;
        } else {
            switch (tipoPlan) {
            case 1:
                periodoCap = 12 / 1;
                valorFinal(interes, periodoCap, capitalesIni[i]);
            break;

            case 2:
                periodoCap = 12 / 3;
                valorFinal(interes, periodoCap, capitalesIni[i]);
            break;
            
            case 3:
                periodoCap = 12 / 6;
                valorFinal(interes, periodoCap, capitalesIni[i]);
            break;
            
            case 4:
                periodoCap = 12 / 12;
                valorFinal(interes, periodoCap, capitalesIni[i]);
            break;
            }
        }

        periodoArray[i] = periodoCap;
        porcentajeInte[i] = interes;
        tiempoArray[i] = cantYears;
    }

    for(int j = 0 ; j < inversionista ; j++){
    cout<<"\n♧ El capital del inversionista " <<j+1 <<" es: " <<capitalesIni[j] <<endl;
    cout<<"♧ El tiempo es: " <<tiempoArray[j] <<" años"<<endl;
    cout<<"♧ El tiempo capitalizable es: " <<periodoArray[j] <<endl;
  }

    return 0;
}
