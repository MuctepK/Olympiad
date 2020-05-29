from math import factorial
n, m = map(int,input().split())
s = 0
for i in range(m,n+1):
    s+=(factorial(n)//((factorial(i)*factorial(n-i))))
print(s)