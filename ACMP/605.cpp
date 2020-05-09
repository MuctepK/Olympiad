#include <bits/stdc++.h>
using namespace std;
string cout_value(int x, int mul, int extra=0){
    if (x==0)return "";

    switch (mul) {
        case 0: return "";
        case 1: return to_string(x) + " ";
        case 2: return "D" + to_string(x) + " ";
        case 3: if (extra==50) return "Bull "; else return "T" + to_string(x) + " ";
        case 4: return "25 ";
        case 5: return "Bull ";
    }
}
int main(){
    int N;
    cin >> N;
    set <string> se;
    for (int i_mul=0;i_mul<6;i_mul++) {
        for (int i = 1; i < 21; i++) {
            for (int j_mul = 0; j_mul < 6; j_mul++) {
                for (int j = 1; j < 21; j++) {
                    for (int k_mul=2;k_mul<4;k_mul++) {
                        for (int k = 1; k < 21; k++) {
                            if (i_mul<4&&k_mul==2&&j_mul<4) {
                                if ((i * i_mul + j * j_mul + k * k_mul) == N) {
                                    string t;
                                    t += cout_value(i, i_mul);
                                    t += cout_value(j, j_mul);
                                    t += cout_value(k, k_mul);
                                    se.insert(t);
                                }
                            }
                            else{
                                int first = i_mul < 4? i*i_mul: i_mul == 4? 25: 50;
                                int second = j_mul < 4? j*j_mul: j_mul == 4? 25: 50;
                                int third = k_mul < 3? k*k_mul: 50;
                                if (first+second+third==N){
                                    string t;
                                    t += cout_value(i, i_mul, first);
                                    t += cout_value(j, j_mul, second);
                                    t += cout_value(k, k_mul, third);
                                    se.insert(t);
                                }
                            }
                        }
                    }

                }
            }
        }
    }
    cout << se.size() << endl;
    for (const auto& it : se){
        cout << it << endl;
    }
}

