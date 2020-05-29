#include <bits/stdc++.h>
using namespace std;
char arr[55][55];
bool used[55][55];
int walls;
int N;

void count_walls(int x, int y);

int main(){
    for (int i=0;i<55;i++){
        for (int j=0;j<55;j++)
        {
            arr[i][j]='#';
        }
    }
     cin >> N;
    queue <pair<int,int> > que;
    for (int i =1;i<=N;i++){
        for (int j =1;j<=N;j++){
            cin >> arr[i][j];
        }
    }
    used[1][1] = true;
    que.push(make_pair(1,1));
    while (!que.empty()){
        int x,y;
        tie(x,y) = que.front();
        que.pop();
        count_walls(x,y);
        if (arr[x][y+1]!='#' && !used[x][y+1]){
            used[x][y+1] = true;
            que.push(make_pair(x,y+1));
        }
        if (arr[x][y-1]!='#' && !used[x][y-1]){
            used[x][y-1] = true;
            que.push(make_pair(x,y-1));
        }
        if (arr[x+1][y]!='#' && !used[x+1][y]){
            used[x+1][y] = true;
            que.push(make_pair(x+1,y));
        }
        if (arr[x-1][y]!='#' && !used[x-1][y]){
            used[x-1][y] = true;
            que.push(make_pair(x-1,y));
        }

    }
    if (!used[N][N]){
        used[N][N] = true;
        que.push(make_pair(N,N));
        while (!que.empty()){
            int x,y;
            tie(x,y) = que.front();
            que.pop();
            count_walls(x,y);
            if (arr[x][y+1]!='#' && !used[x][y+1]){
                used[x][y+1] = true;
                que.push(make_pair(x,y+1));
            }
            if (arr[x][y-1]!='#' && !used[x][y-1]){
                used[x][y-1] = true;
                que.push(make_pair(x,y-1));
            }
            if (arr[x+1][y]!='#' && !used[x+1][y]){
                used[x+1][y] = true;
                que.push(make_pair(x+1,y));
            }
            if (arr[x-1][y]!='#' && !used[x-1][y]){
                used[x-1][y] = true;
                que.push(make_pair(x-1,y));
            }

        }
    }
    cout << (walls-4)*25;

}

void count_walls(int x, int y) {

        if (arr[x+1][y]=='#')walls++;
        if (arr[x-1][y]=='#')walls++;
        if (arr[x][y+1]=='#')walls++;
        if (arr[x][y-1]=='#')walls++;


}
