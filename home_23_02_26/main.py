# 1

numbers = [1, 3, 2, 4, 5]

count = 0

for i in range(1, len(numbers)):
    if numbers[i] > numbers[i - 1]:
        count += 1

print("Кількість елементів:", count)

# 2

numbers = [1, 2, 2, 3, 4, 4, 5]

result = []

for num in numbers:
    if numbers.count(num) == 1:
        result.append(num)

print("Результат:", result)

# 3

numbers = [1, 2, 1, 2, 3, 4, 1]

max_length = 1
current_length = 1

max_sequence = [numbers[0]]
current_sequence = [numbers[0]]

for i in range(1, len(numbers)):
    if numbers[i] > numbers[i - 1]:
        current_sequence.append(numbers[i])
        current_length += 1
    else:
        if current_length > max_length:
            max_length = current_length
            max_sequence = current_sequence

        current_sequence = [numbers[i]]
        current_length = 1

if current_length > max_length:
    max_length = current_length
    max_sequence = current_sequence

print("Довжина послідовності:", max_length)
print("Послідовність:", max_sequence)
