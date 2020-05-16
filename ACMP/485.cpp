#include <iostream>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    for (int i =5;i<100000000;i++){
        int count = 0, start=i;
        while (start>0){
            start-=K;
            if (start%N!=0)break;
            start = start - start/N;
            count++;
            if (count==N){
                cout << i;
                return 0;
            }
        }
    }
}