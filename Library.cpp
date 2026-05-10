#include "Library.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

// --- add items and members ---

void Library::addItem(std::unique_ptr<LibraryItem> item) {
    if (!item) {
        throw std::invalid_argument("Cannot add null item");
    }
    items.push_back(std::move(item));
}

void Library::addMember(const Member& member) {
    members.push_back(member);
}

// --- borrow and return ---

void Library::borrowItem(const std::string& memberId,
                         const std::string& itemId,
                         const std::string& dueDate) {
    // find the item
    auto itemIt = std::find_if(items.begin(), items.end(),
        [&itemId](const std::unique_ptr<LibraryItem>& i) {
            return i->getItemId() == itemId;
        });

    if (itemIt == items.end()) {
        throw std::runtime_error("Item not found: " + itemId);
    }
    if (!(*itemIt)->isAvailable()) {
        throw std::runtime_error("Item is already borrowed: " + itemId);
    }

    // find the member
    auto memberIt = std::find_if(members.begin(), members.end(),
        [&memberId](const Member& m) {
            return m.getMemberId() == memberId;
        });

    if (memberIt == members.end()) {
        throw std::runtime_error("Member not found: " + memberId);
    }

    // create the loan
    loans.push_back(Loan(memberId, itemId, dueDate));
    (*itemIt)->setAvailable(false);
    memberIt->addBorrowedId(itemId);

    std::cout << "Borrowed successfully." << std::endl;
}

void Library::returnItem(const std::string& memberId,
                         const std::string& itemId) {
    // find the loan
    auto loanIt = std::find_if(loans.begin(), loans.end(),
        [&memberId, &itemId](const Loan& l) {
            return l.getMemberId() == memberId && l.getItemId() == itemId;
        });

    if (loanIt == loans.end()) {
        throw std::runtime_error("Loan not found");
    }

    // find the item and mark available
    auto itemIt = std::find_if(items.begin(), items.end(),
        [&itemId](const std::unique_ptr<LibraryItem>& i) {
            return i->getItemId() == itemId;
        });

    if (itemIt != items.end()) {
        (*itemIt)->setAvailable(true);
    }

    // find the member and remove from their list
    auto memberIt = std::find_if(members.begin(), members.end(),
        [&memberId](const Member& m) {
            return m.getMemberId() == memberId;
        });

    if (memberIt != members.end()) {
        memberIt->removeBorrowedId(itemId);
    }

    // remove the loan
    loans.erase(loanIt);

    std::cout << "Returned successfully." << std::endl;
}

// --- display ---

void Library::displayAllItems() const {
    if (items.empty()) {
        std::cout << "No items in library." << std::endl;
        return;
    }
    for (const auto& item : items) {
        item->displayInfo();
    }
}

void Library::displayAllMembers() const {
    if (members.empty()) {
        std::cout << "No members." << std::endl;
        return;
    }
    for (const auto& member : members) {
        member.displayInfo();
    }
}

void Library::displayAllLoans() const {
    if (loans.empty()) {
        std::cout << "No active loans." << std::endl;
        return;
    }
    for (const auto& loan : loans) {
        loan.displayInfo();
    }
}

// --- search and sort ---

void Library::searchByTitle(const std::string& title) const {
    bool found = false;
        for (const auto& item : items) {
        if (item->getTitle().find(title) != std::string::npos) {
            item->displayInfo();
            found = true;
        }
    }

    if (!found) {
        std::cout << "Nothing found for: " << title << std::endl;
    }
}

void Library::sortByTitle() {
    std::sort(items.begin(), items.end(),
        [](const std::unique_ptr<LibraryItem>& a,
           const std::unique_ptr<LibraryItem>& b) {
            return a->getTitle() < b->getTitle();
        });
    std::cout << "Items sorted by title." << std::endl;
}

int Library::countAvailable() const {
    return std::count_if(items.begin(), items.end(),
        [](const std::unique_ptr<LibraryItem>& i) {
            return i->isAvailable();
        });
}