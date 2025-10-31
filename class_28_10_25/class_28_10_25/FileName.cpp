﻿#include <iostream>
#include "Library.h"
using namespace std;

int main() {
    Book books[30] = {
        Book("Dune", "Frank Herbert", "Sci-Fi"),
        Book("1984", "George Orwell", "Dystopia"),
        Book("The Hobbit", "J.R.R. Tolkien", "Fantasy"),
        Book("Fahrenheit 451", "Ray Bradbury", "Dystopia"),
        Book("Brave New World", "Aldous Huxley", "Dystopia"),
        Book("The Catcher in the Rye", "J.D. Salinger", "Drama"),
        Book("To Kill a Mockingbird", "Harper Lee", "Classic"),
        Book("The Great Gatsby", "F. Scott Fitzgerald", "Classic"),
        Book("Moby Dick", "Herman Melville", "Adventure"),
        Book("The Lord of the Rings", "J.R.R. Tolkien", "Fantasy"),
        Book("Crime and Punishment", "Fyodor Dostoevsky", "Philosophical"),
        Book("The Brothers Karamazov", "Fyodor Dostoevsky", "Drama"),
        Book("War and Peace", "Leo Tolstoy", "Historical"),
        Book("Anna Karenina", "Leo Tolstoy", "Drama"),
        Book("The Picture of Dorian Gray", "Oscar Wilde", "Philosophical"),
        Book("Dracula", "Bram Stoker", "Horror"),
        Book("Frankenstein", "Mary Shelley", "Horror"),
        Book("The Shining", "Stephen King", "Horror"),
        Book("It", "Stephen King", "Horror"),
        Book("Pet Sematary", "Stephen King", "Horror"),
        Book("Harry Potter", "J.K. Rowling", "Fantasy"),
        Book("The Silmarillion", "J.R.R. Tolkien", "Fantasy"),
        Book("A Game of Thrones", "George R.R. Martin", "Fantasy"),
        Book("The Name of the Wind", "Patrick Rothfuss", "Fantasy"),
        Book("Mistborn", "Brandon Sanderson", "Fantasy"),
        Book("The Way of Kings", "Brandon Sanderson", "Fantasy"),
        Book("The Martian", "Andy Weir", "Sci-Fi"),
        Book("Ready Player One", "Ernest Cline", "Sci-Fi"),
        Book("Ender's Game", "Orson Scott Card", "Sci-Fi"),
        Book("Neuromancer", "William Gibson", "Cyberpunk")
    };
    
    int alice_books[] = { books[0].GetId(), books[1].GetId(), books[2].GetId() };
    int bob_books[] = { books[3].GetId(), books[4].GetId() };
    int charlie_books[] = { books[5].GetId(), books[6].GetId(), books[7].GetId() };
    int dave_books[] = { books[8].GetId() };
    int eve_books[] = { books[9].GetId(), books[10].GetId(), books[11].GetId(), books[12].GetId() };
    int frank_books[] = { books[13].GetId(), books[14].GetId() };
    int grace_books[] = { books[15].GetId(), books[16].GetId(), books[17].GetId() };
    int heidi_books[] = { books[18].GetId() };
    int ivan_books[] = { books[19].GetId(), books[20].GetId(), books[21].GetId() };
    int judy_books[] = { books[22].GetId(), books[23].GetId(), books[24].GetId(), books[25].GetId(), books[26].GetId() };
    
    User users[10] = {
        User("Alice", alice_books, 3, 5),
        User("Bob", bob_books, 2, 3),
        User("Charlie", charlie_books, 3, 4),
        User("Dave", dave_books, 1, 2),
        User("Eve", eve_books, 4, 5),
        User("Frank", frank_books, 2, 3),
        User("Grace", grace_books, 3, 4),
        User("Heidi", heidi_books, 1, 2),
        User("Ivan", ivan_books, 3, 5),
        User("Judy", judy_books, 5, 4)
    };
    
    Library lib(users, 10, books, 30);


    int menu = 0;
    do {
        cout << "\n========= LIBRARY MENU =========\n";
        cout << "1. Search by title;\n";
        cout << "2. Search by genre;\n";
        cout << "3. Search by author;\n";
        cout << "4. Find the most frequent library visitor;\n";
        cout << "5. Display/add records (books, visitors);\n";
        cout << "6. Organize book lending/return;\n";
        cout << "0. Exit.\n";
        cout << "Choose: ";
        cin >> menu;

        string title, genre, author;
        int uid, bid;
        switch (menu) {
        case 1:
            cout << "Enter book title: ";
            cin.ignore();
            cin >> title;
            try {
                Book n = lib.FindBookViaName(title);
                cout << n << endl;
                lib.ShowUserViaId(n.GetOwerId());
            }
            catch (const char* e) {
                cout << e << endl;
            }
            break;

        case 2:
            cout << "Enter genre: ";
            cin.ignore();
            cin >> genre;
            try {
                lib.ShowAllBooksViaGenre(genre);
            }
            catch (const char* e) {
                cout << e << endl;
            }
            break;

        case 3:
            cout << "Enter author: ";
            cin.ignore();
            cin >> author;
            try {
                lib.ShowAllBooksViaAuthtor(author);
            }
            catch (const char* e) {
                cout << e << endl;
            }
            break;

        case 4:
            try {
                cout << "Most frequent visitor:\n" << lib.MostFrequenceUs() << endl;
            }
            catch (const char* e) {
                cout << e << endl;
            }
            break;

        case 5: {
            int sub = 0;
            cout << "\n--- Records Menu ---\n";
            cout << "1. Show all books;\n";
            cout << "2. Show all users;\n";
            cout << "3. Add a new book;\n";
            cout << "4. Add a new user;\n";
            cout << "0. Back;\n";
            cout << "Choose: ";
            cin >> sub;
            switch (sub) {
            case 1:
                lib.ShowAllLibrary();
                break;
            case 2:
                lib.ShowAllUsers();
                break;
            case 3:
                lib.AddBook();
                break;
            case 4:
                lib.AddUser();
                break;
            default:
                break;
            }
            break;
        }

        case 6: {
            int sub = 0;
            cout << "\n--- Lending/Return Menu ---\n";
            cout << "1. Lend book;\n";
            cout << "2. Return book;\n";
            cout << "0. Back;\n";
            cout << "Choose: ";
            cin >> sub;

            cout << "Enter user id: ";
            cin >> uid;
            cout << "Enter book id: ";
            cin >> bid;

            try {
                if (sub == 1)
                    lib.LendBook(uid, bid);
                else if (sub == 2)
                    lib.ReturnBook(uid, bid);
            }
            catch (const char* e) {
                cout << e << endl;
            }
            break;
        }
        case 7:
            cout << "User id: ";
            cin >> uid;
            try
            {
                lib.ShowUserViaId(uid);
            }
            catch (const char* e)
            {
                cout << e << endl;
            }
            break;
        default:
            menu = 0;
            cout << "Exit.\n";
            break;
        }

    } while (menu > 0);

    return 0;
}