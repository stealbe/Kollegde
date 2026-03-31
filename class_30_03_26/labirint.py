Labirint = {
    0: {'n': 'RN', 'code': {'T': '###', 'M': '\v\v#', 'B': '###'}},
    1: {'n': 'LN', 'code': {'T': '###', 'M': '#\v\v', 'B': '###'}},
    2: {'n': 'TN', 'code': {'T': '###', 'M': '#\v#', 'B': '#\v#'}},
    3: {'n': 'BN', 'code': {'T': '#\v#', 'M': '#\v#', 'B': '###'}},
    4: {'n': 'TB', 'code': {'T': '#\v#', 'M': '#\v#', 'B': '#\v#'}},
    5: {'n': 'RL', 'code': {'T': '###', 'M': '\v\v\v', 'B': '###'}},
    6: {'n': 'CR', 'code': {'T': '#\v#', 'M': '\v\v\v', 'B': '#\v#'}},
    7: {'n': 'TR', 'code': {'T': '#\v#', 'M': '#\v\v', 'B': '###'}},
    8: {'n': 'BR', 'code': {'T': '###', 'M': '#\v\v', 'B': '#\v#'}},
    9: {'n': 'TL', 'code': {'T': '#\v#', 'M': '\v\v#', 'B': '###'}},
    10: {'n': 'BL', 'code': {'T': '###', 'M': '\v\v#', 'B': '#\v#'}},
}

import random

size = 10, 4
#
sides = 'T', 'M', 'B'

l = []

for i in range(size[1]):
    l.append([])
    for j in range(size[0]):
        if i > 0 and j > 0:
            if '\v' in l[i - 1][j]['code']['B'][1] and '\v' in l[i][j - 1]['code']['M'][2]:
                l[i].append(Labirint['TL'])
            elif '\v' in l[i][j - 1]['code']['M'][2]:
                l[i].append(Labirint[random.randint('RN', 'RB', 'RL')])
            elif '\v' in l[i - 1][j]['code']['B'][1]:
                l[i].append(Labirint[random.randint('TB', 'TR', 'TN')])
        elif j > 0:
            if '\v' in l[i][j - 1]['code']['M'][2]:
                l[i].append(Labirint[random.randint('RN', 'RB', 'RL')])
        elif i > 0:
            if '\v' in l[i - 1][j]['code']['B'][1]:
                l[i].append(Labirint[random.randint('TB', 'TR', 'TN')])

        l[i].append(Labirint[random.randint(0, 10)])

print(l)

# while (True):
#     l = []
#     is_Susp = False
#
#     for i in range(size[0]):
#         l.append(Labirint[random.randint(0, 10)])
#     if str(l[0].get('code').get('B'))[0] != '\v': is_Susp = True
#     for i in range(len(l)):
#         if '\v' in l[i].get('code').get('T'): is_Susp = False
#
#     if is_Susp:
#         continue

# for i in range(3):
#     stroke = ''
#     for j in range(size[0]):
#         stroke += str(l[j].get('code').get(sides[i]))
#     print(stroke)
