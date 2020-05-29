#include <bits/stdc++.h>
using namespace std;
int main(){
    map <string, int> dic;
    vector <string> vec;
    set <string> se;
    string s;
    int count  =0;
    getline(cin,s);
    se.insert(s);
    vec.push_back(s);
    while (s!="ENDOFINPUT"){
        cin >> s;
        se.insert(s);
        vec.push_back(s);
    }
    for (auto it : vec){
        for (int i =1;i<it.size();i++){
            if (se.count(it.substr(0,i)) && se.count(it.substr(i,it.size()-i))) {
                count++;
                break;
            }
        }
    }
    cout << count;
}

