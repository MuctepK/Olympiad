#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, s =0;
    cin >> N;
    for (int i =1;i<=N;i++){
        s += (i+i*2)*(i*2-i+1)/2;
    }
    cout << s;
}