#include <bits/stdc++.h>
using namespace std;
int arr[9][9];
bool used[9][9];
int attack_count=1;
bool in_bounds(int x, int y){
    if (x > 0 && x < 9 && y > 0 && y < 9 && !used[x][y]){
        attack_count++;
        used[x][y] = true;
    }
}
void check_horizontal(int x, int y){
    for (int i=1;i<9;i++)
        in_bounds(x,i);
}
void check_vertical(int x, int y){
    for (int i=1;i<9;i++)
        in_bounds(i, y);
}
void check_diagonal(int x, int y){
    int x1=x, y1=y;
    while (x1>0&&y1>0){
        in_bounds(x1,y1);
        x1--;y1--;
    }
    x1=x, y1=y;
    while (x1<9&&y1<9){
        in_bounds(x1,y1);
        x1++;y1++;
    }
    x1=x, y1=y;
    while (x1<9&&y1>0){
        in_bounds(x1,y1);
        x1++;y1--;
    }
    x1=x, y1=y;
    while (x1>0&&y1<9){
        in_bounds(x1,y1);
        x1--;y1++;
    }
}
void check_horse(int x, int y){
    in_bounds(x+2, y+1);
    in_bounds(x-2, y+1);
    in_bounds(x+2, y-1);
    in_bounds(x-2, y-1);
    in_bounds(x+1, y+2);
    in_bounds(x-1, y+2);
    in_bounds(x+1, y-2);
    in_bounds(x-1, y-2);

}
int main(){
    map <char, int> dic = {
            {'A',1},
            {'B',2},
            {'C',3},
            {'D',4},
            {'E',5},
            {'F',6},
            {'G',7},
            {'H',8},
    };
    string F, L, K;
    cin >> F >> L >> K;
    int f_y = dic[F[0]], f_x = int(F[1]-'0'), l_y = dic[L[0]], l_x = int(L[1]-'0'), k_y = dic[K[0]], k_x = int(K[1]-'0');
    used[f_x][f_y] = used[l_x][l_y] = used[k_x][k_y] = true;
    check_diagonal(f_x,f_y); check_horizontal(f_x,f_y); check_vertical(f_x, f_y);
    check_vertical(l_x, l_y); check_horizontal(l_x, l_y);
    check_horse(k_x, k_y);
    cout << attack_count-1;
}
