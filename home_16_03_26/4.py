dict = {
    0: {"authtor": "Nikola", "name": "Python basic book", "genre": "dicumentation", "press year": 2002, "pages": 230,
        "press": "national germany press"}
}

while True:
    menu = input(
        "1. Find for id\n 2. Find for authtor\n 3. Find  for name\n 4. Insert\n 5. Delete\n 6. Show all\n 7. Exit\n")
    if menu == "1":
        print(dict.get(input("Enter the id: "), 0))
    if  menu == "2":
        authtor = input("Enter the authtor: ")
        for i in dict:
            if dict.get(i).get("authtor") == authtor: print(dict.get(i))
    if menu == "3":
        name = input("Enter the name: ")
        for i in dict:
            if dict.get(i).get("name") == name: print(dict.get(i))
    if menu == "4":
        dict[len(dict)] = {"authtor": input("Enter the authtor: "), "name": input("Enter the name: "), "genre": input("Enter the genre: "), "press year": input("Enter the press year: "), "pages": input("Enter the pages: "), "press": input("Enter the press: ")}
    if menu == "5":
        dict.pop(input("Enter the id: "))
    if menu == "6":
        for i in dict:
            print(dict.get(i))
    else:
        break
