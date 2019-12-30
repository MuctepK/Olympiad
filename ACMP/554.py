# Пицца
# (Время: 1 сек. Память: 16 Мб Сложность: 20%)
# Пицца – любимое лакомство Васи, он постоянно покупает и с удовольствием употребляет различные сорта этого великолепного блюда. Однажды, в очередной раз, разрезая круглую пиццу на несколько частей, Вася задумался: на какое максимальное количество частей можно разрезать пиццу за N прямых разрезов?

# Помогите Васе решить эту задачу, определив максимальное число не обязательно равных кусков, которые может получить Вася, разрезая пиццу таким образом.

# Входные данные
# Входной файл INPUT.TXT содержит натуральное число N – число прямых разрезов пиццы (N ≤ 1000).
N = int(input())
l = [2]
for i in range(1,N):
    l.append(l[i-1]+i+1)
print(l[-1])