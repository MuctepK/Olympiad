#include <bits/stdc++.h>
using namespace std;
map <long long, long long> dic;
long long calculate(long long N){
    if (N<3) return 0;
    if (N==3) return 1;
    else if (dic.find(N)!=dic.end()){
        return dic[N];
    }
    if (N%2==0){
        long long value = calculate(N/2)*2;
        dic[N] = value;
        return value;
    }
    else{
        long long value_1= calculate(N/2), value_2 = calculate((N+1)/2);
        dic[N] = value_1+value_2;
        return dic[N];
    }
}
int main(){
    long long N;
    cin >> N;
    cout << calculate(N);
}
