#include <iostream>
using namespace std;

int main()
{
    int hours = 00;
    int minutes = 00;
    int seconds = 00;

    do{
        cout<<hours <<" : " <<minutes <<" : "<< seconds <<endl;
        
        seconds++;

        if(seconds > 59){
            seconds = 0;
            minutes++;
            if(minutes > 59){
                minutes = 0;
                hours++;
            }
        }
    }
    while(hours < 24);

    return 0;
}
