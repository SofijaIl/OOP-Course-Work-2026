#include "Book.h"
#include <iostream>
#include <stdexcept>

Book::Book(const std::string& title, const std::string& id,
            const std::string& author, const std::string& isbn,
            const std::string& language, int copies)
    : LibraryItem(title, id, language, copies) {
    if (author.empty()) { throw std::invalid_argument("Author cannot be empty"); }
    if (isbn.empty()) { throw std::invalid_argument("ISBN cannot be empty"); }
    this->author = author;
    this->isbn = isbn;
}

std::string Book::getAuthor() const { return author; }
std::string Book::getIsbn() const { return isbn; }

void Book::displayInfo() const {
    std::cout << "[Book] " << title
              << " | Author: " << author
              << " | ISBN: " << isbn
              << " | Language: " << language
              << " | " << (available ? "Available" : "Borrowed")
              << std::endl;
}

std::string Book::getType() const {
    return "Book";
}