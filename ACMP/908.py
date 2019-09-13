import sys
sys.setrecursionlimit(5000)
count = 0
def fun(a):
	global count
	print(count)
	if a==1:
	  return 1
	elif a%2==0 or a%3==0:
	  if a%2==0 and a%3==0:
	    return min(fun(a//3)+1,fun(a//2)+1)
	  elif a%2==0:
	    return min(fun(a//2)+1,fun((a-a%3)//3)+a%3)
	  elif a%3==0:
	    return min(fun(a//3)+1,fun((a-a%2)//2)+a%2)
	else:
	  return fun(a-1)+1
print(fun(10))