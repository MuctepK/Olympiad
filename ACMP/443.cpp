#include <bits/stdc++.h>
using namespace std;
int get_hash(string s, long base, long mod){
    long res=0, mul = base;
    for (int i =0;i<s.size();i++){
        if (i==0)
            res+=(s[i]-'0')%mod;
        else {
            res += (((s[i] - '0')%mod) * (base%mod))  % mod;
            base*=mul;
            base%=mod;
        }
    }
    return res%mod;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long n,m,x; cin >> n >> m >> x;
    map <long, long> dic;
    string s;
    for (long i =0;i<n;i++){
        cin >> s;
        dic[get_hash(s, x, m)]++;
    }
    int sum = 0;
    for (auto it: dic){
        for (int i =1;i<it.second;i++){
            sum+=i;
        }
    }
    cout << sum;
}

