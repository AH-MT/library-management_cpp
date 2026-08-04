#pragma once
#include <vector>
#include <string>


class book{
    private:
        std::string title;
        std::string author;
        std::string bookId;
        bool isAvailable;
    public:
        book(std::string title, std::string author, std::string bookId, bool isAvailable):
        title(std::move(title)),author(std::move(author)),bookId(std::move(bookId)), isAvailable(isAvailable){}

        void setAvailability(bool status) { isAvailable = status; }
        void setTitle(std::string newTitle) { title = std::move(newTitle); }
        void setAuthor(std::string newAuthor) { author = std::move(newAuthor); }

        const std::string& getTitle() const { return title; }
        const std::string& getAuthor() const { return author; }
        const std::string& getBookId() const { return bookId; }
        bool getAvailability() const { return isAvailable; }

        ~book() = default;
};