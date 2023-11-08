#include <iostream>
#include <string>
using namespace std;

int arraySize , i , j;

int sumaMatriz(int arrayA[][2] , int arrayB[][2]){
  //Obtnener valores de las matrices y hacer la operación
  int numOne , numTwo;
  int suma = 0;

  for(i = 0; i < arraySize ; i++){
    for(j = 0; j < arraySize ; j++){
      numOne = arrayA[i][j];
      numTwo = arrayB[i][j];
      suma = numOne + numTwo;
      cout<< suma <<" ";
    }
    cout<< endl;
  }
}

int main() {

  cout<<"Ingresa el la longitud de altura y anchura de las matrices" <<endl;
  cin>> arraySize;

  int arrayA[arraySize][arraySize];
  int arrayB[arraySize][arraySize];
  
  //Digite los datos para insertar en las matrices

  for(i = 0; i < arraySize; i++){
    for(j = 0; j < arraySize; j++){
      cout<<"Digite el número para la matriz A en la columna " << i <<" Fila " << j<<endl;
      cin>> arrayA[i][j];
    }
  }
  
  for(i = 0; i < arraySize; i++){
    for(j = 0; j < arraySize; j++){
      cout<<"Digite el número para la matriz B en la columna " << i <<" Fila " << j<<endl;
      cin>> arrayB[i][j];
    }
  }

  //Recorriendo las matrices

  cout<<"\nMatriz A: " <<endl;
  for(int i = 0; i < arraySize; i++){
    for(int j = 0; j < arraySize; j++){
      cout<< arrayA[i][j] <<" ";
    }
    cout<<endl;
  }
  
  cout<<"\nMatriz B: " <<endl;
  for(i = 0; i < arraySize; i++){
    for(j = 0; j < arraySize; j++){
      cout<< arrayB[i][j] <<" ";
    }
    cout<<endl;
  }

  //Suma de las matrices

  cout<<"\nSuma de las matrices: " <<endl;
  for(i = 0; i < arraySize ; i++){
    cout<< sumaMatriz(arrayA , arrayB);
  }

  //Resta de las matrices
  
  int resta = 0;
  
  cout<<"\nResta de las matrices: " <<endl;
  for(i = 0; i < arraySize ; i++){
    for(j = 0; j < arraySize ; j++){
      // numOne = arrayA[i][j];
      // numTwo = arrayB[i][j];
      // resta = numOne - numTwo;
      cout<< resta <<" ";
    }
    cout<< endl;
  }

  int multi[arraySize][arraySize];

  // Operación de la multiplicación de las matrices

  for(i = 0; i < arraySize; i++){
    for(j = 0; j < arraySize; j++){
      multi[i][j]= 0; // Se debe inicializar, porque a la hora de hacer la suma por primera vez (más abajo) debe sumar algo, en este caso 0 (cero)
      for(int k = 0; k < arraySize; k++){
        multi[i][j] += arrayA[i][k] * arrayB[k][j]; //La primera matriz se recorre normal, la segunda, se recorre de izq a der.
      }
    }
  }

  cout<<"\nMultiplicación de las matrices: " <<endl;
  for(i = 0; i < arraySize; i++){
    for(j = 0; j < arraySize; j++){
      cout<< multi[i][j];
      cout<<" ";
    }
    cout<< endl;
  }

}

// C++ nos deja tener el número de filas vacías, pero debemos tener el número de columnas - ejemplo:  matriz[][2];