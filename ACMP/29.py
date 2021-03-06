# Компьютерная игра
# (Время: 1 сек. Память: 16 Мб Сложность: 38%)
# Вы можете вспомнить хоть одного своего знакомого до двадцатилетнего возраста, который в детстве не играл в компьютерные игры? Если да, то может быть вы и сами не знакомы с этим развлечением? Впрочем, трудностей при решении этой задачи это создать не должно.

# Во многих старых играх с двумерной графикой можно столкнуться с подобной ситуацией. Какой-нибудь герой прыгает по платформам (или островкам), которые висят в воздухе. Он должен перебраться от одного края экрана до другого. При этом при прыжке с одной платформы на соседнюю, у героя уходит |y2-y1| единиц энергии, где y1 и y2 – высоты, на которых расположены эти платформы. Кроме того, у героя есть суперприем, который позволяет перескочить через платформу, но на это затрачивается 3*|y3-y1| единиц энергии. Конечно же, энергию следует расходовать максимально экономно.

# Предположим, что вам известны координаты всех платформ в порядке от левого края до правого. Сможете ли вы найти, какое минимальное количество энергии потребуется герою, чтобы добраться с первой платформы до последней?

# Входные данные
# В первой строке входного файла INPUT.TXT записано количество платформ n (1 ≤ n ≤ 30000). Вторая строка содержит n натуральных чисел, не превосходящих 30000 – высоты, на которых располагаются платформы.

# Выходные данные
# В выходной файл OUTPUT.TXT запишите единственное число – минимальное количество энергии, которую должен потратить игрок на преодоление платформ (конечно же в предположении, что cheat-коды использовать нельзя).
N = int(input())
l = [int(i) for i in input().split()]
if N<=2:
    if N==1:
        print(0)
    else:
        print(abs(l[0]-l[1]))
else:
    s=0
    d = [0 for i in range(N)]
    d[1] = abs(l[1]-l[0])
    d[2] = min(abs(l[2-1]-l[2])+d[1],3*abs(l[2-2]-l[2]))
    for i in range(3,N):
        d[i] = min(abs(l[i-1]-l[i])+d[i-1],3*abs(l[i-2]-l[i])+d[i-2])
    
    print(d[-1])