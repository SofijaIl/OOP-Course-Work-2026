#ifndef LIBRARY_H
#define LIBRARY_H

#include "LibraryItem.h"
#include "Member.h"
#include "Loan.h"
#include <vector>
#include <memory>
#include <string>

class Library {
private:
    std::vector<std::unique_ptr<LibraryItem>> items;
    std::vector<Member> members;
    std::vector<Loan> loans;

public:
    void addItem(std::unique_ptr<LibraryItem> item);
    void addMember(const Member& member);

    void borrowItem(const std::string& memberId, const std::string& itemId, const std::string& dueDate);
    void returnItem(const std::string& memberId, const std::string& itemId);

    void displayAllItems() const;
    void displayAllMembers() const;
    void displayAllLoans() const;

    void searchByTitle(const std::string& title) const;
    void sortByTitle();

    int countAvailable() const;
};

#endif