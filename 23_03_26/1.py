def Sum(start, end):
    sum = 0
    while start < end:
        sum += start
        start += 1
    return sum

print(Sum(3,5))

def Mult(list):
    res = 1
    for num in list:
        res *= num
    return res

print(Mult([1,2,3,4,5]))