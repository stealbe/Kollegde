dict = {
    0: {"name": "Mickle Jordan", "height": 2.15}
}

while True:
    menu = input("1. Find for id\n 2. Find for name\n 3. Insert\n 4. Show all\n 5. Delete\n Any to exit\n")
    if menu == "1":
        print(dict.get(input("Id: "), 0))
    if menu == "2":
        name = input("Name: ")
        for i in dict:
            if dict.get(i).get("name") == name: print(dict.get(i))
    if menu == "3":
        dict[len(dict)] = {"name": input("Name: "), "height": float(input("Height: "))}
    if menu == "4":
        for i in dict:
            print(dict.get(i))
    if menu == "5":
        dict.pop(input("Id: "))
    else:
        break
