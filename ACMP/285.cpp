#include <iostream>
using namespace std;
int main(){
    int N,M, total=0, value, m=0;
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        cin >> value;
        if (m<value) m=value;
        total+=value;
    }
    total = total - N+1;
    if (m>M||total<M) cout << "no";
    else
        cout << "yes";
    
}