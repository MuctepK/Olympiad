# ЗАДАЧА №122		
# Максимальная подпоследовательность
# (Время: 1 сек. Память: 16 Мб Сложность: 38%)
# Дана числовая последовательность, требуется найти длину наибольшей возрастающей подпоследовательности.

# Входные данные
# В первой строке входного файла INPUT.TXT записано число N - длина последовательности (1 ≤ N ≤ 1000). Во второй строке записана сама последовательность (через пробел). Числа последовательности - целые числа, не превосходящие 10000 по модулю.

# Выходные данные
# В выходной файл OUTPUT.TXT требуется вывести наибольшую длину возрастающей подпоследовательности.
N = int(input())
arr = [int(i) for i in input().split()]
res_arr=[]
d = [0 for i in range(N)]
p = [-1 for i in range(N)]
for i in range(N):
	d[i]=1
	for j in range(0,i):
		if arr[j]<arr[i]:
			if 1+d[j]>d[i]:
				d[i]=1+d[j]
				p[i]=j
ans=d[0]
start=0
for i in range(1,N):
	if ans<d[i]:
		ans=d[i]
		start=i
# while start!=-1:
# 	res_arr.append(arr[start])
# 	start = p[start]
print(ans)
# print(reversed(res_arr))