#include "Loan.h"
#include <iostream>
#include <stdexcept>

Loan::Loan(const std::string& memberId, const std::string& itemId,
           const std::string& dueDate) {
    if (memberId.empty()) {
        throw std::invalid_argument("Member ID cannot be empty");
    }
    if (itemId.empty()) {
        throw std::invalid_argument("Item ID cannot be empty");
    }
    if (dueDate.empty()) {
        throw std::invalid_argument("Due date cannot be empty");
    }
    this->memberId = memberId;
    this->itemId = itemId;
    this->dueDate = dueDate;
}

std::string Loan::getMemberId() const { return memberId; }
std::string Loan::getItemId() const { return itemId; }
std::string Loan::getDueDate() const { return dueDate; }

void Loan::displayInfo() const {
    std::cout << "[Loan] Member: " << memberId
              << " | Item: " << itemId
              << " | Due: " << dueDate
              << std::endl;
}