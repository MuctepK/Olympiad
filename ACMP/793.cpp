#include <bits/stdc++.h>
using namespace std;
vector <int> divisors;
bool is_prime(long x){
    if (x<2) return false;
    if (x==2) return true;
    if (x%2==0) return false;
    for (int i =3;i<=sqrt(x)+1;i+=2){
        if (x%i==0) return false;
    }
    return true;
}
void calculate_divisors(){
    for (int i=2;i<=10000;i++){
        if (is_prime(i))divisors.emplace_back(i);
    }
}

long get_sum_of_digits(long x){
    long s=0;
    while (x){
        s+=(x%10);
        x/=10;
    }
    return s;
}
long get_divisors_sum_of_digit(long x){
    long s=0;
    long limit = x/2;
    for (int i=2;i<=limit;i++) {
        while (x % i == 0) {
            s+=get_sum_of_digits(i);
            x /= i;
        }
    }
    return s;
}
bool is_smith(long n) {
    return !is_prime(n) && get_sum_of_digits(n) == get_divisors_sum_of_digit(n);
}

int main(){
    calculate_divisors();
    long n;
    while (cin>>n){
        if(is_smith(n))cout<<"1";
        else cout <<"0";
    }
}
