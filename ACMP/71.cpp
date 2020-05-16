#include <bits/stdc++.h>
using namespace std;

int arr[20];
int N, m=1000000000, sum=0;
vector < vector <int> > v;
vector <int> temp;
void calculate(int element, int current_sum, int size ){

    if (size>=N-1){
        return;
    }
    temp.push_back(element);
    int another=sum-current_sum;
    if (abs(another-current_sum)<m) {
        m = abs(another-current_sum);
    }
    for (int i =element;i<N;i++){
        calculate(i+1, current_sum+arr[i], size+1);
    }
}
int main(){
    cin >> N;
    for (int i =0;i<N;i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    calculate(0,0, 0);
//    for (const auto& vec : v){
//        for (auto it : vec){
//            cout << it << "---------";
//        }
//        cout << endl;
//    }
    cout << m << endl;
}

