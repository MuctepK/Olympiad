# https://www.codewars.com/kata/path-finder-number-1-can-you-reach-the-exit/python
# Task
# You are at position [0, 0] in maze NxN and you can only move in one of the four cardinal directions (i.e. North, East, South, West). Return true if you can reach position [N-1, N-1] or false otherwise.
#
# Empty positions are marked .. Walls are marked W. Start and exit positions are empty in all test cases.
from queue import Queue


def available(maze, x, y):
    return 0 <= x < len(maze) and 0 <= y < len(maze)


def check_and_put(maze, used, que, x, y):
    if available(maze, x, y) and not used[x][y] and maze[x][y] == '.':
        que.put((x, y))
        used[x][y] = True


def path_finder(maze):
    maze = maze.split('\n')
    used = [[False for i in range(len(maze))] for j in range(len(maze))]
    que = Queue()
    que.put((0, 0))
    used[0][0] = True
    while not que.empty():
        x, y = que.get()
        for x, y in (x+1, y), (x-1, y), (x, y + 1), (x, y - 1):
            check_and_put(maze, used, que, x, y)
    return used[-1][-1]
