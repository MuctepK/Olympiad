#include <iostream>
using namespace std;
int main(){
    int T1, T2;
    double S1, S2, S;
    cin >> T1 >> T2>> S1 >> S2 >> S;
    double up = double(S1)/ double(T1), down = double(S2) / double(T2), total = 0;
    while (S>0){
        double S_initial = S;
        int temp=T1;
        while (temp>0&&S>0){
            S-=up;
            total++;
            temp--;
        }
        temp = T2;
        while (temp > 0 && S>0){
            S+=down;
            total++;
            temp--;
        }
        if (S_initial<=S){
            cout << "NO";
            return 0;
        }
    }
    printf("%.2f", total);
}