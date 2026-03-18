import random

digits1 = tuple([random.randint(0, 10) for i in range(10)])
print(digits1)
digits2 = tuple([random.randint(0, 10) for i in range(10)])
print(digits2)
digits3 = tuple([random.randint(0, 10) for i in range(10)])
print(digits3)

# Зробити з використанням set
# Завдання 1
# Маємо три кортежі цілих чисел. Знайдіть елементи, які є у всіх кортежах.

simple = set(digits1).intersection(digits2).intersection(digits3)
print(simple)


# Завдання 2
# Маємо три кортежі цілих чисел. Знайдіть елементи, які унікальні для
# кожного списку.

diferent = set(digits1).symmetric_difference(digits2).symmetric_difference(digits3)
print(diferent)