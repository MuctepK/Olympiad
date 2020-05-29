#include <bits/stdc++.h>
using namespace std;
long long d[16][16];
int main(){
    d[2][1] = 7;
    for (int i =3;i<16;i++){
        d[i][0] = 1;
        for (int k=0;k<i;k++)
            d[i][0] *= i;
        for (int j=1;j<=i;j++){
            d[i][j] = d[i][j-1] - i +1;
        }
    }
    int n,m;
    cin >> n >> m;
    cout << d[n][m];
}
