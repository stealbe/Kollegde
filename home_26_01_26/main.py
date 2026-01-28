a, b, c = 2, 3, 4
choice = 1

if choice == 1:
    result = a + b + c
elif choice == 2:
    result = a * b * c
else:
    result = "Невірний вибір!"

print("Результат:", result)

a, b, c = 5, 8, 3
choice = 2

if choice == 1:
    result = max(a, b, c)
elif choice == 2:
    result = min(a, b, c)
elif choice == 3:
    result = (a + b + c) / 3
else:
    result = "Невірний вибір!"

print("Результат:", result)

grade = 4

if grade == 1:
    result = "Дуже погано."
elif grade == 2:
    result = "Погано."
elif grade == 3:
    result = "Задовільно."
elif grade == 4:
    result = "Добре."
elif grade == 5:
    result = "Відмінно."
else:
    result = "Невірна оцінка!"

print(result)

meters = 100
choice = 2
unit = 2

if choice == 1:
    if unit == 1:
        result = meters * 0.000621371
    elif unit == 2:
        result = meters * 39.3701
    elif unit == 3:
        result = meters * 1.09361
    else:
        result = "Невірна одиниця!"
    print("Результат:", result)
elif choice == 2:
    print("Милі:", meters * 0.000621371)
    print("Дюйми:", meters * 39.3701)
    print("Ярди:", meters * 1.09361)
elif choice == 3:
    print("Кілометри:", meters / 1000)
    print("Сантиметри:", meters * 100)
else:
    print("Невірний вибір!")

a, b = 10, 3
operation = 4

if operation == 1:
    result = a + b
elif operation == 2:
    result = a - b
elif operation == 3:
    result = a * b
elif operation == 4:
    result = a / b if b != 0 else "Ділення на нуль!"
elif operation == 5:
    result = a % b if b != 0 else "Ділення на нуль!"
elif operation == 6:
    result = a ** b
else:
    result = "Невірна операція!"

print("Результат:", result)

num = 555

digits = str(num)
if len(digits) == 3:
    if digits[0] == digits[1] == digits[2]:
        result = "Всі цифри однакові"
    else:
        result = "Цифри різні"
else:
    result = "Це не тризначне число!"

print(result)