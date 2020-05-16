def calc(n):
    if n<0:
        return 0
    if n==0:
        return 1
    if n==1:
        return 1
    if n==2:
        return 1
    else:
        return calc(n-1)+calc(n-2)+calc(n-4)
d = [0] * 1001
d[1], d[0],d[2] = 1, 1, 2
decrease = [2]
powers = [2, 4, 8, 16, 32, 64, 128, 256, 512]
for i in range(3,1001):
    d[i] += d[i-1]
    if i in powers:
        decrease.append(i)
    if i%2==0:
        for _ in range(len(decrease)):
            d[i] +=1
print(d)
print(calc(5))