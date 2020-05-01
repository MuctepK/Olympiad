st = input().strip()
n = int(input())
if n>0:
    if len(st)>=1023:
        print(st[:1023])
    else:
        initial = st
        for i in range(n-1):
            if len(st)>1023:
                break
            st += initial
        print(st[:1023])
else:
    n*=-1
    size = len(st)//n
    temp= st[:size]
    if temp*n==st:
        print(temp[:1023])
    else:
        print("NO SOLUTION")