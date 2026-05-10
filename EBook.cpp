#include "EBook.h"
#include <iostream>
#include <stdexcept>

EBook::EBook(const std::string& title, const std::string& id,
             const std::string& author, const std::string& isbn,
             const std::string& language, int copies,
             const std::string& fileFormat, double fileSizeMB)
    : Book(title, id, author, isbn, language, copies) {
    if (fileFormat.empty()) {
        throw std::invalid_argument("File format cannot be empty");
    }
    if (fileSizeMB <= 0) {
        throw std::invalid_argument("File size must be positive");
    }
    this->fileFormat = fileFormat;
    this->fileSizeMB = fileSizeMB;
}

std::string EBook::getFileFormat() const { return fileFormat; }
double EBook::getFileSizeMB() const { return fileSizeMB; }

void EBook::displayInfo() const {
    std::cout << "[EBook] " << title
              << " | Author: " << author
              << " | ISBN: " << isbn
              << " | Format: " << fileFormat
              << " | Size: " << fileSizeMB << " MB"
              << " | Language: " << language
              << " | " << (available ? "Available" : "Borrowed")
              << std::endl;
}

std::string EBook::getType() const {
    return "EBook";
}