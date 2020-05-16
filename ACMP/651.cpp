#include <bits/stdc++.h>
using namespace std;
long long factorize(long long n){
    long long s =0;
    for (int i =2;i*i<=n;i++){
        while (n%i==0){
            n/=i;
            s++;
        }
    }
    if (n>1)s++;
    return s;
}
int main(){
    long long N, M; cin >> N >> M;
    if (N==M) {
        cout << 0;
        return 0;
    }
    long long gcd = __gcd(N,M);
    N/=gcd;M/=gcd;
    long long s = factorize(N) + factorize(M);
    cout << s;
}

