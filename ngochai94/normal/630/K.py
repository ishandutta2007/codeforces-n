import math

def d(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)
    
def f(n,r):
    return d(n+r-1,r-1)
    
n=input()
print n-n/2-n/3-n/5-n/7+n/6+n/10+n/14+n/15+n/21+n/35-n/30-n/70-n/42-n/105+n/210