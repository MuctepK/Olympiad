'''Римские числа
(Время: 1 сек. Память: 16 Мб Сложность: 50%)
Необходимо сократить дробь, записанную в римской системе счисления. Напомним, что в римской записи используются символы M, D, C, L, X, V и I. Приведем таблицу с примерами перевода римских чисел в арабскую систему:

I - 1	VII - 7	XLVI - 46	CCCII - 302
II - 2	VIII - 8	L - 50	CDXLI - 441
III - 3	IX - 9	LXXV - 75	ID - 499
IV - 4	X - 10	XCII - 92	D - 500
V - 5	XVIII - 18	IC - 99	DCXCV - 695
VI - 6	XXXI - 31	C - 100	CM - 900
Входные данные
Во входном файле INPUT.TXT записана дробь в римской системе счисления. Формат записи считается корректным, если запись представляет собой: римское число, деление, римское число (без пробелов), и каждое из чисел находится в диапазоне от 1 до 999. Строка заданной дроби состоит не более, чем из 100 символов.

Выходные данные
В выходной файл OUTPUT.TXT выведите сокращенную дробь в римской системе счисления. В тех случаях, когда первое число делится на второе, следует выводить результат в виде только одного римского числа. В том случае, когда во входных данных содержится ошибка, следует вывести ERROR.'''
from math import gcd
def RomanToInt(string):
    to_add = {
        'M': 1000,
        'D': 500,
        'C': 100,
        'L': 50,
        'X': 10,
        'V': 5,
        'I': 1
    }
    to_delete = [('IV',2), ('IX',2), ('XL',20), ('XC',20), ('CD',200), ('CM',200)]
    s = sum([to_add[i] for i in string])
    s -= sum([to_delete[i][1] for i in range(len(to_delete)) if to_delete[i][0] in string])
    return s

def IntToRoman(integer):
    dic = {
        'M': 1000,
        'CM':900,
        'D': 500,
        'CD': 400,
        'C': 100,
        'XC':90,
        'L': 50,
        'XL':40,
        'X': 10,
        'IX': 9,
        'V': 5,
        'IV':4,
        'I': 1
    }
    s=''
    for letter, value in dic.items():
        while integer>=value:
            integer-=value
            s+=letter
    return s
available = ['/','M','D','C','L','X','V','I']
s = input()
for i in s:
    if not i in available:
        print('ERROR')
        break
else:
    first, second = s[:s.index('/')], s[s.index('/')+1:]
    first, second = RomanToInt(first), RomanToInt(second)
    if first%second==0:
        result = IntToRoman(first//second)
    else:
        div = gcd(first,second)
        first, second = first//div, second//div
        result = IntToRoman(first) + '/' + IntToRoman(second)
    print(result)
