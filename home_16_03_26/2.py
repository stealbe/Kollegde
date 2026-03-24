dict = {
    "language": "langue"
}

while (True):
    menu = input(print(f'1. Find translate\n 2. Insert/change\n 3. Delete\n Any to exit.'))
    if (menu == "1"):
        print(dict.get(input(f'World to translate: '), 0))
    elif (menu == "2"):
        dict[input(f'Word: ')] = input("Enter your translate: ")
    elif (menu == "3"):
        dict.pop(input("Enter word to delete: "))
    else:
        break
