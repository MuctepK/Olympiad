#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin >> N;
    double x, y;
    map <double, bool> dic;
    vector <pair<double, double> > vec;
    for (int i=0;i<N;i++){
        cin >> x >> y;
        vec.emplace_back(make_pair(x, y));
    }
    for (int i =0;i<vec.size()-1;i++){
        for (int j =i+1;j<vec.size();j++){
            double x1,y1,x2,y2;
            tie(x1,y1) = vec[i];
            tie(x2, y2) = vec[j];
            dic[sqrt(pow((x1-x2),2) + pow(y1-y2,2))] = true;
        }
    }
    cout << dic.size() << endl;
    for (auto it: dic){
        printf("%.12f\n", it.first);
    }
}

