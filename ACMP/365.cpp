#include <bits/stdc++.h>
using namespace std;
int arr[100];
int N = 5, m=1;
void calc(int last, int sum){
    if (sum==N){
        for (int i =0;i<=last;i++){
            if (i==last)
                cout << arr[i];
            else
            cout << arr[i] << "+";
        }
        cout << endl;
    }
    else{
        for (int j =1;j<=min(arr[last],N-sum);j++){
            last++;
            arr[last]=j;
            calc(last, sum+arr[last]);
            last--;
        }
    }
}
int main(){
    cin >> N;
    for (int i =1;i<N;i++){
        arr[0] = i;
        calc(0,i);
    }
}
