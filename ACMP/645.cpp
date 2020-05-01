#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int H=1, W=1, m=10000;
    for (int i =1; i<=1000;i++){
        for (int j=1;j<=1000;j++){
            if (m>=(abs(i-j)+N-i*j) && i*j <=N){
                H=i;W=j;
                m= (abs(i-j)+N-i*j);
            }
        }
    }
    cout << H << " " << W;
    return 0;

}
