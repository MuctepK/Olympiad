#include <iostream>
using namespace std;
int main(){
    long long N, M,res=0; cin >> N >> M;
    string str (N,'.');
    if (M==0&&N==0) cout << 1;
    else if (M>N||N==0) cout << 0;
    else if (M==1) cout << N;
    else if (M==N||M==0) cout << 1;
    else {
        int step = 1;
        while (step<N){

            for (int j =0;j<N;j++) {
                long long  c = M;
                for (int i = j; i < N && c>0; i += step) {
                    c--;
                }
                if (c==0) res++;
            }
            step++;
        }

        cout << res;
    }

}

