#include <iostream>
using namespace std;

int main(){
    int cantGrupos , cantAlumnos , cantMaterias;
    double promedioGrupo = 0;

    cout<<"♧ Cantidad de grupos en total" <<endl;
    cin>> cantGrupos;

    for(int i = 0; i < cantGrupos; i++){        
        cout<<"♧ Cantidad de alumnos del grupo "<< i+1 <<endl;
        cin>> cantAlumnos;

        for(int j = 0; j < cantAlumnos; j++){
            double promedio = 0;
            double promedioMateriasTotales;
            cout<<"♧ Cantidad de materias del alumno " <<j+1 <<endl;
            cin>> cantMaterias;

            for(int k = 0; k < cantMaterias; k++){
                int notaMateria = 0;

                for(int l = 0; l < 3; l++){
                    cout<<"\n♢ Nota " <<l+1 <<" de la materia " <<k+1 <<" del alumno " <<i+1 <<" : " <<endl;
                    cin>> notaMateria;
                    promedio += notaMateria;
                }
                promedio = promedio/3;
                promedioMateriasTotales += promedio;
                cout<<"\n♧ El promedio de la materia " <<k+1 <<" es: " <<promedio <<endl;
                promedio = 0; // Se reinicia el promedio cada vez que la materia termine
            }
            promedioMateriasTotales /= cantMaterias;
            cout<<"\n♧ El promedio total de las materias del ustudiante " <<j+1 <<" es: " <<promedioMateriasTotales <<endl; 
            promedioGrupo = promedioMateriasTotales;
        }
        promedioGrupo /= cantAlumnos;
        cout<<"\n♧ El promedio total del grupo " <<i+1 <<" es: " <<promedioGrupo <<endl; 
    }
}