#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int N,  command, step;
    cin >> N;
    double x=0, y=0;
    for (int i =0;i<N;i++){
        cin >> command >> step;
        switch (command) {
            case 1: y+=step; break;
            case 2: x+=step/sqrt(2); y+=step/sqrt(2); break;
            case 3: x+=step; break;
            case 4: x+=step/sqrt(2); y-=step/sqrt(2); break;
            case 5: y-=step; break;
            case 6: x-=step/sqrt(2); y-=step/sqrt(2); break;
            case 7 : x-=step; break;
            case 8 : x-=step/sqrt(2); y+=step/sqrt(2); break;
        }


    }
    printf("%.3f %.3f", x, y);
}