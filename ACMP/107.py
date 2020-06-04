def calculate(s):
    if len(s)==2:
        if s[0]==s[1]:
            return 2
    elif len(s)==3:
        if s[0]==s[-1] and s[0] !=s[1] or s[0] == s[1] and s[0]!=s[-1] or s[1]==s[-1] and s[1]!=s[0]:
            return 2
        elif s[0]==s[1]==s[2]:
            return 3
    elif len(s)==4:
        if len(set(s))==3:
            if s[0]==s[2] and s[0] != s[1] and s[1] != s[3] and s[0]!=s[3] or s[1] ==s[3] and s[1] != s[0] and s[0]!=s[2] and s[2] != s[1]:
                return 2
        elif len(set(s))==2:
            if s[0] == s[-1] and s[0] !=s[1] and s[1] == s[2]:
                return 4
            if s[0] == s[2] and s[0] != s[1] and s[1] == s[3] or s[0] ==s[1] and s[0] !=s[2] and s[2] == s[3] or s[0] !=s[1] and s[1] == s[2] == s[3] or s[0] !=s[1] and s[0] ==s[2] == s[3] or s[0] ==s[1] == s[3] and s[1] !=s[2] or s[0] == s[1] == s[2] and s[2] !=s[3]:
                return 3

        elif len(set(s)) == 1:
            return 5

    return 0

groups = [[2, 2, 3], [2, 3, 2], [3, 2, 2], [3, 4], [4, 3]]
s = input()
l, m, index,  = [], 0, -1
for i, group in enumerate(groups):
    if len(group)==3:
        first, second, third = s[:group[0]], s[group[0]:group[0]+group[1]], s[group[0]+group[1]:]
        c = calculate(first) + calculate(second) + calculate(third)
        l.append('{}-{}-{}'.format(first,second,third))
        if c > m:
            m = c
            index = i
    else:
        first, second = s[:group[0]], s[group[0]:]
        c = calculate(first) + calculate(second)
        l.append('{}-{}'.format(first,second))
        if c > m:
            m = c
            index = i
print(l[index], m, sep='\n')