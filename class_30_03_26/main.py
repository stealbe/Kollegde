# 1

name = 'Paradovskiy Oleksandr'
age = 17
city = 'Odesa'
is_student = True
print(name, '\n', age, '\n', city)
if is_student:
    print("student\n")

# 2
a = 33
b = 54

print(a + b)
print(a - b)
print(a * b)
print(a / b)

# 3
a = 5
w = 4
h = 10

print(a * w * h)

# 4
a = '45'

print(int(a))
print(float(a))

# 5
n1 = 123
n2 = 4534

n1, n2 = n2, n1
print(n1, n2)

# 6
age = 23
if age >= 18:
    print(f'Welcome')

# 7
num = 5324
res = int
if num > 0:
    res = 1
elif num < 0:
    res = -1
else:
    res = 0

print(res)

# 8
num = 5324
if num == 0:
    print('Zero')
elif num % 2 == 0:
    print('even')
else:
    print('odd')

# 9
num1 = 3423
num2 = 3643
if num1 != num2:
    print(max(num1, num2))
else:
    print(f'Numbers are equal')

# 10
p = 74
max = 100
if (p > max or p < 0):
    print(f'Невiрний балл')
elif int(p / (max / 4)) in (4, 3):
    print(f'Високий рiвень')
elif int(p / (max / 4)) in (3, 2):
    print(f'Достатнiй рiвень')
elif int(p / (max / 4)) in (2, 1):
    print(f'Середнiй рiвень')
elif int(p / (max / 4)) in (1, 0):
    print(f'Низький рiвень')

# 11
num = 34
if num > 10 and num <= 50:
    print(f'Correct num')

# 12
user = {
    'login': 'admin',
    'password': '1253'
}

if user['login'] == 'admin' and user['password'] == '1234': print(f'Ur welcome')

# 13
for i in range(1, 20): print(i)

# 14
for i in range(2, 30):
    if (i % 2 == 0): print(i)

# 15
n = 43
sum = 0
for i in range(1, n + 1):
    sum += i

print(sum)

# 16
n = 2
c = 10
for i in range(1, c + 1):
    print(i, ": ", n * i)

# 17
num = 35
res = 1

for i in range(1, num + 1):
    res *= i

print(res, '\n')

# 18
num = 5324
print(len(str(num)), '\n')

# 19
nums = 151, 412, 413514, 5234, 314
print(nums[0])
print(nums[len(nums) - 1])
sum = 0
for i in range(1, len(nums)):
    sum += nums[i]

print(sum, '\n')

# 20
n = 314
nums = 151, 412, 413514, 5234, 314

if n in nums: print(n, '\n')

# 21
nums = 151, 412, 413514, 5234, 314
for i in nums:
    if i > 5: print(i)

# 22
s = 't43r3gfedwfe'
print('\n', len(s))
print(s[0])
print(s[len(s) - 1], '\n')

# 23
s = 't43r3gfedwfe'
print(s.upper())
print(s.lower(), '\n')

# 24
s = 'копкцщаултот'
vowel = 'а', 'у', 'о', 'ы', 'э', 'я', 'ю', 'ё', 'и', 'е'
sum = 0
for c in s:
    if c in vowel: sum += 1

print(sum)