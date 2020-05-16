#include <iostream>
using namespace std;
#define l long
l arr[70][70];
l arr_count[70][70];
l N,M;
bool is_available(l x, l y){
    return x>=0&&x<N&&y>=0&&y<M;
}

int main(){
    cin >> N >> M;
    for (l i =0;i<N;i++){
        for (l j =0;j<M;j++){
            cin >> arr[i][j];
        }
    }
    if (is_available(0+arr[0][0], 0))
        arr_count[0+arr[0][0]][0] = 1;
    if (is_available(0, 0+arr[0][0]))
        arr_count[0][0+arr[0][0]] = 1;
    for (l i =0;i<N;i++){
        for (l j=0;j<M;j++){
            if (arr_count[i][j]!=0||(i==0&&j==0)) {
                if (is_available(i + arr[i][j], j)&&(i!=N-1||j!=M-1)) {
                    arr_count[i + arr[i][j]][j] += arr_count[i][j];
                }
                if (is_available(i, j + arr[i][j])&&(i!=N-1||j!=M-1)) {
                    arr_count[i][j + arr[i][j]] += arr_count[i][j];
                }
            }
        }
    }
    cout << arr_count[N-1][M-1];
}