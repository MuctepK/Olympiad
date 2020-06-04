#include <bits/stdc++.h>
using namespace std;
int LIFO(deque < pair <int, int> > arrival, int release){
    arrival.back().first-=release;
    int weight,price, remain=0;
    while (!arrival.empty() && arrival.back().first <=0){
        tie(weight,price) = (arrival.back());
        arrival.pop_back();
        if (!arrival.empty())
            arrival.back().first+=weight;
    }
    while (!arrival.empty() && arrival.back().first>0){
        tie(weight,price) = (arrival.back());
        arrival.pop_back();
        remain +=weight*price;
    }
    return remain;
}
int FIFO(deque < pair <int, int> > arrival, int release){
    arrival.front().first-=release;
    int weight,price, remain=0;
    while (!arrival.empty() && arrival.front().first <=0){
        tie(weight,price) = (arrival.front());
        arrival.pop_front();
        if (!arrival.empty())
            arrival.front().first+=weight;
    }
    while (!arrival.empty() && arrival.front().first>0){
        tie(weight,price) = (arrival.front());
        arrival.pop_front();
        remain +=weight*price;
    }
    return remain;
}
int MEDIUM(deque <pair<int,int>> arrival, int release){
    int total_weight=0, remaining_weight=0, total=0, medium;
    for (auto it : arrival) {
        total_weight += it.first;
        total+=it.first*it.second;
    }
    medium = total/total_weight;
    remaining_weight = total_weight-release;
    return medium*remaining_weight;

}
int main(){
int N,M,K,weight,price, temp, fifo, lifo, medium;
vector <pair <int, string>> ans = {
        {0,"FIFO"}, {0, "LIFO"}, {0,"MEDIUM"}
};
cin >> N;
for (int i =0;i<N;i++){
    cin >> M >> K;
    deque <pair<int,int>> arrival;
    int release=0;
    for (int m=0;m<M;m++){
        cin >> weight >> price;
        arrival.emplace_back(make_pair(weight,price));
    }
    for (int k=0;k<K;k++){
        cin >> temp;
        release+=temp;
    }
    fifo = FIFO(arrival, release); lifo = LIFO(arrival, release); medium = MEDIUM(arrival, release);
    cout << fifo << "\n" << lifo << "\n" << medium << "\n";
    ans[0].first+=fifo; ans[1].first += lifo; ans[2].first +=medium;

}
sort(ans.begin(), ans.end(),[] (const pair<int, string> &a,const pair<int, string> &b) -> bool{
    return a.first < b.first ? true : a.second < b.second;
});
cout << ans[0].second;

}
