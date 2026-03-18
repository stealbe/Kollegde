import random

# Завдання 1
# Маємо дві множини з назвами міст. Створіть третю множину з тими
# назвами, які містяться в першій множині, але відсутні у другій.

towns1 = {'Kiyiv', 'Odesa', 'Harkiv', 'Dnipro', 'Udzhgorod'}
towns2 = {'Harkiv', 'Udzhgorod', 'Lviv', 'Reni'}

print(towns1.difference(towns2))

# Завдання 2
# Маємо дві множини з назвами міст. Створіть третю множину з тими
# назвами, які містяться в другій множині, але відсутні в першій.

towns3 = towns2.difference(towns1)
print(towns3)

# Завдання 3
# Маємо дві множини з назвами міст. Створіть третю множину з
# унікальними назвами для кожної множини.

towns4 = towns1.symmetric_difference(towns2)
print(towns4)