# https://www.codewars.com/kata/path-finder-number-2-shortest-path/train/python
# Task
# You are at position [0, 0] in maze NxN and you can only move in one of the four cardinal directions (i.e. North, East, South, West). Return the minimal number of steps to exit position [N-1, N-1] if it is possible to reach the exit from the starting position. Otherwise, return false in JavaScript/Python and -1 in C++/C#/Java.
#
# Empty positions are marked .. Walls are marked W. Start and exit positions are guaranteed to be empty in all test cases.
from queue import Queue


def available(maze, x, y):
    return 0 <= x < len(maze) and 0 <= y < len(maze)


def check_and_put(maze, used, que,dist, new_x, new_y, x, y):
    if available(maze, new_x, new_y) and not used[new_x][new_y] and maze[new_x][new_y] == '.':
        que.put((new_x, new_y))
        used[new_x][new_y] = True
        dist[new_x][new_y] = dist[x][y] + 1


def path_finder(maze):
    maze = maze.split('\n')
    used = [[False for i in range(len(maze))] for j in range(len(maze))]
    dist = [[0 for i in range(len(maze))] for j in range(len(maze))]
    que = Queue()
    que.put((0, 0))
    used[0][0] = True
    dist[0][0] = 0
    while not que.empty():
        x, y = que.get()
        for new_x, new_y in (x+1, y), (x-1, y), (x, y + 1), (x, y - 1):
            check_and_put(maze, used, que,dist, new_x, new_y, x, y)
    print(dist)
    return dist[-1][-1]
