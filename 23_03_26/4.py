def PrintText():
    print(
        f"\"Don't compare yourself with anyone in this world…\n\tif you do so, you are insulting yourself.\"\n\t\tBill Gates")


PrintText()


def TwinNums(start, end):
    res = []
    for i in range(start, end):
        if i % 2 == 0:
            res.append(i)
    return res

print(TwinNums(0,5))