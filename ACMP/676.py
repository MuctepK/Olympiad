N = int(input())
d = [0, 1, 1] + [0]*10000
d[1000] = 1
for i in range(3,N+1):
    if i ==1000:
        continue
    if i>1000:
        if d[i-1] + d[i-2] + d[i-1000]>3:
            d[i] = 1
        else:
            d[i] = 2
    else:
        if d[i-1] + d[i-2]>2:
            d[i] = 1
        else:
            d[i] = 2
print(d[N])