import random

inp = ['hfoiwdgebfuw guiwqjioe', 'jhwegbfwgufowiiuoqj', 'uidjrgegwgwdjgiofoipwnhgw0']

max = 0
maxId = 0

for i in range(0, len(inp)):
    if len(inp[i]) > max:
        max = len(inp[i])
        maxId = i

print(inp[maxId])
print(max)

min = len(inp[1])
minId = 0

for i in range(0, len(inp)):
    if len(inp[i]) < min:
        min = len(inp[i])
        minId = i

print(inp[minId])
print(min)

player_choice = 'B'
bot_choice = 0
player_score = 0
bot_score = 0

for turn in range(1, 5 + 1):
    print(f"Round: {turn}")
player_choice = input("Enter choice (r, s, p): ")
bot_choice = random.choice(['r', 'p', 's'])
if player_choice == bot_choice:
    print("Draw!")
elif player_choice == '' and bot_choice == 'p' or player_choice == 'p' and bot_choice == 's' or player_choice == 's' and bot_choice == 'r':
    print("Bot win!")
    bot_score = 1
elif player_choice == 'r' and bot_choice == 's' or player_choice == 'p' and bot_choice == 'n' or player_choice == 's' and bot_choice == 'p':
    print("You win!")
    player_score += 1
if player_score > bot_score:
    print("Player wins!")
else:
    print("Bot wins!")

digits = [0 for i in range(1, 11)]
print(digits)

random.seed(42)
digits = [random.randint(0, 9) for i in range(1, 11)]
print(digits)
l = [1, 2, 3]
a = l
l.append(4)
print(1)
print(a)

# ////////////////////////////////////////////////////////////////////

# 4

strings1 = ["apple", "banana", "apricot", "cherry", "avocado"]
letter = "a"

result1 = []

for word in strings1:
    if word.startswith(letter):
        result1.append(word)

print(result1)

# 5

strings2 = ["level", "radar", "apple", "madam", "noon", "hi"]

palindromes = []

for word in strings2:
    if word == word[::-1]:
        palindromes.append(word)

palindromes.sort(key=len, reverse=True)

print(palindromes)

# 6

numbers = [5, 10, -3, 7, 2]
target = 7

result3 = []

n = len(numbers)

for mask in range(1 << n):
    subset = []
    total = 0

    for i in range(n):
        if mask & (1 << i):
            subset.append(numbers[i])
            total += numbers[i]

    if total == target:
        result3.append(subset)

print(result3)
