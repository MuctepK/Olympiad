#include <bits/stdc++.h>
using namespace std;

long long fun(long long N){
	cout << N << endl;
	if (N==1){
		return 1;
	}
	if (N==2){
		return 3;
	}
	if (N==3){
		return 3;
	}
	return fun(N-3)+fun(N-2)+fun(N-1);
}
int main(int argc, char const *argv[])
{
	long long int N;
	cin >> N;
	cout << fun(N);
	return 0;
}