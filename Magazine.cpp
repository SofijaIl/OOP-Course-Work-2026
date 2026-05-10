#include "Magazine.h"
#include <iostream>
#include <stdexcept>

Magazine::Magazine(const std::string& title, const std::string& id,
                   const std::string& publisher, int issueNum, const std::string& language, int copies)
    : LibraryItem(title, id, language, copies) {
    if (publisher.empty()) {
        throw std::invalid_argument("Publisher cannot be empty");
    }
    if (issueNum <= 0) {
        throw std::invalid_argument("Issue number must be positive");
    }
    this->publisher = publisher;
    this->issueNum = issueNum;
}

std::string Magazine::getPublisher() const { return publisher; }
int Magazine::getIssueNum() const { return issueNum; }

void Magazine::displayInfo() const {
    std::cout << "[Magazine] " << title
              << " | Publisher: " << publisher
              << " | Issue: " << issueNum
              << " | Language: " << language
              << " | " << (available ? "Available" : "Borrowed")
              << std::endl;
}
std::string Magazine::getType() const {
    return "Magazine";
}