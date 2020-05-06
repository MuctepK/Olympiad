#include <iostream>
using namespace std;
int count(int n){
    if (n==2) return 0;
    if (n%2==0) return count(n/2) + 1;
    return count(3*n+1) + 1;
}
int main(){
    int N, K, temp, total = 0; cin >> N >> K;
    for (int i =N;i<=K;i++){
        total += count(i);
    }
    cout << total;
}

