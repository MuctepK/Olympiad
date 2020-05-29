n = int(input())
if n == 2:
    print(3)
elif n == 3:
    print(27)
else:
    n += n*(n-3)//2
    ans=1
    for i in range(1,n+1):
        ans*=3
    print(ans)