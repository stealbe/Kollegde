from array import array


def printN(
        str="Don't let the noise of others opinions\n\t\t drown out your own inner voice.\n\t\t\t\t\t\t\t Steve Jobs"):
    print(str)


printN()


def line(lengh, char, dir="\n"):
    str = ""
    if "\t" in dir and "-\t" not in dir:
        for i in range(lengh):
            str += ("\n" + "\t" * i + char)
    elif "-\t" in dir:
        for i in range(lengh, 0, -1):
            str += ("\n" + "\t" * i + char)
    else:
        for i in range(lengh):
            str += (char + dir)
    print(str)


line(10, "a", "")
line(10, "a")
line(10, "a", "\n" + "\t")
line(10, "a", "\n" + "-\t")


def maxN(*nums):
    nums = tuple(nums)
    if isinstance(nums[0], (list, tuple)):
        nums = nums[0]
    max = nums[0]
    for i in range(len(nums)):
        if nums[i] > max: max = nums[i]

    return max


print(maxN(-10, -10, -3, -2))


def simple(n):
    for i in range(0, n):
        if n % i == 0:
            return False
    return True


def simpleList(start, finish):
    l = []
    for i in range(start, finish + 1):
        if simple(i):
            l.append(i)
    return l


def winNum(num):
    num = str(num)
    if int(num[0]) + int(num[1]) + int(num[2]) == int(num[3]) + int(num[4]) + int(num[5]):
        return True
    else:
        return False


print(winNum(656672))
print(winNum(656673))
print(winNum(656674))


def digNums(s, f):
    s, f = int(s), int(f)
    res = min(s, f)
    for i in range(min(s, f) + 1, max(s, f) + 1):
        res *= i
    return res


print(digNums(1, 100))

import random

random.seed(4254)


def lenGen(len):
    list = []
    for i in range(len):
        list.append(random.randint(1, 1000))
    return list


listN = lenGen(10)
print(listN)
print(maxN(listN))
