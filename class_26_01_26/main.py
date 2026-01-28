a = float(input("Введіть перше число: "))
b = float(input("Введіть друге число: "))

print("Оберіть дію:")
print("1 - сума")
print("2 - різниця")
print("3 - середнє арифметичне")
print("4 - добуток")

choice = input("Ваш вибір (1-4): ")

if choice == "1":
    result = a + b
    print("Сума:", result)
elif choice == "2":
    result = a - b
    print("Різниця:", result)
elif choice == "3":
    result = (a + b) / 2
    print("Середнє арифметичне:", result)
elif choice == "4":
    result = a * b
    print("Добуток:", result)
else:
    print("Невірний вибір")


usd = float(input("Введіть суму в доларах: "))

print("Оберіть валюту:")
print("EUR - євро")
print("GBP - фунти")
print("JPY - єни")

currency = input("Введіть валюту (EUR/GBP/JPY): ").upper()

rate = float(input("Введіть курс цієї валюти до долара: "))

converted = usd * rate

print(f"Сума в валюті {currency}: {converted}")
