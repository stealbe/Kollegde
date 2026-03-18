import random

digits1 = tuple([random.randint(0, 100) for i in range(100)])
digits2 = tuple([random.randint(0, 100) for i in range(100)])
digits3 = tuple([random.randint(0, 100) for i in range(100)])

simple = []
for i in range(100):
    if i in digits1 and i in digits2 and i in digits3:
        if digits1.index(i) == digits2.index(i) and digits3.index(i) == digits1.index(i):
            simple.append(i)

print(simple)