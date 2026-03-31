def Square(size, char, fill):
    if fill:
        for i in range(size):
            print(char*size)
    else:
        print(char*size)
        for i in range(size-2):
            print(char+' '*(size-2)+char)
        print(char*size)

Square(30,'*',True)

def MinN(*nums):
    res = nums[0]
    for num in nums:
        if num < res:
            res = num
    return res

print(MinN(3,42,-5,67,-35))