#pragma once
#include <string>
#include <utility>

class Book{
    private:
        std::string title;
        std::string author;
        int bookId;
        bool isAvailable;
    public:
        Book(std::string title_t, std::string author_t, int bookId_t, bool isAvailable_t):
        title(std::move(title_t)),author(std::move(author_t)),bookId(bookId_t), isAvailable(isAvailable_t){}

        void setAvailability(bool status) { isAvailable = status; }
        void setTitle(std::string newTitle) { title = std::move(newTitle); }
        void setAuthor(std::string newAuthor) { author = std::move(newAuthor); }

        const std::string& getTitle() const { return title; }
        const std::string& getAuthor() const { return author; }
        const int& getBookId() const { return bookId; }
        bool getAvailability() const { return isAvailable; }

};
