a, b, c = map(int,input().split())
a, b, c = a if a!=0 else "", b if b!=0 else "", c if c!=0 else ""

if b!="":
    b = '+' + str(b)  + 'x' if b >1  else '+x' if b==1 else '-x' if b==-1 else str(b) + 'x'
    if a=="" and b[0]!='-':
        b = b[1:]
if c!="":
    c = '+' + str(c)  + 'y' if c >1  else '+y' if c==1 else '-y' if c==-1 else  str(c) + 'y'
    if b==""   and c[0]!='-' and a=="" :
        c=c[1:]
s = str(a)+b+c
print(s if s else 0)
