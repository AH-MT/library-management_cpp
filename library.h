#include "book.cpp"
#include "member.h"
#include "person.h"
#include "librarian.h"
#include <string>
#include <vector>


class Library{
    private:
        std::vector<Book> books;
        std::vector<Member> members;
    public:
        void addBook(const Book& book);
        bool removeBook(const std::string& bookId);
        void addMember(const Member& member);
        bool removeMember(const std::string& memberId);
        Book* findBookById(const std::string& bookId);
        Member* findMemberById(const std::string& memberId);
        bool borrowBook(const std::string& bookId, const std::string& memberId);
        bool returnBook(const std::string& bookId, const std::string& memberId);
        void displayAllBooks();
        void displayAvailableBooks();
        void displayAllMembers();



};