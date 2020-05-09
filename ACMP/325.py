import sys

dic = {chr(ord('a')+i): i+1 for i in range(8)}


def check(x, y, count):
    global end_x, end_y
    if x < 1 or x > 8 or y < 1 or y > 8 or count > 2:
        return
    if x == end_x and y == end_y:
        print(2 if count == 0 else count)
        sys.exit()
    for new_x, new_y in (x+1, y+2), (x-1, y+2), (x+1, y-2), (x-1, y-2), (x+2,y+1), (x-2,y+1), (x+2,y-1), (x-2,y-1):
        check(new_x, new_y, count+1)


start, end = input().split()
start_x, start_y, end_x, end_y = int(dic[start[0]]) , int(start[1]), int(dic[end[0]]), int(end[1])
check(start_x, start_y, 0)
print('NO')