def normalize(a, b):
    if a > b:
        return a
    else:
        return b

a = 1
b = 10
if (normalize(a,b) != b):
    buf = a
    a = b
    b = buf
while a < b:
    if a % 2 == 0:
        print(a)
    a += 1

a = 1
b = 10
if (normalize(a,b) != b):
    buf = a
    a = b
    b = buf
while a < b:
    if b % 2 != 0:
        print(b)
    b -= 1