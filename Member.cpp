#include "Member.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

Member::Member(const std::string& name, const std::string& memberId) {
    if (name.empty()) {
        throw std::invalid_argument("Member name cannot be empty");
    }
    if (memberId.empty()) {
        throw std::invalid_argument("Member ID cannot be empty");
    }
    this->name = name;
    this->memberId = memberId;
}

std::string Member::getName() const { return name; }
std::string Member::getMemberId() const { return memberId; }
std::vector<std::string> Member::getBorrowedIds() const { return borrowedIds; }

void Member::addBorrowedId(const std::string& itemId) {
    borrowedIds.push_back(itemId);
}

void Member::removeBorrowedId(const std::string& itemId) {
    auto it = std::find(borrowedIds.begin(), borrowedIds.end(), itemId);
    if (it != borrowedIds.end()) {
        borrowedIds.erase(it);
    }
}

void Member::displayInfo() const {
    std::cout << "[Member] " << name
              << " | ID: " << memberId
              << " | Borrowed: " << borrowedIds.size()
              << " items" << std::endl;
}