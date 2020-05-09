#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double n, p;
    cin >> n >> p;
    printf("%.9f", (100.0*n)/((n-1)*p+100));
}

