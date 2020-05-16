N, M = map(int,input().split())
l = [[int(i) for i in input().split()] for j in range(N)]
transposed = list(zip(*l))
bottom = max([min(l[i])for i in range(N)])
top = min([max(transposed[i]) for i in range(M)])
print(bottom, top)