#include <iostream>
using namespace std;
int main(){
    long N, M, K, count = 0;
    cin >> N >> M >> K;
    if (M > N && K >=N){
        cout << "NO";
        return 0;
    }
    while (1){
        M-=N;
        count++;
        if (M<=0) break;
        M+=K;
    }
    cout << count;
}
