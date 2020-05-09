#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    set <string> se;
    cin >> s;
    for (int i =0;i<s.size()-2; i++){
        for(int j =i+1;j<s.size()-1;j++){
            for(int k=j+1;k<s.size();k++){
                if (s[i]!='0') {
                    string temp;
                    temp.push_back(s[i]);
                    temp.push_back(s[j]);
                    temp.push_back(s[k]);
                    se.insert(temp);
                }
            }
        }
    }
    cout << se.size();
}