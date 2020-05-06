#include <iostream>
using namespace  std;
int arr[101][101];
int main(){
    int N, total = 0,x1,y1,x2,y2;
    cin >> N;
    for (int i =0;i<N;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1> x2 ) swap(x1,x2);
        if (y1> y2) swap(y1,y2);
        for (; x1 < x2; x1 ++){
            int temp = y1;
            for (; temp < y2; temp++){
                arr[x1][temp]++;
            }
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1> x2 ) swap(x1,x2);
    if (y1> y2) swap(y1,y2);
    for (; x1 < x2; x1 ++){
        int temp = y1;
        for (; temp < y2; temp++){
           total += arr[x1][temp];
        }
    }
    cout << total;
}

