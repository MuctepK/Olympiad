#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[20][101], N, M, dist[20][101], path[20][101];

void find_min(int i, int j);

int main(){
    cin >> N >> M;
    for (int i =1;i<=N;i++){
        for (int j =1;j<=M;j++){
            cin >> arr[i][j];
        }
    }
    for (int i =1;i<=N;i++){

        dist[i][1] = arr[i][1];
        path[i][1] = -1;
    }
    for (int i=2;i<=M;i++){
        for (int j =1;j<=N;j++){
            dist[j][i]=100000000;
        }
    }
    for (int i =2;i<=M;i++){
        for (int j=1;j<=N;j++){
            find_min(j,i);
        }
    }
    int min_index=-1, min=1000000;
    for (int i =1;i<=N;i++){
        if (dist[i][M]<min){
            min=dist[i][M];
            min_index=i;
        }

    }
    int y = min_index, x=M;
    vector <int> vec;
    while (true){
        vec.push_back(y);
        if (path[y][x]==-1) break;
        y = path[y][x];x--;
    }
    reverse(vec.begin(),vec.end());
    for (auto it: vec){
        cout << it << " ";
    }
    cout << endl;
    cout << min;
}
bool in_bounds(int j, int i){
    return i>=1&&i<=M&&j>=1&&j<=N;
}
void find_min(int i, int j) {

    if (in_bounds(i-1,j-1)&&dist[i][j]>dist[i-1][j-1]+arr[i][j]){
        dist[i][j] = dist[i-1][j-1]+arr[i][j];
        path[i][j] = i-1;
    }
    if (in_bounds(i,j-1)&&dist[i][j]>dist[i][j-1]+arr[i][j]){
        dist[i][j] = dist[i][j-1]+arr[i][j];
        path[i][j] = i;
    }
    if (in_bounds(i+1,j-1)&&dist[i][j]>dist[i+1][j-1]+arr[i][j]){
        dist[i][j] = dist[i+1][j-1]+arr[i][j];
        path[i][j] = i+1;
    }
}
