#include <iostream>
using namespace std;
int main(){
    double end, start=0.0, incr = 1.0;
    int count=0, divisor = 2;
    cin >> end;
    while (start <= end){
        start += 1.0/divisor;
        count++;
        divisor++;
    }
    cout << count << " card(s)";
}

