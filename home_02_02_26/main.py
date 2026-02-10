start = int(input("Початок діапазону: "))
end = int(input("Кінець діапазону: "))

if start > end:
    start, end = end, start

for i in range(start, end + 1):
    if i % 7 == 0:
        print(i)

start = int(input("Початок діапазону: "))
end = int(input("Кінець діапазону: "))

if start > end:
    start, end = end, start

print("Усі числа діапазону:")
for i in range(start, end + 1):
    print(i, end=" ")

print("\nУ спадному порядку:")
for i in range(end, start - 1, -1):
    print(i, end=" ")

print("\nЧисла, кратні 7:")
for i in range(start, end + 1):
    if i % 7 == 0:
        print(i, end=" ")

count = 0
for i in range(start, end + 1):
    if i % 5 == 0:
        count += 1

print("\nКількість чисел, кратних 5:", count)

start = int(input("Початок діапазону: "))
end = int(input("Кінець діапазону: "))

if start > end:
    start, end = end, start

for i in range(start, end + 1):
    if i % 3 == 0 and i % 5 == 0:
        print("Fizz Buzz")
    elif i % 3 == 0:
        print("Fizz")
    elif i % 5 == 0:
        print("Buzz")
    else:
        print(i)

start = int(input("Початок діапазону: "))
end = int(input("Кінець діапазону: "))
step = int(input("Крок: "))
order = input("Порядок (1 - прямий, 2 - зворотний): ")

if start > end:
    start, end = end, start

if order == "1":
    i = start
    while i <= end:
        print(i, end=" ")
        i += step
else:
    i = end
    while i >= start:
        print(i, end=" ")
        i -= step

start = int(input("Початок діапазону: "))
end = int(input("Кінець діапазону: "))

if start > end:
    start, end = end, start

product = 1
found = False

for i in range(start, end + 1):
    if i % 4 == 0 and i % 6 != 0:
        product *= i
        found = True

if found:
    print("Добуток:", product)
else:
    print("Таких чисел немає")

a = int(input("Число A: "))
n = int(input("Степінь N: "))

result = 1
for i in range(n):
    result *= a

print("Результат:", result)
