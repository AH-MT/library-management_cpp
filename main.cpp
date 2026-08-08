#include "saveAndLoad.h"

void clearInput() {
    std::cin.clear();
    std::cin.ignore();
}
int showLoginMenu() {
    int choice;
    while (true) {
        std::cout << "\n========== LIBRARY SYSTEM ==========\n";
        std::cout << "1. Login as Member\n";
        std::cout << "2. Login as Librarian (Admin)\n";
        std::cout << "0. Exit\n";
        std::cout << "Select your role: ";
        
        if (std::cin >> choice) {
            if (choice >= 0 && choice <= 2) return choice;
        }
        
        std::cout << "Invalid choice! Please try again.\n";
        clearInput();
    }
}
void showMemberMenu(const int& memberId, const int& password,Library& myLibrary) {
    if (!myLibrary.checkMember(memberId, password)) {
        std::cout << "Invalid Input! Please try again.\n";
        return;
    }

    int choice;
    int bookId;

    while (true) {
        std::cout << "\n--- Wellcome " << myLibrary.findMemberById(memberId)->getName() << ") ---\n";
        std::cout << "1. View All Books\n";
        std::cout << "2. Borrow a Book\n";
        std::cout << "3. Return a Book\n";
        std::cout << "0. Logout\n";
        std::cout << "Choice: ";
        
        if (!(std::cin >> choice)) { clearInput(); continue; }
        if (choice == 0) break;

        switch (choice) {
            case 1:
                myLibrary.displayAvBooks();
                break;
            case 2:
                std::cout << "Enter Book ID to borrow: ";
                std::cin >> bookId;
                myLibrary.borrowBook(bookId, memberId);
                break;
            case 3:
                std::cout << "Enter Book ID to return: ";
                std::cin >> bookId;
                myLibrary.returnBook(bookId, memberId);
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}
void showLibrarianMenu(Library& myLibrary) {
    int choice;
    while (true) {
        std::cout << "\n--- Librarian/Admin Menu ---\n";
        std::cout << "1. Add New Book\n";
        std::cout << "2. Remove Book\n";
        std::cout << "3. View All Members\n";
        std::cout << "4. View All Books\n";
        std::cout << "5. Add new Member\n";
        std::cout << "0. Logout\n";
        std::cout << "Choice: ";

        if (!(std::cin >> choice)) { clearInput(); continue; }
        if (choice == 0) break;

        switch (choice) {
            case 1: {
                std::string title, author;
                std::cout << "Enter book title: ";
                std::cin >> title;
                std::cout << "Enter author name: ";
                std::cin >> author;

                myLibrary.addBook(title, author);
                break;
            }
            case 2: {
                int bId;
                std::cout << "Enter Book ID to remove: ";
                std::cin >> bId;
                myLibrary.removeBook(bId);
                break;
            }
            case 3:
                myLibrary.displayAllMembers();
                break;
            case 4:
                myLibrary.displayAllBooks();
                break;
            case 5:{
                std::string name;
                std::cout << "Enter your name: ";
                std::cin >> name;
                int password;
                std::cout << "Enter password: ";
                std::cin >> password;
                myLibrary.addMember(name, password);
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}

int main(){
    Library myLibrary;
    loadBooks(myLibrary);
    loadMembers(myLibrary);
    while (true) {
        int role = showLoginMenu();
        
        if (role == 0) {
            std::cout << "Goodbye!\n";
            saveBooks(myLibrary);
            saveMembers(myLibrary);
            break;
        }
        if (role == 1) { // Member
            int id, password;
            std::cout << "Enter your Member ID: ";
            std::cin >> id;
            std::cout << "Enter your password: ";
            std::cin >> password;
            if(myLibrary.isMemberById(id)){
                showMemberMenu(id, password,myLibrary);
            }
            else{
                std::cout<<"there is no such person..."<<std::endl;
            }
            
        } 
        else if (role == 2) { // Librarian
            showLibrarianMenu(myLibrary);
        }
    }

    return 0;
}