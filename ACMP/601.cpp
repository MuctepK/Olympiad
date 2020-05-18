#include <bits/stdc++.h>
using namespace std;

map <int, set <pair<int,int> > > rooms;
map <int, pair<int,int>> color;
int main(){
    int N, M, x, y, c, K; cin >> N >> M;

    for (int i =0;i<M;i++){
        cin >> x >> y >> c;
        rooms[x].insert(make_pair(y, c));
        rooms[y].insert(make_pair(x, c));
    }
    cin >> K;
    int room =1;
    for (int i =0;i<K;i++){
        cin >> c;
        bool found=false;
        for (auto it: rooms[room]){
            if (it.second==c) {
                room = it.first;
                found=true;
                break;
            }
        }
        if(!found){
            cout << "INCORRECT";
            return 0;
        }
    }
    cout << room;
}
