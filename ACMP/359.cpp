#include <iostream>
using namespace std;
int main(){
    long long n, ans=2, step=2,start=2, temp;
    cin >> n;
    while (ans<n){
        temp = step;
        for (;temp>=0;temp--) {
            if (start%10==0)temp++;
            start++;
        }
        ans++;
        if (ans==n)break;
        temp = step;
        for (;temp>=0;temp--) {
            if (start%10==0)temp++;
            start++;
        }
        step+=2;
        ans++;
    }
    cout << start;

}
