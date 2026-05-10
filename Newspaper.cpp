#include "Newspaper.h"
#include <iostream>
#include <stdexcept>

Newspaper::Newspaper(const std::string& title, const std::string& id,
                     const std::string& publisher, const std::string& date, const std::string& language, int copies)
    : LibraryItem(title, id, language, copies) {
    if (publisher.empty()) {
        throw std::invalid_argument("Publisher cannot be empty");
    }
    if (date.empty()) {
        throw std::invalid_argument("Date cannot be empty");
    }
    this->publisher = publisher;
    this->date = date;
}

std::string Newspaper::getPublisher() const { return publisher; }
std::string Newspaper::getDate() const { return date; }

void Newspaper::displayInfo() const {
    std::cout << "[Newspaper] " << title
              << " | Publisher: " << publisher
              << " | Language: " << language
              << " | Date: " << date
              << " | " << (available ? "Available" : "Borrowed")
              << std::endl;
}

std::string Newspaper::getType() const {
    return "Newspaper";
}