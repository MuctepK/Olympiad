#include <iostream>
using namespace std;
int arr[50][50] = {1};
char cities[50][50];
int main(){
    int N, count=0;
    cin >> N;
    for (int i =0;i<N;i++){
        for (int j =0;j<N;j++){
            cin >> cities[i][j];
            if (cities[i][j]=='C')count++;
            arr[i][j]=1;
        }
    }
    int used=0;
    for (int i =0;i<N;i++){
        for (int j =0;j<N;j++) {
            if (count/2>used)
                arr[i][j]=2;
            if (count/2>used && cities[i][j]=='C')
                used++;
            cout << arr[i][j];
            }
         cout << endl;
    }
}