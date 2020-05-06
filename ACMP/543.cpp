#include <iostream>
using namespace std;
int main(){
    long long N, W, D, P, total=0;
    cin >> N >> W >> D >> P;
    for (int i =0, incr=W;i<N-1;i++, incr+=W){
        total+=incr;
    }
    for (int i =0, incr=W-D, decr=W;i<N-1;i++, incr+=W-D, decr+=W){
        if (total - decr + incr == P){
            cout << i+1;
            return 0;
        }
    }
    cout << N;
}
