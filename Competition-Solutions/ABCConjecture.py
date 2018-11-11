import math
import sys

def getPrimes(n):
    nPrimes = set()
    def factor(x):
        if x % 2 == 0:
            return 2
        for res in range(3, int(math.sqrt(x)) + 1, 2):
            if x % res == 0:
                return res
        return x
    while n > 1:
        fact = factor(n)
        nPrimes.add(fact)
        n //= fact
    return nPrimes

for line in sys.stdin:
    arr = line.split()
    a = int(arr[0])
    b = int(arr[1])
    c = a + b

    aPrimes = getPrimes(a)
    bPrimes = getPrimes(b)

    if len(aPrimes.intersection(bPrimes)) != 0:
        print("bad")
        continue
    
    res = 1
    allPrimes = getPrimes(a * b * c)
    for prime in allPrimes:
        res *= prime
    if res < c:
        print("less")
    elif res > c:
        print("greater")
    else:
        print("equal")
