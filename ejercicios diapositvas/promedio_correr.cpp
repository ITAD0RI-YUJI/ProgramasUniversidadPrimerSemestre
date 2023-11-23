#include <iostream>
using namespace std;

int main() {
    int horas = 0;
    int minutos = 0;
    int segundos = 0;
    int horasSuma = 0;
    int minutosSuma = 0;
    int segundosSuma = 0;

    for (int dia = 1; dia <= 3; dia++) {
        cout << "\nTiempo del día " << dia << " en este orden Horas : Minutos : Segundos" << endl;

        cout << "Horas: ";
        cin >> horas;

        horas *= 3600;
        horasSuma += horas;

        cout << "Minutos: ";
        cin >> minutos;

        minutos *= 60;
        minutosSuma += minutos;

        cout << "Segundos: ";
        cin >> segundos;

        segundosSuma += segundos;
    }

    int promedioHoras = horasSuma / 3;
    int promedioMinutos = minutosSuma / 3;
    int promedioSegundos = segundosSuma / 3;

    cout << "\nEl promedio de tiempo en hacer el recorrido a lo largo de la semana es: "
        << promedioHoras << " horas, " << promedioMinutos << " minutos, " << promedioSegundos << " segundos" << endl;

    return 0;
}
