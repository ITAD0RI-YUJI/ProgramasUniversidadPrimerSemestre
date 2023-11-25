#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int cuadrado[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

int main() {
    srand(time(NULL));

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if((cuadrado[i][j] == cuadrado[0][0]) && (cuadrado[i][j] == cuadrado[0][2]) && (cuadrado[i][j] == cuadrado[2][0]) && (cuadrado[i][j] == cuadrado[2][2])){
                if(cuadrado[i][j] == 0){
                    cuadrado[i][j] = 8;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << cuadrado[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
