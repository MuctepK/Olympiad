#include <bits/stdc++.h>
using namespace std;
char arr[100][100];
int main(){
    int N,M,count=0;cin>>N>>M;
    map < char, pair<int,int> > dic;
    vector <char> big, little;
    for (int i =0;i<N;i++){
        for (int j =0;j<M;j++){
            cin >> arr[i][j];
            if (arr[i][j]!='.') dic[arr[i][j]] = make_pair(i,j);
        }
    }
    for (int i =0;i<N;i++){
        for (int j =0;j<M;j++){
            cin >> arr[i][j];
            if (arr[i][j]!='.') {
                int x, y;
                tie(x, y) = (dic[arr[i][j]]);
                if (x!=i || y!=j){
                    count++;
                    if (isupper(arr[i][j]))big.push_back(arr[i][j]);
                    else little.push_back(arr[i][j]);
                }

            }
        }
    }
    sort(little.begin(), little.end());
    sort(big.begin(),big.end());
    cout << count << endl;
    for (auto it: little)cout << it;
    for (auto it: big) cout << it;
}
