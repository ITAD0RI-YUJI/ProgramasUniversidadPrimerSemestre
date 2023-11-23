#include <iostream>
using namespace std;

int main() {
  double acumulado = 0;

  cout<<endl;
  for (int i = 0; i < 3; i++) {
    double nota;
    cout << "Nota " << i + 1 << ": ";
    cin >> nota;

    acumulado += nota;
  }

  acumulado /= 3;

  double examFinal;
  cout << "Nota exámen final: ";
  cin >> examFinal;

  double gradoFinalMath = (acumulado * 0.1) + (examFinal * 0.9);
  cout << "Nota Final en matemáticas: " << gradoFinalMath << endl;
  
  cout<<endl;
  for (int i = 0; i < 2; i++) {
    double nota;
    cout << "Nota " << i + 1 << ": ";
    cin >> nota;

    acumulado += nota;
  }

  acumulado /= 3;

  examFinal = 0;
  cout << "Nota exámen final: ";
  cin >> examFinal;

  double gradoFinalFisica = (acumulado * 0.2) + (examFinal * 0.8);
  cout << "Nota Final en Física: " << gradoFinalFisica << endl;
  

  cout<<endl;
  for (int i = 0; i < 3; i++) {
    double nota;
    cout << "Nota " << i + 1 << ": ";
    cin >> nota;

    acumulado += nota;
  }

  acumulado /= 3;

  examFinal = 0;
  cout << "Nota exámen final: ";
  cin >> examFinal;

  double gradoFinalProgram = (acumulado * 0.15) + (examFinal * 0.85);
  cout << "Nota Final en Programación: " << gradoFinalProgram << endl;

  double pormedioTotal = (gradoFinalMath + gradoFinalFisica + gradoFinalProgram) / 3;

  cout<< "\nEl promedio total de las tres materias es: "<< pormedioTotal<< endl;

  return 0;
}