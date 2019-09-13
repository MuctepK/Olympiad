dic_1 = {i:chr(65+i-10) for i in range(10,36)}
dic_2 = {chr(65+i-10):i for i in range(10,36)}
 
 
 
def convert_decimal_to(n,base):
    s=''
    while n:
        remainder =  n%base
        remainder = str(remainder) if remainder < 10 else dic_1[remainder]
        s = remainder + s
        n//=base
    return s
     
     
def convert_to_decimal_from(s,base):
    decimal = 0
    for i in s:
        digit = int(i) if i.isdigit() else dic_2[i]
        decimal = decimal * base + digit
    return decimal
     
     
From, to = map(int,input().split())
s = input()
if From!=10:
    s = convert_to_decimal_from(s,From)
if to!=10:
    s = convert_decimal_to(int(s),to)
print(s)