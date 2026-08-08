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
        int nextBookId = 1;
        int nextMemberId = 1;
    public:
        void addBook(const std::string& title, const std::string& author);
        bool removeBook(const int& bookId);
        void addMember(const std::string& name, const int password);
        bool removeMember(const int& memberId);
        Book* findBookById(const int& bookId);
        Member* findMemberById(const int& memberId);
        bool isMemberById(const int& memberId);
        bool borrowBook(const int&, const int& memberId);
        bool returnBook(const int& bookId, const int& memberId);
        void displayAllBooks();
        void displayAllMembers();
        int memberIdMaker();
        int bookIdMaker();
        void displayAvBooks();
        bool checkMember(const int& id, const int& password);
        const std::vector<Member>* getAllMembers() const;
        const std::vector<Book>* getAllBooks() const;
        void addMember_f(const int& id,const std::string& name, const int& password, std::vector<int>& book);
        void addBook_f(const int& id,const std::string& title, const std::string& author, const bool& available);



};
