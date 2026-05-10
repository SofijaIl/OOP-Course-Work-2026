#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>

class Member {
private:
    std::string name;
    std::string memberId;
    std::vector<std::string> borrowedIds;

public:
    Member(const std::string& name, const std::string& memberId);

    std::string getName() const;
    std::string getMemberId() const;
    std::vector<std::string> getBorrowedIds() const;

    void addBorrowedId(const std::string& itemId);
    void removeBorrowedId(const std::string& itemId);

    void displayInfo() const;
};

#endif