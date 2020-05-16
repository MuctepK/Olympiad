#include <bits/stdc++.h>
using namespace std;
int arr[100];
int N = 5, c=0;
void calc(int last, int sum){
    if (sum==N){
        c++;
    }
    else{
        for (int j =1;j<=min(arr[last]-1,N-sum);j++){
            last++;
            arr[last]=j;
            calc(last, sum+arr[last]);
            last--;
        }
    }
}
int main(){
    cin >> N;
    for (int i =1;i<=N;i++){
        arr[0] = i;
        calc(0,i);
    }
    cout << c;
}

