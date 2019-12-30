'''Ежеминутные автобусы
(Время: 2 сек. Память: 128 Мб Сложность: 30%)
На автобусную остановку каждую минуту подходит автобус одного из маршрутов. Диспетчерская служба собрала данные за N минут – номера маршрутов каждого автобуса.

Требуется определить максимально возможное время ожидания для пассажира, желающего уехать определенным маршрутом. Т.е. в данной последовательности номеров маршрутов нужно найти два самых удаленных числа, равных между собой, между которыми нет равных им. Например, для последовательности 2, 11, 2, 2, 25, 11, 25, 11 максимальное время ожидания равно 4 (для маршрута номер 11).

Входные данные
Входной файл INPUT.TXT содержит в первой строке число N (2 ≤ N ≤ 106). Во второй строке записаны N чисел – номера маршрутов. Все числа натуральные и не превышают 100. Каждый номер маршрута встречается не менее двух раз.

Выходные данные
В выходной файл OUTPUT.TXT выведите ответ на задачу.

Примеры
№	INPUT.TXT	        OUTPUT.TXT
1	8
    2 11 2 2 25 11 25 11	4
2	4
    23 23 41 41	            1
'''
n = int(input())
l = [int(i) for i in input().split()]
dic = {}
m = 0
for i in range(len(l)):
    index = dic.get(l[i])
    if index != None:
        if m < i - index:
            m = i - index
        dic.update({l[i]: i})
    else:
        dic.update({l[i]: i})

print(m)