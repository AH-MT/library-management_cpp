//
// Created by AH MT on 08/08/2026.
//
#include "saveAndLoad.h"
void saveMembers(const Library& library) {
    std::ofstream file("C:\\Users\\Gilas\\Desktop\\people.txt");

    if (!file.is_open()) {
        std::cout << "ERROR: Could not open people.txt for writing!\n";
        return;
    }

    for (const Member& p : *library.getAllMembers()) {
        file << p.getId() << " "
             << p.getName() << " "
             << p.getPassword() << " "
             << p.getRole();

        for (const int& isbn : *p.getBooks()) {
            file << " " << isbn;
        }

        file << '\n';
    }

    file.close();

    std::cout << "Members saved successfully!\n";
}
void loadMembers(  Library& library) {
    std::ifstream input("C:\\Users\\Gilas\\Desktop\\people.txt");

    std::string line;

    while (std::getline(input, line)) {
        std::stringstream ss(line);

        int id, password;
        std::string name, role;

        ss >> id >> name >> password >> role;

        std::vector<int> book;

        int isbn;
        while (ss >> isbn) {
            book.push_back(isbn);
        }

        if (role == "Member") {
            library.addMember_f(id, name, password, book);
        }
    }

    input.close();
}

void saveBooks(const Library& library) {
    std::ofstream file("C:\\Users\\Gilas\\Desktop\\Book.txt");

    if (!file.is_open()) {
        std::cout << "ERROR: Could not open people.txt for writing!\n";
        return;
    }

    for (const Book& p : *library.getAllBooks()) {
        file << p.getBookId() << " "
             << p.getTitle() << " "
             << p.getAuthor() << " "
             << p.getAvailability();
        file << '\n';
    }
    file.close();

    std::cout << "Books saved successfully!\n";
}
void loadBooks(Library& library) {
    std::ifstream input("C:\\Users\\Gilas\\Desktop\\Book.txt");

    std::string line;

    while (std::getline(input, line)) {
        std::stringstream ss(line);

        int id;
        std::string title, author;
        bool available;
        ss >> id >> title >> author >> available;

        library.addBook_f(id, title, author, available);
    }

    input.close();
}
