dic_2 = {chr(65+i-10):i for i in range(10,36)}


def convert_to_decimal_from(s,base):
    decimal = 0
    for i in s:
        digit = int(i) if i.isdigit() else dic_2[i]
        decimal = decimal * base + digit
    return decimal


decr = {i+1: chr(ord('a')+i) for i in range(26)}
decr[27] = ' '
s = input()
s = [convert_to_decimal_from(i, 27) for i in s]

for i in range(len(s)):
    s[i] = s[i]-i-1
    if s[i] <=0:
        while s[i] <=0:
            s[i]+=27
    s[i] = decr[s[i]]
print(''.join(s))