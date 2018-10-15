from sys import stdin, stdout
from math import sqrt
import decimal

def isSquare(apositiveint):
    x = apositiveint // 2
    seen = set([x])
    while x * x != apositiveint:
        x = (x + (apositiveint // x)) // 2
        if x in seen:
            return False
        seen.add(x)
    return True

if __name__ == '__main__':
    decimal.getcontext().prec = 5000
    for line in stdin:
        arr = [str(x) for x in line.split()]

        p1, q1, p2, q2 = 1, 1, 1, 1
        s1, s2 = arr[0].find('/'), arr[1].find('/')

        if s1 == -1:
            p1 = int(arr[0])
        else:
            p1 = int(arr[0][:s1])
            q1 = int(arr[0][s1 + 1:])

        if s2 == -1:
            p2 = int(arr[1])
        else:
            p2 = int(arr[1][:s2])
            q2 = int(arr[1][s2 + 1:])

        hasRationalArea = (((p1 * p2) % (q1 * q2)) == 0)

        t11 = (p1**2 * q2**2) + (p2**2 * q1**2)
        t12 = int(decimal.Decimal(t11).sqrt())
        hasRationalC = (t11 == t12 * t12)

        if hasRationalArea and hasRationalC:
            print((p1 * p2) // (q1 * q2) // 2)
        else:
            print('no')
