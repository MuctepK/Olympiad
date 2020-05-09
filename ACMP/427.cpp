#include <bits/stdc++.h>
using namespace std;
int main(){
    long n, value;
    cin >> n;
    vector <long long> v(n);
    for (long long i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    long long s = 0;
    for (long long i = 0; i < n; i++) {
        if (v[i] > s + 1) {
            cout << s + 1;
            return 0;
        } else
            s += v[i];
    }
    cout << s + 1;
}