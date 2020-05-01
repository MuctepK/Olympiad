#include <iostream>
using namespace std;
int main(){
    int A, B, K, count=0, digit=0;
    bool start_to_count=false;
    cin >> A >> B >> K;
    while (count <K){
        if (A < B){
            A*=10;
            start_to_count=true;
        }
        digit = A / B;
        A = A % B;
        if (start_to_count){
            count++;
        }
    }
    cout << digit;
}
