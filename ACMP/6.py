dic_letter = {'A':1, 'B':2, 'C':3, 'D': 4, 'E':5, 'F':6, 'G':7, 'H':8}
dic_number = {y:x for x,y in dic_letter.items()}


def get_letter(x, y):
    global dic_number
    if x<1 or y < 1 or x > 8 or y > 8:
        return None
    res = dic_number[x] + str(y)
    return res

try:
    start, end = input().split('-')
    if not dic_letter.get(start[0]) or not dic_letter.get(end[0]) or not (0 <int(start[1]) <= 8) or not (0 <int(end[1]) <= 8) or len(start)!=2 or len(end)!=2:
        raise RuntimeError
    x, y = int(dic_letter[start[0]]), int(start[1])
    l = []
    for x, y in ((x+1, y+2), (x-1, y-2), (x-1, y+2), (x+1, y-2), (x+2, y+1), (x-2, y-1), (x-2, y+1), (x+2, y-1)):
        a = get_letter(x, y)
        if a:
            l.append(a)
    if end in l:
        print('YES')
    else:
        print('NO')

except Exception as e:
    print('ERROR')