#include <iostream>
using namespace std;
int main(){
    long long N, cost = 3, solved, total=0;
    cin >> N;
    for (int i =0;i<N;i++){
        cin >> solved;
        if (solved) {
            total+=cost;
            cost++;
        }
        else
            cost = cost - 3 > 3? cost - 3: 3;

    }
    cout << total;
}

