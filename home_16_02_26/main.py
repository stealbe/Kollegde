text = "Hellow world! Hellow world? Hellow world. Hellow world."

count = 0

for char in text:
    if char == "." or char == "!" or char == "?":
        count += 1

print("Кількість речень:", count)

text = "Козак з казок"

clean_text = text.lower().replace(" ", "")

if clean_text == clean_text[::-1]:
    print("Це паліндром")
else:
    print("Це не паліндром")

text = "if x > 0 return x else return 0"

reserved_words = ["if", "else", "return"]

words = text.split()

for i in range(len(words)):
    if words[i] in reserved_words:
        words[i] = words[i].upper()

new_text = " ".join(words)

print("Змінений текст:")
print(new_text)

text = "abcdefgxyz"
char1 = "c"
char2 = "x"

index1 = text.find(char1)
index2 = text.find(char2)

if index1 != -1 and index2 != -1 and index1 < index2:
    new_text = text[:index1] + text[index2 + 1:]
else:
    new_text = text

print("Результат:")
print(new_text)

text = "apple banana cherry kiwi mango"
bad_chars = "ae"

words = text.split()
new_words = []

for word in words:
    remove = False

    for ch in bad_chars:
        if ch in word:
            remove = True
            break

    if not remove:
        new_words.append(word)

result = " ".join(new_words)

print("Результат:")
print(result)

text = "Hellow Python"

words = text.split()
words.reverse()

result = " ".join(words)

print("Зворотний текст:")
print(result)

text = "Python"

reversed_text = ""

for char in text:
    reversed_text = char + reversed_text

print("Перевернутий рядок:")
print(reversed_text)

text = "python code python java python"
search_word = "python"

words = text.split()
count = 0

for word in words:
    if word == search_word:
        count += 1

print("Кількість входжень:", count)
