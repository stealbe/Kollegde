dict = {
    0: {"name": "O.O Paradovskiy", "phone": "+380000000", "email": "para@gmail.com", "state": "Dir", "office": "#12",
        "nick": "@stealbe"}
}

while True:
    menu = input("1. Find for id\n 2. Find for name\n 3. Insert\n 4. Delete\n 5. Show all\n Any to exit\n ")
    if menu == "1":
        print(dict.get(input("Id: "), 0))
    if menu == "2":
        name = input("Name: ")
        for i in dict:
            if dict.get(i).get("name") == name: print(dict.get(i))
    if menu == "3":
        dict[len(dict)] = {"name": input("Name: "), "phone": input("Phone: "), "email": input("Email: "),
                           "state": input("State: "), "office": input("Office: "), "nick": input("Nick: ")}
    if menu == "4":
        dict.pop(input("Id: "))
    if menu == "5":
        for i in dict:
            print(dict.get(i))
    else:
        break
