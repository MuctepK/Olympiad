import copy


def FIFO(arrival, release):
    arrival = copy.deepcopy(arrival)
    arrival[0][0] -= release
    while arrival and arrival[0][0] <= 0:
        previous, _ = arrival.pop(0)
        if arrival:
            arrival[0][0] += previous
    remain = 0
    while arrival and arrival[0][0]>0:
        weight, price = arrival.pop(0)
        remain += weight*price
    return remain


def LIFO(arrival, release):
    arrival = copy.deepcopy(arrival)
    arrival[-1][0] -= release
    while arrival and arrival[-1][0] <= 0:
        previous, _ = arrival.pop()
        if arrival:
            arrival[-1][0] += previous
    remain = 0
    while arrival and arrival[-1][0] > 0:
        weight, price = arrival.pop()
        remain += weight*price
    return remain


def MEDIUM(arrival, release):
    total_weight = sum(weight for weight, _ in arrival)
    medium = sum(weight*price for weight, price in arrival)//total_weight
    remaining_weight = total_weight - release
    return remaining_weight*medium

res = [[0, 'LIFO'], [0, 'FIFO'], [0, 'MEDIUM']]

for i in range(int(input())):
    K, M = map(int,input().split())
    arrival, release = [], []
    for k in range(K):
        w, p = map(int, input().split())
        arrival.append([w, p])
    for m in range(M):
        release.append(int(input()))
    release = int(sum(release))
    if release > 0:
        lifo, fifo, medium = LIFO(arrival[:], release), FIFO(arrival[:], release), MEDIUM(arrival[:], release)
        print(fifo, lifo, medium, sep='\n')
        res[0][0]+=lifo
        res[1][0]+=fifo
        res[2][0]+=medium
    else:
        print('0\n0\n0')
res.sort(key=lambda x: (x[0],x[1]))
print(res[0][1])
