name = 'Paradovskiy Oleksandr'
#       012345678910123456789

print(name[7], name[8], name[10]) #sky
print(name[4], name[2], name[9], name[15]) #drink
print(name[1], name[18], name[19]) #and
print(name[2], name[3], name[4], name[9], name[5]) #radio
print(name[13], name[17],name[14]) #lake
print(name[2], name[17], name[20], name[14]) #rare

url = 'https://youtube.com/results?search_query='

print(url[8:-1])

text = 'ovcyrctvuybkjnkmnjbhvjghcftxrcytuvybijnkjbhvtyccvgjhb'

word = 'M'
count = 0
for i in range(len(text)):
    if word == text[i]: count += 1

print(count)
print(text.count('M'))

counter = 0
uWord = 'd'
row = 'hfujjobufeqdwopmkdnbtguhejidpmnbofoijpodfnudwdijpcsmkjsidfeij0edosdv'
for i in range(len(row)):
    if row[i].lower() == uWord.lower(): counter += 1

print(counter)