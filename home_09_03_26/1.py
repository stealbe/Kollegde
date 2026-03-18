import random

random.seed(9657437529658)
digits1 = tuple([random.randint(0, 999) for i in range(100)])
random.seed(4346756)
digits2 = tuple([random.randint(0, 999) for i in range(100)])
random.seed(7565237364)
digits3 = tuple([random.randint(0, 999) for i in range(100)])

print(digits1)
print(digits2)
print(digits3)

# 1
print(f'1')
simple = []
for digit in digits1:
    if digit in digits2 and digit in digits3:
        simple.append(digit)

# for digit in digits1:
#     if digit in digits2 and digit in digits3 and digit not in simple:
#         simple.append(digit)

print(simple)

# 2
print(f'2')
notSimple = []
for digit in digits1:
    if digit not in digits2 and digit not in digits3:
        notSimple.append(digit)

# for digit in digits1:
#     if digit not in digits2 and digit not in digits3 and digit not in notSimple:
#         notSimple.append(digit)

print(notSimple)

# 3
print(f'3')
digits1 = tuple([random.randint(0, 100) for i in range(100)])
digits2 = tuple([random.randint(0, 100) for i in range(100)])
digits3 = tuple([random.randint(0, 100) for i in range(100)])

simple = []
for i in range(100):
    if i in digits1 and i in digits2 and i in digits3:
        if digits1.index(i) == digits2.index(i) and digits3.index(i) == digits1.index(i):
            simple.append(i)

print(simple)
