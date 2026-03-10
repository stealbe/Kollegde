print(len(('Orange', 'Melon', 'Lime', 'Peach', 'Strawberry')))

exmpl = [
    'Apple', 'Banana', 'Cherry', 'Date', 'Elderberry',
    'Fig', 'Grape', 'Honeydew', 'Kiwi', 'Lemon',
    'Mango', 'Nectarine', 'Orange', 'Papaya', 'Quince',
    'Raspberry', 'Strawberry', 'Tangerine', 'Ugli', 'Watermelon',
    'Apricot', 'Blueberry', 'Cantaloupe', 'Dragonfruit', 'Feijoa',
    'Guava', 'Huckleberry', 'Jackfruit', 'Kumquat', 'Lime',
    'Mandarin', 'Nutmeg', 'Olive', 'Passionfruit', 'Pear',
    'Plum', 'Pomegranate', 'Rambutan', 'Satsuma', 'Tangelo',
    'Uva', 'Vanilla', 'Wolfberry', 'Ximenia', 'Yuzu',
    'Ziziphus', 'Avocado', 'Coconut', 'Grapefruit', 'Mangosteen'
]

fruits = 'banana', 'apple', 'mango', 'strawberry-banana', 'blueberryBanana_DragonfruitOrange', 'StrawberryTangerine', 'Ugli', 'WatermelonApricotBlueberry', 'CantaloupeDragonfruit', 'FeijoaGuavaHuckleberry', 'JackfruitKumquatLimeMandarinNutmegOlivePassionfruit'
count = 0

for fruit in fruits:
    founded = 0
    for find in exmpl:
        if find.lower() in fruit.lower():
            count += 1
            founded += len(find)
        if founded == len(fruit): continue

print(count)

namings = 'Mercedes', 'Audi', 'BMW', 'Audi', 'BMW', 'Mercedes', 'Jaguar', 'Chevrolet'
namings = list(namings)
for name in range(0, len(namings)):
    if namings[name] == 'Mercedes':
        namings[name] = 'Zero'

namings = tuple(namings)
print(namings)

import random

random.seed(9657437529658)
digits = [random.randint(0, 999) for i in range(100)]
count1 = 0
count2 = 0
count3 = 0
for digit in digits:
    if digit < 10: count1 += 1
    elif digit < 100: count2 += 1
    elif digit < 1000: count3 += 1

print(digits)
print(f'1 element is {count1} times, 2 elements is {count2} times, 3 elements is {count3} times')

random.seed(873243325)
digits = [random.randint(10, 99) for i in range(100)]
print(digits)
print(len(digits))
digits = set(digits)
print(len(digits))