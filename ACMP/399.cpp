#include <bits/stdc++.h>
using namespace std;
char arr[105][105];
int arr_count[105][105];
int N, M;
bool is_available(int x, int y){
    return x>=0&&x<N&&y>=0&&y<M&&(arr[x][y]!='@');
}
int get_minimum(int x, int y){
    int Min=10000009;
    if (is_available(x+1,y))
        Min = min(arr_count[x+1][y],Min);

    if (is_available(x,y+1))
        Min = min(arr_count[x][y+1],Min);

    if (is_available(x-1,y))
        Min = min(arr_count[x-1][y],Min);

    if (is_available(x,y-1))
        Min = min(arr_count[x][y-1],Min);

    return Min;
}
int get_step(int x, int y, int previous){
    vector <pair<int,int>> v;
    int Min = get_minimum(x, y);
    if (Min==10000009) return -1;
    if (previous!=-1){
        switch (previous) {
            case 0: if(is_available(x+1, y) && Min==arr_count[x+1][y]) return 0; break;
            case 1: if(is_available(x, y+1) && Min==arr_count[x][y+1]) return 1; break;
            case 2: if(is_available(x-1, y) && Min==arr_count[x-1][y]) return 2; break;
            case 3: if(is_available(x, y-1) && Min==arr_count[x][y-1]) return 3; break;
        }
    }
    if(is_available(x+1, y) && Min==arr_count[x+1][y]) return 0;
    if(is_available(x, y+1) && Min==arr_count[x][y+1]) return 1;
    if(is_available(x-1, y) && Min==arr_count[x-1][y]) return 2;
    if(is_available(x, y-1) && Min==arr_count[x][y-1]) return 3;
    return -1;

}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    string str;
    arr_count[2][2] = 1;
    for (int i =1;i<=N;i++){
        for (int j =1;j<=M;){
            getline(cin,str);
            for(auto it : str) {
                arr[i][j]=it;
                j++;
            }
        }
    }

    long x=2, y=2, previous_step=-1;
    for (long i = 0;i<9000000;i++){
        if (x==N-1&&y==M-1){
            cout << i;
            return 0;
        }
        int step = get_step(x,y,previous_step);
        switch (step) {
            case -1: cout << -1; return 0;
            case 0: x++; previous_step=0;break;
            case 1: y++; previous_step=1;break;
            case 2: x--; previous_step=2;break;
            case 3: y--; previous_step=3;break;
        }
        arr_count[x][y]++;
    }
    cout << -1;
}