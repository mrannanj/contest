#!/usr/bin/python

N = int(input())
A = []

for i in range(N):
    try:
        x = raw_input()
        splitx = x.split()
        for s in splitx:
            try:
                x = int(s)
                A.append(x)
            except:
                break
    except:
        break

t = tuple(A)
print hash(t)
