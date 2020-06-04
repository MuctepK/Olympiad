#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long res=0, last =-1;
    bool is_previous = false;
    bool is_cleared = false;
    int N;
    map <int, int> dic;
    vector <int> vec, repeated, non_repeated;
    while (cin >> N){
        if (last==N) is_previous=true;
        else is_previous = false;
        last = N;
        if (!is_previous){

            is_cleared = false;
            if (!repeated.empty()){
                repeated.clear();
                res+=2;
            }
            non_repeated.push_back(N);
            if (non_repeated.size()==128){
                non_repeated.clear();
                is_cleared = true;
                res+=129;
            }
        }
        else{
            if (is_cleared){
                res--;

                is_cleared=false;
            }
            if (!non_repeated.empty()){
                repeated.push_back(non_repeated.back());
                non_repeated.pop_back();
                if (!non_repeated.empty())
                    res+=non_repeated.size()+1;
                non_repeated.clear();

            }
            repeated.push_back(N);
            if (repeated.size()==128){
                repeated.clear();
                res+=2;
            }
        }

    }
    if (!non_repeated.empty()){
        res+=non_repeated.size()+1;
    }
    if (!repeated.empty()){
        res+=2;
    }
    cout << res;
}

