#include "LibraryItem.h"
#include <stdexcept>      //defines a set of standard exceptions 

LibraryItem::LibraryItem(const std::string& title, const std::string& Id, const std::string& language, int copies) {  //constructor
    if (title.empty()) {
        throw std::invalid_argument("Title cannot be empty");
    }
    if (Id.empty()) {
        throw std::invalid_argument("Item ID cannot be empty");
    }
    if (language.empty()) {
    throw std::invalid_argument("Language cannot be empty");
    }
    if (copies <= 0) {
    throw std::invalid_argument("We don't have this library item");
    }
    this->title = title;
    this->Id = Id;
    this->language = language;
    this->copies = copies;
    this->available = true;
}

// Getters — return the value
std::string LibraryItem::getTitle() const {
    return title;
}
std::string LibraryItem::getItemId() const {
    return Id;
}
bool LibraryItem::isAvailable() const {
    return available;
}
void LibraryItem::setAvailable(bool status) {
    available = status;
}
std::string LibraryItem::getLanguage() const { 
    return language; 
}